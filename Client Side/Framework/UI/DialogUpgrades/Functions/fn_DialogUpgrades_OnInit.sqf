/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogUpgrades_OnInit";
disableSerialization;

_this params [ "_display", "_params" ];

if (isNull _display) exitWith {};

_params params [
	["_object", objNull, [objNull]]
];

_display setVariable ["selectedObject", _object];

private _list = _display displayCtrl 5701;

{
	private _picture = getText (_x >> "icon");
	private _name = getText (_x >> "displayName");

	private _index = _list lbAdd _name;
	_list lbSetPicture [_index, _picture];
	_list lbSetData [_index, configName _x];
} forEach ("isClass _x" configClasses ([_object] call ULP_fnc_upgradeCfg));