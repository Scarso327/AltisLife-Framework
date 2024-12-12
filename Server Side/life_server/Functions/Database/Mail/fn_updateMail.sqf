/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_updateMail";

_this params [
	["_mailId", -1, [0]],
	["_data", [], [0, [], ""]],
	["_totalAmount", 0, [0]],
	["_amountClaimed", 0, [0]]
];

if (_mailId isEqualTo -1 || { _data isEqualTo -1 }) exitWith {};

[format[
	"UPDATE `mail` SET `data`='%2', `claimed`='%3' WHERE `id`='%1'", 
	[_mailId, ""] call ULP_fnc_numberText, (switch (true) do {
		case (_data isEqualType []) : { [_data] call DB_fnc_mresArray };
		case (_data isEqualType 0) : { [_data, ""] call ULP_fnc_numberText };
		default { [_data] call DB_fnc_mresString };
	}), [0, 1] select (_totalAmount isEqualTo _amountClaimed || { _data isEqualType 0 && { _data <= 0 } })
], 1] call DB_fnc_asyncCall;

["MailClaimed"] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];