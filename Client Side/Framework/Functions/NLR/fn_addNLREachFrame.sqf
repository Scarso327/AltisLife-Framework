/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_addNLREachFrame";

[_this, {
	_this params [
		"_pos", "_area", "_marker", "_nlrName", "_nlrDistance", "_endTime"
	];

	if (time >= _endTime) exitWith {
		deleteMarkerLocal _marker;
		deleteMarkerLocal _area;

		[_thisEventHandler] call ULP_fnc_removeEachFrame;
	};

	if ((player distance _pos) <= _nlrDistance && { ULP_Respawned }) exitWith {
		_this pushBack time;

		["You have entered your NLR zone!"] call ULP_fnc_hint;

		[
			{ (player distance (_this select 0)) > (_this select 4) }, _this, {
				["You have left your NLR zone!"] call ULP_fnc_hint;

				_this set [5, ((_this select 5) + (time - (_this select 6)))];
				_this deleteAt 6;
				_this call ULP_fnc_addNLREachFrame;
			}
		] call ULP_fnc_waitUntilExecute;

		[_thisEventHandler] call ULP_fnc_removeEachFrame;
	};

	_marker setMarkerTextLocal format["NLR: %1", [_endTime - time, "MM:SS"] call BIS_fnc_secondsToString];
}] call ULP_fnc_addEachFrame;