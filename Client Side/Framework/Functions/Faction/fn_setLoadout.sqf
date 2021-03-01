/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setLoadout";

[] call ULP_fnc_stripGear;

private _faction = missionConfigFile >> "CfgFactions" >> ([player] call ULP_fnc_getFaction) >> "Loadout";

// This faction has no loadout...
if !(isClass (_faction)) exitWith {};

private _class = _faction >> "Uniforms";
if (isClass (_class)) then {
	private _uniform = ((("isClass _x" configClasses _class) select {
		isClass (missionConfigFile >> "CfgClothing" >> (configName _x)) && {
			(isText(_x >> "condition") && {
				(call compile getText(_x >> "condition"))
			}) || 
			(getText(_x >> "condition") isEqualTo "")
		}
	}) apply { configName _x });

	if (_uniform isEqualTo []) exitWith {};

	_uniform = (configName (missionConfigFile >> "CfgClothing" >> (selectRandom _uniform)));

	private _textures = ((("isClass _x" configClasses (
		[
			(missionConfigFile >> "CfgClothing" >> _uniform >> "Textures"), 
			(_class >> _uniform >> "Textures")
		] select (isClass (_class >> _uniform >> "Textures"))
	)) select {
		(isText(_x >> "condition") && {
			(call compile getText(_x >> "condition"))
		}) || 
		(getText(_x >> "condition") isEqualTo "")
	}) apply { configName _x });

	player forceAddUniform _uniform;

	if !(_textures isEqualTo []) then {
		private _texture = (_textures select 0); // Always select first as that'll be highest rank if it's a rank based item...

		if !(_texture isEqualTo "") then {
			[player, uniformContainer player, _texture] call ULP_fnc_setTextures;
		};
	};
};

_class = _faction >> "LinkedItems";
if (isClass (_class)) then {
	if (getNumber (_class >> "hasMap") isEqualTo 1) then { player linkItem "ItemMap" };
	if (getNumber (_class >> "hasGPS") isEqualTo 1) then { player linkItem "ItemGPS" };
	if (getNumber (_class >> "hasCompass") isEqualTo 1) then { player linkItem "ItemCompass" };
	if (getNumber (_class >> "hasWatch") isEqualTo 1) then { player linkItem "ItemWatch" };
	if (getNumber (_class >> "hasRadio") isEqualTo 1) then { player linkItem "ItemRadio" };
};