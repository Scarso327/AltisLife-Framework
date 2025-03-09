/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_onPlayerKilled";

_this params [
	"_unit", "_killer", "_instigator"
];

private _isWounded = _unit getVariable ["Wounded", false];
private _wasKilledByPolice = ((group _killer) getVariable ["faction", ""]) isEqualTo "Police";

if ([_unit, ["Civilian"]] call ULP_fnc_isFaction && { _wasKilledByPolice }) then {
	[getPlayerUID _unit] call ULP_SRV_fnc_clearWarrants;
};

// Notify the server...
if (isNull _killer || { (getPlayerUID _unit) isEqualTo (getPlayerUID _killer) } || { !(_killer isKindOf "Man") }) then {
	[["Bleedout", "Suicide"] select (_isWounded), [[_unit, false, true] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
	[getPlayerUID _unit, "Bleedout", [getPos _unit, getUnitLoadout _unit, _isWounded]] call ULP_SRV_fnc_logPlayerEvent;
} else {
	if ([_killer, ["Civilian"]] call ULP_fnc_isFaction) then {
		[
			getPlayerUID _killer, 
			"OffencesAct", 
			"S1", 
			format ["Suspected Weapon: %1", ([currentWeapon _killer] call ULP_fnc_itemCfg) param [5, "Unknown"]]
		] call ULP_SRV_fnc_addWarrant;
	};

	[["Executed", "Killed"] select (_isWounded), [[_unit, false, true] call ULP_fnc_getName, [_killer, false, true] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
	[getPlayerUID _unit, "Executed", [getPlayerUID _killer, getPos _unit, getUnitLoadout _unit, _isWounded]] call ULP_SRV_fnc_logPlayerEvent;

	if (["capture_cartel_", [_unit, _killer]] call ULP_fnc_isUnitsInZone) then {
		[_unit, _killer] call ULP_SRV_fnc_onCartelKill;	
	} else {
		
		// Not Police or unarmed = hurt rep
		private _shouldHurtRep = (!([player, ["Police"]] call ULP_fnc_isFaction) || { (currentWeapon _unit) isEqualTo "" });

		if (_shouldHurtRep) then {
			private _unitRep = _unit getVariable ["reputation", 0];

			[_killer, missionConfigFile >> "CfgReputation" >> "Types" >> (switch (true) do {
				case (_unitRep >= 500): { "ExecuteHigh" };
				case (_unitRep > -500): { "ExecuteNorm" };
				default { "ExecuteLow" };
			})] call ULP_SRV_fnc_reputation;
		};
	};
};
