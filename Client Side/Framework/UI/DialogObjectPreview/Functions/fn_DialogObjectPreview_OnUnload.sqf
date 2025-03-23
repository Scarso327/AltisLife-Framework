/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogObjectPreview_OnUnload";

_this params [ "_display" ];

if (isNull _display) exitWith {};

uiNamespace setVariable ["DialogObjectPreview", nil];

private _camera = _display getVariable ["camera", objNull];
private _object = _display getVariable ["object", objNull];

_camera cameraEffect ["Terminate", "BACK"];
camDestroy _camera;

deleteVehicle _object;

if (["EnableHUD", "HUD"] call ULP_fnc_getOption isEqualTo 1) then {
	[] call ULP_UI_fnc_openHUD;
};