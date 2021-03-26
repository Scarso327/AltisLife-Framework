/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_say3D";

_this params [
	["_object", objNull, [objNull]],
	["_sound", "", [""]],
	["_distance", 50, [0]],
	["_pitch", 1, [0]]
];

if !(_sound in getArray (missionConfigFile >> "CfgSettings" >> "Remotes" >> "Sound" >> "sounds")) exitWith { false };
_distance = (_distance min (getNumber (missionConfigFile >> "CfgSettings" >> "Remotes" >> "Sound" >> "maxDistance")));

_object say3D [_sound, _distance, _pitch];
true