/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_buyHouse";

if (canSuspend) exitWith {
    [ULP_SRV_fnc_buyHouse, _this] call ULP_fnc_directCall;
};

_this params [
	["_buyer", objNull, [objNull]],
	["_house", objNull, [objNull]],
	["_money", 0, [0]]
];

if (isNull _house || { !([_house] call ULP_fnc_isHouse) } || { [_house] call ULP_fnc_isHouseOwned } || { _house getVariable ["blacklisted", false] }) exitWith {
	["HouseBought", [_house, false, "This house can't be bought...", _money]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];
};

private _steamid = getPlayerUID _buyer;

// Get ID...
private _id = ["houses"] call ULP_SRV_fnc_getNextId;

// Insert...
[format[
	"INSERT INTO `houses` (`id`, `pid`, `classname`, `pos`, `storage`, `virtualStorage`, `upgrades`) VALUES ('%1', '%2', '%3', '%4', '""[]""', '""[]""', '""[]""');", 
	[_id, ""] call ULP_fnc_numberText, _steamid, (typeOf _house), [getPos _house] call DB_fnc_mresArray
], 1] call DB_fnc_asyncCall;

[_house, [_id, [_steamid, ([group _buyer] call ULP_fnc_groupId), name _buyer]]] call ULP_SRV_fnc_setupHouse;
[_steamid, "House", ["Bought", getPos _house, [_money, ""] call ULP_fnc_numberText]] call ULP_SRV_fnc_logPlayerEvent;

["HouseBought", [
	_house, true, 
	format ["You have successfully bought this house for %1%2...", "£", [_money] call ULP_fnc_numberText]
]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];