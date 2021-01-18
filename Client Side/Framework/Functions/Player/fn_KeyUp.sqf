/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
scopeName "fn_keyUp";

_this params [
    "_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
];

private _handled = false;

if (isDowned(player)) then { 
	switch (_code) do {
        case F: { if (_shift && { missionNamespace getVariable ["ULP_CanRespawn", false] }) then { player SetDammage 1; _handled = true; } }; // Respawn (Shift + F)...
		case E: {  }; // Request Medic (E, TODO)
    };
};

_handled