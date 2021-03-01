/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vehicleChange";

_this params [
	["_list", controlNull, [controlNull]],
	["_index", -1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _settings = _display displayCtrl 3403;
private _info = _display displayCtrl 3404;

private _cfg = [(_list lbData _index)] call ULP_fnc_vehicleCfg;
if (_cfg isEqualTo []) exitWith {};

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

private _buyPrice = getNumber(_missionCfg >> "buyPrice");
private _rentPrice = round (_buyPrice * getNumber(missionConfigFile >> "CfgVehicles" >> "rentPerc"));
private _retrievalPrice = round (_buyPrice * getNumber(missionConfigFile >> "CfgVehicles" >> "retrievalPerc"));
private _sellPrice = round (_buyPrice * getNumber(missionConfigFile >> "CfgVehicles" >> "sellPerc"));

_settings ctrlSetStructuredText parseText format ["
<br/><br/><br/>
<img image = '%1' align='center' size='3.5' /> <br/>
<t align = 'center' size = '1.5'>%2</t><br/>
<t align = 'left' size = '1'><br/>%3</t>", _picture, _name, "DESCRIPTION TODO"];

_info ctrlSetStructuredText parseText format ["<t align = 'left' size = '1'>Buy Price <t align='right'>%1</t></t>
<t align = 'left' size = '1'><br/>Rent Price <t align='right'>%2</t></t>
<t align = 'left' size = '1'><br/>Sell Price <t align='right'>%3</t></t>
<t align = 'left' size = '1'><br/>Retrieval Price <t align='right'>%4</t></t>
<t align = 'left' size = '1'><br/>Virtual Item Space <t align='right'>%5</t></t>
<t align = 'left' size = '1'><br/>Top Speed <t align='right'>%6 km/h</t></t>
<t align = 'left' size = '1'><br/>Armor Level <t align='right'>%7</t></t>
<t align = 'left' size = '1'><br/>Seats <t align='right'>%8</t></t>
<t align = 'left' size = '1'><br/>Horse Power <t align='right'>%9 bhp</t></t>
<t align = 'left' size = '1'><br/>Fuel Capacity <t align='right'>%10</t></t>", 
([format["£%1", [_buyPrice] call life_fnc_numberText], "-"] select (_buyPrice < 1)),
([format["£%1", [_rentPrice] call life_fnc_numberText], "-"] select (_rentPrice < 1)), 
([format["£%1", [_sellPrice] call life_fnc_numberText], "-"] select (_sellPrice < 1)), 
([format["£%1", [_retrievalPrice] call life_fnc_numberText], "-"] select (_retrievalPrice < 1)), getNumber(_missionCfg >> "virtualSpace"),
_topSpeed, _armor, _seats, _power, _fuel];

_display setVariable ["selected", _cfg];