/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_spawnMenu";

disableSerialization;

if !(createDialog "DialogSpawn") exitWith {
	["Abort", true, false] call BIS_fnc_endMission;
};

private _display = findDisplay 3000;
if (isNull _display) exitWith {};

_display displaySetEventHandler ["keyDown","_this call ULP_UI_fnc_blockEsc"];

private _map = _display displayCtrl 3001;
_map ctrlEnable false;

private _list = _display displayCtrl 3002;
lbClear _list;

private _item = -1;
private _icon = "";

{
	if (call compile getText(_x >> "conditions") && { [player, getArray(_x >> "factions")] call ULP_fnc_isFaction }) then {
		_item = _list lbAdd getText(_x >> "displayName");
		_icon = getText(_x >> "icon");

		if !(_icon isEqualTo "") then {
			_list lbSetPicture [_item, _icon];
		};
		
		_list lbSetData [_item, configName _x];
	};
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgSpawns" >> worldName));

_list lbSetCurSel 0;
[_list, 0, 0] call ULP_fnc_changeSpawn;
_list ctrlSetEventHandler ["LBSelChanged", "_this call ULP_fnc_changeSpawn;"];