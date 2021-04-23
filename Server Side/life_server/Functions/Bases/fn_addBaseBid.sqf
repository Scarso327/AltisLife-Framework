/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_addBaseBid";

_this params [
	["_unit", objNull, [objNull]],
	["_bid", 0, [0]],
	["_base", "", [""]]
];

private _obj = missionNamespace getVariable [format ["ULP_SRV_Base_%1", _base], objNull];
private _cfg = _obj getVariable ["cfg", configNull];
if (isNull _unit || { _bid < 1 } || { isNull _obj } || { !(isClass _cfg) }) exitWith { false };

if !([getNumber (_cfg >> "includeBidding")] call ULP_fnc_bool) exitWith {
	["BaseBid", ["This base can't be bid on..."]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	false
};

private _expectedBid = (_obj getVariable ["ulp_current_bid_server", getNumber (missionConfigFile >> "CfgBases" >> "StartingBid")]) + getNumber (missionConfigFile >> "CfgBases" >> "BidIncrement");

if !(_expectedBid isEqualTo _bid) exitWith {
	["BaseBid", [format ["Your bid didn't meet the miniumum required bid of %1%2. Someone may have placed a bid just before you...", "£", [_expectedBid] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	false
};

private _group = group _unit;

if !([_group] call ULP_fnc_isGroup) exitWith {
	["BaseBid", ["You must be in a group to place a base bid..."]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

private _funds = (_group getVariable ["group_funds", 0]);
if (_bid > _funds) exitWith {
	["BaseBid", ["Your group can't afford to place this bid..."]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

private _groupId = [_group] call ULP_fnc_groupId;

if (_groupId isEqualTo (_obj getVariable ["current_bidder", -1])) exitWith {
	["BaseBid", ["Your group already has the highest bid..."]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
};

[format ["INSERT INTO base_bids (base, group_id, bid) VALUES ('%1', '%2', '%3');", _base, _groupId, [_bid, ""] call ULP_fnc_numberText], 1] call DB_fnc_asyncCall;

_obj setVariable ["ulp_current_bid_server", _bid];
_obj setVariable ["current_bidder", _groupId];
_obj setVariable ["current_bid", _bid, true];

["BaseBid", [format ["You have successfully placed a bid for %1%2...", "£", [_bid] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
true