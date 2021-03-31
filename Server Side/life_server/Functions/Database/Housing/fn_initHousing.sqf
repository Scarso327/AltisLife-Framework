/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_initHousing";

if (canSuspend) exitWith {
    [ULP_SRV_fnc_initHousing, _this] call ULP_fnc_directCall;
};

["Setting Up Housing..."] call ULP_fnc_logIt;

private _query = ["SELECT houses.id, houses.pid, players.group_id, players.name, houses.classname, houses.pos, houses.name, houses.storage, houses.virtualStorage, houses.shared FROM houses INNER JOIN players ON players.pid = houses.pid WHERE houses.sold='0'", 2, true] call DB_fnc_asyncCall;

if (_query isEqualTo "" || { _query isEqualTo [] }) exitWith { 0 };

ULP_SRV_Houses = [];

{
	_x params ["_id", "_pid", "_gangId", "_ownerName", "_classname", "_pos", "_name", "_storage", "_virtualStorage", "_shared"];

	if (isClass (missionConfigFile >> "CfgHousing" >> "Houses" >> _classname)) then {
		// Convert Datatypes...
		_pos = [_pos] call DB_fnc_mresToArray;
		_storage = [_storage] call DB_fnc_mresToArray;
		_virtualStorage = [_virtualStorage] call DB_fnc_mresToArray;
		_shared = [_shared] call ULP_fnc_bool;

		private _house = (_pos nearObjects [_classname, 5]) param [0, objNull];
		
		if (isNull _house || { _house in ULP_SRV_Houses }) then {
			[format ["House wasn't found: %1 at %2 (%3, %4)", _classname, _pos, _id, (_house in ULP_SRV_Houses)]] call ULP_fnc_logIt;
		} else {
			if (_house getVariable ["blacklisted", false]) then {
				[format["UPDATE houses SET sold='1' WHERE id='%1'", [_id, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;
				[_steamid, "House", ["Blacklisted", getPos _house, [0, ""] call ULP_fnc_numberText]] call ULP_SRV_fnc_logPlayerEvent;
			} else {
				[_house, [_id, [_pid, _gangId, _ownerName], _shared, _name, _storage, _virtualStorage]] call ULP_SRV_fnc_setupHouse;
			};
		};
	} else {
		[format ["House doesn't exist in config: %1 (%2)", _classname, _id]] call ULP_fnc_logIt;
	};
} forEach _query;