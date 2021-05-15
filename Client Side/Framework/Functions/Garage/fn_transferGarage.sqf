/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_transferGarage";

if (canSuspend) exitWith {
    [ULP_fnc_transferGarage, _this] call ULP_fnc_directCall;
};

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _vehInfo = _display getVariable ["selected", []];
if (_vehInfo isEqualTo []) exitWith {};

_vehInfo params [ "_id", "_classname" ];

private _cfg = [_classname] call ULP_fnc_vehicleCfg;
if (_cfg isEqualTo []) exitWith {};

_cfg params [ "", "_missionCfg", "", "_name" ];

if !([getNumber (_missionCfg >> "canTransfer")] call ULP_fnc_bool) exitWith {
	["This vehicle can't be transfered"] call ULP_fnc_hint;
};

[ (findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), ["Civilian"], [_display, _id, _name], {
	_this params [
		["_display", displayNull, [displayNull]],
		["_vehId", -1, [0]],
		["_name", "", [""]],
		["_selectDisplay", displayNull, [displayNull]]
	];

	if (isNull _selectDisplay || { isNull _display } || { _vehId <= 0 }) exitWith {};

	private _list = _selectDisplay displayCtrl 3809;

	private _player = (_list tvData (tvCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _player) exitWith {
		["You didn't select anyone!"] call ULP_fnc_hint;
	};
	
	private _list = _display displayCtrl 3501;
	_list lbDelete (lbCurSel _list);

	_list lbSetCurSel 0;
	[_list, 0] call ULP_fnc_onGarageSwitch;

	[player, _player, _vehId] remoteExecCall ["ULP_SRV_fnc_transferVehicle", RSERV];
	[format ["You transferred your <t color='#B92DE0'>%1</t> to <t color='#B92DE0'>%2</t>.", _name, name _player]] call ULP_fnc_hint;
}, false, false] call ULP_fnc_selectPlayer;