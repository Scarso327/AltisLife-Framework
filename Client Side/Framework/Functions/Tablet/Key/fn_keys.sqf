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
private _list = _display displayCtrl 23022;
lbClear _list;

switch (lbCurSel _toolbox) do {
	case 1: {
		_list ctrlShow false;
	};
	default {
		_list ctrlShow true;
		
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
					
					_item = _list lbAdd _name;
					_list lbSetData [_item, _x call BIS_fnc_netId]; // Uses BIS_fnc_netId as it can work in SP for testing + saves parseing an object to string...
					_list lbSetTooltip [_item, format["Distance: %1m", [_distance, ">100"] select (_distance >= 100)]];

					if !(_picture isEqualTo "") then {
						_list lbSetPicture [_item, _picture];
					};
				};
			};
		} forEach ULP_Keys;

		if ((lbSize _list) > 0) then {
			_list lbSetCurSel 0;
		} else {
			_list lbAdd "No Keys...";
		};
	};
};

