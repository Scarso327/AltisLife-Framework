/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initCartels";

["Initialising Cartels"] call ULP_fnc_logIt;

if !(hasInterface) exitWith {};

{
	private _object = missionNamespace getVariable [format["ULP_SRV_Cartel_%1", configName _x], objNull];

	if !(isNull _object) then {
		if ([player, getArray (_x >> "factions")] call ULP_fnc_isFaction) then {
			private _zoneRadius = getNumber (_x >> "zoneRadius");

			private _trigger = createTrigger ["EmptyDetector", getArray (_x >> "position"), false];
			_trigger setTriggerArea [_zoneRadius, _zoneRadius, 0, false];
			_trigger setTriggerActivation ["ANYPLAYER", "PRESENT", true];
			_trigger setTriggerStatements ["this && { (vehicle player) in thisList }", format ["[""%1"", ""create""] call ULP_fnc_cartelHud;", configName _x], format ["[""%1"", ""remove""] call ULP_fnc_cartelHud;", configName _x]];

			_object setVariable ["trigger", _trigger];
		};
	};
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgCartels" >> "Fixed"));