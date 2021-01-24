/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onRestrained";

_this params [
	["_detainer", objNull, [objNull]]
];

// (Double) Checks...
if (isNull _detainer || { [player] call ULP_fnc_isRestrained }) exitWith {};

player setVariable ["restrained", ([_detainer] call ULP_fnc_getFaction), true]; // Tells the server we're restrained... 

// Just handles animations... We use events for escorting, death, etc. This keeps the loops resource requirement low.
[] spawn {
	for "_i" from 0 to 1 step 0 do {
		if !([player] call ULP_fnc_isRestrained) exitWith {};

		if (isNull (objectParent player)) then {
			player playMove "AmovPercMstpSnonWnonDnon_Ease";
		};

		waitUntil { !((animationState player) isEqualTo "AmovPercMstpSnonWnonDnon_Ease") || { !([player] call ULP_fnc_isRestrained) } };
	};
};