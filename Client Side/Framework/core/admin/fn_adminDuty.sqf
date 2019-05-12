#include "..\..\script_macros.hpp"

private _suit = switch (FETCH_CONST(life_adminlevel)) do {
    case 1: {"U_I_Protagonist_VR"};
    case 2: {"U_B_Protagonist_VR"};
    default {"U_O_Protagonist_VR"};
};

if(admin_duty) then {
	admin_duty = !admin_duty; 
	player setVariable["duty", 0, true];

	removeUniform player;
	removeVest player;
	removeBackpack player;
	removeHeadgear player;
	removeGoggles player;

	player forceAddUniform life_oldUniform;
	_count = (count life_oldUniformItems) - 1; 
	for "_x" from 0 to _count do { 
		_item = life_oldUniformItems select _x;
		player addItemToUniform _item;
	};

	player addVest life_oldVest;
	_count = (count life_oldVestItems) - 1; 
	for "_x" from 0 to _count do { 
		_item = life_oldVestItems select _x;
		player addItemToVest _item;
	};

	player addBackpack life_oldBackpack;
	_count = (count life_oldBackpackItems) - 1; 
	for "_x" from 0 to _count do {
		_item = life_oldBackpackItems select _x;
		player addItemToBackpack _item;
	};
	
	player addHeadgear life_oldHeadgear;
	player addGoggles life_oldGoggles;
	[] call life_fnc_playerSkins;

	player addWeapon life_oldPWeapon;
	player addWeapon life_oldSWeapon;
	player addMagazine life_oldPWeaponMag;
	player addMagazine life_oldSWeaponMag;
	{
		player addPrimaryWeaponItem _x;
	} forEach life_oldPWeaponItems;
	{
		player addHandgunItem _x;
	} forEach life_oldSWeaponItems;
	
	player allowDamage true;
} 

else {
	admin_duty = admin_duty;
	player setVariable["duty", 1, true];

	life_oldUniformItems = uniformItems player;
	life_oldVestItems = vestItems player;
	life_oldBackpackItems = backpackItems player;

	life_oldPWeapon = primaryWeapon player;
	life_oldSWeapon = handgunWeapon player;
	life_oldPWeaponMag = (getarray (configFile >> "CFGWeapons" >> life_oldPWeapon >> "magazines") select 0);
	life_oldSWeaponMag = (getarray (configFile >> "CFGWeapons" >> life_oldSWeapon >> "magazines") select 0);
	life_oldPWeaponItems = primaryWeaponItems player;
	life_oldSWeaponItems = handgunItems player;

	life_oldUniform = uniform player;
	life_oldVest = vest player;
	life_oldBackpack = backpack player;
	life_oldHeadgear = headgear player;
	life_oldGoggles = goggles player;

	removeUniform player;
	removeVest player;
	removeBackpack player;
	removeHeadgear player;
	removeGoggles player;
	removeAllWeapons player;

	player forceAddUniform _suit;
	player addGoggles "G_Aviator";
	player addHeadgear "H_Cap_headphones";

	player addItem "ItemMap";
	player assignItem "ItemMap";
	player addItem "ItemCompass";
	player assignItem "ItemCompass";
	player addItem "ItemWatch";
	player assignItem "ItemWatch";
	player addItem "ItemGPS";
	player assignItem "ItemGPS";
	
	player allowDamage false;
	[] call life_fnc_playerSkins;
};