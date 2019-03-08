class PageTitleLic : Life_RscText {
    idc = IDC_LIC_TITLE;
    text = "License Menu";
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.247 * safezoneH + safezoneY;
    w = 0.201094 * safezoneW;
    h = 0.022 * safezoneH;
};

class CloseButtonLic: Life_RscButtonMenuIcon
{
    onButtonClick = "[23100, ""Home""] call FF_fnc_switchApp;";
    idc = IDC_LIC_CLOSE;
    x = 0.70625 * safezoneW + safezoneX;
    y = 0.247 * safezoneH + safezoneY;
    w = 0.0154688 * safezoneW;
    h = 0.022 * safezoneH;
    colorText[] = {1,1,1,1};
    colorBackground[] = {0,0,0,0};
    tooltip = "Return"; //--- ToDo: Localize;
    text = "a3\ui_f\data\gui\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
};

class LicenseList: Life_RscListBox {
    idc = IDC_LIC_LIST;
    rowHeight = 0.09;
    sizeEx = 0.033;
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.28 * safezoneH + safezoneY;
    w = 0.211406 * safezoneW;
    h = 0.462 * safezoneH;
    colorBackground[] = {0,0,0,0.6};
};

class LicenseInfo: Life_RscStructuredText
{
    idc = IDC_LIC_ITEM_DES;
    x = 0.494844 * safezoneW + safezoneX;
    y = 0.28 * safezoneH + safezoneY;
    w = 0.226875 * safezoneW;
    h = 0.462 * safezoneH;
    colorBackground[] = {-1,-1,-1,0.6};
};