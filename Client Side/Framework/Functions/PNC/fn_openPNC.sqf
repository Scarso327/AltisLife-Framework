/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_openPNC";

if (canSuspend) exitWith {
    [ULP_fnc_openPNC, _this] call ULP_fnc_directCall;
};

if (time < (player getVariable ["pnc_cd", 0])) exitWith {
	["You've been locked out of the PNC temporarily..."] call ULP_fnc_hint;
};

if ([player] call ULP_fnc_isRestrained) exitWith {
	["You cannot access this while restrained!"] call ULP_fnc_hint;
};

if (createDialog "DialogPNC") then {
	private _display = findDisplay 4700;

	(_display displayCtrl 4701) ctrlSetStructuredText parseText format ["Police National Computer<t align='right'>Threat Level: %1</t>",
		getArray (missionConfigFile >> "CfgSettings" >> "threatLevels") select (call (missionNamespace getVariable ["ULP_SRV_Setting_ThreatLevel", {0}]))
	];

	private _login = _display displayCtrl 4702;
	private _main = _display displayCtrl 4703;

	_login ctrlShow true;
	_main ctrlShow false;

	(_display displayCtrl 4704) ctrlShow false;
	(_display displayCtrl 4705) ctrlShow false;

	private _userInput = _login controlsGroupCtrl 101;
	private _passInput = _login controlsGroupCtrl 102;

	_userInput ctrlEnable false;
	_passInput ctrlEnable false;

	[_display, _login, _main, _userInput, _passInput] spawn {
		_this params [ "_display", "_login", "_main", "_user", "_pass" ];

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

		private _filter = _main controlsGroupCtrl 105;
		private _list = _main controlsGroupCtrl 106;

		[_filter, _list] call BIS_fnc_initListNBoxSorting;

		_display setVariable ["WarrantsRetrievedEvent", ["WarrantsRetrieved", { _this call ULP_fnc_listWarrants; }] call ULP_fnc_addEventHandler];
		[] remoteExecCall ["ULP_SRV_fnc_fetchWarrants", RSERV];
	};
};