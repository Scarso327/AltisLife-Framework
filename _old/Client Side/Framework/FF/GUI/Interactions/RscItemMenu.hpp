class RscItemMenu {
	idd = 8000;
	name = "RscItemMenu";
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
            x = 0.407187 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class PageTitle : Life_RscText {
            idc = 8001;
            text = "Give Items";
            x = 0.407187 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.12375 * safezoneW;
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

		class Line:Life_RscText{
			idc = -1;
            x = 0.407188 * safezoneW + safezoneX;
            y = 0.72 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.00133334 * safezoneH;
			colorBackground[] = {0,0,0,1};
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
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
            idc = 8004;
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
        };

		class ValueEdit:Life_RscEdit {
			idc = 8002;
            x = 0.412344 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.175313 * safezoneW;
            h = 0.022 * safezoneH;
            text = "1";
			colorBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
		};

        class SubmitButton:Life_RscButtonMenu{
			idc = 8003;
			x = 0.515469 * safezoneW + safezoneX;
            y = 0.726 * safezoneH + safezoneY;
            w = 0.0721875 * safezoneW;
            h = 0.022 * safezoneH;
			style = 2;
			text = "GIVE";
			onButtonClick = "[""Give""] call life_fnc_giveItem";
			borderSize = 0;
			colorBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
            colorBackgroundDisabled[] = {0.05,0.05,0.05,0.8};
			font = "PuristaLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 30) * 1);
		};
    };
};