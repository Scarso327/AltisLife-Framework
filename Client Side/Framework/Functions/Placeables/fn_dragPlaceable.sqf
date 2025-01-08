/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_dragPlaceable";

_this params [
	["_object", objNull, [objNull]],
	["_placeable", "", [""]]
];

private _cfg = missionConfigFile >> "CfgPlaceables" >> "Objects" >> _placeable;
if (isNull _object 
	|| { !isClass _cfg }
	|| { !isNull (objectParent player) } 
	|| { [] call ULP_fnc_isInputBlocked }) exitWith { false };

if !(isNull (_object getVariable ["unitDragging", objNull])) exitWith {
	["Someone else is already dragging this placeable..."] call ULP_fnc_hint;
	false
};

[] spawn ULP_UI_fnc_closeDialogs;

_object setVariable ["unitDragging", player, true];
_object attachTo [player, [0, 1.65, 0.3]];

ULP_PlaceableObjectDragAction = player addAction [format ["Release %1", getText(_cfg >> "displayName")], {
		_this params ["", "", "_actionId", "_params"];
		_params params [ "_cfg", "_object" ];

		player removeAction _actionId;

		if (isNull _object) exitWith {};

		[_object, player] call ULP_fnc_releasePlaceable;
	}, [_cfg, _object], 10, false, false, "", "true"];

[ { !([player] call ULP_fnc_isDragging) }, _object, {
	player removeAction ULP_PlaceableObjectDragAction;
	ULP_PlaceableObjectDragAction = nil;
}] call ULP_fnc_waitUntilExecute;

player playActionNow "grabDrag";

[ { (animationState player) == "acinpknlmstpsnonwnondnon" }, _object, {
	[ { !((animationState player) in ["acinpknlmstpsnonwnondnon", "acinpknlmwlksnonwnondb"]) }, _this, {
		[_this, player] call ULP_fnc_releasePlaceable;
	}] call ULP_fnc_waitUntilExecute;
}] call ULP_fnc_waitUntilExecute;

true