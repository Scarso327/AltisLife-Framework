/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onAirdropSpawn";

_this params [
	["_airdrop", objNull, [objNull]],
	["_message", "", [""]]
];

if (isNull _airdrop) exitWith {};

[parseText _message] call ULP_fnc_hint;

_airdrop addAction [
	"Claim Airdrop", {
		_this params [ "_airdrop", "", "_actionId" ];

		["Claiming Airdrop", 150, [_airdrop, _actionId], { true }, {
			_this params [ "_airdrop", "_actionId" ];

			_airdrop removeAction _actionId;
			["Claiming Airdrop..."] call ULP_fnc_hint;

			[player, _airdrop] remoteExecCall ["ULP_SRV_fnc_claimAirdrop", RSERV];
		}, {}] call ULP_UI_fnc_startProgress;
	}, nil, 8, true, true, "", "!(_target getVariable [""locked"", false]) && { (((getPos _target) select 2) <= 1) }", 5
];