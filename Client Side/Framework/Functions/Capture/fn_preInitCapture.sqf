/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_preInitCapture";

["SiteCaptured", {
	_this params [
		["_location", objNull, [objNull]],
		["_groupTag", "", [""]]
	];

	private _capture = _location getVariable ["site", ""];

	private _cfg = missionConfigFile >> "CfgCapture" >> worldName >> _capture;
	if (isNull _location || { !(isClass _cfg) } || { _groupTag isEqualTo "" }) exitWith {};

	[format [
		"<t color='#ff0000' size='1.5px'>Site Captured<br/></t><t color='#ffffff' size='1px'><t color='#B92DE0'>%1</t> have captured the <t color='#B92DE0'>%2</t>.",
		_groupTag, getText (_cfg >> "displayName")
	]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;

["SiteNeutralised", {
	_this params [
		["_location", objNull, [objNull]]
	];

	private _capture = _location getVariable ["site", ""];

	private _cfg = missionConfigFile >> "CfgCapture" >> worldName >> _capture;
	if (isNull _location || { !(isClass _cfg) }) exitWith {};

	[format [
		"<t color='#ff0000' size='1.5px'>Site Neutralised<br/></t><t color='#ffffff' size='1px'>The police have neutralised the <t color='#B92DE0'>%1</t>.",
		getText (_cfg >> "displayName")
	]] call ULP_fnc_hint;
}] call ULP_fnc_addEventHandler;