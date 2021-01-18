/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
#include "..\..\dikCodes.hpp"
scopeName "fn_keyDown";

_this params [
    "_ctrl", "_code", "_shift", "_ctrlKey", "_alt"
];

private _handled = false;
private _disabledKeys = [];
private _interruptKeys = [W, A, S, D];

_disabledKeys append (actionKeys "tacticalView"); // Disable tactical view...

if (_code in _disabledKeys) then { _handled = true };

if (isDowned(player)) then { 
    // Incapacitated Inputs...
    switch (_code) do {
        case ESC: { _handled = true };
    };
} else {
    switch (_code) do {
        case Y: {
            if (!_alt && { !_ctrlKey } && { !dialog } && { !(player call ULP_fnc_isRestrained) } && { !life_action_inUse }) then {
                [] call life_fnc_p_openMenu;
            };
        };
    };
};

_handled