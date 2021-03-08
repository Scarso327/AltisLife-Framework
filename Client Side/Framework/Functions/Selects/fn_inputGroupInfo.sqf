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
	["_onSelect", {}, [{}]],
	["_tablet", true, [false]]
];

if (isNull _parent) exitWith {};

private _display = _parent createDisplay "DisplayInputGroupInfo";

(_display displayCtrl 3701) ctrlShow _tablet;
(_display displayCtrl 3702) ctrlShow !_tablet;

private _cfg = missionConfigFile >> "CfgGroups";

private _tagInput = _display displayCtrl 3705;
private _nameInput = _display displayCtrl 3706;
private _button = _display displayCtrl 3707;

_tagInput setVariable ["Length", [getNumber (_cfg >> "Tag" >> "MinLength"), getNumber (_cfg >> "Tag" >> "MaxLength")]];
_nameInput setVariable ["Length", [getNumber (_cfg >> "Name" >> "MinLength"), getNumber (_cfg >> "Name" >> "MaxLength")]];

_tagInput ctrlSetEventHandler ["KeyUp", "_this call ULP_UI_fnc_inputLimit;"];
_nameInput ctrlSetEventHandler ["KeyUp", "_this call ULP_UI_fnc_inputLimit;"];

_display setVariable ["params", _params];
_display setVariable ["onSelect", _onSelect];