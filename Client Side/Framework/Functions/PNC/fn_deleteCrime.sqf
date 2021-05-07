/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_deleteCrime";

if (canSuspend) exitWith {
    [ULP_fnc_deleteCrime, _this] call ULP_fnc_directCall;
};

_this params [
	["_ctrl", controlNull, [controlNull]]
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _steamid = _display getVariable ["warrant_steam_id", ""];
private _act = _display getVariable ["act_cfg_name", ""];
private _crime = _display getVariable ["crime_cfg_name", ""];
private _crimeId = _display getVariable ["selected_crime_id", -1];

private _unit = [_steamid] call ULP_fnc_playerByUid;

if (isNull _unit || { _crime isEqualTo "" } || { _crimeId isEqualTo -1 }) exitWith {
	["You must select a crime to remove..."] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Remove", "Cancel"],
	format ["Are you sure you want to remove %1 from %2's warrant...", getText (missionConfigFile >> "CfgWarrants" >> _act >> _crime >> "displayName"), name _unit], [_unit, _act, _crime, _crimeId, _display],
	{	
		_this params [ "_unit", "_act", "_crime", "_crimeId", "_display" ];

		_display setVariable ["warrant_steam_id", nil];
		_display setVariable ["act_cfg_name", nil];
		_display setVariable ["crime_cfg_name", nil];
		_display setVariable ["selected_crime_id", nil];

		[getPlayerUID _unit, _act, _crime, _crimeId] remoteExecCall ["ULP_SRV_fnc_deleteCrime", RSERV];

		private _group = _display displayCtrl 4703;

		private _list = _group controlsGroupCtrl 102;

		private _crimes = _list tvData (tvCurSel _list);
		if (_crimes isEqualTo "") exitWith {};
		(parseSimpleArray _crimes) params [ "_configName", "_crimes" ];

		_crimes = createHashMapFromArray _crimes;
		_crimes deleteAt _crimeId;

		if ((count _crimes) isEqualTo 0) then {
			_list tvDelete (tvCurSel _list);
		} else {
			_list tvSetText [(tvCurSel _list), format ["%1 (%2)", getText (missionConfigFile >> "CfgWarrants" >> _act >> _crime >> "displayName"), [count _crimes] call ULP_fnc_numberText]];
			_list tvSetData [(tvCurSel _list), str [_configName, _crimes]];
		};

		private _crimeList = _group controlsGroupCtrl 106;
		_crimeList lnbDeleteRow (lnbCurSelRow _crimeList);
		(_group controlsGroupCtrl 107) ctrlSetText "";

		[format ["You have removed a count of %1 from %2's warrant", getText (missionConfigFile >> "CfgWarrants" >> _act >> _crime >> "displayName"), name _unit]] call ULP_fnc_hint;
	}, {}, false
] call ULP_fnc_confirm;