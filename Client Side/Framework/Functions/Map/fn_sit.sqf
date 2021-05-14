/*
** Author: Lewis Mackinnon
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sit";

params [
  ["_mode", "init", [""]],
  ["_params", [], [[]]]
];


switch _mode do {
	case "init": {
    	_params params [["_chair", cursorObject, [objNull]], ["_unit", player, [objNull]]];
   		_chair addAction ["Sit Down", {["sitDown", _this] call ULP_fnc_sit}, [], 0, true, true, "", "!(_target getVariable [""occupied"", false]) && { isNil ""isSitting"" }", 2];
  	};

  	case "sitDown": {
    	if !(isNil "isSitting") exitWith {};

    	isSitting = true;

    	_params params [["_chair", cursorObject, [objNull]], ["_player", player, [objNull]]];

    	_chair setVariable ["occupied", true, true];
    	[player, "Crew"] call ULP_fnc_switchMove;

    	_player setPos (getPosATL _chair);
    	_player setDir ((getDir _chair) - 180);
    	_player setPosATL [getPosATL _player # 0, getPosATL _player # 1, (getPosATL _player # 2)];

    	_player addAction ["Stand Up", {(_this # 3) params ["_chair", "_player"]; ["standUp", [_chair, _player, _this # 2]] call ULP_fnc_sit}, [_chair, _player]];
 	};

  	case "standUp": {
		_params params [["_chair", cursorObject, [objNull]], ["_player", player, [objNull]], ["_actionID", -1, [0]]];

		_player switchMove "";
		_player removeAction _actionID;

		_chair setVariable ["occupied", false, true];

		isSitting = nil;
  	};
};