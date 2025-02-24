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

if (_item isEqualTo (missionNamespace getVariable ["ULP_SRV_Setting_BuffedItem", ""])) then { _secondaryReward = _secondaryReward * getNumber(missionConfigFile >> "CfgSettings" >> "buffedSellIncrease"); };
if (["ULP_SRV_Setting_DonationGoal"] call ULP_fnc_constant) then { _secondaryReward = _secondaryReward * getNumber(missionConfigFile >> "CfgSettings" >> "DonationRewards" >> "sellIncrease"); };

if (_isLegal) then {
	_secondaryReward = ["LegalTrader", _secondaryReward, false] call ULP_fnc_activatePerk;
	_secondaryReward = [_secondaryReward] call ULP_fnc_taxPrice;
} else {
	_secondaryReward = ["ShadyTrader", _secondaryReward, false] call ULP_fnc_activatePerk;

	{
		private _object = missionNamespace getVariable [format["ULP_SRV_Cartel_%1", configName _x], objNull];

		if !(isNull _object) then {
			private _owner = (_object getVariable ["owner", []]) param [0, grpNull];
			if !(isNull _owner) then {
				if (isClass (_x >> "Drug")) then {
					if (_owner isEqualTo (group player)) then {
						_secondaryReward = _secondaryReward * getNumber (_x >> "Drug" >> "extraPay");
					} else {
						private _tax = _secondaryReward * getNumber (_x >> "Drug" >> "saleTax");
						_cartelTaxes pushBack [_owner, _tax];
						_secondaryReward = _secondaryReward - _tax;
					};
				};
			};
		};
	} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgCartels" >> "Fixed"));
};

private _gangTax = _secondaryReward * ([] call ULP_fnc_groupTax);

if ([] call ULP_fnc_isGroup && { _gangTax > 0 }) then {
	_secondaryReward = _secondaryReward - _gangTax;
	
	[group player, _gangTax, true] remoteExecCall ["ULP_SRV_fnc_handleGroupFunds", RSERV];
	[format ["You've been given your cut of <t color='#B92DE0'>%1%2</t> for the cargo, earned some group xp and <t color='#B92DE0'>%1%3</t> was taken as tax by your group", "£", [_secondaryReward] call ULP_fnc_numberText, [_gangTax] call ULP_fnc_numberText]] call ULP_fnc_hint;
} else {
	[format ["You've been given your cut of <t color='#B92DE0'>%1%2</t> for the cargo and earned some group xp", "£", [_secondaryReward] call ULP_fnc_numberText]] call ULP_fnc_hint;
};

[_secondaryReward, false, "Cargo Mission Cut"] call ULP_fnc_addMoney;
[(group player), "CargoRun"] remoteExecCall ["ULP_SRV_fnc_addGroupXP", RSERV];

true