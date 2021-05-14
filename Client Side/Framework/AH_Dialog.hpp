#define GUI_GRID_X	(0)
#define GUI_GRID_Y	(0)
#define GUI_GRID_W	(0.025)
#define GUI_GRID_H	(0.04)

#ifndef CT_STATIC
	#define CT_STATIC           0
	#define CT_BUTTON           1
	#define CT_EDIT             2
	#define CT_SLIDER           3
	#define CT_COMBO            4
	#define CT_LISTBOX          5
	#define CT_TOOLBOX          6
	#define CT_CHECKBOXES       7
	#define CT_PROGRESS         8
	#define CT_HTML             9
	#define CT_STATIC_SKEW      10
	#define CT_ACTIVETEXT       11
	#define CT_TREE             12
	#define CT_STRUCTURED_TEXT  13
	#define CT_CONTEXT_MENU     14
	#define CT_CONTROLS_GROUP   15
	#define CT_SHORTCUTBUTTON   16
	#define CT_XKEYDESC         40
	#define CT_XBUTTON          41
	#define CT_XLISTBOX         42
	#define CT_XSLIDER          43
	#define CT_XCOMBO           44
	#define CT_ANIMATED_TEXTURE 45
	#define CT_OBJECT           80
	#define CT_OBJECT_ZOOM      81
	#define CT_OBJECT_CONTAINER 82
	#define CT_OBJECT_CONT_ANIM 83
	#define CT_LINEBREAK        98
	#define CT_USER             99
	#define CT_MAP              100
	#define CT_MAP_MAIN         101
	#define CT_LISTNBOX         102
	#define CT_CHECKBOX         77

		
	#define ST_POS            0x0F
	#define ST_HPOS           0x03
	#define ST_VPOS           0x0C
	#define ST_LEFT           0x00
	#define ST_RIGHT          0x01
	#define ST_CENTER         0x02
	#define ST_DOWN           0x04
	#define ST_UP             0x08
	#define ST_VCENTER        0x0C

	#define ST_TYPE           0xF0
	#define ST_SINGLE         0x00
	#define ST_MULTI          0x10
	#define ST_TITLE_BAR      0x20
	#define ST_PICTURE        0x30
	#define ST_FRAME          0x40
	#define ST_BACKGROUND     0x50
	#define ST_GROUP_BOX      0x60
	#define ST_GROUP_BOX2     0x70
	#define ST_HUD_BACKGROUND 0x80
	#define ST_TILE_PICTURE   0x90
	#define ST_WITH_RECT      0xA0
	#define ST_LINE           0xB0

	#define ST_SHADOW         0x100
	#define ST_NO_RECT        0x200
	#define ST_KEEP_ASPECT_RATIO  0x800

	#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

		
	#define SL_DIR            0x400
	#define SL_VERT           0
	#define SL_HORZ           0x400

	#define SL_TEXTURES       0x10

		
	#define ST_VERTICAL       0x01
	#define ST_HORIZONTAL     0

		
	#define LB_TEXTURES       0x10
	#define LB_MULTI          0x20

		
	#define TR_SHOWROOT       1
	#define TR_AUTOCOLLAPSE   2

		
	#define MB_BUTTON_OK      1
	#define MB_BUTTON_CANCEL  2
	#define MB_BUTTON_USER    4
#endif

class AH_Data {
	version = 2;
};

class AH_RscText {
	deletable = 0;
	fade = 0;

	type = 0;
	idc = -1;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {1, 1, 1, 1};
	text = "";
	fixedWidth = 0;
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	style = 0;
	shadow = 1;
	colorShadow[] = {0, 0, 0, 0.5};
	font = "PuristaMedium";
	SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	linespacing = 1;
	tooltipColorText[] = {1, 1, 1, 1};
	tooltipColorBox[] = {1, 1, 1, 1};
	tooltipColorShade[] = {0, 0, 0, 0.65};
};
class AH_RscStructuredText {
	deletable = 0;
	fade = 0;

