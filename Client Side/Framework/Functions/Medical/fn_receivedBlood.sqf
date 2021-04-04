/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_receivedBlood";

_this params [
	["_medic", objNull, [obNull]]
];

if !(alive player || { isDowned(player) }) exitWith {};

private _incapUi = ["RscIncapacitated"] call ULP_UI_fnc_getLayer;
if (isNull _incapUi) exitWith {};

private _increase = getNumber (missionConfigFile >> "CfgSettings" >> "Medical" >> "BloodBagIncrease");

hint ([
	format ["%1 has administered you blood and so your bleedout has been extended...", name _medic],
	"You have received more blood and so your bleedout has been extended..."
] select (isNull _medic));

_incapUi setVariable ["endTime", (_incapUi getVariable ["endTime", time + 10]) + _increase];