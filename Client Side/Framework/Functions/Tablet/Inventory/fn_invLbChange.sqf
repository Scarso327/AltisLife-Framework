/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_invLbChange";

_this params [
	["_list", controlNull, [controlNull]],
	["_index", -1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _info = _display displayCtrl 23017;

private _cfg = missionConfigFile >> (_display getVariable ["cfg", ""]) >> (_list lbData _index);
if !(isClass _cfg) exitWith {};

private _name = getText(_cfg >> "displayName");
if ([getNumber (_cfg >> "Settings" >> "isScripted")] call ULP_fnc_bool) then {
	_name = format [_name, (([configName _cfg] call ULP_fnc_hasItem) select (_list lbValue _index))];
};

_info ctrlSetStructuredText parsetext format ["
<br/>
<br/>
<img image = '%1' align='center' size='4.5' /> <br/>
<t align = 'center' size = '1.5'>%2</t><br/>
<br/>
<t align = 'left' size = '1'><br/>%3 </t>", getText(_cfg >> "icon"), _name, "DESCRIPTION TODO"];