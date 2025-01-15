/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_knockOut";

_this params [
	["_target", cursorObject, [objNull]]
];

// Checks...
if (isNull _target 
	|| { !(isPlayer _target) }
	|| { _target isEqualTo player }
	|| { (_target distance player) >= 3 }
	|| { isDowned(_target) }
	|| { isDowned(player) }
	|| { time <= missionNamespace getVariable["ULP_KnockOut_Cooldown", 0] }
	|| { [player] call ULP_fnc_isRestrained || { [player] call ULP_fnc_isKnocked } || { [_target] call ULP_fnc_isKnocked } }
	|| { !(isNull (objectParent player)) }
	|| { !(isNull (objectParent _target)) }
	|| { [_target] call ULP_fnc_onDuty }
	|| { [getNumber (missionConfigFile >> "CfgSettings" >> "disabledDamageInGreenzone")] call ULP_fnc_bool && { ["greenzone_", [_target]] call ULP_fnc_isUnitsInZone } }
) exitWith { false };

if ([player, "AwopPercMstpSgthWrflDnon_End2"] call ULP_fnc_switchMove) exitWith {
	missionNamespace setVariable["ULP_KnockOut_Cooldown", time + 5];

	[0.08, _target, { [player] remoteExecCall ["ULP_fnc_onKnocked", _this] }] call ULP_fnc_waitExecute;
	["KnockOut"] call ULP_fnc_achieve;

	if ([player, ["Civilian"]] call ULP_fnc_isFaction) then {
		[getPlayerUID player, "OffencesAgainstThePerson", "Section20",
			format [
				"Suspected Weapon: %1", 
				([currentWeapon player] call ULP_fnc_itemCfg) param [5, "Unknown"]
			]
		] remoteExecCall ["ULP_SRV_fnc_addWarrant", RSERV];
	};

	private _shouldHurtRep = (!([player, ["Police"]] call ULP_fnc_isFaction));
	if (_shouldHurtRep) then {
		private _unitRep = _target getVariable ["reputation", 0];
		[player, missionConfigFile >> "CfgReputation" >> "Types" >> (switch (true) do {
			case (_unitRep >= 500): { "AssaultHigh" };
			default { "AssaultNorm" };
		})] call ULP_SRV_fnc_reputation;
	};

	true
};

false