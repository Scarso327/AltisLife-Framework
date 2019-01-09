/*
	@File: fn_welcomeNotification.sqf

	@Author: Jack "Scarso" Farhall

	@Description: Displays text when first joining to introduce the server.
*/

_onScreenTime = 10;
_world = worldName;
sleep 3;
 
_role1 = "Hello Fella!";
_role1names = ["Welcome to", "Scarso's "+ _world +" Life!"];
_role2 = "Forums";
_role2names = ["Website:", "tritanhub.co.uk"];
_role3 = "Teamspeak!";
_role3names = ["Teamspeak IP:", "ts3.tritanhub.co.uk!"];
_role4 = "Dev Team!";
_role4names = ["Development Team", "Scarso"];
_role5 = "Version!";
_role5names = ["Current Version: V1"];
  
{
    sleep 2;

    _memberFunction = _x select 0;
    _memberNames = _x select 1;
    _finalText = format ["<t size='0.40' color='#f2cb0b' align='right'>%1<br /></t>", _memberFunction];
    _finalText = _finalText + "<t size='0.70' color='#FFFFFF' align='right'>";

    {
        _finalText = _finalText + format ["%1<br />", _x]
    } forEach _memberNames;

    _finalText = _finalText + "</t>";
    _onScreenTime + (((count _memberNames) - 1) * 0.5);
    [_finalText,[safezoneX + safezoneW - 0.8,0.50],[safezoneY + safezoneH - 0.8,0.7],_onScreenTime,0.5] spawn BIS_fnc_dynamicText;
    sleep (_onScreenTime);
} forEach [
    [_role1, _role1names],
    [_role2, _role2names],
    [_role3, _role3names],
    [_role4, _role4names],
    [_role5, _role5names]
];