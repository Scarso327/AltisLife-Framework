/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_destroyGarage";

if (canSuspend) exitWith {
    [ULP_fnc_destroyGarage, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _vehInfo = _display getVariable ["selected", []];
if (_vehInfo isEqualTo []) exitWith {};

_vehInfo params [
	"_id", "_classname", "_texture", "_index"
];

private _vehicleCfg = [_classname] call ULP_fnc_vehicleCfg;
if (_vehicleCfg isEqualTo []) exitWith {};

[_id] remoteExecCall ["ULP_SRV_fnc_destroyVehicle", RSERV];

private _list = _display displayCtrl 3501;
_list lbDelete _index;

_list lbSetCurSel 0;
[_list, 0] call ULP_fnc_onGarageSwitch;

_vehicleCfg params [
	"", "_missionCfg", "_picture", "_name"
];

[format ["You have destroyed your <t color='#B92DE0'>%1</t> (<t color='#B92DE0'>%2</t>)", _name, getText(_missionCfg >> "Textures" >> _texture >> "displayName")]] call ULP_fnc_hint;