/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_sellHouse";

if (canSuspend) exitWith {
    [ULP_SRV_fnc_sellHouse, _this] call ULP_fnc_directCall;
};

_this params [
	["_seller", "", [""]],
	["_house", objNull, [objNull]]
];

private _owner = _house getVariable ["building_owner", []];
_owner params [
	["_steamid", "", [""]],
	["_groupId", -5, [0]]
];

if (isNull _house || { !([_house] call ULP_fnc_isHouse) } || { !(_steamid isEqualTo _seller) }) exitWith {
	["HouseSold", [_house, false, "You don't have permission to sell this house..."]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

[format["UPDATE `houses` SET `sold`='1' WHERE `id`='%1'", [(_house getVariable ["building_id", -1]), ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;

private _cfg = missionConfigFile >> "CfgHousing" >> "houses" >> (typeOf _house);

if (_house getVariable ["building_shared", false]) then {
	private _group = [_groupId] call ULP_fnc_getGroupById;

	if (isNull _group) then {
		["HouseRemoved", [_house]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
	} else {
		{
			["HouseRemoved", [_house]] remoteExecCall ["ULP_fnc_invokeEvent", _x];
		} forEach (units _group);
	};
} else {
	["HouseRemoved", [_house]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

private _money = round (getNumber (_cfg >> "price") * getNumber (_cfg >> "sellMultiplier"));
[_steamid, "House", ["Sold", getPos _house, [_money, ""] call ULP_fnc_numberText]] call ULP_SRV_fnc_logPlayerEvent;

_house setVariable ["building_id", nil, true];
_house setVariable ["building_owner", nil, true];
_house setVariable ["building_shared", nil, true];

// Unlock Doors...
for "_i" from 1 to (getNumber(configFile >> "CfgVehicles" >> (typeOf _house) >> "numberOfDoors")) do {
	_house setVariable [format ["bis_disabled_Door_%1", _i], 0, true];
};

private _storage = _house getVariable ["building_storage", objNull];
if !(isNull _storage) then {
	deleteVehicle _storage;
};

_house allowDamage true;

ULP_SRV_Houses deleteAt (ULP_SRV_Houses find _house);

["CALL deleteOldHouses", 1] call DB_fnc_asyncCall;
["HouseSold", [_house, true, format["You have successfully sold this house for %1%2...", "£", [_money] call ULP_fnc_numberText], _money]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];