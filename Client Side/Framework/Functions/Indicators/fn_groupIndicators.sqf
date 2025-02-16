/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_groupIndicators";

_this params [
	["_enable", true, [false]]
];

if !(isNil "ULP_Draw3d_Indicators") then { removeMissionEventHandler ["Draw3D", ULP_Draw3d_Indicators] };

if (_enable) then {
	ULP_Draw3d_Indicators = addMissionEventHandler["Draw3D", {
		if ([] call ULP_fnc_hasComms) then {
			private _included = [];
			private _units = units (group player);

			private _maxDist = ["IndicatorDistance", "Indicators"] call ULP_fnc_getOption;
			private _includeName = [["EnableNamesOnIndicators", "Indicators"] call ULP_fnc_getOption] call ULP_fnc_bool;

			{
				private _unit = _x;
				private _veh = vehicle _unit;
				private _dist = _unit distance player;

				if (!(_veh isEqualTo (vehicle player)) && { !(_veh in _included) } && { _dist <= _maxDist } && { [_unit] call ULP_fnc_hasComms }) then {
					private _hex = ([_unit] call ULP_fnc_getIndicatorColour);
					private _text = [0.9, 0.9, 0.9, 1];
					private _name = name _x;

					private _pos = 
						if (_veh isEqualTo _unit) then {
							_unit modelToWorldVisual (_unit selectionPosition "spine3")
						} else {
							private _crew = ((crew _veh) select { _x in _units });
							_unit = _crew param [0, objNull];

							private _count = ((count _crew) - 1);
							_name = format ["%1%2", name _unit, (["", format [" (%1)", _count]] select (_count > 0))];

							_included pushBackUnique _veh;

							_veh modelToWorldVisual [0,0,0]
						};

					{ _x set [3, linearConversion [_maxDist / 1.2, _maxDist, _dist, 1, 0, true]]; } forEach [_hex, _text];

					drawIcon3D [ "\a3\ui_f\data\IGUI\Cfg\Cursors\select_ca.paa", _hex, _pos, .9, .9, 0 ];

					if (_includeName) then {
						drawIcon3D [ "", _text, _pos, 1, 1, 0, name _x, 0, 0.027, "RobotoCondensedBold" ];
					};

					if (isDowned(_unit)) then {
						drawIcon3D [ "\a3\ui_f\data\IGUI\Cfg\Cursors\unitInjured_ca.paa", _hex, _pos, 1.26, 1.26, 0 ];
					};
				};
			} forEach _units;
		};
	}];
};