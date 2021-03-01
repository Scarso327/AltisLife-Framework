/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onBuyClothes";

_this params [
	"_cartValue", "_cartList", "_className", "_texClass", "_cfgName", "_itemCfg", "_i", "_override"
];

// If the texture is it's own entity in CfgClothing, it's an item...
if (isClass (missionConfigFile >> "CfgClothing" >> _texClass)) then {
	_className = _texClass;
} else {
	if (isClass (missionConfigFile >> "CfgClothing" >> _className >> "Textures" >> _texClass)) then {
		// If it's a textured item, always override...
		_override = true;
	};
};

[_className, _override, _texClass] call ULP_fnc_handleGear