/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onRestrain";

_this params [
	["_detainer", objNull, [objNull]]
];

_detainer = [[_detainer] call ULP_fnc_getFaction, nil] select (isNull _detainer);

player setVariable ["restrained", _detainer, true]; // Set restrain state...

if ([player] call ULP_fnc_isRestrained) then {
	[[], {
        if (alive player && { !(isDowned(player)) } && { [player] call ULP_fnc_isRestrained }) then {
            player playMove "AmovPercMstpSnonWnonDnon_Ease";
        } else {
			detach player;

            player playMoveNow "AmovPercMstpSnonWnonDnon";
            [_thisEventHandler] call ULP_fnc_removeEachFrame;
        };
    }] call ULP_fnc_addEachFrame;
};