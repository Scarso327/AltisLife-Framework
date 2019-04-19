class RscProcessing {
	idd = 5000;
	name = "RscProcessing";
  	onLoad = "";

    class ControlsBackground {
        class Background : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.16,0.16,0.16,1};
            x = 0.407188 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.506 * safezoneH;
        };

        class HeaderBackground : Life_RscBackground {
            idc = -1;
            moving = true; // Allows it to be dragged around
            colorBackground[] = {0.09,0.09,0.09,1};
            x = 0.407188 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class FooterBackground : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.102,0.102,0.102,1};
            x = 0.407188 * safezoneW + safezoneX;
            y = 0.72 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.033 * safezoneH;
        };

		class Line : Life_RscText{
			idc = -1;
			x = 0.407188 * safezoneW + safezoneX;
            y = 0.72 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = safeZoneH * 0.00133334;
			colorBackground[] = {0,0,0,1};
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
		};

        class PageTitle : Life_RscText {
            idc = -1;
            text = "Processing Menu";
            x = 0.407188 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.12375 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class PriceBackground : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.09,0.09,0.09,1};
            x = 0.412343 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.175313 * safezoneW;
            h = 0.022 * safezoneH;
        };
    };

    class Controls {
		class CloseButton : Life_RscButtonMenuIcon {
			onButtonClick = "closeDialog 0;";
			idc = -1;
			x = 0.577344 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			tooltip = "Return"; //--- ToDo: Localize;
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

        class ListBox : Life_RscListBox {
            idc = 5001;
            x = safeZoneX + safeZoneW * 0.412344;
            y = safeZoneY + safeZoneH * 0.28;
            w = safeZoneW * 0.175313;
            h = safeZoneH * 0.396;
            color[] = {0.09,0.09,0.09,1};
			colorBackground[] = {0.09,0.09,0.09,1};
			colorText[] = {1,1,1,1};
			font = "PuristaLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			rowHeight = 0.1;
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
            onLBSelChanged = "_this call FF_fnc_ProcessingLBChanged";
        };

        class PriceText : Life_RscStructuredText {
            idc = 5002;
            text = "Select an item above...";
            x = 0.412343 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.175313 * safezoneW;
            h = 0.022 * safezoneH;
        };

		class ProcessButton : Life_RscButtonMenu {
			idc = 5003;
			x = safeZoneX + safeZoneW * 0.515469;
			y = safeZoneY + safeZoneH * 0.726;
			w = safeZoneW * 0.0721875;
			h = safeZoneH * 0.022;
			text = "PROCESS";
			onButtonClick = "[] call life_fnc_processAction";
			borderSize = 0;
			colorBackground[] = {0.09,0.09,0.09,1};
			colorText[] = {1,1,1,1};
			font = "PuristaLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
		};
    };
};