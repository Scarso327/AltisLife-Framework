/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_receivedBlood";

_this params [
	["_medic", objNull, [objNull]],
	["_increase", getNumber (missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "BloodBagIncrease"), [0]]
];

if !(alive player || { isDowned(player) }) exitWith {};

private _incapUi = ["RscIncapacitated"] call ULP_UI_fnc_getLayer;
if (isNull _incapUi) exitWith {};

[[format ["<t color='#B92DE0'>%1</t> has administered you blood and so your bleedout has been extended...", name _medic], "You have received more blood and so your bleedout has been extended..."] select (isNull _medic)] call ULP_fnc_hint;

_incapUi setVariable ["endTime", (_incapUi getVariable ["endTime", time + 10]) + _increase];