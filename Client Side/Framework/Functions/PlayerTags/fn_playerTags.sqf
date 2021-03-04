/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_playerTags";

_this params [
	["_enable", true, [false]]
];

if !(isNil "ULP_Draw3d_Tags") then { removeMissionEventHandler ["Draw3D", ULP_Draw3d_Tags] };

if (_enable) then {
	ULP_Draw3d_Tags = addMissionEventHandler["Draw3D", {
		{
			_x params ["_object", "_pos", "_distance", "_icon", "_name", "_subtitle"];

			private _mainColour = [_object] call ULP_fnc_getTagColour;
			private _otherColour = getArray(missionConfigFile >> "CfgTags" >> "baseColour");

			_pos = _object modelToWorldVisual(_pos vectorAdd [0, 0, _distance * 0.02]);

			private _alpha = linearConversion [ 15 / 1.25, 15, _distance, 1, 0, true];
			_mainColour set [3, _alpha];
			_otherColour set [3, _alpha];
			
			if !(_icon isEqualTo "") then { drawIcon3D[getMissionPath _icon, [1, 1, 1, _alpha], _pos, 1.3, 1.3, 0, ""]; };
			if !(_name isEqualTo "") then { drawIcon3D["", _mainColour, _pos, 0, 1.3, 0, _name, 0, 0.035, "RobotoCondensed", "center"]; };
			if !(_subtitle isEqualTo "") then { drawIcon3D["", _otherColour, _pos, 0, 2.3, 0, _subtitle, 0, 0.03, "RobotoCondensed", "center"]; };
		} count ((((getPosATLVisual player) nearEntities [ "Man", 10 ]) select { 
			lineIntersects [eyePos player, eyePos _x, player, _x] || player isEqualTo _x
		}) apply {
			private _headPos = (_x selectionPosition "head");
			[
				_x, [(_headPos select 0) - 0.03, (_headPos select 1), (_headPos select 2) + 0.5], (player distance _x), 
				(_x getVariable ["icon", ""]), [_x] call ULP_fnc_getName, (_x getVariable ["subtitle", ""])
			]
		});
	}];
};