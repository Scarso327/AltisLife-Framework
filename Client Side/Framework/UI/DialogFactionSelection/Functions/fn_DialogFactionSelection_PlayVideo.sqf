/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogFactionSelection_PlayVideo";

#define IDC_MAIN_SPOTLIGHT_PICTURE	1023
#define IDC_MAIN_SPOTLIGHT_VIDEO	1024
#define IDC_MAIN_SPOTLIGHT_HOVER	1025
#define IDC_MAIN_SPOTLIGHT_BUTTON	1026
#define IDC_MAIN_SPOTLIGHT_ACTION	1027
#define IDC_MAIN_SPOTLIGHT_TEXT		1028
#define IDC_MAIN_SPOTLIGHT_TEXTBCG	1029

_this params [ "_ctrlGroup", "_play" ];

if (isNull _ctrlGroup) exitWith {};

private _ctrlPicture = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_PICTURE;
private _ctrlVideoSource = _ctrlGroup controlsGroupCtrl IDC_MAIN_SPOTLIGHT_VIDEO;
private _file = ctrlText _ctrlVideoSource;

if (_file isEqualTo "") exitwith {};

[_ctrlGroup controlsGroupCtrl 222] spawn {
	disableSerialization;
	ctrlDelete (_this select 0);
};

private _ctrlVideo = controlNull;

if (_play) then {
	_ctrlVideo = (ctrlParent _ctrlGroup) ctrlCreate ["Life_RscVideo", 222, _ctrlGroup];

	_ctrlVideo ctrlSetText _file;
	_ctrlVideo ctrlSetPosition ctrlPosition _ctrlVideoSource;
	_ctrlVideo ctrlCommit 0;
	_ctrlVideo ctrlEnable false;

	_ctrlPicture ctrlSetTextColor [0,0,0,1];
	_ctrlPicture ctrlSetPosition ctrlPosition _ctrlVideoSource;
	_ctrlPicture ctrlCommit 0;

	_ctrlVideo ctrladdeventhandler [
		"videoStopped",
		{
			[ctrlParentControlsGroup (_this select 0), true] call ULP_UI_fnc_DialogFactionSelection_PlayVideo;
		}
	];
};