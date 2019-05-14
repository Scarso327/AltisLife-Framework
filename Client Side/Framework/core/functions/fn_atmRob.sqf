private["_player","_atm","_cash","_ui","_progress","_pgText","_progress","_wip","_pos"];
_atm = [_this,0,ObjNull,[ObjNull]] call BIS_fnc_param;
_player = [_this,1,ObjNull,[ObjNull]] call BIS_fnc_param; 
_cash = 1000 + round(random 10000);
_cops = (west countSide playableUnits);
_chance = random(20);

if(_player distance _atm > 3) exitWith { hint "You are not close enough to rob this." };
if (_wip) exitWith { hint "A robbery already in progress!" };
if (vehicle player != _player) exitWith { hint "You cannot do this from inside a vehicle!" };
if (_cash == 0) exitWith { hint "There is no cash in the ATM!" };
if !(_cash) then { _cash = 1000; };
if(_cops < 0) exitWith{ hint "There must be at least one officer active to rob this!" };
if(!([false,"rfidReader",1] call life_fnc_handleInv)) exitWith { hint "You require an RFID Reader to rob an ATM!" };
[true,"rfidReader",1] call life_fnc_handleInv; 
disableSerialization;

5 cutRsc ["life_progress","PLAIN"];
_ui = uiNameSpace getVariable "life_progress";
_progress = _ui displayCtrl 38201;
_pgText = _ui displayCtrl 38202;
_pgText ctrlSetText format["Robbery in progress, stay within (3m) to complete (1%1)...","%"];
_progress progressSetPosition 0.01;
_progress = 0.0001;

_atm switchMove "AmovPercMstpSsurWnonDnon";

_wip = true;
_cash = 1000 + round(random 10000);
if(_chance >= 50) then {[1,format["!!! AN ATM IS BEING ROBBED !!!", _atm]] remoteExec ["life_fnc_broadcast",west]; };
if(_wip) then {
    while{true} do {
        sleep 3;
        _progress = _progress + 0.01;
        _progress progressSetPosition _progress;
        _pgText ctrlSetText format["Robbery in Progress! Stay within 3-meters to complete (%1%2)...",round(_progress * 100),"%"];
        _Pos = position player;
            _marker = createMarker ["atmRob", _Pos];
            "atmRob" setMarkerType "mil_dot";
            "atmRob" setMarkerColor "ColorRed";
            "atmRob" setMarkerText "!!! ROBBERY IN PROGRESS !!!";
        if(_progress >= 1) exitWith {};
        if(_player distance _atm > 3) exitWith { };
        if!(alive _player) exitWith {};
    };
    if!(alive _player) exitWith { _wip = false; };
    if(_player distance _atm > 3) exitWith { deleteMarker "atmRob"; _atm switchMove ""; hint "You need to stay within 3m to rob this ATM!"; 5 cutText ["","PLAIN"]; _rip = false; };
    5 cutText ["","PLAIN"];

    titleText[format["You have sucessfully stolen £%1!",[_cash] call life_fnc_numberText],"PLAIN"];
    deleteMarker "atmRob";
    life_cash = life_cash + _cash;

    _wip = false;
    life_use_atm = false;
    sleep (30 + random(180));
    life_use_atm = true;
    if!(alive _player) exitWith {};
};
sleep 420;
_atm switchMove "";