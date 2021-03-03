/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_switchTexture";

_this params [
	["_list", controlNull, [controlNull]],
	["_index", -1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _total = _display displayCtrl 3405;
private _texPrice = 0;

private _vehCfg = _display getVariable ["selected", []];
if (_vehCfg isEqualTo []) exitWith {};

_vehCfg params [
	"", "_missionCfg"
];

private _buyPrice = getNumber(_missionCfg >> "buyPrice");

private _texture = _missionCfg >> "Textures" >> (_list lbData _index);
if !(isClass _texture) exitWith {};

_texPrice = getNumber (_texture >> "buyPrice");

_total ctrlSetStructuredText parseText format ["<t align = 'left' size = '1'>Texture Price <t align='right'>%1</t></t>
<t align = 'left' size = '1'><br/>Total Price <t font='PuristaBold' align='right'>%2</t></t>",
([format["£%1", [_texPrice] call ULP_fnc_numberText], "-"] select (_texPrice < 1)),
([format["£%1", [_buyPrice] call ULP_fnc_numberText], "-"] select (_buyPrice < 1))];