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
		private _texs = (("true" configClasses (missionConfigFile >> "CfgTags" >> "Tags" >> "Whitelisting" >> _faction >> _x)) apply { (configName _x) });
		reverse _texs;

		{
			private _icons = (format["(configName _x) isEqualTo ""%1"" && { call compile getText(_x >> ""condition"") }", _x] configClasses (missionConfigFile >> "CfgTags" >> "Icons"));
			
			if !(_icons isEqualTo []) exitWith {
				_icon = getText((_icons select 0) >> "icon");
				_subtitle = getText((_icons select 0) >> "subtitle");
				breakOut "fn_setTags_Loop";
			};
			nil
		} count _texs;
		nil
	} count ((configProperties [(missionConfigFile >> "CfgFactions" >> _faction >> "Whitelisting"), format["isClass (missionConfigFile >> ""CfgTags"" >> ""Tags"" >> ""Whitelisting"" >> ""%1"" >> (configName _x))", _faction]]) apply { (configName _x) });
};

if (_subtitle isEqualTo "") then {
	_subtitle = getText(missionConfigFile >> "CfgFactions" >> _faction >> "displayName");
};

player setVariable ["icon", _icon, true];
player setVariable ["subtitle", _subtitle, true];

private _title = profileNamespace getVariable ["selected_title", ""];
if (isClass (missionConfigFile >> "CfgTitles" >> _title)) then {
	player setVariable ["title", _title, true];
} else {
	player setVariable ["title", nil, true];
};