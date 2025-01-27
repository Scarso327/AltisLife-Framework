/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_populateGarage";

if (canSuspend) exitWith {
    [ULP_fnc_populateGarage, _this] call ULP_fnc_directCall;
};

_this params [
	["_vehicles", [], [[]]]
];

private _display = findDisplay 3500;
if (isNull _display) exitWith {};

private _impound = _display getVariable ["impound", false];

private _list = _display displayCtrl 3501;
lbClear _list;

private _vehicleCfg = configNull;
private _index = -1;

{
	_x params [
		"_id", "_classname", "", "_texture", ["_fee", 0, [0]], "_faction"
	];

	_vehicleCfg = [_classname] call ULP_fnc_vehicleCfg;

	if ((count _vehicleCfg) > 0) then {
		_vehicleCfg params [
			"", "", "_picture", "_name", "", "", "", "", "", "_dlcInfo"
		];

		private _dlcPicture = _dlcInfo param [1, "", [""]];

		_index = _list lbAdd _name;
		_list lbSetPicture[_index, _picture];
		_list lbSetData[_index, str [_id, _classname, _texture, _fee, _faction]];

		if (_fee > 0) then {
			if !(_impound) then {
				_list lbSetTooltip [_index, "Impounded"];
				_list lbSetColor [_index, [1, 1, 1, 0.3]];
				_list lbSetPictureColor [_index, [1, 1, 1, 0.3]];
			};

			_list lbSetValue [_index, _fee];
		};

		if !(_dlcPicture isEqualTo "") then {
			_list lbSetPictureRight[_index, _dlcPicture];
		};
	};
} forEach _vehicles;

if ((lbSize _list) isEqualTo 0) then {
	_list lbAdd format["No %1 Vehicles...", (["Garaged", "Impounded"] select (_impound))];
};

lbSort _list;
_list lbSetCurSel 0;
[_list, 0] call ULP_fnc_onGarageSwitch;