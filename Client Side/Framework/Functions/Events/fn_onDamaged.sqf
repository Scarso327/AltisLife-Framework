/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_onDamaged";

_this params [
    ["_unit", objNull, [objNull]],
    ["_part", "", [""]],
    ["_damage", 0, [0]],
    ["_source", objNull, [objNull]],
    ["_projectile", "", [""]],
    ["_index", 0, [0]],
	["_instigator", objNull, [objNull]]
];

// Get our current damage...
private _originalDamage = ([
	_unit getHit _part,
	damage _unit
] select (_part isEqualTo "")) min 0.99; // Mine ensures we don't somehow get damage of 1 and kill ourselves

// Do quick checks to avoid doing damage when we don't really want to
if ([_unit] call ULP_fnc_onDuty || { [_unit] call ULP_fnc_isKnocked }) exitWith { _originalDamage };

if (!(isNull (objectParent _unit)) && { (vehicle _unit) isKindOf "LandVehicle" }) then {
	private _multiplier = [
		1.25,
		1
	] select (_unit getVariable["seatBelt", false]);

	_damage = (_originalDamage + ((_damage - _originalDamage) * _multiplier)) * ([
		1.1,
		0.9
	] select ((speed (vehicle _unit)) <= 80));
};

if !(isNull _source) then {
	// 1. Check they should actually be able to do this and aren't abusing something
	if ([_source] call ULP_fnc_isKnocked || { [_source] call ULP_fnc_isRestrained }) exitWith { _damage = _originalDamage; };

	// 2. Check for Rubber / Taser as we want it to work with things like quad bikes
	private _weaponNonLethalCfg = missionConfigFile >> "CfgItems" >> (currentWeapon _source) >> "NonLethal";

	if (isClass _weaponNonLethalCfg 
		&& { !isArray (_weaponNonLethalCfg >> "projectiles") 
			|| { _projectile in getArray (_weaponNonLethalCfg >> "projectiles") } }) exitWith {

		private _hasInjuryThreshold = isNumber (_weaponNonLethalCfg >> "injuryThreshold");
		private _hasMetInjuryThreshold = !_hasInjuryThreshold || { _damage >= getNumber (_weaponNonLethalCfg >> "injuryThreshold") };

		if ((_unit distance _source) <= getNumber (_weaponNonLethalCfg >> "distance") 
			&& { _hasMetInjuryThreshold }
			&& { !isNumber (_weaponNonLethalCfg >> "chance")
				|| { random 1 <= getNumber (_weaponNonLethalCfg >> "chance") } }) then {
			[_source, false, getArray (_weaponNonLethalCfg >> "sound")] call ULP_fnc_onKnocked;
		};

		_damage = if !(_hasInjuryThreshold) then {
			_originalDamage
		} else {
			_damage min 0.99
		};
	};

	// 3. Now process anti vdm
	private _sourceVeh = vehicle _source;

	if (_projectile isEqualTo "" && { _sourceVeh isKindOf "LandVehicle" } && { !(_sourceVeh isEqualTo (vehicle _unit)) }) exitWith {
		if (isPlayer _source && { !(diag_tickTime - (_unit getVariable ["vdmVar", 0]) < 2) }) then {
			[format ["You have just been ran over by <t color='#B92DE0'>%1</t>!", name _source]] call ULP_fnc_hint;
		};

		_unit setVariable ["vdmVar", diag_tickTime];

		_damage = _originalDamage;
	};

	// 4. Finally greenzone protection, only stops being shot
	if ([getNumber (missionConfigFile >> "CfgSettings" >> "disabledDamageInGreenzone")] call ULP_fnc_bool && { !(_projectile isEqualTo "") } && { ["greenzone_", [_unit]] call ULP_fnc_isUnitsInZone }) exitWith {
		_damage = _originalDamage;
	};
};

// Stop damage being applied if recently ran over
if (_part isEqualTo "" && { _projectile isEqualTo "" } && { diag_tickTime - (_unit getVariable ["vdmVar", 0]) < 2 }) then { _damage = _orginalDamage };

if (_damage >= 1) then {
	private _isRagDolled = ((animationState _unit) find "unconscious") >= 0;

	if (_isRagDolled && { _part isEqualTo "" } && { _projectile isEqualTo "" } && { isNull _source } && { isNull _instigator }) exitWith { _damage = _orginalDamage };

	_damage = 0.99; // They're hurt... 1 or over would kill them...

	// If they're already downed, kill them...
	if (isDowned(_unit)) then {
		// Checks...
		if (isNull _source || { _projectile isEqualTo "" } || { diag_tickTime - (_unit getVariable ["Incap_time", 0]) < 2 } || { _part in ["arms", "legs", "hands"] }) exitWith {};

		_damage = 1; // Kill them...
	} else {
		if !(alive _unit) exitWith {}; // They're dead??

		[_unit, _source] call ULP_fnc_onIncapacitated; // Event...
		_unit setVariable ["Incap_time", diag_tickTime, true];
	};
};

_damage