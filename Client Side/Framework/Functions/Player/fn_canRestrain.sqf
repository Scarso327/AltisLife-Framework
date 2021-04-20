/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canRestrain";

_this params [
	["_target", cursorObject, [objNull]]
];

!(isNull _target) 
&& { isPlayer _target
} && { alive _target
} && { isNull (objectParent _target)
} && { (_target distance player) < 3
} && { !([_target] call ULP_fnc_isRestrained)
} && { [_target] call ULP_fnc_isSurrendered || [_target] call ULP_fnc_isKnocked || [player] call ULP_fnc_onDuty
} &&  { alive player
} && { !(isDowned(player))
} && { !([player] call ULP_fnc_isRestrained)
} && { !([player] call ULP_fnc_isSurrendered)
} && { !([player] call ULP_fnc_isKnocked)
} && { [player, ["Police"]] call ULP_fnc_isFaction || 
	{ [player] call ULP_fnc_onDuty && { ["Restrain", false] call ULP_fnc_checkPower } } ||
	{ ([player, ["Civilian"]] call ULP_fnc_isFaction && { (((["Ziptie"] call ULP_fnc_hasItem) > 0) || { ["cuffCourier"] call ULP_fnc_hasPerk }) }) }
} 