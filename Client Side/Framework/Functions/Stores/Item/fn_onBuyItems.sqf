/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onBuyItems";

_this params [
	"_cartValue", "_cartList", "_className", "_texClass", "_cfgName", "_itemCfg", "_i", "_override"
];

if !(_texClass isEqualTo "") then {
	_className = _texClass;
};

[_className, _override] call ULP_fnc_handleGear