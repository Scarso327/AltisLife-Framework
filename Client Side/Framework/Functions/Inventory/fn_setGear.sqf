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

			if !(_items isEqualTo _texture) then {
				[unitBackpack player, backpackContainer player, _texture] call ULP_fnc_setTextures;
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

			if !(_items isEqualTo _texture) then {
				[player, uniformContainer player, _texture] call ULP_fnc_setTextures;
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