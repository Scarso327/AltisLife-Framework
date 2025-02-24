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

private _sellPrice = getNumber (missionConfigFile >> "CfgVirtualItems" >> _item >> "sellPrice");

private _cfg = missionConfigFile >> "CfgVirtualItems" >> _item;
([_item, 0, _sellPrice, !([getNumber (_cfg >> "Settings" >> "isIllegal")] call ULP_fnc_bool)] call ULP_fnc_getSellPrices) params [
	["_sellPrice", _sellPrice, [0]], ["_gangTax", 0, [0]], ["_cartels", [], [[]]]
];

_sellPrice = _sellPrice * _countRemoved;
_gangTax = _gangTax * _countRemoved;

{
	_x params [ "_groupNetId", "_price" ];

	private _group = _groupNetId call BIS_fnc_groupFromNetId;

	if (!isNull _group && { [_group] call ULP_fnc_isGroup }) then {
		[[_group] call ULP_fnc_groupId, round (_price * _countRemoved), true] remoteExecCall ["ULP_SRV_fnc_updateGroupFunds", RSERV];
	};
} forEach _cartels;

if ([] call ULP_fnc_isGroup && { _gangTax > 0 }) then {
	[[] call ULP_fnc_groupId, _gangTax, true] remoteExecCall ["ULP_SRV_fnc_updateGroupFunds", RSERV];
	[format ["You've been given your cut of <t color='#B92DE0'>%1%2</t> for the cargo, earned some group xp and <t color='#B92DE0'>%1%3</t> was taken as tax by your group", "£", [_sellPrice] call ULP_fnc_numberText, [_gangTax] call ULP_fnc_numberText]] call ULP_fnc_hint;
} else {
	[format ["You've been given your cut of <t color='#B92DE0'>%1%2</t> for the cargo and earned some group xp", "£", [_sellPrice] call ULP_fnc_numberText]] call ULP_fnc_hint;
};

[_sellPrice, false, "Cargo Mission Cut"] call ULP_fnc_addMoney;
[(group player), "CargoRun"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];

true