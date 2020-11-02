playSound "welcome";

_onScreenTime = 10;
sleep 3;
 
_role1 = "Hello there!";
_role1names = ["Welcome to", "LifePlus' Tanoa Life!"];
_role2 = "Teamspeak!";
_role2names = ["Teamspeak IP:", "ts3.lifeplusrp.co.uk!"];
_role3 = "Development Team!";
_role3names = ["Development Team", "Jack and Lewis"];
  
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
    [_role3, _role3names]
];