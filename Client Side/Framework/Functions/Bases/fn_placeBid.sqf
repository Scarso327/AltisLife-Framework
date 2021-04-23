/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_placeBid";

_this params [
	["_base", "", [""]]
];

if (!([player, ["Civilian"]] call ULP_fnc_isFaction) || { [] call ULP_fnc_isUndercover }) exitWith {
	["Only civilians can place base bids..."] call ULP_fnc_hint;
};

if !([] call ULP_fnc_isGroup) exitWith {
	["You must be in a group to place a bid on a group base..."] call ULP_fnc_hint;
};

private _obj = missionNamespace getVariable [format ["ULP_SRV_Base_%1", _base], objNull];
if (isNull _obj) exitWith {
	["An error occured while attempting to place a bid..."] call ULP_fnc_hint;
};

private _bid = (_obj getVariable ["current_bid", getNumber (missionConfigFile >> "CfgBases" >> "StartingBid")]) + getNumber (missionConfigFile >> "CfgBases" >> "BidIncrement");

if (_bid > ([] call ULP_fnc_groupFunds)) exitWith {
	[format ["The next bid is %1%2, your group funds can't afford this...", "£", [_bid] call ULP_fnc_numberText]] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "Confirmation", ["Confirm", "Cancel"],
	format ["Are you sure you want to place a bid of %1%2...", "£", [_bid] call ULP_fnc_numberText], [_bid, _base],
	{	
		_this params [ "_bid", "_base" ];
		
		if (player getVariable ["bidding", false]) exitWith {
			["You're already placing a bid!"] call ULP_fnc_hint;
		};

		player setVariable ["bidding", true];

		["BaseBid", {
			[_this param [0, "You have successfully placed a bid for this base..."]] call ULP_fnc_hint;
			player setVariable ["bidding", nil];
		}, true] call ULP_fnc_addEventHandler;

		["Placing Bid..."] call ULP_fnc_hint;
		[player, _bid, _base] remoteExecCall ["ULP_SRV_fnc_addBaseBid", RSERV];
	}, false
] call ULP_fnc_confirm;