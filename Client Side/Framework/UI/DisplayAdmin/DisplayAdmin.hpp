#define WIDTH 0.12375012375
#define XP_WIDTH (WIDTH + (WIDTH / 4))

class DisplayAdmin {
    name = "DisplayAdmin";
    idd = 600;
    onLoad=" [""Load"", _this] call ULP_fnc_adminCamera;";
	onUnload=" [""Unload"", _this] call ULP_fnc_adminCamera;";
    objects[]={};

    class ControlsBackground {};
    class Controls {};
};