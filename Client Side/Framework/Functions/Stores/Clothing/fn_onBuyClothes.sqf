/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onBuyClothes";

_this params [
	"_cartValue", "_cartList", "_className", "_texClass", "_cfgName", "_itemCfg", "_i"
];

if (player canAdd _className && { (_texClass isEqualTo "") }) then {
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
		switch (_cfgName) do {
			case "CfgVehicles": {
				if (getNumber(_itemCfg >> "isBackpack") isEqualTo 1) then {
					// Backpack
					private _bpItems = backpackItems player;
					removeBackpack player;
					player addBackpack _className;
					[_bpItems] call ULP_fnc_addItems;

					// Texture
					[unitBackpack player, backpackContainer player, _texClass, true, false] call ULP_fnc_setTextures;
				};	
			};
			case "CfgGlasses": {
				player addGoggles _className;
			};
			default {
				if (getNumber(_itemCfg >> "type") in [4096, 131072]) then {
					switch (getNumber(_itemCfg >> "ItemInfo" >> "type")) do {
						case 605: { player addHeadgear _className }; // Headgear
						case 701: {
							// Vest
							private _vItems = vestItems player;
							player addVest _className;
							[_vItems] call ULP_fnc_addItems;
						};
						case 801: {
							// Uniform
							private _uItems = uniformItems player;
							player forceAddUniform _className;
							[_uItems] call ULP_fnc_addItems;

							// Texture
							[player, uniformContainer player, _texClass] call ULP_fnc_setTextures;
						};
					};
				};
			};
		};

		true breakOut "fn_onBuyClothes";
	} else {
		_cartValue = _cartValue - (_cartList lbValue _i); // Remove it from the total cost...
	};
};

false