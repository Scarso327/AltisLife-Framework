class RscMoneyMenu {
    idd = 7200;
    movingEnable = true;
    enableSimulation = true;
    onload = "";

    class ControlsBackground {
        class Background : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.16,0.16,0.16,1};
            x = 0.427812 * safezoneW + safezoneX;
            y = 0.401 * safezoneH + safezoneY;
            w = 0.144375 * safezoneW;
            h = 0.132 * safezoneH;
        };
        class HeaderBackground : Life_RscBackground {
            idc = -1;
            moving = true; // Allows it to be dragged around
            colorBackground[] = {0.09,0.09,0.09,1};
            x = 0.427812 * safezoneW + safezoneX;
            y = 0.401 * safezoneH + safezoneY;
            w = 0.144375 * safezoneW;
            h = 0.022 * safezoneH;
        };
        class FooterBackground : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.102,0.102,0.102,1};
            x = 0.427812 * safezoneW + safezoneX;
            y = 0.5 * safezoneH + safezoneY;
            w = 0.144375 * safezoneW;
            h = 0.033 * safezoneH;
        };
		class Line:Life_RscText{
			idc = -1;
            x = 0.427812 * safezoneW + safezoneX;
            y = 0.5 * safezoneH + safezoneY;
            w = 0.144375 * safezoneW;
            h = 0.00133334 * safezoneH;
			colorBackground[] = {0,0,0,1};
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
		};
        class PageTitle : Life_RscText {
            idc = -1;
            text = "Give Money";
            x = 0.427812 * safezoneW + safezoneX;
            y = 0.401 * safezoneH + safezoneY;
            w = 0.12375 * safezoneW;
            h = 0.022 * safezoneH;
        };
    };

	class Controls {
		class CloseButton: Life_RscButtonMenuIcon
		{
			onButtonClick = "closeDialog 0;";
			idc = -1;
			x = 0.556719 * safezoneW + safezoneX;
            y = 0.401 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			tooltip = "Return"; //--- ToDo: Localize;
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};
        class TaxEdit:Life_RscEdit {
			idc = 7201;
            x = 0.438125 * safezoneW + safezoneX;
            y = 0.445 * safezoneH + safezoneY;
            w = 0.12375 * safezoneW;
            h = 0.033 * safezoneH;
            text = "";
			colorBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
		};
        class SubmitButton:Life_RscButtonMenu{
			idc = 7202;
			x = 0.494844 * safezoneW + safezoneX;
            y = 0.505 * safezoneH + safezoneY;
            w = 0.0721875 * safezoneW;
            h = 0.022 * safezoneH;
			style = 2;
			text = "GIVE";
			onButtonClick = "[life_pInact_curTarget] call life_fnc_giveMoney";
			borderSize = 0;
			colorBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
            colorBackgroundDisabled[] = {0.05,0.05,0.05,0.8};
			font = "PuristaLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 30) * 1);
		};
    };
};