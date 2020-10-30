class PageProfessionTitle : Life_RscText {
    idc = IDC_PROF_TITLE;
    text = "Profession Menu";
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.247 * safezoneH + safezoneY;
    w = 0.201094 * safezoneW;
    h = 0.022 * safezoneH;
};

class CloseProfessionButton: Life_RscButtonMenuIcon
{
    onButtonClick = "[23100, ""Home""] call FF_fnc_switchApp;";
    idc = IDC_PROF_CLOSE;
    x = 0.70625 * safezoneW + safezoneX;
    y = 0.247 * safezoneH + safezoneY;
    w = 0.0154688 * safezoneW;
    h = 0.022 * safezoneH;
    colorText[] = {1,1,1,1};
    colorBackground[] = {0,0,0,0};
    tooltip = "Return"; //--- ToDo: Localize;
    text = "a3\ui_f\data\gui\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
};

class ProfessionView : Life_RscControlsGroup {
    idc = IDC_PROF_VIEW;
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.28 * safezoneH + safezoneY;
    w = 0.443438 * safezoneW;
    h = 0.462 * safezoneH;
    colorBackground[] = {0, 0, 0, 0};

    class Controls {};
};