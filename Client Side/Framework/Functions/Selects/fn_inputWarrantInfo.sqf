/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_inputWarrantInfo";

_this params [
	["_parent", displayNull, [displayNull]],
	["_params", [], [[]]],
	["_onSelect", {}, [{}]]
];

if (isNull _parent) exitWith {};

private _display = _parent createDisplay "DisplayWarrantCreation";

private _cfg = missionConfigFile >> "CfgWarrants";

private _noteInput = _display displayCtrl 5001;
if (isNull (_noteInput getVariable ["Placeholder", controlNull])) then { [_noteInput, (_display displayCtrl 5002)] call ULP_UI_fnc_placeholder; };

private _types = _display displayCtrl 5003;
lbClear _types;

{
	private _act = configName _x;

	{
		private _item = _types lbAdd getText (_x >> "displayName");
		_types lbSetData [_item, str [_act, configName _x]];
	} forEach ("isClass _x" configClasses _x);
} forEach ("isClass _x" configClasses _cfg);

_types lbSetCurSel 0;

_noteInput setVariable ["Length", [0, getNumber (_cfg >> "NoteLength")]];

_noteInput ctrlSetEventHandler ["KeyUp", "_this call ULP_UI_fnc_inputLimit;"];
ctrlSetFocus _noteInput;

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onSelect];