class PagePerkTitle : Life_RscText {
    idc = IDC_PERK_TITLE;
    text = "Perk Menu";
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.247 * safezoneH + safezoneY;
    w = 0.201094 * safezoneW;
    h = 0.022 * safezoneH;
};

class ClosePerkButton: Life_RscButtonMenuIcon
{
    onButtonClick = "[23100, ""Home""] call FF_fnc_switchApp;";
    idc = IDC_PERK_CLOSE;
    x = 0.70625 * safezoneW + safezoneX;
    y = 0.247 * safezoneH + safezoneY;
    w = 0.0154688 * safezoneW;
    h = 0.022 * safezoneH;
    colorText[] = {1,1,1,1};
    colorBackground[] = {0,0,0,0};
    tooltip = "Return"; //--- ToDo: Localize;
    text = "a3\ui_f\data\gui\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
};

class UnlockedPerkBackground : Life_RscBackground {
	idc = IDC_PERK_UNLOCKED_BACKGROUND;
	colorBackground[] = {0,0,0,1};
	x = 0.278282 * safezoneW + safezoneX;
	y = 0.28 * safezoneH + safezoneY;
	w = 0.443438 * safezoneW;
	h = 0.022 * safezoneH;
};

class UnlockedPerkTitle : Life_RscText {
    idc = IDC_PERK_UNLOCKED_TITLE;
    text = "Unlocked Perks";
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.28 * safezoneH + safezoneY;
    w = 0.201094 * safezoneW;
    h = 0.022 * safezoneH;
};

class PerksView : Life_RscControlsGroup {
    idc = IDC_PERK_SCROLL;
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.302 * safezoneH + safezoneY;
    w = 0.443438 * safezoneW;
    h = 0.286 * safezoneH;
    colorBackground[] = {0, 0, 0, 0};

    class Controls {
		class PerkIcon : life_RscPicture {
			idc = 23618;
			x = 0.283437 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.088 * safezoneH;
			colorBackground[] = {0,0,0,0};
			text = "#(argb,8,8,3)color(1,1,1,1)";
		};
	};
};

class PerkBackground : Life_RscBackground {
	idc = IDC_PERK_ACTIVE_BACKGROUND;
	colorBackground[] = {0,0,0,1};
	x = 0.278281 * safezoneW + safezoneX;
	y = 0.588 * safezoneH + safezoneY;
	w = 0.443438 * safezoneW;
	h = 0.022 * safezoneH;
};

class UnlockedPerksTitle : Life_RscText {
    idc = IDC_PERK_ACTIVE_TITLE;
    text = "Active Perks";
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.588 * safezoneH + safezoneY;
    w = 0.201094 * safezoneW;
    h = 0.022 * safezoneH;
};

class Perk_1_Box : Life_RscStructuredText {
    idc = IDC_PERK_ACTIVE_ONE;
    text = "";
    x = 0.283437 * safezoneW + safezoneX;
    y = 0.621 * safezoneH + safezoneY;
    w = 0.0825 * safezoneW;
    h = 0.044 * safezoneH;
	colorBackground[] = {0,0,0,0.5};
};

class Perk_2_Box : Life_RscStructuredText {
    idc = IDC_PERK_ACTIVE_TWO;
    text = "";
    x = 0.371094 * safezoneW + safezoneX;
    y = 0.621 * safezoneH + safezoneY;
    w = 0.0825 * safezoneW;
    h = 0.044 * safezoneH;
	colorBackground[] = {0,0,0,0.5};
};

class Perk_3_Box : Life_RscStructuredText {
    idc = IDC_PERK_ACTIVE_THREE;
    text = "";
    x = 0.45875 * safezoneW + safezoneX;
    y = 0.621 * safezoneH + safezoneY;
    w = 0.0825 * safezoneW;
    h = 0.044 * safezoneH;
	colorBackground[] = {0,0,0,0.5};
};

