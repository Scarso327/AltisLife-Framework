/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_wipeEffects";

if ((count ULP_Effects) isEqualTo 0) exitWith {};

for "_i" from 0 to (count ULP_Effects) - 1 do {
	{
		_x params [
			"_effectHandle",
			["_onDestroyed", {}, [{}]]
		];

		_effectHandle call _onDestroyed; // Execute the onDestroyed event...
		ppEffectDestroy _effectHandle;
	} forEach (ULP_Effects select _i);
};