/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_administerBlood";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(alive _unit) }) exitWith {};

if ((0 max (["BloodBag"] call ULP_fnc_hasItem)) < 1) exitWith { ["You need a bloodbag to administer blood!"] call ULP_fnc_hint; };
if !(isDowned(_unit)) exitWith { ["You can only administer blood to injured players!"] call ULP_fnc_hint; };

private _name = [_unit, true] call ULP_fnc_getName;

private _time = 20;

if !([format["Administering Blood to %1", _name], _time, [_unit, _name], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { isDowned((_this select 0)) } && { (0 max (["BloodBag"] call ULP_fnc_hasItem)) > 0 } && 
	{ (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_unit", "_name" ];

	if (isNull _unit || { !(alive _unit) } || { !(isDowned(_unit)) } || { (0 max (["BloodBag"] call ULP_fnc_hasItem)) < 1 }) exitWith {
		["You either lost your bloodbag or the patient you were treating has died..."] call ULP_fnc_hint;
	};

	["BloodBag", 1, true] call ULP_fnc_handleItem;
	[format ["You have administered blood to <t color='#B92DE0'>%1</t>.", _name]] call ULP_fnc_hint;

	private _unitRep = _unit getVariable ["reputation", 0];
	if (_unitRep >= 500) then {
		[_medic, "BloodHigh"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];
	};
	
	["GivenBlood"] call ULP_fnc_achieve;

	[player, ["BloodCarrier", getNumber (missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "BloodBagIncrease")] call ULP_fnc_activatePerk] remoteExecCall ["ULP_fnc_receivedBlood", _unit];
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress) exitWith {
	["You can't administer blood while performing another action..."] call ULP_fnc_hint;
};

closeDialog 0;