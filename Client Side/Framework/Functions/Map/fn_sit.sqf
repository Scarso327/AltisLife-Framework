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
		
		private _offset = switch (typeOf _chair) do {
			case "Land_RattanChair_01_F": { -1 };
			default { 0 };
		};

		private _playerPos = getPosATL _player;
    	_player setPosATL [_playerPos # 0, _playerPos # 1, (_playerPos # 2) + _offset];

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