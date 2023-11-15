/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_finishFreight";

if (canSuspend) exitWith {
    [ULP_fnc_finishFreight, _this] call ULP_fnc_directCall;
};

if !("CorporateFreight" in ULP_Missions) exitWith {
	[getText (missionConfigFile >> "CfgMissions" >> "CorporateFreight" >> "Messages" >> "onFinishWithoutMission")] call ULP_fnc_hint;
	false
};

(missionNamespace getVariable ["ULP_FreightVehicle", [objNull, 0]]) params [
	"_vehicle",
	"_expectedQuantity"
];

if (isNull _vehicle || { !(alive _vehicle) } || { (player distance _vehicle) > 15 }) exitWith {
	["Your original vehicle has been destroyed or you are too far away from it"] call ULP_fnc_hint;
	false
};

private _countRemoved = [_vehicle, "FreightCargo"] call ULP_fnc_wipeItemFromCargo;

if !(_countRemoved isEqualTo _expectedQuantity) exitWith {
	["Your vehicle didn't have the expected amount of freight, no reward shall be issued."] call ULP_fnc_hint;
	false
};

private _secondaryReward = getNumber (missionConfigFile >> "CfgVirtualItems" >> "FreightCargo" >> "sellPrice") * _countRemoved;

[_secondaryReward, false, "Freight Mission Cut"] call ULP_fnc_addMoney;
[(group player), "Freight"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];

[format ["You've been given your cut of %1%2 for the freight and earned some group xp", "£", [_secondaryReward] call ULP_fnc_numberText]] call ULP_fnc_hint;

true