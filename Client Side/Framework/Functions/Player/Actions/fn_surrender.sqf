/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_surrender";

_this params [
	["_surrender", true, [false]]
];

if ((player getVariable ["surrender", false]) isEqualTo _surrender || { !(isNull (objectParent player)) }) exitWith { false };

player setVariable["surrender", _surrender, true];

if (_surrender) then {
	[[], {
        if (alive player && { !(isDowned(player)) } && { [player] call ULP_fnc_isSurrendered } && { !([player] call ULP_fnc_isRestrained) } && { isNull (objectParent player) }) then {
            player playMove "amovpercmstpsnonwnondnon_amovpercmstpssurwnondnon";
        } else {
            player playMoveNow "AmovPercMstpSsurWnonDnon_AmovPercMstpSnonWnonDnon";
            [_thisEventHandler] call ULP_fnc_removeEachFrame;
        };
    }] call ULP_fnc_addEachFrame;
};

true