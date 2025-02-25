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
	"_id", "_classname", "_texture", "", "_index"
];

private _vehicleCfg = [_classname] call ULP_fnc_vehicleCfg;
if (_vehicleCfg isEqualTo []) exitWith {};

_vehicleCfg params [
	"", "_missionCfg", "", "_name"
];

private _textureName = getText(_missionCfg >> "Textures" >> _texture >> "displayName");

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Yes", "No"],
	format ["Are you sure you want to destory <t color='#B92DE0'>%1</t> (<t color='#B92DE0'>%2</t>), this cannot be undone...", _name, _textureName], 
	[_display, _id, _classname, _texture, _index, _name, _textureName],
	{	
		_this params [ "_display", "_id", "_classname", "_texture", "_index", "_name", "_textureName" ];

		[_id] remoteExecCall ["ULP_SRV_fnc_destroyVehicle", RSERV];

		private _list = _display displayCtrl 3501;
		_list lbDelete _index;

		_list lbSetCurSel 0;
		[_list, 0] call ULP_fnc_onGarageSwitch;

		[format ["You have destroyed your <t color='#B92DE0'>%1</t> (<t color='#B92DE0'>%2</t>)", _name, _textureName]] call ULP_fnc_hint;
		[getPlayerUID player, "Destroy", [_name, _textureName]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];
	}, {}, false
] call ULP_fnc_confirm;
