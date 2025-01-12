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

(getArray (missionConfigFile >> "CfgBases" >> "Restart")) params [ "_start", "_end" ];

private _bidIncrement = getNumber (missionConfigFile >> "CfgBases" >> "BidIncrement");
private _startingBid = getNumber (missionConfigFile >> "CfgBases" >> "StartingBid");
private _initialBid = _startingBid + _bidIncrement;

player createDiaryRecord ["wiki", ["Gang Bases", format["<br />Gang Wars takes place every week on <font color='#B92DE0'>%1</font> between <font color='#B92DE0'>%2</font> and <font color='#B92DE0'>%3</font>. To participate, you must be in a group, although no limit is placed on group type. The objective is to control a central flag located in the middle of each gang base, which is used for placing bids.<br /><br />The bidding starts at <font color='#B92DE0'>£%4</font>, with increments of <font color='#B92DE0'>£%5</font>. The money for the bids comes from the group's funds, and you must outbid and prevent other groups from placing higher bids to secure control of the base.<br /><br />Winning the bid grants your group full access to nearly all illegal equipment available on the island, as well as a spawn point until the next gang war. The base becomes your gang’s stronghold, providing both resources and strategic advantage for the duration of your reign.",
	getText(missionConfigFile >> "CfgBases" >> "Day"), _start, _end, [_initialBid] call ULP_fnc_numberText, [_bidIncrement] call ULP_fnc_numberText]], taskNull, "NONE", false];

player createDiarySubject ["majorcrimes", "Major Crimes"];

{
	private _crimeStages = configProperties [_x >> "Stages", "isClass _x && { isText (_x >> ""description"") }", true] apply {
		format ["<font face='PuristaSemiBold'>%1</font><br/>%2", getText (_x >> "displayName"), getText (_x >> "description")]
	};

	player createDiaryRecord ["majorcrimes", [getText(_x >> "title"), format [
		"<br />%1<br /><br /><font size='15' face='PuristaSemiBold'>Stages</font><br /><br />%2", 
		getText (_x >> "description"),
		_crimeStages joinString "<br/>"]], taskNull, "NONE", false];
} forEach ("isClass _x && { isText (_x >> ""description"") }" configClasses (missionConfigFile >> "CfgCrimes" >> worldName));

player createDiarySubject ["serverinfo", "Server Info"];

player createDiaryRecord ["serverinfo", ["Links", "<br />
	<font face='PuristaSemiBold'>Website</font><br />
	Link: <font color='#B92DE0'>https://mantlenetwork.co.uk/</font><br /><br />
	<font face='PuristaSemiBold'>Discord</font><br />
	Link: <font color='#B92DE0'>https://mantlenetwork.co.uk/discord</font>"], taskNull, "NONE", false];
