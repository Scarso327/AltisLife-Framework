/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_setPlayerInfo";

if (ULP_Loaded) exitWith {};

if (canSuspend) exitWith {
    [ULP_fnc_setPlayerInfo, _this] call ULP_fnc_directCall;
};

_this params [
	["_playerData", false, [[], false]]
];

["Setting Player Information"] call ULP_fnc_logIt;

if (_playerData isEqualType false) exitWith {}; // Fail

_playerData params ["_uid", "_steamid", "_groupid", "_cash", "_bank", "", "", "_adminlevel", "_eventslevel", "_donorlevel", 
	"_licenses", "_gear", "_stats", "_professions", "_prestige", "_level", "_xp", "_achievements", "_daily", "_weekly", 
	"_textures", "_titles", "_perks", "_reputation", "_blueprints", "_wounded", "_bool"];

private _count = count _playerData;

if !(_steamid isEqualTo (getPlayerUID player)) exitWith {}; // Fail

private _factionCfg = missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction; // Gets the config for our current faction...

if !(isNil "ULP_FailedEventId") then {
	["PlayerInformationQueryFailed", ULP_FailedEventId] call ULP_fnc_removeEventHandler;
	missionNamespace setVariable ["ULP_FailedEventId", nil];
};

if (!isNil "ULP_ID" || { !isNil "ULP_Staff" } || { !isNil "ULP_Event" } || { !isNil "ULP_Donator" } || { !isNil { CASH } } || { !isNil { BANK } }) exitWith {
	ULP_Spector = ["FailedInitialVarCheck", getPlayerUID player];
	clientOwner publicVariableClient "ULP_Spector";
	
	endMission "CheatCheck";
};

ULP_ID = _uid;

// Money...
CASH = _cash;
BANK = _bank;

// System whitelisting...
CONST(ULP_Staff, _adminlevel);
CONST(ULP_Event, _eventslevel);
CONST(ULP_Donator, _donorlevel);

ULP_Licenses = (_licenses select {
	isClass (missionConfigFile >> "CfgLicenses" >> _x)
});

ULP_Professions = _professions;
ULP_Achievements = _achievements;

private _max = [] call ULP_fnc_getMaxLevel;
if (_level > _max) then { _level = _max; };

private _required = [_level] call ULP_fnc_getRequiredXP;
for "_i" from 0 to 1 step 0 do {
	scopeName "fn_setPlayerInfo_rankLoop";

	if (_xp < _required) exitWith {};

	if (_xp >= _required) then {
		if (_level isEqualTo _max) then {
			_xp = _required;
			breakOut "fn_setPlayerInfo_rankLoop";
		} else {
			_xp = _xp - _required;
			_level = _level + 1;
			_required = [_level] call ULP_fnc_getRequiredXP;
		};
	};
};

ULP_Prestige = _prestige;
ULP_Level = _level;
ULP_XP = _xp;

_stats params [
	["_hunger", 100, [0]],
	["_thirst", 100, [0]],
	["_damage", 0, [0]]
];

// Set saved survival statistics....
ULP_Survival_Hunger = _hunger;
ULP_Survival_Thirst = _thirst;
player setDamage _damage;

// TODO : Handle Blacklisting...

switch (configName _factionCfg) do {
	case "Civilian": {
		ULP_Imprisioned = _bool;
		ULP_Prison_Time = _playerData select 27;

		// Handle undercover...
		private _copLevel = _playerData select 28;
		private _ucLevel = _playerData select 29;
		if (_copLevel > 0 && { _ucLevel > 0 }) then {
			ULP_UCLevels = [_copLevel, _ucLevel];
		};

		// New player check

		if ([] call ULP_fnc_isHobo) then {
			player setVariable ["isHobo", true, true];

			ULP_HoboEventHandlers = [];

			ULP_HoboEventHandlers pushBack ["MoneyChanged", (["MoneyChanged", { [] call ULP_fnc_isStillHobo; }] call ULP_fnc_addEventHandler)];
			ULP_HoboEventHandlers pushBack ["OnXPIncreased", (["OnXPIncreased", { [] call ULP_fnc_isStillHobo; }] call ULP_fnc_addEventHandler)];
			ULP_HoboEventHandlers pushBack ["LicenseBought", (["LicenseBought", { [] call ULP_fnc_isStillHobo; }] call ULP_fnc_addEventHandler)];
		};
	};
	case "Dunamis": {
		ULP_Imprisioned = _bool;
		ULP_Prison_Time = _playerData select 27;
	};
};

// Set any whitelisting values our faction may have...
if (isClass (_factionCfg >> "Whitelisting")) then {
	{
		private _varName = format["%1_%2", configName _factionCfg, configName _x];

		if !(isNil _varName) exitWith {
			ULP_Spector = ["FailedWhitelistedVarCheck", getPlayerUID player];
			clientOwner publicVariableClient "ULP_Spector";

			endMission "CheatCheck";
		};

		missionNamespace setVariable [_varName, compileFinal str(_playerData select (getNumber(_x >> "queryIndex")))];
	} forEach ("isNumber(_x >> 'queryIndex')" configClasses (_factionCfg >> "Whitelisting"));
};

// Add us into a gang if we're apart of one...
private _group = _playerData select (_count - 5);
if (_group isEqualType 0) then {
	if !(_groupid isEqualTo _group) exitWith {
		[format["Server didn't catch group id mismatch (%1, %2)", _groupid, _group]] call ULP_fnc_logIt;
	};

	InitGroupId = _groupid;
	[format["Joined Group (%1)", _group]] call ULP_fnc_logIt;
};

// Retrieve any houses returned to us from the sever and set them up...
private _houses = _playerData select (_count - 4);
if (_houses isEqualType []) then {
	[_houses] call ULP_fnc_setupHouses;
};

// Get vehicle keys we've had this restart...
{
	ULP_Keys pushBack _x
} forEach (_playerData select (_count - 3));

[_daily, _weekly] call ULP_fnc_initPersonalGoals;

ULP_New = (_playerData select (_count - 2)); // Tells us if this is a new database insert...
ULP_Date = (_playerData select (_count - 1)); // Contains Year, Month and Day in that order...

// Apply our saved gear...
ULP_Gear = _gear;
[ULP_Gear] call ULP_fnc_loadGear;

ULP_UnlockedTextures = _textures;
ULP_Titles = _titles;
ULP_Perks = _perks;
ULP_Reputation = _reputation;
ULP_Blueprints = _blueprints;
ULP_Wounded = _wounded;

if (_wounded) then {
	player setVariable ["Wounded", true, true];
};

[] call ULP_fnc_setLoggedIn; // Tells the initialisation script we're able to continue...
InitGroupId = nil; // Only used during init for "fn_setupHouses" as Arma doesn't seem to add us to group in time...