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
		private _objects = ((nearestObjects [ cameraOn, ["Man", "Land_InfoStand_V1_F", "Land_Cargo10_red_F"], 10 ]) select { 
			(isPlayer _x || { _x getVariable ["hasPlayerTags", false] }) 
				&& { !(isObjectHidden _x) } 
				&& { !(lineIntersects [eyePos cameraOn, [eyePos _x select 0, eyePos _x select 1, (eyePos _x select 2) + 0.5], vehicle cameraOn, _x]) } 
				&& { !(cameraOn isEqualTo _x) || { ["ShowOwnTags", "HUD"] call ULP_fnc_getOption isEqualTo 1 } }
		}) apply {
			[
				_x, [_x] call ULP_fnc_getTagPos, (cameraOn distance _x), [_x] call ULP_fnc_getTagIcon, 
				[_x, true] call ULP_fnc_getName, [_x] call ULP_fnc_getSubTitle, (_x getVariable ["title", ""])
			]
		};

		{
			_x params ["_object", "_pos", "_distance", "_icon", "_name", "_subtitle", "_title"];

			private _mainColour = [_object] call ULP_fnc_getTagColour;
			private _otherColour = getArray(missionConfigFile >> "CfgTags" >> "baseColour");

			_pos = _object modelToWorldVisual(_pos vectorAdd [0, 0, _distance * 0.02]);

			private _alpha = linearConversion [ 15 / 1.25, 15, _distance, 1, 0, true];
			_mainColour set [3, _alpha];
			_otherColour set [3, _alpha];

			if (_object getVariable ["speaking", false]) then {
				_icon = format["data\ui\sound%1.paa", (round(time * 7)) mod 2];
			};
			
			if !(_icon isEqualTo "") then { drawIcon3D[getMissionPath _icon, [1, 1, 1, _alpha], _pos, 1.3, 1.3, 0, ""]; };
			if !(_name isEqualTo "") then { drawIcon3D["", _mainColour, _pos, 0, 1.3, 0, _name, 0, 0.035, "RobotoCondensed", "center"]; };
			if !(_subtitle isEqualTo "") then { drawIcon3D["", _otherColour, _pos, 0, 2.3, 0, _subtitle, 0, 0.03, "RobotoCondensed", "center"]; };
			if !(_title isEqualTo "") then { drawIcon3D["", _otherColour, _pos, 0, 3.3, 0, _title, 0, 0.03, "RobotoCondensed", "center"]; };
		} count _objects;
	}];
};