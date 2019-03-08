
class HeaderImage : Life_RscPicture {
    idc = IDC_MAIN_HEADER;
    fade = 1;
    x = 0.278282 * safezoneW + safezoneX;
    y = 0.247 * safezoneH + safezoneY;
    w = 0.443438 * safezoneW;
    h = 0.154 * safezoneH;
    text = "data\ui\header.jpg";
    colorText[] = {1, 1, 1, 0.3};
};

class TimeText : Life_RscText {
    idc = IDC_MAIN_CLOCK;
    text = "00:00";
    font = "PuristaLight";
    shadow = 0;
    fade = 1;
    x = 0.298906 * safezoneW + safezoneX;
    y = 0.269 * safezoneH + safezoneY;
    w = 0.0979687 * safezoneW;
    h = 0.11 * safezoneH;
    sizeEx = 0.08 * safezoneH;
};

class BankText : Life_RscStructuredText {
    idc = IDC_MAIN_BANK;
    text = "<t align='right'>Bank: £N/A</t>";
    font = "PuristaLight";
    shadow = 0;
    fade = 1;
    x = 0.536094 * safezoneW + safezoneX;
    y = 0.291 * safezoneH + safezoneY;
    w = 0.165 * safezoneW;
    h = 0.022 * safezoneH;
};

class CashText : Life_RscStructuredText {
    idc = IDC_MAIN_CASH;
    text = "<t align='right'>Cash: £N/A</t>";
    font = "PuristaLight";
    shadow = 0;
    fade = 1;
    x = 0.536094 * safezoneW + safezoneX;
    y = 0.313 * safezoneH + safezoneY;
    w = 0.165 * safezoneW;
    h = 0.022 * safezoneH;
};

class RepText : Life_RscStructuredText {
    idc = IDC_MAIN_REP;
    text = "<t align='right'>Reputation: N/A</t>";
    font = "PuristaLight";
    shadow = 0;
    fade = 1;
    x = 0.536094 * safezoneW + safezoneX;
    y = 0.335 * safezoneH + safezoneY;
    w = 0.165 * safezoneW;
    h = 0.022 * safezoneH;
};

class HomeView : Life_RscControlsGroupNoScrollbars {
    idc = IDC_MAIN_BUTTONS;
    x = 0.278282 * safezoneW + safezoneX;
    y = 0.236 * safezoneH + safezoneY;
    w = 0.443438 * safezoneW;
    h = 0.506 * safezoneH;
    colorBackground[] = {0, 0, 0, 0};
    fade = 1;

    // Filled by script fn_openMenu.sqf...
    class Controls {};
};