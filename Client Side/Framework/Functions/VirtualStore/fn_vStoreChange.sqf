/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vStoreChange";

_this params [
	["_list", controlNull, [controlNull]],
	["_index", -1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _info = _display displayCtrl 3304;

private _cfg = missionConfigFile >> "CfgVirtualItems" >> (_list lnbData [_index, 0]);
if !(isClass _cfg) exitWith {};

private _buyPrice = getNumber (_cfg >> "buyPrice");
private _sellPrice = getNumber (_cfg >> "sellPrice");

_info ctrlSetStructuredText parseText format ["
<br/>
<img image = '%1' align='center' size='4.5' /> <br/>
<t align = 'center' size = '1.5'>%2</t><br/>
<br/>
<t align = 'left' size = '1'><br/>%3</t>
<t align = 'left' size = '1'><br/>Buy Price <t align='right'>%4</t></t>
<t align = 'left' size = '1'><br/>Sell Price <t align='right'>%5</t></t>
<t align = 'left' size = '1'><br/>Weight <t align='right'>%6</t></t>", 
getText(_cfg >> "icon"), getText(_cfg >> "displayName"), "DESCRIPTION TODO", 
([format["£%1", [_buyPrice] call ULP_fnc_numberText], "-"] select (_buyPrice isEqualTo -1)), 
([format["£%1", [_sellPrice] call ULP_fnc_numberText], "-"] select (_sellPrice isEqualTo -1)),
[getNumber (_cfg >> "weight")] call ULP_fnc_numberText];

_display setVariable ["lastSel", _index];