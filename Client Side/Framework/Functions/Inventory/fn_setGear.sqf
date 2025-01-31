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
	{
		_x params [ "_wep", "_mags" ];

		if (!(_wep isEqualTo "" && { (count _mags) > 0 }) && { (_item in ([_wep, true, false] call ULP_fnc_compatibleItems)) }) then {
			switch (_forEachIndex) do {
				case 0: { player addPrimaryWeaponItem _item; };
				case 1: { player addSecondaryWeaponItem _item; };
				case 2: { player addHandgunItem _item; };
			};

			true breakOut "fn_setGear";
		};
	} forEach [
		[primaryWeapon player, primaryWeaponMagazine player],
		[secondaryWeapon player, secondaryWeaponMagazine player],
		[handgunWeapon player, handgunMagazine player]
	];
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
				ULP_BackpackTexture = _texture;
				[unitBackpack player, typeOf (unitBackpack player), backpackContainer player, _texture] call ULP_fnc_setTextures;
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
				ULP_UniformTexture = _texture;
				[player, uniform player, uniformContainer player, _texture] call ULP_fnc_setTextures;
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
			{
				if (!(_x isEqualTo "") && { (_item in ([_x, false, true] call ULP_fnc_compatibleItems)) }) then {
					switch (_forEachIndex) do {
						case 0: { player addPrimaryWeaponItem _item; };
						case 1: { player addSecondaryWeaponItem _item; };
						case 2: { player addHandgunItem _item; };
					};

					true breakOut "fn_setGear";
				};
			} forEach [primaryWeapon player, secondaryWeapon player, handgunWeapon player];
		};
	};
};