/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_createFactorySound";

_this params [
	["_factory", objNull, [objNull]]
];

if (isNull _factory) exitWith { false };

private _source = createSoundSource ["Factory_Processing", getPosATL _factory, [], 0];
_source attachTo [_factory, [0, 0, 0]];
_factory setVariable ["sound", _source];

true