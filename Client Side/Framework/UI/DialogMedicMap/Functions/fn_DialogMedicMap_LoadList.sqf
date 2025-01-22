/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogMedicMap_LoadList";

_this params [ "_display" ];

if (isNull _display) exitWith {};

disableSerialization;
uiNamespace setVariable ["DialogMedicMap", _display];

private _list = _display displayCtrl 5402;
tvClear _list;

private _unassignedList = _list tvAdd [[], "Unassigned"];
_list tvSetPicture [[_unassignedList], "\a3\3den\Data\Cfg3DEN\History\removefromlayer_ca.paa"];
_list tvSetValue  [[_unassignedList], 0];

private _assignedList = _list tvAdd [[], "Assigned"];
_list tvSetPicture [[_assignedList], "\a3\3den\Data\Cfg3DEN\History\makenewlayer_ca.paa"];
_list tvSetValue  [[_assignedList], 1];

private _incapacitatedPlayers = _display getVariable["IncapacitatedPlayers", []];

{
	private _distance = player distance _x;
	private _path = if (isNull (_x getVariable ["AssignedMedic", objNull])) then { _unassignedList } else { _assignedList };

	private _index = _list tvAdd [[_path], [_x] call ULP_fnc_getName];
	_list tvSetData  [[_path, _index], _x call BIS_fnc_netId];
	_list tvSetValue  [[_path, _index], _distance];
} forEach _incapacitatedPlayers;

_list tvSortByValueAll [[], true];

private _button = _display displayCtrl 5404;
_button ctrlEnable false;