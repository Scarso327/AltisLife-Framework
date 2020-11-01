/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_initialisation";

private _startTime = diag_tickTime;
["Initialisation Started"] call ULP_fnc_logIt;

[] call ULP_fnc_initVars;

waitUntil { !isNull player && { player isEqualTo player } };

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

["Starting Client Loop"] call ULP_fnc_logIt;
[] execFSM "Functions\FSM\client.fsm";

waitUntil { !isNull (findDisplay 46) }; // Wasn't always set?? Arma??

["Starting Input Handler"] call ULP_fnc_logIt;
(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call life_fnc_keyHandler"];

["Finishing Initialisation"] call ULP_fnc_logIt;

[] call life_fnc_spawnMenu;

[format["Initialisation Lasted %1s", diag_tickTime - _startTime]] call ULP_fnc_logIt;