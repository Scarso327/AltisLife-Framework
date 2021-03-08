/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
scopeName "fn_stripStrings";

_this params [
	["_string", "", ["", []]],
	["_allowedChars", getText (missionConfigFile >> "CfgSettings" >> "allowedCharacters"), [[]]]
];

if (_string isEqualTo "" || { _string isEqualTo [] }) exitWith { _string };
if (_string isEqualType "") then {
	_string = toArray _string;
};

if (_allowedChars isEqualType "") then {
	_allowedChars = toArray _allowedChars;
};

{
	if !(_x in _allowedChars) then {
		_string set [_forEachIndex, nil];
	};
	nil
} forEach _string;

toString (_string select {
   !(isNil "_x")
})