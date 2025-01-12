/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_spawn";

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _spawnCfg = _display getVariable ["spawn", ""];
if (_spawnCfg isEqualTo "") exitWith {};

private _name = "";
private _pos = [0,0,0];
private _dir = random 360;

switch (true) do {
	case (_spawnCfg isEqualType configNull) : {
		_name = getText (_spawnCfg >> "displayName");
		_pos = getMarkerPos getText(_spawnCfg >> "marker");

		private _buildings = getArray (_spawnCfg >> "buildings");
		private _radius = getNumber (_spawnCfg >> "radius");

		if (!(_buildings isEqualTo []) && { _radius > 0 }) then {
			_buildings = (nearestObjects [_pos, _buildings, getNumber (_spawnCfg >> "radius")]) select {
				!(isObjectHidden _x || { [_x] call ULP_fnc_isHouseOwned })
			};

			if !(_buildings isEqualTo []) then {
				_pos = (selectRandom _buildings) buildingPos 0;
			};
		};
	};
	case (_spawnCfg isEqualType []) : {
		_name = "a base";
		_pos = _spawnCfg;
	};
	default {
		_name = [typeOf _spawnCfg] call ULP_fnc_vehicleCfg select 3;
		_pos = _spawnCfg modelToWorldVisual getArray(missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _spawnCfg) >> "spawnPos");
	};
};

player playMoveNow (["IDLE", "STAND"] call ULP_fnc_getAnim);
player setPosASL AGLtoASL _pos;
player setDir _dir;

closeDialog 0;
cutText ["","BLACK IN"];
titleText[format ["%2 %1", _name, "You have spawned at"], "BLACK IN"];

if (ULP_FirstSpawn) then {
    ULP_FirstSpawn = false;

	if (["EnableWelcome"] call ULP_fnc_getOption isEqualTo 1) then {
		[
			3, [],
			{ [] call ULP_UI_fnc_screenCredits; }
		] call ULP_fnc_waitExecute;
	};

	["FirstSpawn"] call ULP_fnc_achieve;

	if ([] call ULP_fnc_donatorLevel > 0) then { ["Donator"] call ULP_fnc_unlockTitle; };
	if ([] call ULP_fnc_donatorLevel > 1) then { ["Investor"] call ULP_fnc_unlockTitle; };

	if (((call ULP_Staff) > 1) || { ((call ULP_Event) > 1) }) then { ["JoinStaff"] call ULP_fnc_achieve; };

	if ([] call ULP_fnc_isGovernor) then { ["Governor"] call ULP_fnc_achieve; };

	if (["Police_Main", 1] call ULP_fnc_hasAccess) then { ["JoinAPC"] call ULP_fnc_achieve; };
	if (["Police_COL", 1] call ULP_fnc_hasAccess) then { ["JoinCOL"] call ULP_fnc_achieve; };
	if (["Police_NPAS", 1] call ULP_fnc_hasAccess) then { ["JoinNPAS"] call ULP_fnc_achieve; };
	if (["Police_SCO", 1] call ULP_fnc_hasAccess) then { ["JoinSCO19"] call ULP_fnc_achieve; };
	if (["Police_NCA", 1] call ULP_fnc_hasAccess) then { ["JoinNCA"] call ULP_fnc_achieve; };
	if (["Police_MPU", 1] call ULP_fnc_hasAccess) then { ["JoinMPU"] call ULP_fnc_achieve; };
	if (["Police_RPU", 1] call ULP_fnc_hasAccess) then { ["JoinRPU"] call ULP_fnc_achieve; };
	if (["Police_SFO", 1] call ULP_fnc_hasAccess) then { ["JoinSFO"] call ULP_fnc_achieve; };
	if (["Police_UC", 1] call ULP_fnc_hasAccess) then { ["JoinUC"] call ULP_fnc_achieve; };

	if (["Medic_Main", 1] call ULP_fnc_hasAccess) then { ["JoinNHS"] call ULP_fnc_achieve; };
	if (["Medic_HR", 1] call ULP_fnc_hasAccess) then { ["JoinHR"] call ULP_fnc_achieve; };
	if (["Medic_AA", 1] call ULP_fnc_hasAccess) then { ["JoinAA"] call ULP_fnc_achieve; };

	if (["Hato_Main", 1] call ULP_fnc_hasAccess) then { ["JoinHATO"] call ULP_fnc_achieve; };
} else {
	[false, true] call ULP_fnc_initPlayer;
};

player allowDammage true;

if (["EnableHUD", "HUD"] call ULP_fnc_getOption isEqualTo 1) then {
	[] call ULP_UI_fnc_openHUD;
};

[getPlayerUID player, "Spawn", [_name, getPos player]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];