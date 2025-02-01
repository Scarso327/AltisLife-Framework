/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_finishCargoRun";

if (canSuspend) exitWith {
    [ULP_fnc_finishCargoRun, _this] call ULP_fnc_directCall;
};

_this params [
	"", // Reward
	["_type", "CorporateFreight", [""]]
];

private _missionCfg = missionConfigFile >> "CfgMissions" >> _type;

if !(_type in ULP_Missions) exitWith {
	[getText (_missionCfg >> "Messages" >> "onFinishWithoutMission")] call ULP_fnc_hint;
	false
};

private _cargoInfo = (ULP_Missions get _type) param [3, [], [[]]];
if (_cargoInfo isEqualTo []) exitWith { false };

_cargoInfo params [
	"_vehicle",
	"",
	"_expectedQuantity"
];

private _item = getText (_missionCfg >> "cargoItem");
(getArray (_missionCfg >> "vehicleRequirement")) params [ "", "_distance" ];

if (isNull _vehicle || { !(alive _vehicle) } || { (player distance _vehicle) > _distance }) exitWith {
	["Your original vehicle has been destroyed or you are too far away from it"] call ULP_fnc_hint;
	false
};

private _countRemoved = [_vehicle, _item] call ULP_fnc_wipeItemFromCargo;

if !(_countRemoved isEqualTo _expectedQuantity) exitWith {
	["Your vehicle didn't have the expected amount of cargo, no reward shall be issued."] call ULP_fnc_hint;
	false
};

private _secondaryReward = getNumber (missionConfigFile >> "CfgVirtualItems" >> _item >> "sellPrice") * _countRemoved;

[_secondaryReward, false, "Cargo Mission Cut"] call ULP_fnc_addMoney;
[(group player), "Freight"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];

[format ["You've been given your cut of <t color='#B92DE0'>%1%2</t> for the cargo and earned some group xp", "£", [_secondaryReward] call ULP_fnc_numberText]] call ULP_fnc_hint;

true