#include "macros.hpp"

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
		LIFE_BAR_XP_BACK,
		LIFE_NUM_CURLVL_BACK,
		LIFE_NUM_NXTLVL_BACK,
		LIFE_BAR_FOOD,
		LIFE_BAR_WATER,
		LIFE_BAR_HEALTH,
		LIFE_BAR_XP,
		LIFE_FOOD_TEXT,
		LIFE_WATER_TEXT,
		LIFE_HEALTH_TEXT,
		LIFE_CASH_TEXT,
		LIFE_XP_TEXT,
		LIFE_CURLVL_TEXT,
		LIFE_NXTLVL_TEXT,
		LIFE_ICON_BACKGROUND
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

	class LIFE_BAR_XP_BACK: Life_RscBackground
	{
		idc = IDC_LIFE_BAR_XP_BACK;
		x = 0.396874 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.20625 * safezoneW;
		h = 0.022 * safezoneH;
		colorBackground[] = {0.7,0.7,0.7,0.3};
	};

	class LIFE_NUM_CURLVL_BACK: Life_RscBackground
	{
		idc = IDC_LIFE_NUM_CURLVL_BACK;
		x = 0.381406 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.0154688 * safezoneW;
		h = 0.022 * safezoneH;
		colorBackground[] = {0, 0, 0, 0.7};
	};

	class LIFE_NUM_NXTLVL_BACK: Life_RscBackground
	{
		idc = IDC_LIFE_NUM_NXTLVL_BACK;
		x = 0.603125 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.0154688 * safezoneW;
		h = 0.022 * safezoneH;
		colorBackground[] = {0, 0, 0, 0.7};
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
		idc = IDC_LIFE_BAR_HEALTH;
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.897 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
		colorText[] = {1, 1, 1, 1};
		colorBackground[] = {0, 0, 0, 0.5};
	};

	class LIFE_BAR_XP: FF_RscProgress
	{
		idc = IDC_LIFE_BAR_XP;
		x = 0.396874 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.20625 * safezoneW;
		h = 0.022 * safezoneH;
		colorText[] = {1, 1, 1, 1};
		colorBackground[] = {0, 0, 0, 0.5};
	};

	/* Text */
	
	class LIFE_FOOD_TEXT: Life_RscStructuredText
	{
		idc = IDC_LIFE_FOOD_TEXT;
		text = "";
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.924 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
	};
	
	class LIFE_WATER_TEXT: Life_RscStructuredText
	{
		idc = IDC_LIFE_WATER_TEXT;
		text = "";
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
	};
	
	class LIFE_HEALTH_TEXT: Life_RscStructuredText
	{
		idc = IDC_LIFE_HEALTH_TEXT;
		text = "";
		x = 0.850625 * safezoneW + safezoneX;
		y = 0.897 * safezoneH + safezoneY;
		w = 0.134062 * safezoneW;
		h = 0.022 * safezoneH;
	};

	/* Icons */

	class LIFE_ICON_BACKGROUND : Life_RscBackground {
		idc = IDC_LIFE_ICON_BACKGROUND;
		text = "";
		x = 0.015312 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.020625 * safezoneW;
		h = 0.022 * safezoneH;
		colorBackground[] = {0, 0, 0, 0.5};
	};

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

	class LIFE_XP_TEXT: Life_RscStructuredText
	{
		idc = IDC_LIFE_XP_TEXT;
		text = "0 / 0";
		x = 0.396874 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.20625 * safezoneW;
		h = 0.022 * safezoneH;
	};

	class LIFE_CURLVL_TEXT: Life_RscStructuredText
	{
		idc = IDC_LIFE_CURLVL_TEXT;
		x = 0.381406 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.0154688 * safezoneW;
		h = 0.022 * safezoneH;
		text = "1";
	};

	class LIFE_NXTLVL_TEXT: Life_RscStructuredText
	{
		idc = IDC_LIFE_NXTLVL_TEXT;
		x = 0.603125 * safezoneW + safezoneX;
		y = 0.951 * safezoneH + safezoneY;
		w = 0.0154688 * safezoneW;
		h = 0.022 * safezoneH;
		text = "2";
	};
};