class Perk_4_Box : Life_RscStructuredText {
    idc = IDC_PERK_ACTIVE_FOUR;
    text = "";
    x = 0.546406 * safezoneW + safezoneX;
    y = 0.621 * safezoneH + safezoneY;
    w = 0.0825 * safezoneW;
    h = 0.044 * safezoneH;
	colorBackground[] = {0,0,0,0.5};
};

class Perk_5_Box : Life_RscStructuredText {
    idc = IDC_PERK_ACTIVE_FIVE;
    text = "";
    x = 0.634062 * safezoneW + safezoneX;
    y = 0.621 * safezoneH + safezoneY;
    w = 0.0825 * safezoneW;
    h = 0.044 * safezoneH;
	colorBackground[] = {0,0,0,0.5};
};

class Perk_1_Removal : Life_RscButtonMenu {
	idc = IDC_PERK_ACTIVE_ONE_REMOVAL;
	x = safeZoneX + safeZoneW * 0.283437;
	y = safeZoneY + safeZoneH * 0.676;
	w = safeZoneW * 0.0825;
	h = safeZoneH * 0.022;
	text = "REMOVE";
	onButtonClick = "";
	borderSize = 0;
	colorBackground[] = {0,0,0,0.5};
	colorText[] = {1,1,1,1};
	font = "PuristaLight";
	sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
};

class Perk_2_Removal : Life_RscButtonMenu {
	idc = IDC_PERK_ACTIVE_TWO_REMOVAL;
	x = safeZoneX + safeZoneW * 0.371094;
	y = safeZoneY + safeZoneH * 0.676;
	w = safeZoneW * 0.0825;
	h = safeZoneH * 0.022;
	text = "REMOVE";
	onButtonClick = "";
	borderSize = 0;
	colorBackground[] = {0,0,0,0.5};
	colorText[] = {1,1,1,1};
	font = "PuristaLight";
	sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
};

class Perk_3_Removal : Life_RscButtonMenu {
	idc = IDC_PERK_ACTIVE_THREE_REMOVAL;
	x = safeZoneX + safeZoneW * 0.45875;
	y = safeZoneY + safeZoneH * 0.676;
	w = safeZoneW * 0.0825;
	h = safeZoneH * 0.022;
	text = "REMOVE";
	onButtonClick = "";
	borderSize = 0;
	colorBackground[] = {0,0,0,0.5};
	colorText[] = {1,1,1,1};
	font = "PuristaLight";
	sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
};

class Perk_4_Removal : Life_RscButtonMenu {
	idc = IDC_PERK_ACTIVE_FOUR_REMOVAL;
	x = safeZoneX + safeZoneW * 0.546406;
	y = safeZoneY + safeZoneH * 0.676;
	w = safeZoneW * 0.0825;
	h = safeZoneH * 0.022;
	text = "REMOVE";
	onButtonClick = "";
	borderSize = 0;
	colorBackground[] = {0,0,0,0.5};
	colorText[] = {1,1,1,1};
	font = "PuristaLight";
	sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
};

class Perk_5_Removal : Life_RscButtonMenu {
	idc = IDC_PERK_ACTIVE_FIVE_REMOVAL;
	x = safeZoneX + safeZoneW * 0.634062;
	y = safeZoneY + safeZoneH * 0.676;
	w = safeZoneW * 0.0825;
	h = safeZoneH * 0.022;
	text = "REMOVE";
	onButtonClick = "";
	borderSize = 0;
	colorBackground[] = {0,0,0,0.5};
	colorText[] = {1,1,1,1};
	font = "PuristaLight";
	sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
};

class RemovalInfo : Life_RscStructuredText {
    idc = IDC_PERK_REMOVE_INFO;
    text = "<t align='center'>Removal Cost: <t color = '#7300e6'>£10,000</t></t>";
    x = 0.283437 * safezoneW + safezoneX;
    y = 0.709 * safezoneH + safezoneY;
    w = 0.433125 * safezoneW;
    h = 0.022 * safezoneH;
};