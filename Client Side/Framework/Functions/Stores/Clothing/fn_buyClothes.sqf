/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_buyClothes";

_this params [
	"_ctrl"
];

if !(canSuspend) exitWith { _this spawn ULP_fnc_buyClothes; };

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _cartList = _display displayCtrl 3107;
if ((lbSize _cartList) isEqualTo 0) exitWith {
	hint "You must add something to your cart before you check out...";
};

_ctrl ctrlEnable false;

private _cartValue = uiNamespace getVariable "cartValue";

if (CASH < _cartValue) then {
	hint "You can't afford these items...";
} else {
	private _itemsBought = 0;
	for "_i" from 0 to ((lbSize _cartList) - 1) do {
		private _data = _cartList lbData _i; // (str [_className, _texClass])
		_data = parseSimpleArray _data;

		_data params [
			"_className", "_texClass"
		];

		([_className] call ULP_fnc_itemCfg) params [
			"_cfgName",
			"_itemCfg" 
		];
		
		if (player canAdd _className && { (_texClass isEqualTo "") }) then {
			player addItem _className;
			_itemsBought = _itemsBought + 1;
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

				_itemsBought = _itemsBought + 1;
			} else {
				_cartValue = _cartValue - (_cartList lbValue _i); // Remove it from the total cost...
			};
		};
	};

	// Wipe Cart...
	lbClear _cartList;
	_cartList lbSetCurSel -1;

	if !(_itemsBought isEqualTo 0) then {
		// Pay for it and wipe total value...
		CASH = CASH - _cartValue;
		uiNamespace setVariable ["cartValue", 0];
		[] call ULP_fnc_syncPlayerInfo;

		// Update inventory view if it's visible...
		if (ctrlShown (_display displayCtrl 3112)) then {
			[_ctrl, 1] call ULP_fnc_switchInventory;
		};

		hint format["You've bought these items for £%1", [_cartValue] call life_fnc_numberText];
	};
};

_ctrl ctrlEnable true;