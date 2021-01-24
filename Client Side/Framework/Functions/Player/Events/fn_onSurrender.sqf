/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onSurrender";

// Already Surrendered...
if ([player] call ULP_fnc_isSurrendered || { isDowned(player) }) exitWith {};

player setVariable ["surrender", true, true];

[] spawn {
	for "_i" from 0 to 1 step 0 do {
		if !([player] call ULP_fnc_isSurrendered) exitWith {};

		if (isNull (objectParent player)) then {
			player playMove "AmovPercMstpSnonWnonDnon_AmovPercMstpSsurWnonDnon";
		};

		waitUntil { !((animationState player) isEqualTo "AmovPercMstpSnonWnonDnon_AmovPercMstpSsurWnonDnon") || { !([player] call ULP_fnc_isSurrendered) } };
	};

	player playMoveNow "AmovPercMstpSsurWnonDnon_AmovPercMstpSnonWnonDnon";
	player setVariable ["surrender", nil, true];
};