/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_openGroup";

if (ULP_Group_Creating) exitWith {
	hint "You can't currently access this application as it's processing a previous creation request...";
};

if ([] call ULP_fnc_isGroup) then {
	["Group"] call ULP_fnc_setScreen;
} else {
	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), [], [],
		{
			scopeName "fn_creationCheck";

			_this params [
				["_display", displayNull, [displayNull]],
				["_tagText", "", [""]],
				["_nameText", "", [""]]
			];
			
			private _cfg = missionConfigFile >> "CfgGroups";
			private _min = 0;
			private _max = 0;
			private _length = 0;

			{
				_x params ["_text", "_cfgSettings"];

				_min = getNumber (_cfgSettings >> "MinLength");
				_max = getNumber (_cfgSettings >> "MaxLength");
				_length = count _text;

				switch (true) do {
					case (_length < _min): {
						hint format["Your group's %1 must be %2 or more in length...", configName _cfgSettings, _min];
						false breakOut "fn_creationCheck";
					};
					case (_length > _max): {
						hint format["Your group's %1 must be %2 or shorter in length...", configName _cfgSettings, _max];
						false breakOut "fn_creationCheck";
					};
					case (_text in getArray (_cfgSettings >> "Blacklisted")): {
						hint format["Your group's %1 is blacklisted and can't be used...", configName _cfgSettings];
						false breakOut "fn_creationCheck";
					};
				};
			} forEach [
				[_tagText, _cfg >> "Tag"],
				[_nameText, _cfg >> "Name"]
			];

			ULP_Group_Creating = true;

			[player, _tagText, _nameText] remoteExecCall ["ULP_SRV_fnc_createGroup", RSERV];
			true
		}
	] call ULP_fnc_inputGroupInfo;
};