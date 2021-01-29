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
} && { [_target] call ULP_fnc_isSurrendered
} &&  { alive player
} && { !(isDowned(player))
} && { !([player] call ULP_fnc_isRestrained)
} && { [player] call ULP_fnc_getFaction in ["Police"] }