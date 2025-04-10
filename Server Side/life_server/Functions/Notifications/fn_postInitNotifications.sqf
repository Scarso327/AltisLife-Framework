/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_postInitNotifications";

["CrimeBreakIn", {
	_this params [
		["_unit", objNull, [objNull]],
		["_crime", "", [""]]
	];

	if (isNull _unit || { _crime isEqualTo "" }) exitWith {};

	[_crime, format ["%1 is breaking into %2!", [_unit, false, true] call ULP_fnc_getName, _crime]] call ULP_SRV_fnc_sendNotification;
}] call ULP_fnc_addEventHandler;

["PowerRedirected", {
	_this params [
		["_location", objNull, [objNull]],
		["_unit", objNull, [objNull]],
		["_toName", "", [""]]
	];

	private _station = _location getVariable ["powerStation", ""];
	if (_siteName isEqualTo "" || { isNull _unit } || { _station isEqualTo "" }) exitWith {};

	["Power Redirected", format ["%1 has redirected power to %2", name _unit, _toName]] call ULP_SRV_fnc_sendNotification;
}] call ULP_fnc_addEventHandler;

["SiteCaptured", {
	_this params [
		["_location", objNull, [objNull]],
		["_groupTag", "", [""]]
	];

	private _capture = _location getVariable ["site", ""];

	private _cfg = missionConfigFile >> "CfgCapture" >> worldName >> _capture;
	if (isNull _location || { !(isClass _cfg) } || { _groupTag isEqualTo "" }) exitWith {};

	["Site Captured", format ["%1 have captured the %2", _groupTag, getText (_cfg >> "displayName")]] call ULP_SRV_fnc_sendNotification;
}] call ULP_fnc_addEventHandler;

["SiteNeutralised", {
	_this params [
		["_location", objNull, [objNull]]
	];

	private _capture = _location getVariable ["site", ""];

	private _cfg = missionConfigFile >> "CfgCapture" >> worldName >> _capture;
	if (isNull _location || { !(isClass _cfg) }) exitWith {};

	["Site Neutralised", format ["The police have neutralised the %1", getText (_cfg >> "displayName")]] call ULP_SRV_fnc_sendNotification;
}] call ULP_fnc_addEventHandler;

["PowerRedirected", {
	_this params [
		["_location", objNull, [objNull]],
		["_groupTag", "", [""]]
	];

	private _capture = _location getVariable ["site", ""];

	private _cfg = missionConfigFile >> "CfgCapture" >> worldName >> _capture;
	if (isNull _location || { !(isClass _cfg) } || { _groupTag isEqualTo "" }) exitWith {};

	["Site Captured", format ["%1 have captured the %2", _groupTag, getText (_cfg >> "displayName")]] call ULP_SRV_fnc_sendNotification;
}] call ULP_fnc_addEventHandler;

["OnSpawnPopupCartel", { [_this param [0, objNull, [objNull]], "PopupCartel"] call ULP_SRV_fnc_buildEventNotification; }] call ULP_fnc_addEventHandler;
["OnClaimedPopupCartel", { ["Popup Cartel", "A popup cartel has been claimed"] call ULP_SRV_fnc_sendNotification; }] call ULP_fnc_addEventHandler;

["OnSpawnAirdrop", { [_this param [0, objNull, [objNull]], "Airdrop"] call ULP_SRV_fnc_buildEventNotification; }] call ULP_fnc_addEventHandler;
["OnClaimedAirdrop", { ["Airdrop", "The airdrop has been claimed"] call ULP_SRV_fnc_sendNotification; }] call ULP_fnc_addEventHandler;

["OnSpawnShipwreck", { [_this param [0, objNull, [objNull]], "Shipwreck"] call ULP_SRV_fnc_buildEventNotification; }] call ULP_fnc_addEventHandler;
["OnClaimedShipwreck", { ["Shipwreck", "The shipwreck has been claimed"] call ULP_SRV_fnc_sendNotification; }] call ULP_fnc_addEventHandler;

["PvpVoteStarted", { ["PVP Vote", "Voting for the next PVP event has started", "1155CC"] call ULP_SRV_fnc_sendNotification; }] call ULP_fnc_addEventHandler;
["onStartConflict", {
	_this params [
		["_locationCfg", configNull, [configNull]]
	];

	if (isNull _locationCfg) exitWith {};

	private _locationName = getText (_locationCfg >> "displayName");

	["Conflict", format["A Conflict Zone has started at %1", _locationName], "990000"] call ULP_SRV_fnc_sendNotification;
}] call ULP_fnc_addEventHandler;
["onStopConflict", {
	_this params [
		["_group", grpNull, [grpNull]],
		["_score", 0, [0]],
		["_reward", 0, [0]]
	];

	if (isNull _group) exitWith {};

	["Conflict", format["%1 won the conflict with %2 points winning £%3", groupId _group, [_score] call ULP_fnc_numberText, [_reward] call ULP_fnc_numberText]] call ULP_SRV_fnc_sendNotification;
}] call ULP_fnc_addEventHandler;