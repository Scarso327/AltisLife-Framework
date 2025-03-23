/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_previewTexture";

_this params [
	["_button", controlNull, [controlNull]]
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _list = _display displayCtrl 3408;
private _index = lbCurSel _list;

private _vehCfg = _display getVariable ["selected", []];
if (_vehCfg isEqualTo []) exitWith {};

_vehCfg params [
	"", "_missionCfg"
];

private _texture = _missionCfg >> "Textures" >> (_list lbData _index);
if !(isClass _texture) exitWith {};

["DialogObjectPreview", [configName _missionCfg, configName _texture]] call ULP_UI_fnc_createDialog;