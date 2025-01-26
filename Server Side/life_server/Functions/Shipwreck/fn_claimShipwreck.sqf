/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_claimShipwreck";

_this params [
	["_unit", objNull, [objNull]],
	["_shipwreck", objNull, [objNull]]
];

if (isNull _unit || { isNull _shipwreck }) exitWith {
	if !(isNull _unit) then {
		["OnClaimedShipwreck", ["This shipwreck has already been claimed..."]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	};
};

if (_shipwreck getVariable ["locked", false]) exitWith {
	["OnClaimedShipwreck", ["The shipwreck is still locked, you must break into it before it can be claimed..."]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

deleteVehicle _shipwreck;

// Notify everyone else...
["OnClaimedShipwreck", [
	format ["<t color='#ff0000' size='1.5px'>Shipwreck Claimed<br/></t><t color='#ffffff' size='1px'>%1 has claimed the shipwreck!", name _unit]
]] remoteExecCall ["ULP_fnc_invokeEvent", (allPlayers select { !(_x isEqualType _unit) })];

if ([_unit, ["Civilian"]] call ULP_fnc_isFaction) then {
	private _loot = [
		(selectRandom ["GeneralItems"]),
		(1 max (random 3))
	] call ULP_fnc_getLoot;

	[getPlayerUID _unit, "Loot", ["Shipwreck", _loot]] call ULP_SRV_fnc_logPlayerEvent;

	// Notify the claimer...
	["OnClaimedShipwreck", [
		format [
			"<t color='#ff0000' size='1.5px'>Shipwreck Claimed<br/></t><t color='#ffffff' size='1px'>You have claimed this shipwreck and recieved:<br/>%1<br/>You can claim these items from your mail box.",
			[getPlayerUID _unit, _loot] call ULP_SRV_fnc_giveLoot
		]
	]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
} else {
	["OnClaimedShipwreck", [
		"<t color='#ff0000' size='1.5px'>Shipwreck Claimed<br/></t><t color='#ffffff' size='1px'>You have destroyed the shipwreck!"
	]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

[(group _unit), "Shipwreck"] call ULP_SRV_fnc_addGroupXP;