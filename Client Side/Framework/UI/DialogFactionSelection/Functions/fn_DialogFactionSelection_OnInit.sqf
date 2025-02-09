/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"

#define IDD_FACTION_SELECTION 		5800
#define IDC_MAIN_SPOTLIGHT_PICTURE	1023
#define IDC_MAIN_SPOTLIGHT_VIDEO	1024
#define IDC_MAIN_SPOTLIGHT_HOVER	1025
#define IDC_MAIN_SPOTLIGHT_BUTTON	1026
#define IDC_MAIN_SPOTLIGHT_ACTION	1027
#define IDC_MAIN_SPOTLIGHT_TEXT		1028
#define IDC_MAIN_SPOTLIGHT_TEXTBCG	1029

scopeName "fn_DialogFactionSelection_OnInit";
disableSerialization;

_this params [ "_display" ];

if (isNull _display) exitWith {};

private _factionIdc = IDD_FACTION_SELECTION + 1;

{
	private _ctrlGroup = _display ctrlCreate ["ULP_RscMainMenuSpotlight", _factionIdc];

	// Hard coded for 4 factions
	// Lazy but works
	private _xPos = switch (_forEachIndex) do {
		case 0: { 0.5 - (2 * 10) * (pixelW * pixelGridNoUIScale * 2) - (4 * pixelW) };
		case 1: { 0.5 - (1 * 10) * (pixelW * pixelGridNoUIScale * 2) - (2 * pixelW) };
		case 2: { 0.5 };
		default { 0.5 + (1 * 10) * (pixelW * pixelGridNoUIScale * 2) + (2 * pixelW) };
	};

	private _currentPosition = ctrlPosition _ctrlGroup;
	_currentPosition set [0, _xPos];

	_ctrlGroup ctrlSetPosition _currentPosition;

	_ctrlGroup ctrlSetFade 0;
	_ctrlGroup ctrlcommit 0.1;

	private _ctrlText = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_TEXT;
	private _text = toUpper getText (_x >> "shortName");

	_ctrlText ctrlSetStructuredText parseText _text;

	private _ctrlTextHeight = ctrlTextHeight _ctrlText;
	private _ctrlTextPos = ctrlPosition _ctrlText;

	_ctrlTextPos set [1, ((ctrlPosition _ctrlGroup select 3) - _ctrlTextHeight) / 2];
	_ctrlTextPos set [3, _ctrlTextHeight];

	_ctrlText ctrlSetPosition _ctrlTextPos;
	_ctrlText ctrlCommit 0;
	_ctrlText ctrlEnable false;
	_ctrlText setVariable ["pos", _ctrlTextPos];

	private _ctrlPicture = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
	_ctrlPicture ctrlSetText getText (_x >> "selectionImage");

	private _ctrlVideo = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_VIDEO;
	_ctrlVideo ctrlSetText getText (_x >> "selectionVideo");

	private _ctrlButton = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_BUTTON;

	_ctrlButton setVariable ["display", _display];
	_ctrlButton setVariable ["faction", configName _x];
	
	_ctrlButton ctrlSetEventHandler ["ButtonClick", "_this call ULP_UI_fnc_DialogFactionSelection_Select"];

	{
		_ctrlButton ctrlAddEventHandler [
			_x,
			{
				private _ctrlButton = _this select 0;
				private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
				private _ctrlPicture = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
				private _ctrlHover = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_HOVER;
				private _ctrlGroupPos = ctrlPosition _ctrlGroup;

				_ctrlHover ctrlSetFade 0;
				_ctrlHover ctrlCommit 0.1;

				[ctrlParentControlsGroup _ctrlPicture, true] call ULP_UI_fnc_DialogFactionSelection_PlayVideo;
			}
		];
	} forEach ["mouseEnter","setFocus"];

	{
		_ctrlButton ctrlAddEventHandler [
			_x,
			{
				private _ctrlButton = _this select 0;
				private _ctrlGroup = ctrlParentControlsGroup _ctrlButton;
				private _ctrlPicture = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
				private _ctrlHover = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_HOVER;
				private _ctrlGroupPos = ctrlPosition _ctrlGroup;

				_ctrlPicture ctrlSetTextColor [1, 1, 1, 1];

				_ctrlHover ctrlSetFade 1;
				_ctrlHover ctrlCommit 0.1;

				[_ctrlGroup, false] call ULP_UI_fnc_DialogFactionSelection_PlayVideo;
			}
		];
	} foreach ["mouseExit","killFocus"];

	_factionIdc = _factionIdc + 1;
} forEach ("isClass _x" configClasses (missionConfigFile >> "CfgFactions"));