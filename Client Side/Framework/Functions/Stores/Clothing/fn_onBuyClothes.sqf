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
};

(_className call BIS_fnc_itemType) params ["_itemType", "_itemCategory"];

if (([_className, _itemType, _itemCategory, _override] call ULP_fnc_canFitGear) && { (_texClass isEqualTo "") }) then {
	player addItem _className;
	true breakOut "fn_onBuyClothes";
} else {
	private _action = [
		format [
			"%1 either can't fit in your inventory or is textured. Would you like to wear it and replace any items blocking it? You won't be able to retrieve the replaced item.", 
			(_cartList lbText _i)
		], "Not Enough Space", "Wear", "Skip"
	] call BIS_fnc_guiMessage;

	if (_action) then {
		([_className, true, _texClass] call ULP_fnc_handleGear) breakOut "fn_onBuyClothes";
	} else {
		_cartValue = _cartValue - (_cartList lbValue _i); // Remove it from the total cost...
	};
};

false