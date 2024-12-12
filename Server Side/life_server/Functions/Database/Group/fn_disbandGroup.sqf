/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_disbandGroup";

_this params [
	["_unit", objNull, [objNull]],
	["_group", grpNull, [grpNull]]
];

private _groupid = [_group] call ULP_fnc_groupId;

if (_groupid isEqualTo -1) exitWith {};

[format["UPDATE `candidates` INNER JOIN `players` ON `candidates`.`pid` = `players`.`pid` SET `candidates`.`active`='0' WHERE `players`.`group_id`='%1';", [_groupid, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
[format["UPDATE `groups` SET `active`='0' WHERE `id`='%1'", [_groupid, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
[format["UPDATE `players` SET `group_id` = '-1', `group_level` = '0' WHERE `group_id`='%1'", [_groupid, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;

if !(isNull _unit) then {
	[getPlayerUID _unit, "Group", ["Disband", _groupid, [(_group getVariable ["group_funds", 0]), ""] call ULP_fnc_numberText]] call ULP_SRV_fnc_logPlayerEvent;
};

{
	[_x] joinSilent (createGroup [side _x, true]);
} forEach (units _group);
deleteGroup _group;