class DialogObjectPreview {
    idd = 6100;
    movingEnable = 0;
    enableSimulation = 0;
    onInit = "_this call ULP_UI_fnc_DialogObjectPreview_OnInit";
    onLoad = "_this call ULP_UI_fnc_DialogObjectPreview_OnLoad";
	onUnload = "_this call ULP_UI_fnc_DialogObjectPreview_OnUnload";

    class ControlsBackground {
        class CancelText: Life_RscStructuredText {
            idc = -1;
            text = "Press <t color = '#8A2BE2'>[ESCAPE]</t> to close";
            x = 0.386562 * safezoneW + safezoneX;
            y = 0.895 * safezoneH + safezoneY;
            w = 0.226875 * safezoneW;
            h = 0.022 * safezoneH;
			class Attributes
			{
				align = "center";
			};
        };
	};
};