/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addFactoryTick";

_this params [
	["_factory", objNull, [objNull]]
];

private _order = _factory getVariable ["product_order", []];
private _productCfg = _order param [0, configNull, [configNull]];

private _startTime = serverTime;
private _tickEndTime = _startTime + 30;

_order set [3, _startTime];

_factory setVariable ["product_order", _order, true];

[{ isNull (_this select 0) 
	|| { !((_this select 0) getVariable ["locked", false]) }
	|| { (((_this select 0) getVariable ["product_order", []]) param [1, 99, [0]]) > ((_this select 0) getVariable ["power", 0]) }
	|| { serverTime >= (_this select 1) }
	|| { !((_this select 0) call ((_this select 0) getVariable "factory_preTickCondition")) } }, 
	[_factory, _tickEndTime], {
	_this call ULP_SRV_fnc_tickFactory;
}] call ULP_fnc_waitUntilExecute;