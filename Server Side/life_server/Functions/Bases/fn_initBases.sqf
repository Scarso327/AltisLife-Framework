/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initBases";

private _hour = _this;

["Initialising Group Bases..."] call ULP_fnc_logIt;

private _newOwners = false;

private _hours = getArray (missionConfigFile >> "CfgBases" >> "Restart");

if (([] call ULP_SRV_fnc_getDayName) isEqualTo getText (missionConfigFile >> "CfgBases" >> "Day") && { _hour >= (_hours select 0) } && { _hour < (_hours select 1) }) then {
	if !(ULP_SRV_Setting_BaseBidsActive) then {
		["UPDATE settings SET `value` = '1' WHERE setting = 'BaseBidsActive'", 1] call DB_fnc_asyncCall;
		missionNamespace setVariable ["ULP_SRV_Setting_BaseBidsActive", true, true];
	};
} else {
	if (ULP_SRV_Setting_BaseBidsActive) then {
		["UPDATE settings SET `value` = '0' WHERE setting = 'BaseBidsActive'", 1] call DB_fnc_asyncCall;
		missionNamespace setVariable ["ULP_SRV_Setting_BaseBidsActive", false, true];

		_newOwners = true;
	};
};

{
	(getArray (_x >> "position")) params [ "_pos", "_dir" ];

	private _owner = -1;

	private _query = [format ["SELECT `settings`.`value`, `groups`.`tag` FROM `settings` 
		LEFT JOIN `groups` ON `groups`.`id` = `settings`.`value`
		WHERE `settings`.`setting` = 'base_owner_%1'", configName _x], 2] call DB_fnc_asyncCall;
	_query params [
		["_queryOwner", -2, [0, ""]],
		["_groupTag", "", [""]]
	];

	if (_queryOwner isEqualTo -2) then {
		// Insert...
		[format ["INSERT INTO settings (setting, `value`) VALUES ('base_owner_%1', '%2');", configName _x, getNumber(_x >> "defaultGroupOwnerId")], 1] call DB_fnc_asyncCall;
	} else {

		// This base is part of bidding wars
		if ([getNumber (_x >> "includeBidding")] call ULP_fnc_bool) then {
			
			// This base is part of bidding and bidding is active so we need to wipe current owner
			if (missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false]) exitWith {
				_queryOwner = -1;
				[format ["UPDATE settings SET `value` = '-1' WHERE setting = 'base_owner_%1'", configName _x], 1] call DB_fnc_asyncCall;
			};

			if (_newOwners) then {
				private _query = [format ["SELECT `groups`.`id`, `groups`.`bank`, `groups`.`owner`, `base_bids`.`bid`, `groups`.`tag` FROM `base_bids` INNER JOIN `groups` WHERE `base_bids`.`base` = '%1' AND `base_bids`.`group_id` = `groups`.id AND `base_bids`.`bid` <= `groups`.`bank` AND `base_bids`.`active` = '1' ORDER BY `base_bids`.`bid` DESC", configName _x], 2] call DB_fnc_asyncCall;
				_query params [
					["_id", -1, [0]], 
					["_bank", 0, [0]], 
					["_ownerId", "", [""]], 
					["_bid", 0, [0]],
					["_tag", "", [""]]
				];

				if (_id < 0 || { _bid < 1 } || { _bank < _bid }) exitWith {};
				
				private _newFunds = _bank - _bid;
				if (_newFunds < 0) exitWith {};

				// Logging...
				[format ["Base Winner: %1 (%2) with a bid of %3", configName _x, _id, [_bid] call ULP_fnc_numberText]] call ULP_fnc_logIt;
				[_ownerId, "BaseBid", ["Winner", [_id,  [_newFunds, ""] call ULP_fnc_numberText, [_bid, ""] call ULP_fnc_numberText]]] call ULP_SRV_fnc_logPlayerEvent;

				// Update group bank, settings, and make bids inactive
				[format ["UPDATE `groups` SET bank = '%2' WHERE id = '%1'", _id, [_newFunds, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
				[format ["UPDATE settings SET `value` = '%2' WHERE setting = 'base_owner_%1'", configName _x, _id], 1] call DB_fnc_asyncCall;
				[format ["UPDATE base_bids SET `active` = '0' WHERE base = '%1'", configName _x], 1] call DB_fnc_asyncCall;

				_queryOwner = _id;
				_groupTag = _tag;
			};
		};

		if (_queryOwner isEqualType "") then { _queryOwner = parseNumber _queryOwner; };
		_owner = _queryOwner;
	};

	private _flag = createVehicle ["Flag_Syndikat_F", _pos, [], 0, "CAN_COLLIDE"];
	_flag setDir _dir;
	_flag allowDamage false;
	_flag enableDynamicSimulation true;
	
	_flag setVariable ["cfg", _x, true];
	_flag setVariable ["owner", _owner, true];

	private _marker = createMarker [format ["gang_base_%1", configName _x], _pos];
	_marker setMarkerType "loc_bunker";
	_marker setMarkerColor "colorOPFOR";
	_marker setMarkerSize [1.2, 1.2];

	private _markerText = "Gang Base";

	if !(_groupTag isEqualTo "") then {
		_markerText = format["%1 | %2", _markerText, _groupTag];
	};

	_marker setMarkerText _markerText;

	missionNamespace setVariable [format ["ULP_SRV_Base_%1", configName _x], _flag, true];
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgBases"));