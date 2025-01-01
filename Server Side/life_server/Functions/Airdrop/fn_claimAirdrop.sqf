/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_claimAirdrop";

_this params [
	["_unit", objNull, [objNull]],
	["_airdrop", objNull, [objNull]]
];

if (isNull _unit || { isNull _airdrop }) exitWith {
	if !(isNull _unit) then {
		["OnClaimedAirdrop", ["This airdrop has already been claimed..."]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	};
};

if (_airdrop getVariable ["locked", false]) exitWith {
	["OnClaimedAirdrop", ["The airdrop is still locked, you must break into it before it can be claimed..."]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

deleteVehicle _airdrop;

// Notify everyone else...
["OnClaimedAirdrop", [
	format ["<t color='#ff0000' size='1.5px'>Airdrop Claimed<br/></t><t color='#ffffff' size='1px'>%1 has claimed the airdrop!", name _unit]
]] remoteExecCall ["ULP_fnc_invokeEvent", (allPlayers select { !(_x isEqualType _unit) })];

private _loot = [
	(selectRandom ["GeneralItems"]),
	(1 max (random 5))
] call ULP_fnc_getLoot;

[getPlayerUID _unit, "Loot", ["Airdrop", _loot]] call ULP_SRV_fnc_logPlayerEvent;

// Notify the claimer...
["OnClaimedAirdrop", [
	format [
		"<t color='#ff0000' size='1.5px'>Airdrop Claimed<br/></t><t color='#ffffff' size='1px'>You have claimed this airdrop and recieved:<br/>%1<br/>You can claim these items from your mail box.",
		[getPlayerUID _unit, _loot] call ULP_SRV_fnc_giveLoot
	]
]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];

[(group _unit), "Airdrop"] call ULP_SRV_fnc_addGroupXP;