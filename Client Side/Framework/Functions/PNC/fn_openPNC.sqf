/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openPNC";

if (time < (player getVariable ["pnc_cd", 0])) exitWith {};

if (createDialog "DialogPNC") then {
	private _display = findDisplay 4700;

	(_display displayCtrl 4701) ctrlSetStructuredText parseText format ["Police National Computer<t align='right'>Threat: %1</t>",
		getArray (missionConfigFile >> "CfgSettings" >> "threatLevels") select (call (missionNamespace getVariable ["ULP_SRV_Setting_ThreatLevel", {0}]))
	];

	private _login = _display displayCtrl 4702;
	private _main = _display displayCtrl 4703;

	_login ctrlShow true;
	_main ctrlShow false;

	private _userInput = _login controlsGroupCtrl 101;
	private _passInput = _login controlsGroupCtrl 102;

	_userInput ctrlEnable false;
	_passInput ctrlEnable false;

	[_login, _main, _userInput, _passInput] spawn {
		_this params [ "_login", "_main", "_user", "_pass" ];

		uiSleep 0.5;

		_user ctrlEnable true;

		private _keyStroke = 1 / (count profileName);
		for "_i" from 0 to (count profileName) do {
			_user ctrlSetText (profileName select [0, _i]);
			uiSleep _keyStroke;
		};

		private _loggedIn = false;

		for "_i" from 0 to (1 max (round (random 5))) do {
			_user ctrlEnable true;
			_pass ctrlEnable true;

			private _passCount = (random 16) max 6;
			_keyStroke = 1 / _passCount;
			_pass ctrlSetText "";
			for "_i" from 0 to _passCount do {
				_pass ctrlSetText format["%1*", ctrlText _pass];
				uiSleep _keyStroke;
			};

			uiSleep 0.2;

			_user ctrlEnable false;
			_pass ctrlEnable false;

			uiSleep 0.2;

			if ([player, ["Police"]] call ULP_fnc_isFaction || { (random 1) >= 0.8 }) exitWith {
				_loggedIn = true;
			};
		};

		if !(_loggedIn) exitWith {
			["You failed to break into the PNC..."] call ULP_fnc_hint;
			player setVariable ["pnc_cd", time + 30];
			closeDialog 0;
		};

		_login ctrlShow false;
		_main ctrlShow true;
	};
};