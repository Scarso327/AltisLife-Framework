/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_keys";

_display = _this;
if (isNull _display) exitWith {};

_display setVariable ["preScreen", "Home"];

private _toolbox = _display displayCtrl 23021;
private _keyList = _display displayCtrl 23022;
lbClear _keyList;

private _carView = _display displayCtrl 23092;

private _houseList = _display displayCtrl 23051;
lbClear _houseList;

private _houseView = _display displayCtrl 23052;

switch (lbCurSel _toolbox) do {
	case 1: {
		_keyList ctrlShow false;
		_carView ctrlShow false;
		_houseList ctrlShow true;

		{
			if !(isNull _x) then {
				private _cfg = [typeOf _x] call ULP_fnc_vehicleCfg;

				if !(_cfg isEqualTo []) then {
					_cfg params [
						"", "_internalCfg", "_picture", "_name"
					];
					
					private _distance = round (player distance _x);
					
					private _item = _houseList lbAdd (_x getVariable ["building_name", _name]);
					_houseList lbSetData [_item, _x call BIS_fnc_netId];
					_houseList lbSetTooltip [_item, format ["Distance: %1m", [_distance] call ULP_fnc_numberText]];
				};
			};
		} forEach ULP_Houses;
		
		if ((lbSize _houseList) > 0) then {
			_houseList lbSetCurSel 0;
			[_houseList, 0] call ULP_fnc_switchHouse;
		} else {
			_houseList lbAdd "No Houses...";
			_houseView ctrlShow false;
		};
	};
	default {
		_keyList ctrlShow true;
		_carView ctrlShow true;
		_houseList ctrlShow false;
		_houseView ctrlShow false;

		private _item = -1;
		private _vehInfo = [];
		private _texture = "";
		private _distance = 0;

		{
			if !(isNull _x) then {
				_vehInfo = [typeOf _x] call ULP_fnc_vehicleCfg;

				if !(_vehInfo isEqualTo []) then {
					_vehInfo params [
						"", "_internalCfg", "_picture", "_name"
					];
					
					_texture = _x getVariable ["texture", ""];

					if !(_texture isEqualTo "") then {
						_name = format ["%1 (%2)", _name, getText (_internalCfg >> "Textures" >> _texture >> "displayName")];
					};

					_distance = round (player distance _x);
					
					_item = _keyList lbAdd _name;
					_keyList lbSetData [_item, _x call BIS_fnc_netId]; // Uses BIS_fnc_netId as it can work in SP for testing + saves parseing an object to string...
					_keyList lbSetTooltip [_item, format["Distance: %1m", [[_distance] call ULP_fnc_numberText, ">100"] select (_distance >= 100)]];

					if !(_picture isEqualTo "") then {
						_keyList lbSetPicture [_item, _picture];
					};
				};
			};
		} forEach ULP_Keys;

		if ((lbSize _keyList) > 0) then {
			_keyList lbSetCurSel 0;
			[_keyList, 0] call ULP_fnc_switchVehicle;
		} else {
			_keyList lbAdd "No Keys...";
			_carView ctrlShow false;
		};
	};
};

