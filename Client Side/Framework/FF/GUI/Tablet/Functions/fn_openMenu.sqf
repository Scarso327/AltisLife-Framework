/*
	@File: fn_openMenu.sqf
  
	@Author: Jack "Scarso" Farhall
  
	@Description: Opens the player menu...
*/
#include "..\..\..\..\script_macros.hpp"
#include "..\macros.hpp"

// A Series of Checks!
if (dialog) exitWith {}; // Dialog Already Active...
if (player getVariable ["restrained", false]) exitWith {}; // We're restrained so NO ACCESS!
if !(alive player) exitWith {}; // We're dead?
if (life_action_inUse) exitWith {}; // We're preforming an action so please no...
if !(isNull (findDisplay IDD_TABLET_MAIN)) exitWith {}; // We are already viewing the tablet?

disableSerialization;

if !(createDialog "RscPlayerMenu") exitWith { systemChat "Failed to create RscLayer...." };
waitUntil { !isNull (findDisplay IDD_TABLET_MAIN) }; // Wait until active...

private _display = findDisplay IDD_TABLET_MAIN;

// Rebind "Escape"
_display displaySetEventHandler ["keyDown","_this call FF_fnc_escapeHandle"];

// Setup Text...
(_display displayCtrl IDC_MAIN_BANK) ctrlSetStructuredText parseText format ["<t align='right'>Bank: £%1</t>",
  [BANK] call life_fnc_numberText
];

(_display displayCtrl IDC_MAIN_CASH) ctrlSetStructuredText parseText format ["<t align='right'>Cash: £%1</t>",
  [CASH] call life_fnc_numberText
];

(_display displayCtrl IDC_MAIN_REP) ctrlSetStructuredText parseText format ["<t align='right'>Reputation: %1</t>",
  [1000] call life_fnc_numberText
];

// Spawn a loop that'll keep our clock updated...
[] spawn {
  for "_i" from 0 to 1 step 0 do {
    if(isNull (findDisplay IDD_TABLET_MAIN)) exitWith {};
    ctrlSetText [IDC_MAIN_CLOCK, [daytime,"HH:MM"] call BIS_fnc_timeToString]; 
    sleep 1; // CPU cycles... We love you...
  };
};

// Setup Application Buttons...
private _appsGrouping = (_display displayCtrl IDC_MAIN_BUTTONS);
private _idc = IDC_MAIN_BUTTONS + 1;

#define BASED_X 0.288594
#define INCREMENT_X 0.113437
#define INCREMENT_Y 0.173

private _currentX = BASED_X - INCREMENT_X;
private _currentY = 0.236;

{
  private _button = _display ctrlCreate ["FF_App_Button", _idc, _appsGrouping];

  _button ctrlSetStructuredText parseText format["<br/><img image='%1' align='center' size='4' color='#808080'/><br/><t align = 'center'>%2</t>",
    getText(_x >> "icon"),
    getText(_x >> "title")
  ];

  private _xValue = _currentX + INCREMENT_X;
  private _yValue = _currentY;

  if (_xValue > 0.628905) then {
    _xValue = BASED_X;
    _currentY = _currentY + INCREMENT_Y;
  };

  _button ctrlSetPosition [
		_xValue * safezoneW + safezoneX,
		_currentY * safezoneH + safezoneY,
		0.108281 * safezoneW,
		0.165 * safezoneH
	];

  _button ctrlSetTooltip getText(_x >> "tooltip");

  _button ctrlSetEventHandler ["ButtonClick", getText(_x >> "onButtonClick")];

  _button ctrlCommit 0;

  _idc = _idc + 1;
  _currentX = _xValue;
} forEach ("[getText(_x >> 'conditions')] call life_fnc_levelCheck" configClasses (missionConfigFile >> "CfgApps"));

[23100, "Home"] call FF(switchApp); // Update UI...