	type = 13;
	idc = -1;
	style = 0;
	colorText[] = {1, 1, 1, 1};
	class Attributes {
	font = "PuristaMedium";
	color = "#ffffff";
	colorLink = "#D09B43";
	align = "left";
	shadow = 1;
	};
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.1;
	text = "";
	size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 1;
};

class AH_RscEdit {
	deletable = 0;
	fade = 0;

	type = 2;
	x = 0;
	y = 0;
	h = 0.04;
	w = 0.2;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {0.95, 0.95, 0.95, 1};
	colorDisabled[] = {1, 1, 1, 0.25};
	colorSelection[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
						1};
	autocomplete = "";
	text = "";
	size = 0.2;
	style = "0x00 + 0x40";
	font = "PuristaMedium";
	shadow = 2;
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	canModify = 1;
	tooltipColorText[] = {1, 1, 1, 1};
	tooltipColorBox[] = {1, 1, 1, 1};
	tooltipColorShade[] = {0, 0, 0, 0.65};
};

class AH_RscListbox {
	deletable = 0;
	fade = 0;

	type = 5;
	rowHeight = 0;
	colorText[] = {1, 1, 1, 1};
	colorDisabled[] = {1, 1, 1, 0.25};
	colorSelect[] = {0, 0, 0, 1};
	colorSelect2[] = {0, 0, 0, 1};
	colorSelectBackground[] = {0.95, 0.95, 0.95, 1};
	colorSelectBackground2[] = {1, 1, 1, 0.5};
	colorBackground[] = {0, 0, 0, 0.3};
	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect", 0.09, 1};
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
	colorPicture[] = {1, 1, 1, 1};
	colorPictureSelected[] = {1, 1, 1, 1};
	colorPictureDisabled[] = {1, 1, 1, 0.25};
	colorPictureRight[] = {1, 1, 1, 1};
	colorPictureRightSelected[] = {1, 1, 1, 1};
	colorPictureRightDisabled[] = {1, 1, 1, 0.25};
	colorTextRight[] = {1, 1, 1, 1};
	colorSelectRight[] = {0, 0, 0, 1};
	colorSelect2Right[] = {0, 0, 0, 1};
	tooltipColorText[] = {1, 1, 1, 1};
	tooltipColorBox[] = {1, 1, 1, 1};
	tooltipColorShade[] = {0, 0, 0, 0.65};
	class ListScrollBar {
		color[] = {1, 1, 1, 1};
		autoScrollEnabled = 1;
	};
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.3;
	style = 16;
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 0;
	colorShadow[] = {0, 0, 0, 0.5};
	period = 1.2;
	maxHistoryDelay = 1;
};
class AH_RscButton {
	deletable = 0;
	fade = 0;

	type = 1;
	text = "";
	colorText[] = {1, 1, 1, 1};
	colorDisabled[] = {1, 1, 1, 0.25};
	colorBackground[] = {0, 0, 0, 0.5};
	colorBackgroundDisabled[] = {0, 0, 0, 0.5};
	colorBackgroundActive[] = {0, 0, 0, 1};
	colorFocused[] = {0, 0, 0, 1};
	colorShadow[] = {0, 0, 0, 0};
	colorBorder[] = {0, 0, 0, 1};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter", 0.09, 1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush", 0.09, 1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1};
	style = 2;
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
	shadow = 2;
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX = 0;
	offsetY = 0;
	offsetPressedX = 0;
	offsetPressedY = 0;
	borderSize = 0;
};

