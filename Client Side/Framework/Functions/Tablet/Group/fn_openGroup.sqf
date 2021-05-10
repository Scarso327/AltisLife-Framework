/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_openGroup";

if !(isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Groups")) exitWith {
	["You don't have access to this!"] call ULP_fnc_hint;
};

if (ULP_Group_Creating) exitWith {
	["You can't currently access this application as it's processing a previous creation request!"] call ULP_fnc_hint;
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
				["_nameText", "", [""]],
				["_type", "", [""]]
			];
			
			private _cfg = missionConfigFile >> "CfgGroups";
			if !(isClass (_cfg >> "Types" >> _type)) exitWith {
				["The selected group type doesn't exist!"] call ULP_fnc_hint;
			};

			{
				_x params ["_text", "_cfgSettings"];

				private _min = getNumber (_cfgSettings >> "MinLength");
				private _max = getNumber (_cfgSettings >> "MaxLength");
				private _length = count _text;

				switch (true) do {
					case (_length < _min): {
						[format["Your group's %1 must be <t color='#B92DE0'>%2 or more</t> in length!", configName _cfgSettings, _min]] call ULP_fnc_hint;
						false breakOut "fn_creationCheck";
					};
					case (_length > _max): {
						[format["Your group's %1 must be <t color='#B92DE0'>%2 or shorter</t> in length!", configName _cfgSettings, _max]] call ULP_fnc_hint;
						false breakOut "fn_creationCheck";
					};
					case (_text in getArray (_cfgSettings >> "Blacklisted")): {
						[format["Your group's %1 is <t color='#B92DE0'>blacklisted</t> and can't be used!", configName _cfgSettings]] call ULP_fnc_hint;
						false breakOut "fn_creationCheck";
					};
				};
			} forEach [
				[_tagText, _cfg >> "Tag"],
				[_nameText, _cfg >> "Name"]
			];

			ULP_Group_Creating = true;

			[player, _tagText, _nameText, _type] remoteExecCall ["ULP_SRV_fnc_createGroup", RSERV];
			true
		}
	] call ULP_fnc_inputGroupInfo;
};