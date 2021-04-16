/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_bpLbChange";

_this params [
	["_list", controlNull, [controlNull]],
	["_path", [0], [[]]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _info = _display displayCtrl 23017;

private _cfg = missionConfigFile >> "CfgBlueprints" >> (_list tvData [_path select 0]) >> (_list tvData _path);
if !(isClass _cfg) exitWith {};

private _required = [];

{
	private _item = missionConfigFile >> "CfgVirtualItems" >> (_x select 0);

	if (isClass _item) then {
		_required pushBack format [" - %1 (%2/%3)", getText (_item >> "displayName"), (([configName _item] call ULP_fnc_hasItem) max 0), [_x select 1] call ULP_fnc_numberText];
	};
} forEach getArray (_cfg >> "materials");

_info ctrlSetStructuredText parsetext format [
	"<br/><br/><img image = '%1' align='center' size='4.5' /><br/><t align = 'center' size = '1.5'>%2</t><br/><t align = 'left' size = '1'><br/>%3<br/><br/>Materials:<br/><t size='0.8'>%4</t></t>", 
	getText(_cfg >> "icon"), 
	getText(_cfg >> "displayName"), 
	getText(_cfg >> "description"), 
	(_required joinString "<br/>")
];

_display setVariable ["craft_cfg", _cfg];