class AH_IGUIBack {
	type = 0;
	idc = 124;
	style = 128;
	text = "";
	colorText[] = {0, 0, 0, 0};
	font = "PuristaMedium";
	sizeEx = 0;
	shadow = 0;
	x = 0.1;
	y = 0.1;
	w = 0.1;
	h = 0.1;
	colorbackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])",
						"(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])",
						"(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",
						"(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
};
class AH_RscCheckbox {
	idc = -1;
	type = 77;
	style = 0;
	checked = 0;
	x = "0.375 * safezoneW + safezoneX";
	y = "0.36 * safezoneH + safezoneY";
	w = "0.025 * safezoneW";
	h = "0.04 * safezoneH";
	color[] = {1, 1, 1, 0.7};
	colorFocused[] = {1, 1, 1, 1};
	colorHover[] = {1, 1, 1, 1};
	colorPressed[] = {1, 1, 1, 1};
	colorDisabled[] = {1, 1, 1, 0.2};
	colorBackground[] = {0, 0, 0, 0};
	colorBackgroundFocused[] = {0, 0, 0, 0};
	colorBackgroundHover[] = {0, 0, 0, 0};
	colorBackgroundPressed[] = {0, 0, 0, 0};
	colorBackgroundDisabled[] = {0, 0, 0, 0};
	textureChecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureUnchecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureFocusedChecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureFocusedUnchecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureHoverChecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureHoverUnchecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	texturePressedChecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	texturePressedUnchecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureDisabledChecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureDisabledUnchecked =
		"A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	tooltipColorText[] = {1, 1, 1, 1};
	tooltipColorBox[] = {1, 1, 1, 1};
	tooltipColorShade[] = {0, 0, 0, 0.65};
	soundEnter[] = {"", 0.1, 1};
	soundPush[] = {"", 0.1, 1};
	soundClick[] = {"", 0.1, 1};
	soundEscape[] = {"", 0.1, 1};
};

class AH_RscCombo
{
  	access = 0;
	type = 4;
	style = ST_LEFT;
	h = 0.05;
	wholeHeight = 0.25;
	colorSelect[] = {0,0,0,0.8};
	colorText[] = {1,1,1,1};
	colorBackground[] = {0,0,0,0.4};
	colorDisabled[] = {0,0,0,0.4};
	colorScrollbar[] = {0,0,0,0.8};
	font = "PuristaMedium";
	sizeEx = 0.04;
	soundSelect[] = {"",0.1,1};
	soundExpand[] = {"",0.1,1};
	soundCollapse[] = {"",0.1,1};
	maxHistoryDelay = 1.0;
	shadow = 0;
	arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa"; // Expand arrow
	arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa"; // Collapse arrow
	class ComboScrollBar
	{
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		thumb = "#(argb,8,8,3)color(1,1,1,1)";
		arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
		arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
		border = "#(argb,8,8,3)color(1,1,1,1)";
		shadow = 0;
	};
};


class AH_RscEdit_AH: AH_RscEdit {
    style=16;
    autocomplete="scripting";
};

class AH_RscListbox_AH: AH_RscListbox {
    type = 5;
    style = 0;
    border = false;
    borderSize = 0;

    class AH_ScrollBar
    {
        arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
        arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
        border = "#(argb,8,8,3)color(1,1,1,1)";
        color[] = {1,1,1,0.6};
        colorActive[] = {1,1,1,1};
        colorDisabled[] = {1,1,1,0.3};
        thumb = "#(argb,8,8,3)color(1,1,1,1)";
    };
    class ListScrollBar: AH_ScrollBar
    {
        color[] = {1,1,1,0.6};
        colorActive[] = {1,1,1,1};
        colorDisabled[] = {1,1,1,0.3};
        thumb = "#(argb,8,8,3)color(1,1,1,1)";
        arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
        arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
        border = "#(argb,8,8,3)color(1,1,1,1)";
        shadow = 0;
    };
};

class AH_Authenticate
{
	idd = 6972;
	movingEnabled = false;
	enableSimulation = true;

	 class controlsBackground {

