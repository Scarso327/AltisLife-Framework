/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_RscIncapacitated_OnEachFrame";

_this params [
	["_display", displayNull, [displayNull]],
	"_startTime", // Time vars...
	["_progressBar", controlNull, [controlNull]],
	["_medicsCountText", controlNull, [controlNull]],
	["_medicalRequestedText", controlNull, [controlNull]]
];

if (isNull _display) exitWith { 
	[_thisEventHandler] call ULP_fnc_removeEachFrame;
};

if !(alive player || { isDowned(player) }) exitWith {
	["RscIncapacitated"] call ULP_UI_fnc_destroyLayer;
};

private _endTime = _display getVariable ["endTime", time + 10];

// My time has come...
if (time >= _endTime) exitWith {
	player setDamage 1;
	["RscIncapacitated"] call ULP_UI_fnc_destroyLayer;
};

_progressBar progressSetPosition (1 - ((time - _startTime) / (_endTime - _startTime)));

private _medicsOnline = count (["Medic"] call ULP_fnc_allMembers);
getArray(missionConfigFile >> "CfgSettings" >> "CfgMedical" >> "AllowBleedoutPercentage") params [ "_bleedOutNoMedics", "_bleedOutMedics" ];

private _respawnPer = [_bleedOutMedics, _bleedOutNoMedics] select (_medicsOnline isEqualTo 0);

if ((progressPosition _progressBar) <= _respawnPer) then {
	if (!ULP_CanRespawn) then {
		ULP_CanRespawn = true;
		_display setVariable ["status", "Press <t color = '#7300e6'>Shift + F</t> to respawn..."];
	};
} else {
	// We've likely been administered blood so we're above the bleedout requirement and so can no longer respawn..
	if (ULP_CanRespawn) then {
		ULP_CanRespawn = false;
		_display setVariable ["status", "Waiting to respawn..."];
	};
};

_medicsCountText ctrlSetStructuredText parseText format [
	"<t align='left' size='1'>%1</t><t align='right' size='1'>Medics Online: %2</t>",
	_display getVariable ["status", "Waiting to respawn..."], _medicsOnline
];

_medicalRequestedText ctrlSetStructuredText parseText ([
	"<t align='center' size='1'>Medic Requested</t>",
	"<t align='center' size='1'>Press <t color='#8A2BE2'>Space</t> to request a medic</t>"
] select (localNamespace getVariable ["ULP_MedicalRequest", 0] < time));