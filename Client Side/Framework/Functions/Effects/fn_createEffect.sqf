/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_createEffect";

if (!(_this isEqualType []) || { (count _this) isEqualTo 0 }) exitWith { false }; // Nothing to create...
if (isNil "ULP_Effects") then { ULP_Effects = [] };

private _count = count ULP_Effects;
private _finalEffects = [];

{
	_x params [
		"_effectHandle",
		["_onDestroyed", {}, [{}]]
	];

	_finalEffects pushBack [_effectHandle, _onDestroyed];
} forEach _this;

ULP_Effects pushBack _finalEffects;

_count // Return the count so we can save the index this effect exists within...