/*
	@File: fn_onDamaged.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Handles all damage...

	@Parameters:
		0 - TYPE: OBJECT - DES: The damaged object...
		1 - TYPE: STRING - DES: The part of the object that was damaged...
		2 - TYPE: INTGER - DES: The damage taken...
		3 - TYPE: OBJECT - DES: The source of the damage...
		4 - TYPE: STRING - DES: The bullet that caused the damage...
		5 - TYPE: INTGER - DES: No idea tbh...
*/
#include "..\..\script_macros.hpp"
params [
    ["_unit",objNull,[objNull]],
    ["_part","",[""]],
    ["_damage",0,[0]],
    ["_source",objNull,[objNull]],
    ["_projectile","",[""]],
    ["_index",0,[0]]
];

// Get our current damage...
private _orginalDamage = [
	_unit getHit _part,
	damage _unit
] select (_part isEqualTo "");

// Knocked out? Tased? No damage...
if (life_istazed || life_isknocked) exitWith {_orginalDamage};

// If we have a source and the souce is not ourselves...
if (!isNull _source && {_source != _unit}) then {
	if (!(isDowned(_unit)) && alive _unit) then {
		if (isPlayer _source) then {
			/* 
				Taser
				Credit: Tonic
			*/
			if (currentWeapon _source in ["hgun_Pistol_heavy_01_F","hgun_Pistol_heavy_01_MRD_F","hgun_Pistol_heavy_01_snds_F"] && _projectile in ["B_45ACP_Ball"]) then {
				if (alive _unit) then {
					if !(life_istazed) then {
						private _distance = 35;
						if (_unit distance _source < _distance) then {
							if !(isNull objectParent _unit) then {
								if (typeOf (vehicle _unit) isEqualTo "B_Quadbike_01_F") then {
									_unit action ["Eject",vehicle _unit];
									[_unit,_source] spawn life_fnc_tazed;
								};
							} else {
								[_unit,_source] spawn life_fnc_tazed;
							};
						};
					};

					_damage = _orginalDamage;
				};
			};

			/* Anti-Restrain Glitch */
			if(_source getVariable ["restrained",false]) then { _damage = _orginalDamage };
		};

		/* Anti-VDM */
		if (isNull objectParent _unit && { (vehicle _source) isKindOf "Car" }) then {
			if !((count (crew (vehicle _source))) isEqualTo 0) then {
				_damage = _orginalDamage;
			};
		};
	};
} else {
	/* Seatbelt System */
	if ((vehicle _unit) isKindOf "Car" && (_source isEqualTo _unit)) then {
		_damage = [
			_damage,
			_damage / 2
		] select (FF_seatbelt);
	};
};

/* 
	Incapacitation System
	Credit: Jack "Scarso" Farhall
*/
if (_damage >= 1) then {
	_damage = 0.99; // They're hurt... 1 or over would kill them...

	// If they're already downed, kill them...
	if (isDowned(_unit)) then {
		// Checks...
		if (isNull _source) exitWith {}; // They can only die if killed by a source...
		if (diag_tickTime - (_unit getVariable ["Incap_time", 0]) < 1) exitWith {}; // Stop really easy executing...
		if (_part in ["arms", "legs", "hands"]) exitWith {}; // Require the shot to hit them in the head or chest to execute them...

		_damage = 1; // Kill them...
	} else {
		if !(alive _unit) exitWith {}; // They're dead??

		[_unit, _source] spawn FF(onIncapacitated); // Event...
		_unit setVariable ["Incap_time", diag_tickTime, true];
	};
};

[] spawn FF_fnc_hudUpdate;
_damage;