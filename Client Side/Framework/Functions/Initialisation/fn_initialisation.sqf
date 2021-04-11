/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initialisation";

waitUntil { !isNull player && { !isNull (findDisplay 46) } };

cutText["","BLACK FADED"];
0 cutFadeOut 9999999;

private _startTime = diag_tickTime;
["Initialisation Started"] call ULP_fnc_logIt;

[] call ULP_fnc_initVars;

player allowDammage false;

["Setting Eventhandlers"] call ULP_fnc_logIt;
[] call ULP_fnc_initPlayerEvents;
[] call ULP_fnc_initEventHandlers;
[] call ULP_fnc_initSurvival;

0 enableChannel [false, false];
1 enableChannel [[["SideChat", "HUD"] call ULP_fnc_getOption] call ULP_fnc_bool, false];
2 enableChannel [false, false];

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

[{
	{
		{
			_x params [ "_object", "_objectContainer" ];
			
			private _texture = _objectContainer getVariable ["texture", ""];

			if !(_texture isEqualTo "") then {
				[_object, _objectContainer, _texture] call ULP_fnc_setTextures;
			};
		} foreach [[_x, uniformContainer _x], [unitBackpack _x, backpackContainer _x]];
	} forEach (allUnits select { !(_x isEqualTo player) });

	{
		if (_x getVariable["jipReady", false]) then { [_x, true] call ULP_fnc_initVehicle; };
		if ((getPlayerUID player) in (_x getVariable ["vehicle_owners", createHashMap])) then { ULP_Keys pushBackUnique _x; };
	} forEach vehicles;
}] call ULP_fnc_directCall;

["Starting Paycheck Loop"] call ULP_fnc_logIt;
ULP_Paycheck = [] call ULP_fnc_calcPaycheck;
CONSTVAR(ULP_Paycheck);
[] execFSM "Functions\Paycheck\pay.fsm";

["Starting Input Handler"] call ULP_fnc_logIt;
(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call ULP_fnc_keyDown"];
(findDisplay 46) displayAddEventHandler ["KeyUp", "_this call ULP_fnc_KeyUp"];

["Creating World"] call ULP_fnc_logIt;

private _mapCfg = missionConfigFile >> "CfgMaps" >> worldName;

if (hasInterface && { isClass (_mapCfg >> "Lighting") }) then {
	ULP_NightLight = "#lightpoint" createVehicleLocal [0, 0, 0];

    ULP_NightLight setLightDayLight false;
	ULP_NightLight setLightBrightness (["NightLight"] call ULP_fnc_getOption);
	ULP_NightLight setLightAttenuation [10e10, getNumber(_mapCfg >> "Lighting" >> "brightness"), 4.31918e-005, 4.31918e-005];
	ULP_NightLight setLightAmbient getArray (_mapCfg >> "Lighting" >> "color");
};

[] call ULP_fnc_initTags;
[] call ULP_fnc_initReputation;
[] call ULP_fnc_initAchievements;
[] call ULP_fnc_initGroups;
[] call ULP_fnc_initGathering;
[] call ULP_fnc_initMissions;
[] call ULP_fnc_initPerks;
[] call ULP_fnc_initBases;
[] call ULP_fnc_initCartels;
[] call ULP_fnc_initRandomEvents;

["Initialising Player"] call ULP_fnc_logIt;
[] call ULP_fnc_initPlayer;
[[["EnablePlayerTags", "HUD"] call ULP_fnc_getOption] call ULP_fnc_bool] call ULP_fnc_playerTags;

["Finishing Initialisation"] call ULP_fnc_logIt;

if (isNil "ULP_UCLevels") then {
	[] call ULP_fnc_spawnMenu;
} else {
	ULP_UCLevels params [ "_cop", "_uc" ];

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Side Selection", ["Police", "Civilian"],
		"Are you playing as civilian or undercover police?", [_cop, _uc],
		{	
			_this params [ "_cop", "_uc" ];

			missionNamespace setVariable ["ULP_IsUndercover", compileFinal "true"];
			missionNamespace setVariable ["Police_Main", compileFinal (str _cop)];
			missionNamespace setVariable ["Police_UC", compileFinal (str _uc)];
			
			[] call ULP_fnc_spawnMenu;
		}, false, { [] call ULP_fnc_spawnMenu; }
	] call ULP_fnc_confirm;
};

[format["Initialisation Lasted %1s", diag_tickTime - _startTime]] call ULP_fnc_logIt;