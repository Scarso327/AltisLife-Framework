/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
scopeName "fn_actionKeyDown";

if (canSuspend) exitWith {
    [ULP_fnc_actionKeyDown, _this] call ULP_fnc_directCall;
};

_this params [
    "_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
];

if (!alive player || 
	{ isDowned(player) } || 
	{ !(isNull (objectParent player)) } || 
	{ dialog } || 
	{ [player] call ULP_fnc_isRestrained } || 
	{ [player] call ULP_fnc_isSurrendered }
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
	private _interactions = [_object] call ULP_fnc_getInteractions;

	if !(_interactions isEqualTo []) exitWith {
		[_object, _interactions] call ULP_fnc_openInteractions;
	};
};

true