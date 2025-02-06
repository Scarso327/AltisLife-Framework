/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_awardGangBases";

// Bidding must be active to award bases
if !(missionNamespace getVariable ["ULP_SRV_Setting_BaseBidsActive", false]) exitWith {};

{
	private _query = [format ["SELECT `groups`.`id`, `groups`.`bank`, `groups`.`owner`, `base_bids`.`bid`, `groups`.`tag` FROM `base_bids` INNER JOIN `groups` WHERE `base_bids`.`base` = '%1' AND `base_bids`.`group_id` = `groups`.id AND `base_bids`.`bid` <= `groups`.`bank` AND `base_bids`.`active` = '1' ORDER BY `base_bids`.`bid` DESC", configName _x], 2] call DB_fnc_asyncCall;
	_query params [
		["_id", -1, [0]], 
		["_bank", 0, [0]], 
		["_owner", "", [""]], 
		["_bid", 0, [0]],
		["_groupTag", "", [""]]
	];

	if (_id < 0 || { _bid < 1 } || { _bank < _bid }) exitWith {};

	private _flag = missionNamespace getVariable [format ["ULP_SRV_Base_%1", configName _x], objNull];

	if (isNull _flag) exitWith {};

	if !([_id, _bid, false] call ULP_SRV_fnc_updateGroupFunds) exitWith { [format ["Failed to award gang base to %1 due to funds", _id]] call ULP_fnc_logIt; };

	[_ownerId, "BaseBid", ["Winner", [_id,  [_bid, ""] call ULP_fnc_numberText]]] call ULP_SRV_fnc_logPlayerEvent;

	_flag setVariable ["owner", _id, true];

	[format ["UPDATE settings SET `value` = '%2' WHERE setting = 'base_owner_%1'", configName _x, _id], 1] call DB_fnc_asyncCall;
	[format ["UPDATE base_bids SET `active` = '0' WHERE base = '%1'", configName _x], 1] call DB_fnc_asyncCall;

	private _marker = _flag getVariable ["marker", ""];

	if (_marker isEqualTo "") exitWith {};

	private _markerText = "Gang Base";

	if !(_groupTag isEqualTo "") then {
		_markerText = format["%1 | %2", _markerText, _groupTag];

		["BaseAwarded", [configName _x, _groupTag], true] call ULP_fnc_invokeEvent;
	};

	_marker setMarkerText _markerText;
} forEach ("isClass _x && { [getNumber (_x >> ""includeBidding"")] call ULP_fnc_bool }" configClasses (missionConfigFile >> "CfgBases"));

missionNamespace setVariable ["ULP_SRV_Setting_BaseBidsActive", false, true];

[] call ULP_SRV_fnc_setBaseMarkers;