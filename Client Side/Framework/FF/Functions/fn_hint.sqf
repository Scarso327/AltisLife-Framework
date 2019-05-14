/*
	@File: fn_hint.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Custom hint file for remote executing...
*/
params [
	["_message", "", [""]],
	["_condition", "true", [""]]
];

private _condition = call compile _condition;

// Checks...
if (_message isEqualTo "") exitWith {}; //  Must actually have a message...
if (_condition isEqualType true) exitWith {}; // Must be true...

hint _message;