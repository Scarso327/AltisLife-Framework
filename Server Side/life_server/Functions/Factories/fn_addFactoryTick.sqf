/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addFactoryTick";

_this params [
	["_factory", objNull, [objNull]],
	["_tickTime", (_factory getVariable ["product_tick", 0]), [0]]
];

[{ isNull (_this select 0) 
	|| { !((_this select 0) getVariable ["locked", false]) }
	|| { ((_this select 0) getVariable ["product_power", 0]) > ((_this select 0) getVariable ["power", 0]) }
	|| { serverTime >= (_this select 1) } }, 
	[_factory, (serverTime + _tickTime)], {
	_this call ULP_SRV_fnc_tickFactory;
}] call ULP_fnc_waitUntilExecute;