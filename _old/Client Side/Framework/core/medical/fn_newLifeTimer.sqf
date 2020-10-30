private["_uiDisp","_time","_timer"];

7 cutRsc ["life_nlrTimer","PLAIN"];
_uiDisp = uiNamespace getVariable "life_nlrTimer";
_timer = _uiDisp displayCtrl 38301;
_time = time + (10 * 60);
life_nlrTimer_running = true;

while {true} do {
      if(isNull _uiDisp) then {
            7 cutRsc ["life_nlrTimer","PLAIN"];
            _uiDisp = uiNamespace getVariable "life_nlrTimer";
            _timer = _uiDisp displayCtrl 38301;
      };
      if(round(_time - time) < 1) exitWith {};
      if(life_nlrTimer_stop) exitWith {life_nlrTimer_stop = false;};
      _timer ctrlSetText format["NLR: %1",[(_time - time),"MM:SS"] call BIS_fnc_secondsToString];
      sleep 0.1;
};

life_nlrTimer_running = false;
7 cutText["","PLAIN"];