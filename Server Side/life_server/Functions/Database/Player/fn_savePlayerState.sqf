/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_savePlayerState";

_this params [
	["_player", objNull, [objNull, ""]],
	["_state", 0, [0]],
	"_data"
];

private _steamid = _player;
private _faction = "";

if (_player isEqualType objNull) then {
	_steamid = getPlayerUID _player;

	_faction = [_player] call ULP_fnc_getFaction;
};

_faction = missionConfigFile >> "CfgFactions" >> _faction;

// We only allow _player to be steamid if state 12 which is set group info
if (_steamid isEqualTo "" || { _player isEqualType objNull && { !(isClass (_faction)) } } || { _player isEqualType "" && { !(_state isEqualTo 12) } }) exitWith {};

private _query = switch (_state) do {
	case 0: { format["`%1licenses`='%2'", getText(_faction >> "DatabaseInfo" >> "queryPrefix"), [_data] call DB_fnc_mresArray] };
	case 1: {
		_data params [["_total", 0, [0]], ["_amount", 0, [0]], ["_increase", true, [false]], ["_reason", "", [""]]];
		if !([_player, [_player, "Cash"] call ULP_SRV_fnc_getSessionField, _total, _amount, _increase] call ULP_SRV_fnc_validateField) exitWith { "" };
		[_player, "Cash", _total] call ULP_SRV_fnc_setSessionField;

		_total = [_total, ""] call ULP_fnc_numberText;

		[_steamid, "Money", ["Cash", (["Removed", "Added"] select (_increase)), _total, [_amount, ""] call ULP_fnc_numberText, _reason]] call ULP_SRV_fnc_logPlayerEvent;
		format["`cash`='%1'", _total]
	};
	case 2:  {
		_data params [["_total", 0, [0]], ["_amount", 0, [0]], ["_increase", true, [false]], ["_reason", "", [""]]];
		if !([_player, [_player, "Bank"] call ULP_SRV_fnc_getSessionField, _total, _amount, _increase] call ULP_SRV_fnc_validateField) exitWith { "" };
		[_player, "Bank", _total] call ULP_SRV_fnc_setSessionField;

		_total = [_total, ""] call ULP_fnc_numberText;

		[_steamid, "Money", ["Bank", (["Removed", "Added"] select (_increase)), _total, [_amount, ""] call ULP_fnc_numberText, _reason]] call ULP_SRV_fnc_logPlayerEvent;
		format["`bankacc`='%1'", _total]
	};
	case 3: { format["`professions`='%1'", [_data] call DB_fnc_mresArray] };
	case 4: { format["`level` = '%1', `xp` = '%2'", [(_data select 0), ""] call ULP_fnc_numberText, [(_data select 1), ""] call ULP_fnc_numberText]};
	case 5: { format["`blueprints` = '""[]""', `professions` = '""[]""', `level` = '1', `xp` = '0', `prestige` ='%1'", [_data, ""] call ULP_fnc_numberText] };
	case 6: { format["`achievements`='%1'", [_data] call DB_fnc_mresArray] };
	case 7: { format["`arrested` = '%1', `prison_timer` = '%2'", [(_data > 0)] call ULP_fnc_bool, [_data, ""] call ULP_fnc_numberText] };
	case 8: { format["`%1daily_tasks`='%2', `%1weekly_tasks`='%3'", getText(_faction >> "DatabaseInfo" >> "queryPrefix"), [_data select 0] call DB_fnc_mresArray, [_data select 1] call DB_fnc_mresArray] };
	case 9: { format["`textures`='%1'", [_data] call DB_fnc_mresArray] };
	case 10: { format["`titles`='%1'", [_data] call DB_fnc_mresArray] };
	case 11: {
		[_player, "Perks", _data] call ULP_SRV_fnc_setSessionField;
		format["`%1perks`='%2'", getText(_faction >> "DatabaseInfo" >> "queryPrefix"), [_data] call DB_fnc_mresArray]
	};
	case 12: { format["`group_id` = '%1', `group_level` = '%2'", _data select 0, _data select 1] };
	case 13: { format["`reputation` = '%1'", [_data, ""] call ULP_fnc_numberText]};
	case 14: { format["`blueprints` ='%1'", [_data] call DB_fnc_mresArray] };
	case 15: {
		[_player, "Gear", _data] call ULP_SRV_fnc_setSessionField;
		format["`%1gear`='%2'", getText(_faction >> "DatabaseInfo" >> "queryPrefix"), [_data] call DB_fnc_mresArray]
	};
	case 16: { format["`%1stats`='%2'", getText(_faction >> "DatabaseInfo" >> "queryPrefix"), [_data] call DB_fnc_mresArray] };
	case 17: { format["`%1wounded`='%2'", getText(_faction >> "DatabaseInfo" >> "queryPrefix"), [_data] call ULP_fnc_bool] };
	default { "" };
};

if (_query isEqualTo "") exitWith {};

[format ["UPDATE `players` SET %1 WHERE `pid`='%2'", _query, _steamid], 1] call DB_fnc_asyncCall;