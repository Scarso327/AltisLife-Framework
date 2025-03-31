/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_startVehicleFactory";

_this params [
	["_factory", objNull, [objNull]],
	["_unit", objNull, [objNull]],
	["_productCfg", configNull, [configNull]],
	["_params", [], [[]]]
];

private _texture = _params param [0, "Default", [""]];
_factory setVariable ["factory_texture", _texture];

1