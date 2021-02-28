/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
scopeName "fn_actionKeyDown";

_this params [
    "_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
];

if (!alive player || 
	{ isDowned(player) } || 
	{ !(isNull (objectParent player)) } || 
	{ dialog } || 
	{ [player] call ULP_fnc_isRestrained } || 
	{ [player] call ULP_fnc_isSurrended }
) exitWith {
	false
};

private _object = cursorObject;

if (isNull _object) then {
	switch (true) do {
		default {
			private _zone = [] call ULP_fnc_getGatherZone;

			if !(isNull _zone) then {
				[_zone] call ULP_fnc_gather;
			};
		};
	};
} else {
	
};

true