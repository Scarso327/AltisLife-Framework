/*
** Author: Jack "Scarso" Farhall
** Description: https://github.com/ConnorAU/SQFDiscordEmbedBuilder
*/
#include "\life_server\script_macros.hpp"
scopeName "fn_sendNotification";

if (isNil "DiscordEmbedBuilder_fnc_buildSqf") exitWith { false };

_this params [
	["_title", "", [""]],
	["_message", "", [""]],
	["_colour", "00FF00", [""]],
	["_image", "https://mantlenetwork.co.uk/_next/image?url=%2Flogos%2Fapple-icon-180.png&w=96&q=75", [""]]
];

if (_title isEqualTo "" || { _message isEqualTo "" } || { _colour isEqualTo "" } || { _image isEqualTo "" }) exitWith { false };

[  
	"Default", "", "", "", false,  
	[  
		[  
			_title,  
			_message,  
			"",  
			_colour,  
			true,  
			_image
		]  
	]  
] call DiscordEmbedBuilder_fnc_buildSqf;

true