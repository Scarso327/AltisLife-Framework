#define UI_X (MARGIN_X * 2)
#define UI_WIDTH 0.13234375
#define BODY_HEIGHT 0.407

class DialogFactionSelection {
    idd = 5800;
    onInit = "_this call ULP_UI_fnc_DialogFactionSelection_OnInit";
    onLoad = "_this call ULP_UI_fnc_DialogFactionSelection_OnLoad";
	onUnload = "_this call ULP_UI_fnc_DialogFactionSelection_OnUnload";

    class ControlsBackground {};
	class Controls {};
};