/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_handleCamera";

_this params [
	["_screen", objNull, [objNull]],
	["_location", "", [""]],
	["_camera", "", [""]]
];

if (isNull _screen) exitWith { false };

if (isNull (_screen getVariable ["camera", objNull])) then {
	if !(isPiPEnabled) exitWith { ["This system requires PiP to be enabled in your video settings!"] call ULP_fnc_hint; false breakOut "fn_handleCamera"; };

	private _cfg = missionConfigFile >> "CfgCameras" >> worldName >> _location;
	if !(isClass _cfg || { call compile getText (_cfg >> "condition") }) exitWith { false breakOut "fn_handleCamera"; };

	private _cameraCfg = _cfg >> "Cameras" >> _camera;
	if !(isClass _cameraCfg) exitWith { false breakOut "fn_handleCamera"; };

	private _cam = "camera" camCreate [0,0,0];
	"rendertarget1" setPiPEffect [0];
	_cam camSetFov 1;
	_cam camCommit 0;
	_cam camSetFocus [9999,0];
	_cam cameraEffect ["INTERNAL", "BACK", "rendertarget1"];
	_screen setVariable ["originalscreen", ((getObjectTextures _screen) param [0, ""])];
	_screen setObjectTexture [0,"#(argb,512,512,1)r2t(rendertarget1,100)"];

	_cam camSetPos getArray (_cameraCfg >> "position");
	_cam camSetTarget getArray (_cameraCfg >> "target");
	_cam camCommit 0;

	_screen setVariable ["camera", _cam];

	[{ isNull (_this getVariable ["camera", objNull]) || { (player distance _this) > 15 } }, _screen, {
		private _cam = _ths getVariable ["camera", objNull];

		if !(isNull _cam) then {
			[_this] call ULP_fnc_handleCamera;
		};
	}] call ULP_fnc_waitUntilExecute;
} else {
	private _cam = _screen getVariable ["camera", objNull];
	_cam cameraEffect ["terminate", "back"];
    camDestroy _cam;
    _screen setObjectTexture [0, (_screen getVariable ["originalscreen", ""])];
	_screen setVariable ["camera", nil];
};

true