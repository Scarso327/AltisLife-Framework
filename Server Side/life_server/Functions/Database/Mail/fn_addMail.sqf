/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addMail";

_this params [
	["_pid", "", [""]],
	["_type", "", [""]],
	["_class", "", [""]],
	["_data", [], ["", 0, []]]
];

if (_pid isEqualTo "" || { _type isEqualTo "" } || { _class isEqualTo "" }) exitWith { false };

[format[
	"INSERT INTO mail (pid, type, class, data) VALUES ('%1', '%2', '%3', '%4');", 
	_pid, _type, _class, (switch (true) do {
		case (_data isEqualType []) : { [_data] call DB_fnc_mresArray };
		case (_data isEqualType 0) : { [_data, ""] call ULP_fnc_numberText };
		default { [_data] call DB_fnc_mresString };
	})
], 1] call DB_fnc_asyncCall;
true