/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_getName";

_this params [
	["_object", objNull, [objNull]],
	["_checkMask", false, [true]]
];

if (_object isKindOf "Man" && { isPlayer _object }) exitWith {
	private _name = [
		_object getVariable ["name", name _object], 
		"Masked Player"
	] select (_checkMask && { [goggles _object] call ULP_fnc_isMask || [headgear _object] call ULP_fnc_isMask });

	if ([player, ["Police", "Hato", "Medic"]] call ULP_fnc_isFaction) then {
		_name = format ["[%1] %2", getText (missionConfigFile >> "CfgFaction" >> ([player] call ULP_fnc_getFaction) >> "shortName"), _name];
	} else {
		private _tag = [] call ULP_fnc_groupTag;
		if ([] call ULP_fnc_isGroup && { !(_tag isEqualTo "") }) then {
			_name = format ["%1 %2", _tag, _name];
		};
	};

	_name
};

_object getVariable ["name", ""];