/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_fetchWarrants";

private _units = ["Civilian"] call ULP_fnc_allMembers;
private _warrants = createHashMap;

if !(_units isEqualTo []) then {
	private _warrants_query = [format ["SELECT * FROM `warrants` WHERE `pid` in (%1) AND `active`='1'", 
		(_units apply { format ["'%1'", getPlayerUID _x] }) joinString ","
	], 2, true] call DB_fnc_asyncCall;

	if (_warrants_query isEqualType "") then {
		_warrants_query = [];
	};

	{
		_x params [ "_id", "_pid", "_act", "_crime", "_info", "_insert" ];

		_info = [_info] call DB_fnc_mresToArray;

		if (_pid in _warrants) then {
			private _history = _warrants get _pid;
			if (_act in _history) then {
				private _crimes = _history get _act;
				if (_crime in _crimes) then {
					private _list = _crimes get _crime;
					_list set [_id, [_info, _insert]];
					_crimes set [_crime, _list];
				} else {
					_crimes set [_crime, createHashMapFromArray [[_id, [_info, _insert]]]];
				};

				_history set [_act, _crimes];
			} else {
				_history set [_act, createHashMapFromArray [[_crime, createHashMapFromArray [[_id, [_info, _insert]]]]]];
			};
		} else {
			_warrants set [_pid, createHashMapFromArray [[_act, createHashMapFromArray [[_crime, createHashMapFromArray [[_id, [_info, _insert]]]]]]]];
		};
	} forEach _warrants_query;
};

["WarrantsRetrieved", [_warrants]] remoteExecCall ["ULP_fnc_invokeEvent", remoteExecutedOwner];