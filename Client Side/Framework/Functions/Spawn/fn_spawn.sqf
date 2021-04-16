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

		if !(_buildings isEqualTo []) then {
			_buildings = nearestObjects[_pos, _buildings, getNumber (_spawnCfg >> "radius")];
			if !(_buildings isEqualTo []) then {
				_pos = (selectRandom (_buildings select { !(isObjectHidden _x && { [_x] call ULP_fnc_isHouseOwned }) })) buildingPos 0;
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

	// Lewis coded from this line until the end of the block... I wanna die...

	if (((call ULP_Staff) > 1) || { ((call ULP_Event) > 1) }) then { ["JoinStaff"] call ULP_fnc_achieve; };

	{
		if ((_x select 0) call ULP_fnc_hasAccess) then { [_x select 1] call ULP_fnc_achieve; };
	} forEach [
		(switch ([player] call ULP_fnc_getFaction) do {
			case "Police" : { [["Police_Main", 1], "JoinAPC"], [["Police_RTA", 1], "JoinRTA"], [["Police_NPAS", 1], "JoinNPAS"], [["Police_SCO", 1], "JoinSCO19"], [["Police_NCA", 1], "JoinNCA"], [["Police_MPU", 1], "JoinMPU"], [["Police_RPU", 1], "JoinRPU"], [["Police_SFO", 1], "JoinSFO"], [["Police_UC", 1], "JoinUC"] };
			case "Medic" : { [["Medic_Main", 1], "JoinNHS"], [["Medic_HR", 1], "JoinHR"], [["Medic_AA", 1], "JoinAA"] };
			case "Hato" : { [["Hato_Main", 1], "JoinHATO"] };
		})
	];
} else {
	[false] call ULP_fnc_initPlayer;
};

player allowDammage true;

if (["EnableHUD", "HUD"] call ULP_fnc_getOption isEqualTo 1) then {
	[] call ULP_UI_fnc_openHUD;
};

[getPlayerUID player, "Spawn", [_name, getPos player]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];