/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogWelcome_OnInit";
disableSerialization;

_this params [ "_display", "_params" ];

if (isNull _display) exitWith {};

_display displaySetEventHandler ["keyDown","_this call ULP_UI_fnc_blockEsc"];

private _info = _display displayCtrl 6001;
private _continueButton = _display displayCtrl 6002;
private _tutorialButton = _display displayCtrl 6003;

_info ctrlSetStructuredText parsetext format [
	"<br /><img image = 'Data\Tags\logo.paa' shadow='0' align='center' size='4.5' /><br /><br />
	Welcome to Mantle's Altis Life.<br /><br />
	Launched in January 2025, our server utilises a fully custom framework to bring a fresh feel to Altis Life in 2025. We're a roleplay server so if you're new we encourage you to read our rules. Failing to follow the rules will see you removed from the server.<br /><br />
	You can get yourself a <t color='#B92DE0'>£500,000</t> starting bonus by signing up to our website and linking your steam account.<br /><br />
	• <a href='https://mantlenetwork.co.uk/' color='#D96600'>Website</a><br />
	• <a href='https://mantlenetwork.co.uk/discord' color='#D96600'>Discord</a>"
];

[_info] call ULP_UI_fnc_setToTextHeight;

if ([] call ULP_fnc_isHobo && { [player, ["Civilian"]] call ULP_fnc_isFaction } && { !ULP_Imprisioned }) exitWith {
	_continueButton ctrlEnable false;

	[[_continueButton, time + 10], {
		_this params ["_continueButton", "_delay"];
		
		if (isNull _continueButton) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

		if (time < _delay) then {
			_continueButton ctrlSetText format["Continue (%1)", [_delay - time, "SS.MS"] call BIS_fnc_secondsToString];
		} else {
			_continueButton ctrlSetText "Continue";
			_continueButton ctrlEnable true;
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
		};
	}] call ULP_fnc_addEachFrame;
};

_tutorialButton ctrlShow false;