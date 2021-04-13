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

private _storeCfg = (_display getVariable ["store", configNull]) >> "Vehicles" >> (configName _missionCfg);
if !(isClass _storeCfg) exitWith {};

_display setVariable ["selected", _cfg];

private _textures = (("isClass _x" configClasses (_storeCfg >> "Textures")) apply {
	configName _x
});

private _textureList = _display displayCtrl 3408;
lbClear _textureList;

private _texCfg = configNull;
private _index = -1;

{
	_texCfg = missionConfigFile >> "CfgVehicles" >> (configName _missionCfg) >> "Textures" >> (configName _x);

	if (isClass _texCfg && { [player, getArray(_texCfg >> "factions")] call ULP_fnc_isFaction } && { _textures isEqualTo [] || { (configName _texCfg) in _textures } } ) then {
		_item = _textureList lbAdd (getText (_texCfg >> "displayName"));
		_textureList lbSetValue [_item, getNumber (_texCfg >> "buyPrice")];
		_textureList lbSetData [_item, configName _texCfg];

		if !([configName _missionCfg, configName _texCfg] call ULP_fnc_isTextureUnlocked) then {
			_textureList lbSetColor [_item, [0, 0, 0, 0.8]];
			_textureList lbSetTooltip [_item, "Locked"];
		};
	};
} forEach ("isText (_x >> ""conditions"") && { call compile getText (_x >> ""conditions"") }" configClasses (_missionCfg >> "Textures"));

if ((lbSize _textureList) isEqualTo 0) then {
	_item = _textureList lbAdd "Default";
	_textureList lbSetValue [_item, getNumber (_texCfg >> "buyPrice")];
	_textureList lbSetData [_item, configName _texCfg];
};

_textureList lbSetCurSel 0;
[_textureList, 0] call ULP_fnc_switchTexture;

private _buyPrice = getNumber(_missionCfg >> "buyPrice");
private _retrievalPrice = round (_buyPrice * getNumber(missionConfigFile >> "CfgVehicles" >> "retrievalPerc"));

_settings ctrlSetStructuredText parseText format ["
<br/><br/><br/>
<img image = '%1' align='center' size='3.5' /> <br/>
<t align = 'center' size = '1.5'>%2</t><br/>
<t align = 'left' size = '1'><br/>%3</t>", _picture, _name, getText(_missionCfg >> "description")];

_info ctrlSetStructuredText parseText format ["<t align = 'left' size = '1'>Buy Price <t align='right'>%1</t></t>
<t align = 'left' size = '1'><br/>Retrieval Price <t align='right'>%2</t></t>
<t align = 'left' size = '1'><br/>Virtual Item Space <t align='right'>%3</t></t>
<t align = 'left' size = '1'><br/>Top Speed <t align='right'>%4 km/h</t></t>
<t align = 'left' size = '1'><br/>Armor Level <t align='right'>%5</t></t>
<t align = 'left' size = '1'><br/>Seats <t align='right'>%6</t></t>
<t align = 'left' size = '1'><br/>Horse Power <t align='right'>%7 bhp</t></t>
<t align = 'left' size = '1'><br/>Fuel Capacity <t align='right'>%8</t></t>", 
([format["£%1", [_buyPrice] call ULP_fnc_numberText], "-"] select (_buyPrice < 1)),
([format["£%1", [_retrievalPrice] call ULP_fnc_numberText], "-"] select (_retrievalPrice < 1)), 
getNumber(_missionCfg >> "virtualSpace"), _topSpeed, _armor, _seats + 1, _power, _fuel];