/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogMedicMap_OnListChanged";

_this params [ "_list", "_path" ];

if (isNull _list) exitWith {};

private _display = ctrlParent _list;
private _button = _display displayCtrl 5404;

private _unit = (_list tvData _path) call BIS_fnc_objectFromNetId;

if (isNull _unit) exitWith {
	_button ctrlEnable false;
};

private _assignedMedic = _unit getVariable ["AssignedMedic", objNull];

_button ctrlEnable (isNull _assignedMedic || { _assignedMedic isEqualTo player });
_button ctrlSetText (if (_assignedMedic isEqualTo player) then {
	"Unassign"
} else {
	"Assign"
});

[(_display displayCtrl 5403), [1, 0.05, getPos _unit]] call ULP_UI_fnc_setMapPosition;