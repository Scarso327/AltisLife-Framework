/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_initBriefing";

if (isServer) exitWith {};

waitUntil { !isNull player && { local player } };

player createDiarySubject ["controls", "Controls"];

player createDiaryRecord ["controls", ["Vehicle Controls", "<br />
	<font face='PuristaSemiBold'>Toggle Vehicle / Door Locks</font><br />
	Key: <font color='#B92DE0'>U</font><br /><br />
	<font face='PuristaSemiBold'>Toggle Vehicle Sirens On</font><br />
	Key: <font color='#B92DE0'>Left Shift + F</font><br /><br />
	<font face='PuristaSemiBold'>Toggle Vehicle Sirens Sound</font><br />
	Key: <font color='#B92DE0'>Left Control + F</font><br /><br />
	<font face='PuristaSemiBold'>Toggle Vehicle Lights On</font><br />
	Key: <font color='#B92DE0'>Left Shift + L</font>"], taskNull, "NONE", false];

player createDiaryRecord ["controls", ["General Controls", "<br />
	<font face='PuristaSemiBold'>User Interaction</font><br />
	Key: <font color='#B92DE0'>Left Windows</font> or <font color='#B92DE0'>Custom Controls > User Action 10</font><br /><br />
	<font face='PuristaSemiBold'>Open Tablet</font><br />
	Key: <font color='#B92DE0'>Y</font><br /><br />
	<font face='PuristaSemiBold'>Open Virtual Inventories</font><br />
	Key: <font color='#B92DE0'>T</font><br /><br />
	<font face='PuristaSemiBold'>Toggle Surrender</font><br />
	Key: <font color='#B92DE0'>Left Shift + B</font><br /><br />
	<font face='PuristaSemiBold'>Toggle Holster</font><br />
	Key: <font color='#B92DE0'>Left Shift + H</font><br /><br />
	<font face='PuristaSemiBold'>Knockout Player</font><br />
	Key: <font color='#B92DE0'>Left Shift + G</font><br /><br />
	<font face='PuristaSemiBold'>Panic Button</font><br />
	Key: <font color='#B92DE0'>Left Shift + J</font>"], taskNull, "NONE", false];

player createDiarySubject ["wiki", "Wiki"];

private _licenses = configProperties [missionConfigFile >> "CfgLicenses", "isClass _x && { isText (_x >> ""displayName"") } && { getNumber (_x >> ""buyPrice"") > 0 }", true] apply {
	format [
		"<font face='PuristaSemiBold'>%1</font><br/><font color='#B92DE0'>£%2</font>", getText (_x >> "displayName"), [getNumber (_x >> "buyPrice")] call ULP_fnc_numberText]
};

player createDiaryRecord ["wiki", ["Licenses", format ["<br />%1", _licenses joinString "<br/>"]], taskNull, "NONE", false];
