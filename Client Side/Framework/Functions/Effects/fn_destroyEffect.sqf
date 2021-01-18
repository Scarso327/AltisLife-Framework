/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_destroyEffect";

_this params [
	["_effectIndex", -1, [0]]
];

private _count = count ULP_Effects;
if (_effectIndex < 0 || { _effectIndex >= _count }) exitWith { false };

{
	_x params [
		"_effectHandle",
		["_onDestroyed", {}, [{}]]
	];

	_effectHandle call _onDestroyed; // Execute the onDestroyed event...
	ppEffectDestroy _effectHandle;
} forEach (ULP_Effects select _effectIndex);

true