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
			private _maxDist = ["IndicatorDistance", "Indicators"] call ULP_fnc_getOption;

			{
				private _icons = [];
				private _veh = vehicle _x;
				private _dist = _x distance player;

				if (!(_veh isEqualTo (vehicle player)) && { _dist <= _maxDist } && { [_x] call ULP_fnc_hasComms }) then {
					private _hex = [([_x] call ULP_fnc_getIndicatorColour), [0.9 , 0, 0, 0.7]] select (isDowned(_x));
					private _text = [0.9, 0.9, 0.9, 1];
					private _pos = [(vehicle _x) modelToWorldVisual [0,0,0], _x modelToWorldVisual (_x selectionPosition "spine3")] select (_veh isEqualTo _x);

					{ _x set [3, linearConversion [_maxDist / 1.2, _maxDist, _dist, 1, 0, true]]; } forEach [_hex, _text];

					if (_veh isEqualTo _x) then {
						_icons pushBack [ "\a3\ui_f\data\IGUI\Cfg\Cursors\select_ca.paa", _hex, _pos, .9, .9, 0 ];
						_icons pushBack [ "", _text, _pos, 1, 1, 0, name _x, 0, 0.027, "RobotoCondensedBold" ];
					} else {
						if !(_veh in _included) then {
							_icons pushBack [ "\a3\ui_f\data\IGUI\Cfg\Cursors\select_ca.paa", _hex, _pos, .9, .9, 0 ];

							private _unit = (crew _veh) param [0, objNull];
							if !(isNull _unit) then {
								private _count = ((count (crew _veh)) - 1);
								_icons pushBack [ "", _text, _pos, 1, 1, 0, format ["%1%2", name _unit, (["", format [" (%1)", _count]] select (_count > 0))], 0, 0.027, "RobotoCondensedBold" ];
							};

							_included pushBackUnique _veh;
						};
					};

					{
						drawIcon3D _x;
					} forEach _icons;
				};
			} forEach (units (group player));
		};
	}];
};