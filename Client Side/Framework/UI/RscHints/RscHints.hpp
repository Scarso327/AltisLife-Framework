class RscHints {
    name = "RscHints";
    idd = -1;
	duration = 10e10;
    fadein=0;
    fadeout=0;
    onLoad="uiNamespace setVariable ['RscHints', _this select 0]; [_this select 0, { _this call ULP_fnc_hintEachFrame }] call ULP_fnc_addEachFrame;";
	onUnload="";

    class Controls {};
};