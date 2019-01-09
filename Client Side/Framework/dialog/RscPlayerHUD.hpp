#define IDC_LIFE_BAR_FOOD 2200
#define IDC_LIFE_BAR_WATER 2201
#define IDC_LIFE_BAR_HEALTH 2202
#define IDC_LIFE_BAR_FOOD_BACK 2203
#define IDC_LIFE_BAR_WATER_BACK 2204
#define IDC_LIFE_BAR_HEALTH_BACK 2205
#define IDC_LIFE_FOOD_TEXT 1000
#define IDC_LIFE_WATER_TEXT 1001
#define IDC_LIFE_HEALTH_TEXT 1002
#define IDC_LIFE_FOOD_TEXT_INFO 1003
#define IDC_LIFE_WATER_TEXT_INFO 1004
#define IDC_LIFE_HEALTH_TEXT_INFO 1004
#define IDC_LIFE_CASH_TEXT 1005

class RscPlayerHUD {
	idd = -1;
	duration = 10e10;
	movingEnable = 0;
	fadein = 0;
	fadeout = 0;
	name = "RscPlayerHUD";
	onLoad = "uiNamespace setVariable ['RscPlayerHUD',_this select 0]";
	objects[] = {};
	controls[] = {
		LIFE_BAR_FOOD_BACK,
		LIFE_BAR_WATER_BACK,
		LIFE_BAR_HEALTH_BACK,
		LIFE_BAR_FOOD,
		LIFE_BAR_WATER,
		LIFE_BAR_HEALTH,
		LIFE_FOOD_TEXT,
		LIFE_WATER_TEXT,
		LIFE_HEALTH_TEXT,
		LIFE_HTEXT,
		LIFE_FTEXT,
		LIFE_WTEXT,
		LIFE_CASH_TEXT
	};

	/* Background */
	
	class LIFE_BAR_FOOD_BACK: Life_RscBackground
	{
		idc = IDC_LIFE_BAR_FOOD_BACK;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.924 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
		colorBackground[] = {0.5,0.5,0.5,0.5};
	};
	
	class LIFE_BAR_WATER_BACK: Life_RscBackground
	{
		idc = IDC_LIFE_BAR_WATER_BACK;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
		colorBackground[] = {0.5,0.5,0.5,0.5};
	};
	
	class LIFE_BAR_HEALTH_BACK: Life_RscBackground
	{
		idc = IDC_LIFE_BAR_HEALTH_BACK;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.897 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
		colorBackground[] = {0.5,0.5,0.5,0.5};
	};

	/* Progress Bars */
	
	class LIFE_BAR_FOOD: FF_RscProgress
	{
		idc = IDC_LIFE_BAR_FOOD;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.924 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
		colorText[] = {1, 1, 1, 1};
		colorBackground[] = {0, 0, 0, 0.5};
	};
	
	class LIFE_BAR_WATER: FF_RscProgress
	{
		idc = IDC_LIFE_BAR_WATER;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
		colorText[] = {1, 1, 1, 1};
		colorBackground[] = {0, 0, 0, 0.5};
	};
	
	class LIFE_BAR_HEALTH: FF_RscProgress
	{
		idc = 2202;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.897 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
		colorText[] = {1, 1, 1, 1};
		colorBackground[] = {0, 0, 0, 0.5};
	};

	/* Text */

	class LIFE_HTEXT: Life_RscText
	{
		idc = IDC_LIFE_HEALTH_TEXT_INFO;
		text = "Health"; //--- ToDo: Localize;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.897 * safezoneH + safezoneY;
		w = 0.0721875 * safezoneW;
		h = 0.022 * safezoneH;
	};
	
	class LIFE_FTEXT: Life_RscText
	{
		idc = IDC_LIFE_FOOD_TEXT_INFO;
		text = "Food"; //--- ToDo: Localize;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.924 * safezoneH + safezoneY;
		w = 0.113437 * safezoneW;
		h = 0.022 * safezoneH;
	};
	class LIFE_WTEXT: Life_RscText
	{
		idc = IDC_LIFE_WATER_TEXT_INFO;
		text = "Water"; //--- ToDo: Localize;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.113437 * safezoneW;
		h = 0.022 * safezoneH;
	};
	
	class LIFE_FOOD_TEXT: Life_RscText
	{
		idc = IDC_LIFE_FOOD_TEXT;
		text = "";
		x = 0.957206 * safezoneW + safezoneX;
		y = 0.924 * safezoneH + safezoneY;
		w = 0.0309375 * safezoneW;
		h = 0.022 * safezoneH;
	};
	
	class LIFE_WATER_TEXT: Life_RscText
	{
		idc = IDC_LIFE_WATER_TEXT;
		text = "";
		x = 0.957206 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.0309375 * safezoneW;
		h = 0.022 * safezoneH;
	};
	
	class LIFE_HEALTH_TEXT: Life_RscText
	{
		idc = IDC_LIFE_HEALTH_TEXT;
		text = "";
		x = 0.957206 * safezoneW + safezoneX;
		y = 0.897 * safezoneH + safezoneY;
		w = 0.0309375 * safezoneW;
		h = 0.022 * safezoneH;
	};

	/* Icons */

	/* Other */

	class LIFE_CASH_TEXT: Life_RscStructuredText
	{
		idc = IDC_LIFE_CASH_TEXT;
		text = "";
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.87 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
	};
};