/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_repackAmmo";

private _time = ["SlightofHand", (LIFE_SETTINGS(getNumber, "repackingTime"))] call ULP_fnc_activatePerk;

["Repacking Magazines", _time, [], { isNull (objectParent player) }, {
	private _repackedMags = []; 
 
	{ 
		private _magazine = _x;
		private _magazineSize = getNumber(configFile >> "CfgMagazines" >> _magazine >> "count");
		
		if (_magazine in _repackedMags || { _magazineSize <= 0 }) exitWith {}; 
		
		private _ammo = 0; 
		
		{ 
			if ((_x select 0) isEqualTo _magazine) then { 
				_ammo = _ammo + (_x select 1); 
			}; 
			
			nil 
		} count (magazinesAmmo player); 

		player removeMagazines _magazine;
		
		while { _ammo > 0 } do {
			private _amount = _ammo min _magazineSize;
			player addMagazine [_magazine, _amount];
			_ammo = _ammo - _amount;
		};

		_repackedMags pushBackUnique _magazine;
		nil 
	} count (magazines player);
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;