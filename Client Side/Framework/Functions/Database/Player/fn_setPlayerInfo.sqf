/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_setPlayerInfo";

if (ULP_Loaded) exitWith {};

_this params [
	["_playerData", false, [[], false]]
];

["Setting Player Information"] call ULP_fnc_logIt;

if (_playerData isEqualType false) exitWith {}; // Fail

_playerData params ["_uid", "_steamid", "_cash", "_bank", "", "", "_adminlevel", "_donorlevel", "_licenses", "_gear", "_stats"];
private _count = count _playerData;

if !(_steamid isEqualTo (getPlayerUID player)) exitWith {}; // Fail

private _factionCfg = missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction; // Gets the config for our current faction...

// Money...
CASH = _cash;
BANK = _bank;

// System whitelisting...
CONST(life_adminlevel, _adminlevel);
CONST(life_donorlevel, _donorlevel);

// Add any licenses we have to our variable so we can check for them later...
{
	ULP_Liceneses pushBackUnique (_x select 0);
} forEach (_licenses select {
	(_x select 1) isEqualTo 1
});

// Set saved survival statistics....
ULP_Survival_Hunger = (_stats select 0);
ULP_Survival_Thirst = (_stats select 1);
player setDamage (_stats select 2);

// TODO : Handle Blacklisting...

// Set any whitelisting values our faction may have...
if (isClass (_factionCfg >> "Whitelisting")) then {
	{
		missionNamespace setVariable [format["%1_%2", configName _factionCfg, configName _x], compileFinal str(_playerData select (getNumber(_x >> "queryIndex")))];
	} forEach ("isNumber(_x >> 'queryIndex')" configClasses (_factionCfg >> "Whitelisting"));
};

// Add us into a gang if we're apart of one...
private _gang = _playerData select (_count - 5);
if (_gang isEqualType []) then {
	// TODO
};

// Retrieve any houses returned to us from the sever and set them up...
private _houses = _playerData select (_count - 4);
if (_houses isEqualType []) then {
	ULP_Houses = _houses;

	{
		_house = nearestObject [(parseSimpleArray (_x select 0)), "House"];
		life_vehicles pushBack (_house);
	} forEach ULP_Houses;
};

[] call life_fnc_initHouses;

// Get vehicle keys we've had this restart...
{
	life_vehicles pushBack _x
} forEach (_playerData select (_count - 3));

// Apply our saved gear...
ULP_Gear = _gear;
[ULP_Gear] call ULP_fnc_loadGear;

ULP_Loaded = true; // Tells the initialisation script we're able to continue...