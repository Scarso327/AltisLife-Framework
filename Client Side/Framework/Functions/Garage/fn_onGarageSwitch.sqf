/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onGarageSwitch";

if (canSuspend) exitWith {
    [ULP_fnc_onGarageSwitch, _this] call ULP_fnc_directCall;
};

_this params [
	["_list", controlNull, [controlNull]],
	["_index", -1, [0]]
];

private _display = ctrlParent _list;
if (isNull _display) exitWith {};

private _settings = _display displayCtrl 3502;
private _info = _display displayCtrl 3503;
private _textureText = _display displayCtrl 3504;

private _itemData = (_list lbData _index);
if (_itemData isEqualTo "") exitWith {};

_itemData = parseSimpleArray _itemData;

private _impound = _display getVariable ["impound", false];

_itemData params [
	"_id", "_classname", "_texture", "_impoundFee", "_faction", "_upgrades"
];

private _cfg = [_classname] call ULP_fnc_vehicleCfg;
if (_cfg isEqualTo []) exitWith {};

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

private _retrievalPrice = [
	round (getNumber(_missionCfg >> "buyPrice") * getNumber(missionConfigFile >> "CfgVehicles" >> "retrievalPerc")),
	(_list lbValue _index)
] select (_impound);

if (["MatesRates"] call ULP_fnc_hasPerk) then { _retrievalPrice = _retrievalPrice * 0.5 };

_upgrades = createHashMapFromArray _upgrades;

_itemData set [3, _retrievalPrice];
_itemData set [4, _index];
_itemData set [5, _faction];
_itemData set [6, _upgrades];

_display setVariable ["selected", _itemData];

_textureText ctrlSetStructuredText parseText format ["<t align = 'center'>%1</t>", getText(_missionCfg >> "Textures" >> _texture >> "displayName")];

_settings ctrlSetStructuredText parseText format ["
	<br/><br/><br/>
	<img image = '%1' align='center' size='3.5' /> <br/>
	<t align = 'center' size = '1.5'>%2</t><br/>
	<t align = 'left' size = '1'><br/>%3</t>", _picture, _name, getText(_missionCfg >> "description")];

private _upgradesText = [];

if !(_upgrades isEqualTo createHashMap) then {
	{
		private _upgradeCfg = missionConfigFile >> "CfgVehicleUpgrades" >> _x;

		if !(isClass _upgradeCfg) exitWith {};

		_upgradesText pushBack format [" - %1", getText (_upgradeCfg >> "displayName")];
	} forEach _upgrades;
};

_info ctrlSetStructuredText parseText format ["<t align = 'left' size = '1'>%8<t align='right'>%1</t></t>
	<t align = 'left' size = '1'><br/>Virtual Item Space <t align='right'>%2</t></t>
	<t align = 'left' size = '1'><br/>Top Speed <t align='right'>%3 km/h</t></t>
	<t align = 'left' size = '1'><br/>Armor Level <t align='right'>%4</t></t>
	<t align = 'left' size = '1'><br/>Seats <t align='right'>%5</t></t>
	<t align = 'left' size = '1'><br/>Horse Power <t align='right'>%6 bhp</t></t>
	<t align = 'left' size = '1'><br/>Fuel Capacity <t align='right'>%7</t></t>
	%9", 
	([format["£%1", [_retrievalPrice] call ULP_fnc_numberText], "-"] select (_retrievalPrice < 1)),
	getNumber(_missionCfg >> "virtualSpace"), _topSpeed, _armor, _seats + 1, _power, _fuel, (["Retreival Price", "Unimpound Fee"] select (_impound)),
	(if !(_upgradesText isEqualTo []) then {
		format ["<br/><br/><t align = 'left' size = '1'>Upgrades:<br/><t size='0.8'>%1</t></t>", (_upgradesText joinString "<br/>")]
	} else {
		""
	})];

[_info] call ULP_UI_fnc_setToTextHeight;

private _actionsEnabled = (_impound || { _impoundFee isEqualTo 0 });

ctrlEnable [3505, _actionsEnabled];

if (ctrlVisible 3506) then {
	ctrlEnable [3506, _actionsEnabled];
	ctrlEnable [3507, _actionsEnabled];
};