/*
** Author: Jack "Scarso" Farhall
** Description: Stops placement of any objects if the user is placing one
*/
#include "..\..\script_macros.hpp"
scopeName "fn_stopPlacement";

_this params [
	["_delete", true, [false]]
];

if !(isNull (missionNamespace getVariable ["ULP_PlaceableObject", objNull])) then {
	// This is used after successfully placement
	// In this case we want to keep object but let the client "forget" about it
	if (_delete) then { deleteVehicle ULP_PlaceableObject; };

	player removeAction (missionNamespace getVariable ["ULP_PlaceableObjectAction", -1]);

	ULP_PlaceableObjectAction = nil;
	ULP_PlaceableObject = nil;
};