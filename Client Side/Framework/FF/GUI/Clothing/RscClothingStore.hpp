class RscClothingStore {
	idd = 3100;
	name = "RscClothingStore";
  	onLoad = "";

    class ControlsBackground {
        class Background : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.16,0.16,0.16,1};
            x = 0.0153125 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.506 * safezoneH;
        };

        class HeaderBackground : Life_RscBackground {
            idc = -1;
            moving = true; // Allows it to be dragged around
            colorBackground[] = {0.09,0.09,0.09,1};
            x = 0.0153125 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class FooterBackground : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.102,0.102,0.102,1};
            x = 0.0153125 * safezoneW + safezoneX;
            y = 0.72 * safezoneH + safezoneY;
            w = 0.185625 * safezoneW;
            h = 0.033 * safezoneH;
        };

		class Line : Life_RscText{
			idc = -1;
			x = 0.0153125 * safezoneW + safezoneX;
            y = 0.72 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = safeZoneH * 0.00133334;
			colorBackground[] = {0,0,0,1};
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
		};

        class PageTitle : Life_RscText {
            idc = 3103;
            text = "Store Title";
            x = 0.0153125 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.12375 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class PriceBackground : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.09,0.09,0.09,1};
           	x = 0.0204687 * safezoneW + safezoneX;
            y = 0.654 * safezoneH + safezoneY;
            w = 0.175313 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class TotalPriceBackground : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.09,0.09,0.09,1};
           	x = 0.0204687 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.175313 * safezoneW;
            h = 0.022 * safezoneH;
        };
    };

    class Controls {
		class CloseButton : Life_RscButtonMenuIcon {
			onButtonClick = "closeDialog 0; [] call FF_fnc_playerSkins;";
			idc = -1;
			x = 0.185469 * safezoneW + safezoneX;
            y = 0.247 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			tooltip = "Return"; //--- ToDo: Localize;
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
		};

		/* Filters */
		class ClothingFilter : Life_RscButtonMenuIcon {
			onButtonClick = "[0,0] call life_fnc_clothingFilter";
			idc = -1;
			x = 0.0204687 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {-1,-1,-1,0.9};
			tooltip = "Uniforms";
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		};

		class HatsFilter : Life_RscButtonMenuIcon {
			onButtonClick = "[0,1] call life_fnc_clothingFilter";
			idc = -1;
			x = 0.0359375 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {-1,-1,-1,0.9};
			tooltip = "Headgear";
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\headgear_ca.paa";
		};

		class GlassesFilter : Life_RscButtonMenuIcon {
			onButtonClick = "[0,2] call life_fnc_clothingFilter";
			idc = -1;
			x = 0.0514062 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {-1,-1,-1,0.9};
			tooltip = "Glasses";
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\goggles_ca.paa";
		};

		class VestsFilter : Life_RscButtonMenuIcon {
			onButtonClick = "[0,3] call life_fnc_clothingFilter";
			idc = -1;
			x = 0.066875 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {-1,-1,-1,0.9};
			tooltip = "Vests";
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\vest_ca.paa";
		};

		class BackpackFilter : Life_RscButtonMenuIcon {
			onButtonClick = "[0,4] call life_fnc_clothingFilter";
			idc = -1;
			x = 0.0823437 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.0154688 * safezoneW;
            h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {-1,-1,-1,0.9};
			tooltip = "Backpacks";
			text = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\backpack_ca.paa";
		};

        class ListBox : Life_RscListBox {
            idc = 3101;
            x = safeZoneX + safeZoneW * 0.0204692;
            y = safeZoneY + safeZoneH * 0.302;
            w = safeZoneW * 0.175313;
            h = safeZoneH * 0.341;
            color[] = {0.09,0.09,0.09,1};
			colorBackground[] = {0.09,0.09,0.09,1};
			colorText[] = {1,1,1,1};
			font = "PuristaLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			rowHeight = 0.1;
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
            onLBSelChanged = "[_this] call life_fnc_changeClothes;";
        };

        class PriceText : Life_RscStructuredText {
            idc = 3102;
            text = "Select an item above...";
            x = 0.0204687 * safezoneW + safezoneX;
            y = 0.654 * safezoneH + safezoneY;
            w = 0.175313 * safezoneW;
            h = 0.022 * safezoneH;
        };

        class TotalPriceText : Life_RscStructuredText {
            idc = 3106;
            text = "";
            x = 0.0204687 * safezoneW + safezoneX;
            y = 0.687 * safezoneH + safezoneY;
            w = 0.175313 * safezoneW;
            h = 0.022 * safezoneH;
        };

		class BuyButton : Life_RscButtonMenu {
			idc = -1;
			x = safeZoneX + safeZoneW * 0.123594;
			y = safeZoneY + safeZoneH * 0.726;
			w = safeZoneW * 0.0721875;
			h = safeZoneH * 0.022;
			text = "Buy";
			onButtonClick = "[] call life_fnc_buyClothes;";
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

        class viewAngle: life_RscXSliderH {
            color[] = {1, 1, 1, 0.45};
            colorActive[] = {1, 1, 1, 0.65};
            idc = 3107;
            text = "";
            onSliderPosChanged = "[4,_this select 1] call life_fnc_s_onSliderChange;";
            tooltip = "";
            x = 0.25 * safezoneW + safezoneX;
            y = 0.93 * safezoneH + safezoneY;
            w = 0.5 * safezoneW;
            h = 0.02 * safezoneH;
        };
    };
};