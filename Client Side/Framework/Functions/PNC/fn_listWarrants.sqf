/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_listWarrants";

if (canSuspend) exitWith {
    [ULP_fnc_listWarrants, _this] call ULP_fnc_directCall;
};

_this params [
	["_warrants", createHashMap, [createHashMap]]
];

private _display = findDisplay 4700;
if (isNull _display) exitWith {};

private _group = _display displayCtrl 4703;
private _list = _group controlsGroupCtrl 102;
tvClear _list;

{
	private _unit = [_x] call ULP_fnc_playerByUID;

	if !(isNull _unit) then {
		private _history = _list tvAdd [[], name _unit];
		_list tvSetPicture [[_history], "\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa"];
		_list tvSetData [[_history], _x];

		{
			private _actCfg = missionConfigFile >> "CfgWarrants" >> _x;
			
			if (isClass _actCfg) then {
				private _act = _list tvAdd [[_history], getText (_actCfg >> "displayName")];
				_list tvSetData [[_history, _act], _x];

				{
					private _crimeCfg = _actCfg >> _x;
					
					if (isClass _crimeCfg) then {
						private _crime = _list tvAdd [[_history, _act], format ["%1 (%2)", getText (_crimeCfg >> "displayName"), [count _y] call ULP_fnc_numberText]];
						_list tvSetData [[_history, _act, _crime], str [_x, _y]];
					};
				} forEach _y;
			};
		} forEach _y;
	};
} forEach _warrants;

private _issue = _display displayCtrl 4704;
private _clear = _display displayCtrl 4705;

_issue ctrlShow true;
_clear ctrlShow true;