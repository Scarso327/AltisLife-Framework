/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setGear";

_this params [
	["_item", "", [""]],
	["_itemType", "", [""]],
	["_itemCategory", "", [""]],
	["_texture", "", [""]]
];

if (_itemType isEqualTo "Magazine") then {

} else {
	switch (_itemCategory) do {
		case "AssaultRifle";
		case "MachineGun";
		case "Rifle";
		case "SniperRifle";
		case "Shotgun";
		case "SubmachineGun": {
			removeAllPrimaryWeaponItems player;
			player addWeaponGlobal _item;
			true breakOut "fn_setGear";
		};
		case "Binocular";
		case "Handgun";
		case "LaserDesignator";
		case "RocketLauncher";
		case "MissileLauncher";
		case "Throw": {
			player addWeaponGlobal _item;
			true breakOut "fn_setGear";
		};
		case "GPS";
		case "Map";
		case "Radio";
		case "UAVTerminal";
		case "Watch";
		case "Compass";
		case "NVGoggles";
		case "Glasses": {
			player linkItem _item;
			true breakOut "fn_setGear";
		};
		case "Headgear": {
			player addHeadgear _item;
			true breakOut "fn_setGear";
		};
		case "Backpack": {
			private _items = [];

			if !((backpack player) isEqualTo "") then {
				_items append (backpackItems player);
				removeBackpack player;
			};

			player addBackpackGlobal _item;

			if !(_items isEqualTo []) then { [_items] call ULP_fnc_addItems; };

			if !(_item isEqualTo _texture) then {
				[{ (backpack player) isEqualTo (_this select 0) }, [_item, _texture], {
					[unitBackpack player, uniformContainer player, (_this select 1)] call ULP_fnc_setTextures;
				}] call ULP_fnc_waitUntilExecute;
			};

			true breakOut "fn_setGear";
		};
		case "Uniform": {
			private _items = [];

			if !((uniform player) isEqualTo "") then {
				_items append (uniformItems player);
				removeUniform player;
			};

			player forceAddUniform _item;

			if !(_items isEqualTo []) then { [_items] call ULP_fnc_addItems; };

			if !(_item isEqualTo _texture) then {
				[{ (uniform player) isEqualTo (_this select 0) }, [_item, _texture], {
					[player, uniformContainer player, (_this select 1)] call ULP_fnc_setTextures;
				}] call ULP_fnc_waitUntilExecute;
			};

			true breakOut "fn_setGear";
		};
		case "Vest": {
			private _items = [];

			if !((vest player) isEqualTo "") then {
				_items append (vestItems player);
				removeVest player;
			};

			player addVest _item;

			if !(_items isEqualTo []) then { [_items] call ULP_fnc_addItems; };

			true breakOut "fn_setGear";
		};
		case "AccessorySights";
		case "AccessoryPointer";
		case "AccessoryMuzzle";
		case "AccessoryBipod": {
			// TODO
		};
	};
};