/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onAirdropSpawn";

if !(hasInterface) exitWith {};

_this params [
	["_airdrop", objNull, [objNull]],
	["_message", "", [""]]
];

if (isNull _airdrop) exitWith {};

[_message] call ULP_fnc_hint;

_airdrop addAction [
	"Claim Airdrop", {
		_this params [ "_airdrop", "", "_actionId" ];

		if (_airdrop getVariable ["locked", false]) exitWith {
			["The airdrop is still locked, you must break into it before it can be claimed..."]  call ULP_fnc_hint;
		};

		["Claiming Airdrop", 150, [_airdrop, _actionId], { true }, {
			_this params [ "_airdrop", "_actionId" ];

			_airdrop removeAction _actionId;
			["Claiming Airdrop..."] call ULP_fnc_hint;

			[player, _airdrop] remoteExecCall ["ULP_SRV_fnc_claimAirdrop", RSERV];
		}, {}] call ULP_UI_fnc_startProgress;
	}, nil, 8, true, true, "", "(((getPos _target) select 2) <= 1)", 5
];