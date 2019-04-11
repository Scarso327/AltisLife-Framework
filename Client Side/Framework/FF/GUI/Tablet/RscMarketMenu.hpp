class MarketPricesTitle : Life_RscText {
    idc = IDC_MARKET_TITLE;
    text = "Market Prices";
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.247 * safezoneH + safezoneY;
    w = 0.201094 * safezoneW;
    h = 0.022 * safezoneH;
};

class MarketCloseButton: Life_RscButtonMenuIcon
{
    onButtonClick = "[23100, ""Home""] call FF_fnc_switchApp;";
    idc = IDC_MARKET_CLOSE;
    x = 0.70625 * safezoneW + safezoneX;
    y = 0.247 * safezoneH + safezoneY;
    w = 0.0154688 * safezoneW;
    h = 0.022 * safezoneH;
    colorText[] = {1,1,1,1};
    colorBackground[] = {0,0,0,0};
    tooltip = "Return"; //--- ToDo: Localize;
    text = "\a3\ui_f\data\gui\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
};

class MarketSearchEdit : Life_RscEdit {
    idc = IDC_MARKET_SEARCH;
    text = "";
    x = 0.278281 * safezoneW + safezoneX;
    y = 0.28 * safezoneH + safezoneY;
    w = 0.0876563 * safezoneW;
    h = 0.022 * safezoneH;
	colorBackground[] = {0,0,0,0.8};
};

class MarketSearchButton: Life_RscButtonMenuIcon
{
    idc = IDC_MARKET_SEARCH_BUTTON;
    x = 0.365937 * safezoneW + safezoneX;
    y = 0.28 * safezoneH + safezoneY;
    w = 0.0154688 * safezoneW;
    h = 0.022 * safezoneH;
    colorText[] = {1,1,1,1};
    colorBackground[] = {0,0,0,0};
    text = "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
};

class ListHeaderBackground: Life_RscText
{
	idc = IDC_MARKET_HEADER_BACKGROUND;
	x = 0.278281 * safezoneW + safezoneX;
    y = 0.313 * safezoneH + safezoneY;
    w = 0.443438 * safezoneW;
    h = 0.022 * safezoneH;
	colorBackground[] = {0,0,0,0.8};
};

class ListHeader: Life_RscListNBox {
	x = 0.278281 * safezoneW + safezoneX;
    y = 0.313 * safezoneH + safezoneY;
    w = 0.443438 * safezoneW;
    h = 0.022 * safezoneH;
	idc = IDC_MARKET_HEADER;
	text = "";	
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = {0,0.3,0.6,0.75};
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;

	class Items {
		class DisplayName {
			text = "Item";
			value = 0;
		};
		class Legality {
			text = "Legality";
			value = 0;
		};
		class Weight {
			text = "Weight";
			value = 0;
		};
		class SellPrice { 
			text = "Sell Price";
			value = 0;
		};
	};
};

class MarketItemList: Life_RscListNBox {
	x = 0.278281 * safezoneW + safezoneX;
    y = 0.333281 * safezoneH + safezoneY;
    w = 0.443438 * safezoneW;
    h = 0.022 * safezoneH;
	idc = IDC_MARKET_LIST;
	text = "";	
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = {0,0.3,0.6,0.75};
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
};