/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_giveLoot";

_this params [
	["_pid", "", [""]],
	["_loot", createHashMap, [createHashMap]]
];

private _message = ["- Nothing"];

if (_pid isEqualTo "" || { (count _loot) < 1 }) exitWith { _loot };

{
	private _type = _x;

	{
		if ([_pid, _type, _x, _y] call ULP_SRV_fnc_addMail) then {
			_message pushBack format ["- %1", (switch (_type) do {
				case "VirtualItem": { format ["%1 (x %2)", getText (missionConfigFile >> "CfgVirtualItems" >> _x >> "displayName"), [_y] call ULP_fnc_numberText] };
				default { format ["%1 (%2)", ([_x] call ULP_fnc_itemCfg) param [5, _x], _y] };
			})];
		};
	} forEach _y;
} forEach _loot;

if ((count _message) > 1) then {
	_message deleteAt 0;
	_message = _message joinString "<br/>";
};

_message