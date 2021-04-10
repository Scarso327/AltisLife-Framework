/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_inputGroupInfo";

_this params [
	["_parent", displayNull, [displayNull]],
	["_boundaries", [0, 1], [[]]],
	["_params", [], [[]]],
	["_onSelect", {}, [{}]]
];

if (isNull _parent) exitWith {};

private _display = _parent createDisplay "DisplayGroupCreation";

private _cfg = missionConfigFile >> "CfgGroups";

private _tagInput = _display displayCtrl 3701;
private _nameInput = _display displayCtrl 3702;

if (isNull (_tagInput getVariable ["Placeholder", controlNull])) then { [_tagInput, (_display displayCtrl 3706)] call ULP_UI_fnc_placeholder; };
if (isNull (_nameInput getVariable ["Placeholder", controlNull])) then { [_nameInput, (_display displayCtrl 3707)] call ULP_UI_fnc_placeholder; };

private _types = _display displayCtrl 3703;
lbClear _types;

{
	private _item = _types lbAdd getText (_x >> "displayName");
	_types lbSetData [_item, configName _x];
} forEach ("isClass _x" configClasses (_cfg >> "Types"));

_types lbSetCurSel 0;

_tagInput setVariable ["Length", [getNumber (_cfg >> "Tag" >> "MinLength"), getNumber (_cfg >> "Tag" >> "MaxLength")]];
_nameInput setVariable ["Length", [getNumber (_cfg >> "Name" >> "MinLength"), getNumber (_cfg >> "Name" >> "MaxLength")]];

_tagInput ctrlSetEventHandler ["KeyUp", "_this call ULP_UI_fnc_inputLimit;"];
_nameInput ctrlSetEventHandler ["KeyUp", "_this call ULP_UI_fnc_inputLimit;"];

ctrlSetFocus _tagInput;

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onSelect];