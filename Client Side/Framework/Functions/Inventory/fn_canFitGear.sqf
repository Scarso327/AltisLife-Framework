/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_canFitGear";

_this params [
	["_item", "", [""]],
	["_itemType", "", [""]],
	["_itemCategory", "", [""]],
	["_replace", false, [true]]
];

switch (_itemType) do {
	case "Weapon": {
		if (_replace) exitWith { true breakOut "fn_canFitGear"; };

		((getNumber (configFile >> "CfgWeapons" >> _item >> "type")) call {
			if (_this isEqualTo 1) exitWith { (primaryWeapon player) isEqualTo "" };
			if (_this isEqualTo 2) exitWith { (handgunWeapon player) isEqualTo "" };
			if (_this isEqualTo 4) exitWith { (secondaryWeapon player) isEqualTo "" };
			false
		}) breakOut "fn_canFitGear";
	};
	case "Magazine": {
		{
			_x params [ "_wep", "_mags" ];

			if (!(_wep isEqualTo "") && { _mags isEqualTo [] }) exitWith {
				(_item in ([_wep, true, false] call ULP_fnc_compatibleItems)) breakOut "fn_canFitGear";
			};
		} forEach [
			[primaryWeapon player, primaryWeaponMagazine player],
			[secondaryWeapon player, secondaryWeaponMagazine player],
			[handgunWeapon player, handgunMagazine player]
		];

		false breakOut "fn_canFitGear";
	};
	case "Item": {
		switch (_itemCategory) do {
			case "AccessoryMuzzle";
			case "AccessoryPointer";
			case "AccessorySights";
			case "AccessoryBipod": {
				{
					_x params [ "_wep", "_attachments" ];

					if !(_wep isEqualTo "" && { (count (_attachments param [1, []] param [(["AccessoryMuzzle", "AccessoryPointer", "AccessorySights", "AccessoryBipod"] find _itemCategory)])) > 0 }) exitWith {
						(_item in ([_wep, false, true] call ULP_fnc_compatibleItems)) breakOut "fn_canFitGear";
					};
				} forEach [
					[primaryWeapon player, primaryWeaponItems player],
					[secondaryWeapon player, secondaryWeaponItems player],
					[handgunWeapon player, handgunItems player]
				];

				false breakOut "fn_canFitGear";
			};
			case "Watch";
			case "Map";
			case "Radio";
			case "NVGoggles";
			case "Glasses";
			case "Compass";
			case "GPS";
			case "UAVTerminal": {
				if (_replace) exitWith { true breakOut "fn_canFitGear"; };
				(!(_item in (assignedItems player))) breakOut "fn_canFitGear";
			};
			case "LaserDesignator";
			case "Binocular": {
				if (_replace) exitWith { true breakOut "fn_canFitGear"; };
				((binocular player) isEqualTo "") breakOut "fn_canFitGear";
			};
		};
	};
	case "Equipment": {
		if (_replace) exitWith { true breakOut "fn_canFitGear"; };
		
		(switch (_itemCategory) do {
			case "Uniform": { (uniform player isEqualTo "") };
			case "Vest": { (vest player isEqualTo "") };
			case "Backpack": { (backpack player isEqualTo "") };
			case "Glasses": { (goggles player isEqualTo "") };
			case "Headgear": { (headgear player isEqualTo "") };
		}) breakOut "fn_canFitGear";
	};
};

true