        class background: AH_RscText
        {
            idc = 1000;
            x = 5.5 * GUI_GRID_W + GUI_GRID_X;
            y = 4 * GUI_GRID_H + GUI_GRID_Y;
            w = 27 * GUI_GRID_W;
            h = 15 * GUI_GRID_H;
            colorBackground[] = {-1,-1,-1,0.6};
        };
        class header_background: AH_RscText
        {
            idc = 1002;
            x = 5.5 * GUI_GRID_W + GUI_GRID_X;
            y = 4 * GUI_GRID_H + GUI_GRID_Y;
            w = 27 * GUI_GRID_W;
            h = 2.5 * GUI_GRID_H;
            colorBackground[] = {-1,-1,-1,0.5};
        };
        class header_text: AH_RscStructuredText
        {
            idc = 1101;
            text = "<t align='center' size='1.5'>Authentication Required</t>";
            x = 7 * GUI_GRID_W + GUI_GRID_X;
            y = 4.2 * GUI_GRID_H + GUI_GRID_Y;
            w = 24 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            colorBackground[] = {-1,-1,-1,0};
        };
        class main_text: AH_RscStructuredText
        {
            idc = 1100;
            text = "<t align='center'>Your account must be authenticated to play on this game server.<br/>To authenticate your account, please click the button below.</t>";
            x = 6.26 * GUI_GRID_W + GUI_GRID_X;
            y = 7.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 25.5 * GUI_GRID_W;
            h = 6 * GUI_GRID_H;
            colorBackground[] = {-1,-1,-1,0};
        };

        class footer_text: AH_RscStructuredText
        {
            idc = 1102;
            text = "<t align='center' size='0.7'>You will be redirected to an external website. You can close the website after authentication has been completed.</t>";
            x = 7 * GUI_GRID_W + GUI_GRID_X;
            y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 24 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            colorBackground[] = {-1,-1,-1,0};
        };
    };

    class controls {
        class auth_btn: AH_RscButton
        {
            idc = 1600;
            text = "Authenticate now";
            x = 7 * GUI_GRID_W + GUI_GRID_X;
            y = 14.2 * GUI_GRID_H + GUI_GRID_Y;
            w = 24 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
            url = "https://fini.dev/authenticate";
        };
        class close_btn: AH_RscButton
        {
            idc = 1601;
            text = "I've authenticated!";
            x = 7 * GUI_GRID_W + GUI_GRID_X;
            y = 14.2 * GUI_GRID_H + GUI_GRID_Y;
            w = 24 * GUI_GRID_W;
            h = 2 * GUI_GRID_H;
			action = "closeDialog 0;";
        };
    };
};

class AH_Menu {
    idd = 6971;
    movingEnable = 0;
    enableSimulation = 1;

    class controlsBackground {
        class Background: AH_IGUIBack
		{
			idc = 2200;

			x = 0.107094 * safezoneW + safezoneX;
			y = 0.06 * safezoneH + safezoneY;
			w = 0.814687 * safezoneW;
			h = 0.902 * safezoneH;
		};
		class thingy1: AH_RscStructuredText
		{
			idc = 2401;

			text = "Bantah V4"; //--- ToDo: Localize;
			x = 0.107094 * safezoneW + safezoneX;
			y = 0.027 * safezoneH + safezoneY;
			w = 0.814687 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
    };

    class controls {
        
		

		class LeftListbox: AH_RscListbox_AH
		{
			idc = 1500;

			x = 0.107094 * safezoneW + safezoneX;
			y = 0.06 * safezoneH + safezoneY;
			w = 0.190781 * safezoneW;
			h = 0.847 * safezoneH;
		};
		class MainListbox: AH_RscListbox_AH
		{
			idc = 1501;

			x = 0.308187 * safezoneW + safezoneX;
			y = 0.06 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.704 * safezoneH;
		};
		class RightListbox: AH_RscListbox_AH
		{
			idc = 1502;

			x = 0.715531 * safezoneW + safezoneX;
			y = 0.06 * safezoneH + safezoneY;
			w = 0.20625 * safezoneW;
			h = 0.847 * safezoneH;
		};
		class RightSearch: AH_RscEdit
		{
			idc = 1401;

