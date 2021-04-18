/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_setTags";

private _icon = "";
private _subtitle = "";

private _faction = [player] call ULP_fnc_getFaction;
private _tagCfg = missionConfigFile >> "CfgTags" >> "Tags" >> "Whitelisting" >> _faction;

if (isClass(missionConfigFile >> "CfgFactions" >> _faction >> "Groups") && { [] call ULP_fnc_isGroup }) then {
	_subtitle = [] call ULP_fnc_getGroupName;
};

if (isClass _tagCfg) then {
	{
		scopeName "fn_setTags_Loop";
		private _texs = getArray (missionConfigFile >> "CfgTags" >> "Tags" >> "Whitelisting" >> _faction >> _x);
		private _level = (call (missionNamespace getVariable [format ["%1_%2", _faction, _x], {0}]));

		if (_level > 0 && { _level < (count _texs) }) then {
			private _iconCfg = missionConfigFile >> "CfgTags" >> "Icons" >> (_texs select _level);
			if (isClass _iconCfg && { call compile getText (_iconCfg >> "condition") }) then {
				_icon = getText(_iconCfg >> "icon");
				_subtitle = getText(_iconCfg >> "subtitle");
				breakOut "fn_setTags_Loop";
			};
		};
		nil
	} count ((configProperties [(missionConfigFile >> "CfgFactions" >> _faction >> "Whitelisting"), format["isArray (missionConfigFile >> ""CfgTags"" >> ""Tags"" >> ""Whitelisting"" >> ""%1"" >> (configName _x))", _faction]]) apply { (configName _x) });
};

if ([player] call ULP_fnc_onDuty) then {
	_icon = getText(missionConfigFile >> "CfgTags" >> "Icons" >> "Admin" >> "icon");
	_subtitle = getText(missionConfigFile >> "CfgTags" >> "Icons" >> "Admin" >> "subtitle");
};

if (_subtitle isEqualTo "") then {
	_subtitle = getText(missionConfigFile >> "CfgFactions" >> _faction >> "displayName");
};

private _profile_icon = profileNamespace getVariable ["selected_icon", ""];
if (_icon isEqualTo "" && { !(_profile_icon isEqualTo "") }) then {
	_icon = getText(missionConfigFile >> "CfgTags" >> "Icons" >> _profile_icon >> "icon");
};

player setVariable ["icon", _icon, true];
player setVariable ["subtitle", _subtitle, true];

private _title = missionConfigFile >> "CfgTitles" >> (profileNamespace getVariable ["selected_title", ""]);
if (isClass _title && { !([player] call ULP_fnc_onDuty) }) then {
	player setVariable ["title", getText (_title >> "displayName"), true];
} else {
	player setVariable ["title", nil, true];
};

private _colour = profileNamespace getVariable ["selected_name_colour", ""];
if !(_colour isEqualTo "") then {
	if (_colour isEqualTo ([player] call ULP_fnc_getTagColour)) then {
		player setVariable ["colour", nil, true];
	} else {
		player setVariable ["colour", _colour, true];
	};
};