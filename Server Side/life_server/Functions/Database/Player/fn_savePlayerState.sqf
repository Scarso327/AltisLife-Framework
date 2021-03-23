/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_savePlayerState";

_this params [
	["_player", objNull, [objNull]],
	["_state", 0, [0]],
	"_data"
];

private _steamid = getPlayerUID _player;
private _faction = [_player] call ULP_fnc_getFaction;

_faction = missionConfigFile >> "CfgFactions" >> _faction;
if (_steamid isEqualTo "" || { !(isClass (_faction)) }) exitWith {};

private _query = switch (_state) do {
	case 0: { format["%1licenses='%2'", getText(_faction >> "DatabaseInfo" >> "queryPrefix"), [_data] call DB_fnc_mresArray] };
	case 1: {
		_data params [["_total", 0, [0]], ["_amount", 0, [0]], ["_increase", true, [false]]];
		if !([_player, [_player, "Cash"] call ULP_SRV_fnc_getSessionField, _total, _amount, _increase] call ULP_SRV_fnc_validateField) exitWith { "" };
		[_player, "Cash", _total] call ULP_SRV_fnc_setSessionField;
		format["cash='%1'", [_total, ""] call ULP_fnc_numberText]
	};
	case 2:  {
		_data params [["_total", 0, [0]], ["_amount", 0, [0]], ["_increase", true, [false]]];
		if !([_player, [_player, "Bank"] call ULP_SRV_fnc_getSessionField, _total, _amount, _increase] call ULP_SRV_fnc_validateField) exitWith { "" };
		[_player, "Bank", _total] call ULP_SRV_fnc_setSessionField;
		format["bankacc='%1'", [_total, ""] call ULP_fnc_numberText]
	};
	case 3: { format["professions='%1'", [_data] call DB_fnc_mresArray] };
	case 4: { format["level = '%1', xp = '%2'", [(_data select 0), ""] call ULP_fnc_numberText, [(_data select 1), ""] call ULP_fnc_numberText]};
	case 5: { format["professions = '""[]""', level = '1', xp = '0', prestige ='%1'", [_data, ""] call ULP_fnc_numberText] };
	case 6: { format["achievements='%1'", [_data] call DB_fnc_mresArray] };
	case 7: { format["arrested = '%1', prison_timer = '%2'", [(_data > 0)] call ULP_fnc_bool, [_data, ""] call ULP_fnc_numberText] };
	case 8: { format["daily_tasks='%1', weekly_tasks='%2'", [_data select 0] call DB_fnc_mresArray, [_data select 1] call DB_fnc_mresArray] };
	default { "" };
};

if (_query isEqualTo "") exitWith {};

[format ["UPDATE players SET %1 WHERE pid='%2'", _query, _steamid], 1] call DB_fnc_asyncCall;