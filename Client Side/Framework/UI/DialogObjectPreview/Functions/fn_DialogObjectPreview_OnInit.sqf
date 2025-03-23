/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogObjectPreview_OnInit";
disableSerialization;

_this params [ "_display", "_params" ];

if (isNull _display) exitWith {};

_params params [ "_className", "_texture" ];

private _position = [0, 0, 5000];

private _camera = "camera" camCreate _position;
_camera cameraEffect ["Internal", "BACK"];
_camera camSetFocus [-1, -1];
showCinemaBorder false;
_camera camCommit 0;

private _object = _className createVehicleLocal [0, 0, 0];
_object enableSimulation false;
_object setPos _position;
_object setVectorUp [0, 0, 1];

[_object, _texture, true] call ULP_fnc_skinVehicle;

private _target = getPos _object;

private _boundingBox = boundingBoxReal _object;

private _bodyDiagonal = [_boundingBox select 0 select 0, _boundingBox select 0 select 2] distance [_boundingBox select 1 select 0, _boundingBox select 1 select 2];
private _distance = _bodyDiagonal * 2;

_camera camSetTarget _target;
_camera camSetPos (_object modelToWorld [0, _distance, _distance * 0.3]);
_camera setVectorUp [0, 0, 1];
_camera camCommit 0;

private _mag = vectorMagnitude (_object worldToModel (getPos _camera));

_display setVariable ["position", _position];
_display setVariable ["camera", _camera];
_display setVariable ["target", _target];
_display setVariable ["object", _object];
_display setVariable ["mag", _mag];
_display setVariable ["zoom", _mag];

_display setVariable ["mouseDownEvh", _display displayAddEventHandler ["MouseButtonDown", { (_this select 0) setVariable ["MouseDown", true]; }]];
_display setVariable ["mouseUpEvh", _display displayAddEventHandler ["MouseButtonUp", { (_this select 0) setVariable ["MouseDown", nil]; }]];

_display setVariable ["mouseMovingEvh", _display displayAddEventHandler ["MouseMoving", {
	_this params ["_display", "_dX", "_dY"];

	private _object = _display getVariable ["object", objNull];

	if (isNull _object || { !(_display getVariable ["MouseDown", false]) }) exitWith {};

	private _dir = vectorDir _object;
	private _newdir = [(_dir select 0) * cos _dx - (_dir select 1) * sin _dx, (_dir select 0) * sin _dx + (_dir select 1) * cos _dx, 0];

	_object setVectorDir vectorNormalized _newdir;
}]];


_display setVariable ["mouseScrollEvh", _display displayAddEventHandler ["MouseZChanged", {
	_this params ["_display", "_scroll"];

	private _object = _display getVariable ["object", objNull];
	private _camera = _display getVariable ["camera", objNull];

	if (isNull _object || { isNull _camera }) exitWith {};

	private _max = _display getVariable ["mag", 0];
	private _zoom = _display getVariable ["zoom", 0];
	private _target = _display getVariable ["target", getPos _object];
		
	private _boundingBox = boundingBoxReal _object;

	private _bodyDiagonal = [_boundingBox select 0 select 0, _boundingBox select 0 select 2] distance [_boundingBox select 1 select 0, _boundingBox select 1 select 2];

	private _min = _bodyDiagonal + 1;
    private _step = (_max - _min) / 10;

    private _oldPos = getPos _camera;

    _zoom = _min max (_zoom - (_step * (abs (_scroll) / _scroll)));
    _zoom = _max min _zoom;

    if (_zoom >= _max || {_zoom <= _min}) exitWith {};

    private _newPos = _target vectorAdd ((vectorNormalized (_oldPos vectorDiff _target)) vectorMultiply _zoom);

    _camera camSetPos _newPos;
    _camera camCommit 0.15;

	_display setVariable ["zoom", _zoom];
}]];

[["RscHUD"] call ULP_UI_fnc_getLayer] call ULP_UI_fnc_closeHUD;