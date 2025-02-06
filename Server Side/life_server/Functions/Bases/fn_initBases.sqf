/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initBases";

private _hour = _this;

["Initialising Group Bases..."] call ULP_fnc_logIt;

(getArray (missionConfigFile >> "CfgBases" >> "Restart")) params [ "_startHour", "_endHour" ];

if (([] call ULP_SRV_fnc_getDayName) isEqualTo getText (missionConfigFile >> "CfgBases" >> "Day") && { _hour >= _startHour } && { _hour < _endHour }) then {
	if !(ULP_SRV_Setting_BaseBidsActive) then {
		["UPDATE settings SET `value` = '1' WHERE setting = 'BaseBidsActive'", 1] call DB_fnc_asyncCall;
		missionNamespace setVariable ["ULP_SRV_Setting_BaseBidsActive", true, true];
	};

	// Wait for the end and award the bases
	[{ (systemTime param [3]) isEqualTo _this || !(isNil "ULP_AwardBasesNow") }, _endHour, {
		[] call ULP_SRV_fnc_awardGangBases;
	}] call ULP_fnc_waitUntilExecute;

} else {
	if (ULP_SRV_Setting_BaseBidsActive) then {
		["UPDATE settings SET `value` = '0' WHERE setting = 'BaseBidsActive'", 1] call DB_fnc_asyncCall;
		missionNamespace setVariable ["ULP_SRV_Setting_BaseBidsActive", false, true];
	};
};

{
	(getArray (_x >> "position")) params [ "_pos", "_dir" ];

	private _query = [format ["SELECT `settings`.`value`, `groups`.`tag` FROM `settings` 
		LEFT JOIN `groups` ON `groups`.`id` = `settings`.`value`
		WHERE `settings`.`setting` = 'base_owner_%1'", configName _x], 2] call DB_fnc_asyncCall;
	_query params [
		["_owner", -2, [0, ""]],
		["_groupTag", "", [""]]
	];

	if (_owner isEqualTo -2) then {
		// Insert...
		[format ["INSERT INTO settings (setting, `value`) VALUES ('base_owner_%1', '%2');", configName _x, getNumber(_x >> "defaultGroupOwnerId")], 1] call DB_fnc_asyncCall;
	} else {

		// This base is part of bidding and bidding is active so we need to wipe current owner
		if ([getNumber (_x >> "includeBidding")] call ULP_fnc_bool && { missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false] }) then {
			_owner = -1;
			[format ["UPDATE settings SET `value` = '-1' WHERE setting = 'base_owner_%1'", configName _x], 1] call DB_fnc_asyncCall;
		};
	};

	if (_owner isEqualType "") then { _owner = parseNumber _owner; };

	private _flag = createVehicle ["Flag_Syndikat_F", _pos, [], 0, "CAN_COLLIDE"];
	_flag setDir _dir;
	_flag allowDamage false;
	_flag enableDynamicSimulation true;

	private _marker = createMarker [format ["gang_base_%1", configName _x], _pos];
	_marker setMarkerType "loc_bunker";
	_marker setMarkerColor "colorOPFOR";
	_marker setMarkerSize [1.2, 1.2];

	private _markerText = "Gang Base";

	if (_owner > -1) then {
		if !(_groupTag isEqualTo "") then {
			_markerText = format["%1 | %2", _markerText, _groupTag];
		};

		_flag setVariable ["owner", _owner, true];
	};

	_marker setMarkerText _markerText;

	_flag setVariable ["cfg", _x, true];
	_flag setVariable ["marker", _marker];

	missionNamespace setVariable [format ["ULP_SRV_Base_%1", configName _x], _flag, true];
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgBases"));

[] call ULP_SRV_fnc_setBaseMarkers;