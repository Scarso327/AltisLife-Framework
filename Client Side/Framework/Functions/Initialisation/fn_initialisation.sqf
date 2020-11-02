/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initialisation";

waitUntil { !isNull player && { player isEqualTo player } && { !isNull (findDisplay 46) } };

private _startTime = diag_tickTime;
["Initialisation Started"] call ULP_fnc_logIt;

[] call ULP_fnc_initVars;

player allowDammage false;

["Setting Eventhandlers"] call ULP_fnc_logIt;
[] call ULP_fnc_initEventHandlers;

["Waiting For Server"] call ULP_fnc_logIt;

waitUntil { !isNil "life_server_isReady" };

[] call ULP_fnc_getPlayerInfo;

waitUntil { ULP_Loaded };

["Checking Whitelisting"] call ULP_fnc_logIt;
private _factionCfg = missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction;

if (isClass (_factionCfg >> "Whitelisting")) then {
	{
		if (call (missionNamespace getVariable format["%1_%2", configName _factionCfg, configName _x]) <= 0) exitWith {
			["NotWhitelisted",false,true] call BIS_fnc_endMission;
			breakOut "fn_initialisation";
		};
	} forEach ("isNumber(_x >> 'required')" configClasses (_factionCfg >> "Whitelisting"));
};

["Setting Textures"] call ULP_fnc_logIt;
private "_container";

{
	_container = uniformContainer _x;
	[_x, _container, _container getVariable ["texture", ""], false, false] call ULP_fnc_setTextures;
} forEach allUnits;

["Starting Paycheck Loop"] call ULP_fnc_logIt;
ULP_Paycheck = [] call ULP_fnc_calcPaycheck;
CONSTVAR(ULP_Paycheck);
[] execFSM "Functions\Paycheck\pay.fsm";

["Starting Input Handler"] call ULP_fnc_logIt;
(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call life_fnc_keyHandler"];

["Finishing Initialisation"] call ULP_fnc_logIt;

[] call life_fnc_spawnMenu;

[format["Initialisation Lasted %1s", diag_tickTime - _startTime]] call ULP_fnc_logIt;