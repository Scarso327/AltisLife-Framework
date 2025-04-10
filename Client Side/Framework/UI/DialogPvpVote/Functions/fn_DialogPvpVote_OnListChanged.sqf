/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogPvpVote_OnListChanged";

_this params [ "_list", "_path" ];

if (isNull _list) exitWith {};

private _display = ctrlParent _list;
private _mapCtrl = _display displayCtrl 6302;

private _selected = parseSimpleArray (_list tvData _path);
if (_selected isEqualTo []) exitWith {};

_selected params [ "_modeCfgName", "_locationCfgName" ];

private _modeCfg = missionConfigFile >> "CfgPvpModes" >> "Modes" >> _modeCfgName;
private _locationCfg = _modeCfg >> "Locations" >> worldName >> _locationCfgName;

_display setVariable ["selectedCfg", _locationCfg];

private _position = getArray (_locationCfg >> "position");

[_mapCtrl, [1, 0.3, _position]] call ULP_UI_fnc_setMapPosition;