			x = 0.716562 * safezoneW + safezoneX;
			y = 0.918 * safezoneH + safezoneY;
			w = 0.201094 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class LeftSearch: AH_RscEdit
		{
			idc = 1400;

			x = 0.110187 * safezoneW + safezoneX;
			y = 0.918 * safezoneH + safezoneY;
			w = 0.187688 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class MainEdit: AH_RscEdit
		{
			idc = 1402;

			x = 0.308187 * safezoneW + safezoneX;
			y = 0.775 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.132 * safezoneH;
			colorText[] = {0.71,0.125,0.251,1};
		};
		class Togglebutton: AH_RscButton
		{
			colorFocused[] = {0.71,0.125,0.251,1};

			idc = 1009;
			text = "Toggles"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.104 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class MainBtn: AH_RscButton
		{
			idc = 1817;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Main Menu"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.104 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class PlayersBtn: AH_RscButton
		{
			idc = 1816;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Player List"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.148 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class AdminLogsBtn: AH_RscButton
		{
			idc = 1815;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Admin Logs"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.192 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class HackerLogsBtn: AH_RscButton
		{
			idc = 1814;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Hacker Logs"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.0429 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class WeaponsBtn: AH_RscButton
		{
			idc = 1813;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Weapons"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.0451 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class VehiclesBtn: AH_RscButton
		{
			idc = 1812;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Vehicles"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class VItemsBtn: AH_RscButton
		{
			idc = 1811;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "V-Items"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class BackpacksBtn: AH_RscButton
		{
			idc = 1810;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Backpacks"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class LoadoutsBtn: AH_RscButton
		{
			idc = 1809;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Loadouts"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.456 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.0429 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class DeathLogsBtn: AH_RscButton
		{
			idc = 1808;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Death Logs"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class ViewerBtn: AH_RscButton
		{
			idc = 1807;
			colorFocused[] = {0.71,0.125,0.251,1};

			text = "Variable Viewer"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.544 * safezoneH + safezoneY;
			w = 0.0928125 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0.71,0.125,0.251,1};
		};
		class ExecBtn: AH_RscButton
		{
			idc = 1805;

			text = "Execute"; //--- ToDo: Localize;
			x = 0.308187 * safezoneW + safezoneX;
			y = 0.918 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class MsgEveryBtn: AH_RscButton
		{
			idc = 1804;

			text = "Message Everyone"; //--- ToDo: Localize;
			x = 0.447406 * safezoneW + safezoneX;
			y = 0.918 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.033 * safezoneH;
		};
		class MsgTargetBtn: AH_RscButton
		{
			idc = 1801;

			text = "Message Target"; //--- ToDo: Localize;
			x = 0.586625 * safezoneW + safezoneX;
			y = 0.918 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.033 * safezoneH;
		};
    };
};

class AH_LagSwitch
{
	idd = 6970;
	movingEnabled = false;
	enableSimulation = true;

	 class controlsBackground {
	    class RscText_1004: AH_RscText
		{
			idc = -1;
			x = -28 * GUI_GRID_W + GUI_GRID_X;
			y = -10 * GUI_GRID_H + GUI_GRID_Y;
			w = 96 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscText_1005: AH_RscText
		{
			idc = -1;
			x = -28 * GUI_GRID_W + GUI_GRID_X;
			y = 34 * GUI_GRID_H + GUI_GRID_Y;
			w = 96 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscText_1006: AH_RscText
		{
			idc = -1;
			x = -28 * GUI_GRID_W + GUI_GRID_X;
			y = -9 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.5 * GUI_GRID_W;
			h = 43 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscText_1007: AH_RscText
		{
			idc = -1;
			x = 66.46 * GUI_GRID_W + GUI_GRID_X;
			y = -9 * GUI_GRID_H + GUI_GRID_Y;
			w = 1.5 * GUI_GRID_W;
			h = 43 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class RscText_1008: AH_RscText
		{
			idc = -1;
			x = -26.32 * GUI_GRID_W + GUI_GRID_X;
			y = -8.88 * GUI_GRID_H + GUI_GRID_Y;
			w = 92.6061 * GUI_GRID_W;
			h = 42.7096 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.2};
		};
	};

	class controls {
		
		class RscText_1000: AH_RscText
		{
			idc = -1;
			text = "LAGSWITCH DETECTION";
			x = 10 * GUI_GRID_W + GUI_GRID_X;
			y = -7.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 20.5 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
			colorText[] = {135,3,3,1};
			sizeEx = 2 * GUI_GRID_H;
			class Attributes {
                align = "center";
            };
		};
		class RscText_1001: AH_RscText
		{
			idc = -1;
			text = "NETWORK LAG DETECTED";
			x = 8 * GUI_GRID_W + GUI_GRID_X;
			y = 29 * GUI_GRID_H + GUI_GRID_Y;
			w = 24.5 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
			colorText[] = {135,3,3,1};
			sizeEx = 2 * GUI_GRID_H;
			class Attributes {
                align = "center";
            };
		};
		class RscText_1002: AH_RscStructuredText
		{
			idc = -1;
			text = "<t align='center' size='1.7'>IF YOU ARE EXPERIENCING THESE INTERRUPTIONS, CHECK YOUR CONNECTION</t>";
			x = -17.5 * GUI_GRID_W + GUI_GRID_X;
			y = 7.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 75.5 * GUI_GRID_W;
			h = 3.5 * GUI_GRID_H;
			colorText[] = {135,3,3,1};
		};
		class RscText_1003: AH_RscStructuredText
		{
			idc = -1;
			text = "IF YOU BELIEVE THIS IS A SERVER SIDE ISSUE, PLEASE REPORT THIS TO OUR SUPPORT TEAM";
			x = -14.5 * GUI_GRID_W + GUI_GRID_X;
			y = 12.5 * GUI_GRID_H + GUI_GRID_Y;
			w = 69.5 * GUI_GRID_W;
			h = 7.5 * GUI_GRID_H;
			colorText[] = {135,3,3,1};
			sizeEx = 1.2 * GUI_GRID_H;
            class Attributes {
                align = "center";
            };
		};
	};
};


class AH_ExecMenu
{
    idd=6969;
    movingEnable = false;
    
    class controlsBackground {
		class AH_DevBackground: AH_RscText
		{
			idc = 1031;
			x = 0.0312851 * safezoneW + safezoneX;
			y = 0.104778 * safezoneH + safezoneY;
			w = 0.183014 * safezoneW;
			h = 0.830355 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.7};
		};
		class AH_DevHeaderBg: AH_RscText
		{
			idc = 1000;

			x = 0.0313498 * safezoneW + safezoneX;
			y = 0.0811797 * safezoneH + safezoneY;
			w = 0.183014 * safezoneW;
			h = 0.0235679 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.9};
		};

		

		class Background: AH_RscText
		{
			idc = 1000;

			x = 0.259373 * safezoneW + safezoneX;
			y = 0.105053 * safezoneH + safezoneY;
			w = 0.598062 * safezoneW;
			h = 0.492593 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.7};
		};

		class ExecutorTopBackground: AH_RscText
		{
			idc = 1000;

			x = 0.259285 * safezoneW + safezoneX;
			y = 0.0809917 * safezoneH + safezoneY;
			w = 0.598125 * safezoneW;
			h = 0.0238519 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.9};
		};

		class WatchTitleBackground: AH_RscText
		{
			idc = 1000;

			x = 0.259285 * safezoneW + safezoneX;
			y = 0.601321 * safezoneH + safezoneY;
			w = 0.598125 * safezoneW;
			h = 0.0238519 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.9};
		};
		class WatchBackground: AH_RscText
		{
			idc = 1000;

			x = 0.259373 * safezoneW + safezoneX;
			y = 0.625007 * safezoneH + safezoneY;
			w = 0.598084 * safezoneW;
			h = 0.310168 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.7};
		};
    };

    class controls {
		class ExecutorText: AH_RscText
		{
			idc = 1005;

			text = "Executor Menu"; //--- ToDo: Localize;
			x = 0.262458 * safezoneW + safezoneX;
			y = 0.0776081 * safezoneH + safezoneY;
			w = 0.0865625 * safezoneW;
			h = 0.0272222 * safezoneH;
		};
		class ScriptEdit: AH_RscEdit_AH
		{
			idc = 1399;

			x = 0.268187 * safezoneW + safezoneX;
			y = 0.11464 * safezoneH + safezoneY;
			w = 0.414267 * safezoneW;
			h = 0.375961 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class ScriptPrevious: AH_RscButton
		{
			idc = 1605;

			text = "<"; //--- ToDo: Localize;
			x = 0.267922 * safezoneW + safezoneX;
			y = 0.530077 * safezoneH + safezoneY;
			w = 0.0191146 * safezoneW;
			h = 0.0449538 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class ExecPlayer: AH_RscButton
		{
			idc = 1600;

			text = "Execute on Player"; //--- ToDo: Localize;
			x = 0.694794 * safezoneW + safezoneX;
			y = 0.532709 * safezoneH + safezoneY;
			w = 0.154248 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class ExecLocal: AH_RscButton
		{
			idc = 1601;

			text = "Execute (Local)"; //--- ToDo: Localize;
			x = 0.411329 * safezoneW + safezoneX;
			y = 0.530829 * safezoneH + safezoneY;
			w = 0.0775639 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class ExecGloal: AH_RscButton
		{
			idc = 1602;

			text = "Execute (Global)"; //--- ToDo: Localize;
			x = 0.494711 * safezoneW + safezoneX;
			y = 0.530829 * safezoneH + safezoneY;
			w = 0.0781801 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class ExecServer: AH_RscButton
		{
			idc = 1603;

			text = "Execute (Server)"; //--- ToDo: Localize;
			x = 0.578887 * safezoneW + safezoneX;
			y = 0.530829 * safezoneH + safezoneY;
			w = 0.0781801 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class ScriptNext: AH_RscButton
		{
			idc = 1604;

			text = ">"; //--- ToDo: Localize;
			x = 0.663327 * safezoneW + safezoneX;
			y = 0.530829 * safezoneH + safezoneY;
			w = 0.0188542 * safezoneW;
			h = 0.044028 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class ExecResult: AH_RscEdit_AH
		{
			idc = 1398;

			x = 0.268187 * safezoneW + safezoneX;
			y = 0.49812 * safezoneH + safezoneY;
			w = 0.414267 * safezoneW;
			h = 0.0225576 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class PlayerList: AH_RscListbox_AH
		{
			idc = 1500;

			x = 0.694794 * safezoneW + safezoneX;
			y = 0.11464 * safezoneH + safezoneY;
			w = 0.154248 * safezoneW;
			h = 0.375961 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class PlayerSearch: AH_RscEdit
		{
			idc = 1400;

			x = 0.694794 * safezoneW + safezoneX;
			y = 0.49812 * safezoneH + safezoneY;
			w = 0.154248 * safezoneW;
			h = 0.0225576 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class WatchTitle: AH_RscText
		{
			idc = 1003;

			text = "Watch Statements"; //--- ToDo: Localize;
			x = 0.260871 * safezoneW + safezoneX;
			y = 0.599254 * safezoneH + safezoneY;
			w = 0.0865625 * safezoneW;
			h = 0.0272222 * safezoneH;
		};
		class Watch1: AH_RscEdit_AH
		{
			idc = 1401;

			x = 0.271624 * safezoneW + safezoneX;
			y = 0.640985 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
		};
		class Watch1Result: AH_RscEdit_AH
		{
			idc = 1402;

			x = 0.271713 * safezoneW + safezoneX;
			y = 0.667303 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class Watch1Toggle: AH_RscCheckbox
		{
			idc = 2800;

			x = 0.832824 * safezoneW + safezoneX;
			y = 0.642489 * safezoneH + safezoneY;
			w = 0.0141668 * safezoneW;
			h = 0.0262964 * safezoneH;
		};
		class Watch2: AH_RscEdit_AH
		{
			idc = 1403;

			x = 0.271713 * safezoneW + safezoneX;
			y = 0.699259 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
		};
		class Watch2Result: AH_RscEdit_AH
		{
			idc = 1404;

			x = 0.271713 * safezoneW + safezoneX;
			y = 0.725765 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class Watch2Toggle: AH_RscCheckbox
		{
			idc = 2801;

			x = 0.832824 * safezoneW + safezoneX;
			y = 0.700763 * safezoneH + safezoneY;
			w = 0.0141668 * safezoneW;
			h = 0.0262964 * safezoneH;
		};
		class Watch3: AH_RscEdit_AH
		{
			idc = 1405;

			x = 0.271624 * safezoneW + safezoneX;
			y = 0.756781 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
		};
		class Watch3Result: AH_RscEdit_AH
		{
			idc = 1406;

			x = 0.271713 * safezoneW + safezoneX;
			y = 0.783099 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class Watch3Toggle: AH_RscCheckbox
		{
			idc = 2802;

			x = 0.832295 * safezoneW + safezoneX;
			y = 0.759789 * safezoneH + safezoneY;
			w = 0.0141668 * safezoneW;
			h = 0.0262964 * safezoneH;
		};
		class Watch4: AH_RscEdit_AH
		{
			idc = 1407;

			x = 0.271713 * safezoneW + safezoneX;
			y = 0.813927 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
		};
		class Watch4Result: AH_RscEdit_AH
		{
			idc = 1408;

			x = 0.271713 * safezoneW + safezoneX;
			y = 0.840244 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class Watch4Toggle: AH_RscCheckbox
		{
			idc = 2803;

			x = 0.832295 * safezoneW + safezoneX;
			y = 0.813927 * safezoneH + safezoneY;
			w = 0.0141668 * safezoneW;
			h = 0.0262964 * safezoneH;
		};
		class Watch5: AH_RscEdit_AH
		{
			idc = 1409;

			x = 0.271713 * safezoneW + safezoneX;
			y = 0.870321 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,1};
		};
		class Watch5Result: AH_RscEdit_AH
		{
			idc = 1410;

			x = 0.271713 * safezoneW + safezoneX;
			y = 0.896639 * safezoneH + safezoneY;
			w = 0.546562 * safezoneW;
			h = 0.0219999 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class Watch5Toggle: AH_RscCheckbox
		{
			idc = 2804;

			x = 0.833144 * safezoneW + safezoneX;
			y = 0.8722 * safezoneH + safezoneY;
			w = 0.0141668 * safezoneW;
			h = 0.0262964 * safezoneH;
		};
		class AH_ExecMode: AH_RscCombo
		{
			idc = 2100;
			x = 0.293747 * safezoneW + safezoneX;
			y = 0.555007 * safezoneH + safezoneY;
			w = 0.111948 * safezoneW;
			h = 0.018798 * safezoneH;
		};
		class AH_ExecArgs: AH_RscEdit_AH
		{
			idc = 1411;
			x = 0.294154 * safezoneW + safezoneX;
			y = 0.530974 * safezoneH + safezoneY;
			w = 0.111605 * safezoneW;
			h = 0.0211125 * safezoneH;
			colorBackground[] = {-1,-1,-1,0.4};
		};
		class AH_DevTitle: AH_RscText
		{
			idc = 1006;

			text = "Developer options"; //--- ToDo: Localize;
			x = 0.0328482 * safezoneW + safezoneX;
			y = 0.078924 * safezoneH + safezoneY;
			w = 0.0865625 * safezoneW;
			h = 0.0272222 * safezoneH;
		};
		class AH_DevOptions: AH_RscListbox_AH
		{
			idc = 1501;
			x = 0.0372553 * safezoneW + safezoneX;
			y = 0.11464 * safezoneH + safezoneY;
			w = 0.171877 * safezoneW;
			h = 0.808316 * safezoneH;
		};
    };
};