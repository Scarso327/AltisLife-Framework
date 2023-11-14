/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_getMail";

_this params [
	["_pid", "", [""]]
];

private _mail = [];

private _query = [format["SELECT id, pid, type, class, data FROM mail WHERE pid='%1' AND claimed='0'", _pid], 2, true] call DB_fnc_asyncCall;

if !(_pid isEqualTo "" || { _query isEqualTo "" } || { _query isEqualTo [] }) then {
	_mail = _query apply {
		private _data = _x param [4, ""];

		if (_data isEqualType "") then {
			_x set [4, [_data] call DB_fnc_mresToArray];
		};

		_x
	};
};

["MailReceived", [_mail]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];