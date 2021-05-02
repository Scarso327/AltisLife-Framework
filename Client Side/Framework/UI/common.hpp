// Geometry

#define SAFEZONE_X(value) x = (value) * safezoneW + safezoneX
#define SAFEZONE_Y(value) y = (value) * safezoneH + safezoneY
#define SAFEZONE_W(value) w = (value) * safezoneW
#define SAFEZONE_H(value) h = (value) * safezoneH

#define MARGIN_X 0.00515625
#define MARGIN_Y 0.011

#define BUTTON_MARGIN_X (MARGIN_X / 2)
#define BUTTON_MARGIN_Y (MARGIN_Y / 2)

// Used for creating a line of equal width boxes.
#define HORIZONTAL_GRID_X(x, width, itemNumber) (x + (width * itemNumber)) + (MARGIN_X * itemNumber)
#define HORIZONTAL_GRID_W(width, items) (((width - (MARGIN_X * (items - 1))) / items))

#define VERTICAL_GRID_Y(y, height, itemNumber, margin) (y + (height * itemNumber)) + (margin * itemNumber)
#define VERTICAL_GRID_H(height, items, margin) (((height - (margin * (items - 1))) / items))

#define BUTTON_H 0.022

// Colours

#define NO_COLOUR {0, 0, 0, 0}

// Structure
#define HEADER_COLOUR_SOLID {0.1, 0.1, 0.1, 1}
#define HEADER_COLOUR {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 1}
#define BODY_COLOUR {0.204, 0.2, 0.204, 1}
#define FOOTER_COLOUR {0.125, 0.122, 0.125, 1}

// Content
#define INNER_BODY_COLOUR {0.098, 0.094, 0.098, 1}

// Control types
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
#define CT_HITZONES         17
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
#define CT_ITEMSLOT         103
#define CT_CHECKBOX         77

// Static styles
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
#define ST_UPPERCASE      0xC0
#define ST_LOWERCASE      0xD0
#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200
#define ST_KEEP_ASPECT_RATIO  0x800

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           0x400

#define SL_TEXTURES       0x10

// progress bar
#define ST_VERTICAL       0x01
#define ST_HORIZONTAL     0

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

// Tree styles
#define TR_SHOWROOT       1
#define TR_AUTOCOLLAPSE   2

#include "gridCommon.inc"

class Life_Checkbox
{
    access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
    idc = -1; // Control identification (without it, the control won't be displayed)
    type = 77; // Type
    style = ST_LEFT + ST_MULTI; // Style
    default = 0; // Control selected by default (only one within a display can be used)
    blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

    x = 0;
    y = 0;
    w = 1 * GUI_GRID_CENTER_W; // Width
    h = 1 * GUI_GRID_CENTER_H; // Height

    //Colors
    color[] = { 1, 1, 1, 0.7 }; // Texture color
    colorFocused[] = { 1, 1, 1, 1 }; // Focused texture color
    colorHover[] = { 1, 1, 1, 1 }; // Mouse over texture color
    colorPressed[] = { 1, 1, 1, 1 }; // Mouse pressed texture color
    colorDisabled[] = { 1, 1, 1, 0.2 }; // Disabled texture color

    //Background colors
    colorBackground[] = { 0, 0, 0, 0 }; // Fill color
    colorBackgroundFocused[] = { 0, 0, 0, 0 }; // Focused fill color
    colorBackgroundHover[] = { 0, 0, 0, 0 }; // Mouse hover fill color
    colorBackgroundPressed[] = { 0, 0, 0, 0 }; // Mouse pressed fill color
    colorBackgroundDisabled[] = { 0, 0, 0, 0 }; // Disabled fill color

    //Textures
    textureChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";        //Texture of checked CheckBox.
    textureUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";        //Texture of unchecked CheckBox.
    textureFocusedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";    //Texture of checked focused CheckBox (Could be used for showing different texture when focused).
    textureFocusedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";    //Texture of unchecked focused CheckBox.
    textureHoverChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    textureHoverUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
    texturePressedChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    texturePressedUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
    textureDisabledChecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
    textureDisabledUnchecked = "\A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";

    tooltip = ""; // Tooltip text
    tooltipColorShade[] = { 0, 0, 0, 1 }; // Tooltip background color
    tooltipColorText[] = { 1, 1, 1, 1 }; // Tooltip text color
    tooltipColorBox[] = { 1, 1, 1, 1 }; // Tooltip frame color

    //Sounds
    soundClick[] = { "\A3\ui_f\data\sound\RscButton\soundClick", 0.09, 1 }; // Sound played after control is activated in format {file, volume, pitch}
    soundEnter[] = { "\A3\ui_f\data\sound\RscButton\soundEnter", 0.09, 1 }; // Sound played when mouse cursor enters the control
    soundPush[] = { "\A3\ui_f\data\sound\RscButton\soundPush", 0.09, 1 }; // Sound played when the control is pushed down
    soundEscape[] = { "\A3\ui_f\data\sound\RscButton\soundEscape", 0.09, 1 }; // Sound played when the control is released after pushing down

};

class Life_RscScrollBar
{
    color[] = {1,1,1,0.6};
    colorActive[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.3};
    thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
    arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
    arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
    border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
    shadow = 0;
    scrollSpeed = 0.06;
    width = 0;
    height = 0;
    autoScrollEnabled = 1;
    autoScrollSpeed = -1;
    autoScrollDelay = 5;
    autoScrollRewind = 0;
};

class Life_RscControlsGroup {
    type = 15;
    idc = -1;
    x = 0;
    y = 0;
    w = 1;
    h = 1;
    shadow = 0;
    style = 16;

    class VScrollBar : Life_RscScrollBar
    {
        width = 0.021;
        autoScrollEnabled = 1;
    };

    class HScrollBar : Life_RscScrollBar
    {
        height = 0.028;
    };

    class Controls {};
};

class Life_RscControlsGroupNoScrollbars : Life_RscControlsGroup {
    class VScrollbar : VScrollbar {
        width = 0;
    };

    class HScrollbar : HScrollbar {
        height = 0;
    };
};

class Life_RscHud
{
    idc = -1;
    type = 0;
    style = 0x00;
    colorBackground[] = { 1 , 1 , 1 , 0 };
    colorText[] = { 1 , 1 , 1 , 1 };
    font = "RobotoCondensedBold";
    sizeEx = 0.025;
    h = 0.25;
    text = "";
};

class Life_RscListNBox
{
    style = 16;
    type = 102;
    shadow = 0;
    font = "RobotoCondensed";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    color[] = {0.95,0.95,0.95,1};
    colorText[] = {1,1,1,1.0};
    colorDisabled[] = {1,1,1,0.25};
    colorScrollbar[] = {0.95,0.95,0.95,1};
    colorSelect[] = {0,0,0,1};
    colorSelect2[] = {0,0,0,1};
    colorSelectBackground[] = {0.8,0.8,0.8,1};
    colorSelectBackground2[] = {1,1,1,0.5};
    colorPicture[] = {1,1,1,1};
    colorPictureSelected[] = {1,1,1,1};
        colorPictureDisabled[] = {1,1,1,1};
    soundSelect[] = {"",0.1,1};
    soundExpand[] = {"",0.1,1};
    soundCollapse[] = {"",0.1,1};
    period = 1.2;
    maxHistoryDelay = 0.5;
    autoScrollSpeed = -1;
    autoScrollDelay = 5;
    autoScrollRewind = 0;
    class ListScrollBar: Life_RscScrollBar{};
    class ScrollBar: Life_RscScrollBar{};
};


class Life_RscText {
    x = 0;
    y = 0;
    h = 0.037;
    w = 0.3;
    type = 0;
    style = 0;
    shadow = 0;
    colorShadow[] = {0, 0, 0, 0.5};
    font = "RobotoCondensed";
    SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    text = "";
    colorText[] = {1, 1, 1, 1.0};
    colorBackground[] = {0, 0, 0, 0};
    linespacing = 1;
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
};

class Life_RscTextHeader : Life_RscText {
    colorBackground[] = HEADER_COLOUR;
    shadow = 0;
};

class Life_RscLine: Life_RscText {
    idc = -1;
    style = 176;
    x = 0.17;
    y = 0.48;
    w = 0.66;
    h = 0;
    text = "";
    colorBackground[] = {0, 0, 0, 0};
    colorText[] = {1, 1, 1, 1.0};
};

class Life_RscTree {
    type = CT_TREE;
    style = ST_SINGLE;
    x = 0;
    y = 0;
    font = "RobotoCondensed";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    hiddenTexture = "\a3\3DEN\Data\Controls\ctrlTree\hiddenTexture_ca.paa";
    expandedTexture = "\a3\3DEN\Data\Controls\ctrlTree\expandedTexture_ca.paa";
    expandOnDoubleclick = 1;
	colorBackground[] = {0,0,0,0};
	colorSelect[] = {1,1,1,0.7};
	colorDisabled[] = {1,1,1,0.25};
	colorText[] = {1,1,1,1};
	colorSelectText[] = {0,0,0,1};
	colorBorder[] = {0,0,0,0};
	colorSearch[] =
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
	};
	colorMarked[] = {0.2,0.3,0.7,1};
	colorMarkedText[] = {0,0,0,1};
	colorMarkedSelected[] = {0,0.5,0.5,1};
	multiselectEnabled = 0;
	colorPicture[] = {1,1,1,1};
	colorPictureSelected[] = {0,0,0,1};
	colorPictureDisabled[] = {1,1,1,0.25};
	colorPictureRight[] = {1,1,1,1};
	colorPictureRightSelected[] = {0,0,0,1};
	colorPictureRightDisabled[] = {1,1,1,0.25};
	colorArrow[] = {1,1,1,1};
    colorLines[] = {0,0,0,0};
    borderSize = 0;
    maxHistoryDelay = 1;
    class ScrollBar: Life_RscScrollBar {};
};

class Life_RscTitle: Life_RscText {
    style = 0;
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    colorText[] = {0.95, 0.95, 0.95, 1};
};

class life_RscPicture {
    shadow = 0;
    type = 0;
    style = 48;
    sizeEx = 0.023;
    font = "RobotoCondensed";
    text = ""; // Stop error message...
    colorBackground[] = {};
    colorText[] = {};
    x = 0;
    y = 0;
    w = 0.2;
    h = 0.15;
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
};

class Life_RscTextMulti: Life_RscText
{
    linespacing = 1;
    style = 0 + 16 + 0x200;
};

class Life_RscPictureKeepAspect : Life_RscPicture
{
    style = 0x30 + 0x800;
};

class Life_RscStructuredText {
    type = 13;
    style = 0;
    x = 0;
    y = 0;
    h = 0.035;
    w = 0.1;
    text = "";
    size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    colorText[] = {1, 1, 1, 1.0};
    shadow = 1;

    class Attributes {
        font = "RobotoCondensed";
        color = "#ffffff";
        align = "left";
        shadow = 1;
    };
};

class Life_RscActiveText {
idc = -1;
    type = 11;
    style = 0;
    x = 0;
    y = 0;
    h = 0.037;
    w = 0.3;
    sizeEx = 0.040;
    font = "RobotoCondensed";
    color[] = {1, 1, 1, 1};
    colorActive[] = {1, 0.2, 0.2, 1};
    colorDisabled[] = {1, 1, 1, 0.75};
    soundEnter[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",0.09,1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundClick",0.09,1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",0.09,1};
    action = "";
    text = "";
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
};

class Life_RscButton
{
    style = 2;
    x = 0;
    y = 0;
    w = 0.095589;
    h = 0.039216;
    shadow = 2;
    font = "RobotoCondensed";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    colorText[] = {1,1,1,1.0};
    colorDisabled[] = {0.4,0.4,0.4,1};
    colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",0.7};
    colorBackgroundActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
    colorBackgroundDisabled[] = {0.95,0.95,0.95,1};
    offsetX = 0.003;
    offsetY = 0.003;
    offsetPressedX = 0.002;
    offsetPressedY = 0.002;
    colorFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
    colorShadow[] = {0,0,0,0};
    colorBorder[] = {0,0,0,0};
    borderSize = 0.0;
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
};

class Life_RscButtonTextOnly : Life_RscButton {
    SizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
    colorBackground[] = {1, 1, 1, 0};
    colorBackgroundActive[] = {1, 1, 1, 0};
    colorBackgroundDisabled[] = {1, 1, 1, 0};
    colorFocused[] = {1, 1, 1, 0};
    colorShadow[] = {1, 1, 1, 0};
    borderSize = 0.0;
};

class Life_RscShortcutButton {
    idc = -1;
    style = 0;
    default = 0;
    shadow = 1;
    w = 0.183825;
    h = "((((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
    color[] = {1,1,1,1.0};
    colorFocused[] = {1,1,1,1.0};
    color2[] = {0.95,0.95,0.95,1};
    colorDisabled[] = {1,1,1,0.25};
    colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
    colorBackgroundFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
    colorBackground2[] = {1,1,1,1};
    animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
    animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
    animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
    animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\over_ca.paa";
    animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\focus_ca.paa";
    animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\down_ca.paa";
    periodFocus = 1.2;
    periodOver = 0.8;
    class HitZone
    {
        left = 0.0;
        top = 0.0;
        right = 0.0;
        bottom = 0.0;
    };
    class ShortcutPos
    {
        left = 0;
        top = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
        w = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
        h = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    };
    class TextPos
    {
        left = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
        top = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
        right = 0.005;
        bottom = 0.0;
    };
    period = 0.4;
    font = "RobotoCondensed";
    size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    text = "";
    soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
    action = "";
    class Attributes
    {
        font = "RobotoCondensed";
        color = "#E5E5E5";
        align = "left";
        shadow = "true";
    };
    class AttributesImage
    {
        font = "RobotoCondensed";
        color = "#E5E5E5";
        align = "left";
    };
};

class Life_RscButtonMenu : Life_RscShortcutButton {
    idc = -1;
    type = 16;
    style = "0x02 + 0xC0";
    default = 0;
    shadow = 0;
    x = 0;
    y = 0;
    w = 0.095589;
    h = 0.039216;
    animTextureNormal = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDisabled = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureOver = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureFocused = "#(argb,8,8,3)color(1,1,1,1)";
    animTexturePressed = "#(argb,8,8,3)color(1,1,1,1)";
    animTextureDefault = "#(argb,8,8,3)color(1,1,1,1)";
    colorBackground[] = {0,0,0,0.8};
    colorBackgroundFocused[] = {1,1,1,1};
    colorBackground2[] = {0.75,0.75,0.75,1};
    color[] = {1,1,1,1};
    colorFocused[] = {0,0,0,1};
    color2[] = {0,0,0,1};
    colorText[] = {1,1,1,1};
    colorDisabled[] = {1,1,1,0.25};
    period = 1.2;
    periodFocus = 1.2;
    periodOver = 1.2;
    size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
    class TextPos
    {
        left = "0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
        top = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
        right = 0.005;
        bottom = 0.0;
    };
    class Attributes
    {
        font = "RobotoCondensed";
        color = "#E5E5E5";
        align = "left";
        shadow = "false";
    };
    class ShortcutPos
    {
        left = "(6.25 * (((safezoneW / safezoneH) min 1.2) / 40)) - 0.0225 - 0.005";
        top = 0.005;
        w = 0.0225;
        h = 0.03;
    };
    soundEnter[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",0.09,1};
    soundPush[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundPush",0.09,1};
    soundClick[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundClick",0.09,1};
    soundEscape[] = {"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",0.09,1};
    textureNoShortcut = "";
};

class Life_RscShortcutButtonMain : Life_RscShortcutButton {
    idc = -1;
    style = 0;
    default = 0;
    w = 0.313726;
    h = 0.104575;
    color[] = {1, 1, 1, 1.0};
    colorDisabled[] = {1, 1, 1, 0.25};

    class HitZone {
        left = 0.0;
        top = 0.0;
        right = 0.0;
        bottom = 0.0;
    };

    class ShortcutPos {
        left = 0.0145;
        top = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)) / 2";
        w = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2) * (3/4)";
        h = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
    };

    class TextPos {
        left = "(        ((safezoneW / safezoneH) min 1.2) / 32) * 1.5";
        top = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20)*2 - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)) / 2";
        right = 0.005;
        bottom = 0.0;
    };
    animTextureNormal = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
    animTextureDisabled = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\disabled_ca.paa";
    animTextureOver = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\over_ca.paa";
    animTextureFocused = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\focus_ca.paa";
    animTexturePressed = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\down_ca.paa";
    animTextureDefault = "\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
    period = 0.5;
    font = "RobotoCondensed";
    size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
    text = "";
    soundEnter[] = {"\A3\ui_f\data\sound\onover", 0.09, 1};
    soundPush[] = {"\A3\ui_f\data\sound\new1", 0.0, 0};
    soundClick[] = {"\A3\ui_f\data\sound\onclick", 0.07, 1};
    soundEscape[] = {"\A3\ui_f\data\sound\onescape", 0.09, 1};
    action = "";

    class Attributes {
        font = "RobotoCondensed";
        color = "#E5E5E5";
        align = "left";
        shadow = "false";
    };

    class AttributesImage {
        font = "RobotoCondensed";
        color = "#E5E5E5";
        align = "false";
    };
};

class Life_RscCheckbox {
    idc = -1;
    type = 7;
    style = 0;
    x = "LINE_X(XVAL)";
    y = LINE_Y;
    w = "LINE_W(WVAL)";
    h = 0.029412;
    colorText[] = {1, 0, 0, 1};
    color[] = {0, 0, 0, 0};
    colorBackground[] = {0, 0, 1, 1};
    colorTextSelect[] = {0, 0.8, 0, 1};
    colorSelectedBg[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 1};
    colorSelect[] = {0, 0, 0, 1};
    colorTextDisable[] = {0.4, 0.4, 0.4, 1};
    colorDisable[] = {0.4, 0.4, 0.4, 1};
    font = "RobotoCondensed";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
    rows = 1;
    5ns = 1;
    strings[] = {UNCHECKED};
    checked_strings[] = {CHECKED};
};

class Life_RscProgress
{
    type = 8;
    style = 0;
    x = 0;
    y = 0;
    w = 0.313726;
    h = 0.0261438;
    texture = "";
    shadow = 0;
    colorFrame[] = {0, 0, 0, 0};
    colorBackground[] = {0,0,0,0.7};
    colorBar[] = { 0.06, 0.06, 0.06, 0.85 };
    // colorBar[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
};

class Life_RscListBox
{
    style = 16;
    idc = -1;
    type = 5;
    w = 0.275;
    h = 0.04;
    font = "RobotoCondensed";
    colorSelect[] = {1, 1, 1, 1};
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0.28,0.28,0.28,0.28};
    colorSelect2[] = {1, 1, 1, 1};
    colorSelectBackground[] = {0.95, 0.95, 0.95, 0.5};
    colorSelectBackground2[] = {1, 1, 1, 0.5};
    colorScrollbar[] = {0.2, 0.2, 0.2, 1};
    colorPicture[] = {1,1,1,1};
    colorPictureSelected[] = {1,1,1,1};
    colorPictureDisabled[] = {1,1,1,1};
    arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
    arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
    wholeHeight = 0.45;
    rowHeight = 0.04;
    color[] = {0.7, 0.7, 0.7, 1};
    colorActive[] = {0,0,0,1};
    colorDisabled[] = {0,0,0,0.3};
    sizeEx = 0.030;
    soundSelect[] = {"",0.1,1};
    soundExpand[] = {"",0.1,1};
    soundCollapse[] = {"",0.1,1};
    maxHistoryDelay = 1;
    autoScrollSpeed = -1;
    autoScrollDelay = 5;
    autoScrollRewind = 0;
    tooltipColorText[] = {1,1,1,1};
    tooltipColorBox[] = {1,1,1,1};
    tooltipColorShade[] = {0,0,0,0.65};
    class ListScrollBar: Life_RscScrollBar
    {
        color[] = {1,1,1,1};
        autoScrollEnabled = 1;
    };
};

class Life_RscEdit {
    type = 2;
    style = 0x00 + 0x40;
    font = "RobotoCondensed";
    shadow = 2;
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    colorBackground[] = {0, 0, 0, 1};
    soundSelect[] = {"",0.1,1};
    soundExpand[] = {"",0.1,1};
    colorText[] = {0.95, 0.95, 0.95, 1};
    colorDisabled[] = {1, 1, 1, 0.25};
    autocomplete = false;
    colorSelection[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 1};
    canModify = 1;
};

class Life_RscSlider {
    h = 0.025;
    color[] = {1, 1, 1, 0.8};
    colorActive[] = {1, 1, 1, 1};
};

class life_RscXSliderH
{
    style = 1024;
    type = 43;
    shadow = 2;
    x = 0;
    y = 0;
    h = 0.029412;
    w = 0.400000;
    color[] = {
            1, 1, 1, 0.7
    };
    colorActive[] = {
            1, 1, 1, 1
    };
    colorDisabled[] = {
            1, 1, 1, 0.500000
    };
    arrowEmpty = "\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
    arrowFull = "\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
    border = "\A3\ui_f\data\gui\cfg\slider\border_ca.paa";
    thumb = "\A3\ui_f\data\gui\cfg\slider\thumb_ca.paa";
};

class Life_RscFrame {
    type = 0;
    idc = -1;
    style = 64;
    shadow = 2;
    colorBackground[] = {0, 0, 0, 0};
    colorText[] = {1, 1, 1, 1};
    font = "RobotoCondensed";
    sizeEx = 0.02;
    text = "";
};

class Life_RscBackground: Life_RscText {
    type = 0;
    IDC = -1;
    style = 512;
    shadow = 0;
    x = 0.0;
    y = 0.0;
    w = 1.0;
    h = 1.0;
    text = "";
    ColorBackground[] = {0.48, 0.5, 0.35, 1};
    ColorText[] = {0.1, 0.1, 0.1, 1};
    font = "RobotoCondensed";
    SizeEx = 1;
};

class Life_RscHTML {
    colorText[] = {1, 1, 1, 1.0};
    colorBold[] = {1, 1, 1, 1.0};
    colorLink[] = {1, 1, 1, 0.75};
    colorLinkActive[] = {1, 1, 1, 1.0};
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
    prevPage = "\A3\ui_f\data\gui\Rsccommon\Rschtml\arrow_left_ca.paa";
    nextPage = "\A3\ui_f\data\gui\Rsccommon\Rschtml\arrow_right_ca.paa";
    shadow = 2;

    class H1 {
        font = "RobotoCondensed";
        fontBold = "RobotoCondensedBold";
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
        align = "left";
    };

    class H2 {
        font = "RobotoCondensed";
        fontBold = "RobotoCondensedBold";
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
        align = "right";
    };

    class H3 {
        font = "RobotoCondensed";
        fontBold = "RobotoCondensedBold";
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
        align = "left";
    };

    class H4 {
        font = "RobotoCondensed";
        fontBold = "RobotoCondensedBold";
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
        align = "left";
    };

    class H5 {
        font = "RobotoCondensed";
        fontBold = "RobotoCondensedBold";
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
        align = "left";
    };

    class H6 {
        font = "RobotoCondensed";
        fontBold = "RobotoCondensedBold";
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
        align = "left";
    };

    class P {
        font = "RobotoCondensed";
        fontBold = "RobotoCondensedBold";
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
        align = "left";
    };
};

class Life_RscHitZones {
    x = 0;
    y = 0;
    w = 0.1;
    h = 0.1;
    xCount = 1;
    yCount = 1;
    xSpace = 0;
    ySpace = 0;
};

class Life_RscMapControl
{
    access = 0;
    type = 101;
    idc = 51;
    style = 48;
    colorBackground[] = {0.969,0.957,0.949,1};
    colorOutside[] = {0,0,0,1};
    colorText[] = {0,0,0,1};
    font = "TahomaB";
    sizeEx = 0.04;
    colorSea[] = {0.467,0.631,0.851,0.5};
    colorForest[] = {0.624,0.78,0.388,0.5};
    colorRocks[] = {0,0,0,0.3};
    colorCountlines[] = {0.572,0.354,0.188,0.25};
    colorMainCountlines[] = {0.572,0.354,0.188,0.5};
    colorCountlinesWater[] = {0.491,0.577,0.702,0.3};
    colorMainCountlinesWater[] = {0.491,0.577,0.702,0.6};
    colorForestBorder[] = {0,0,0,0};
    colorRocksBorder[] = {0,0,0,0};
    colorPowerLines[] = {0.1,0.1,0.1,1};
    colorRailWay[] = {0.8,0.2,0,1};
    colorNames[] = {0.1,0.1,0.1,0.9};
    colorInactive[] = {1,1,1,0.5};
    colorLevels[] = {0.286,0.177,0.094,0.5};
    colorTracks[] = {0.84,0.76,0.65,0.15};
    colorRoads[] = {0.7,0.7,0.7,1};
    colorMainRoads[] = {0.9,0.5,0.3,1};
    colorTracksFill[] = {0.84,0.76,0.65,1};
    colorRoadsFill[] = {1,1,1,1};
    colorMainRoadsFill[] = {1,0.6,0.4,1};
    colorGrid[] = {0.1,0.1,0.1,0.6};
    colorGridMap[] = {0.1,0.1,0.1,0.6};
    stickX[] = {0.2,{"Gamma",1,1.5}};
    stickY[] = {0.2,{"Gamma",1,1.5}};
    widthRailWay = 4;
    class Legend
    {
        colorBackground[] = {1,1,1,0.5};
        color[] = {0,0,0,1};
        x = "SafeZoneX + (((safezoneW / safezoneH) min 1.2) / 40)";
        y = "SafeZoneY + safezoneH - 4.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        w = "10 * (((safezoneW / safezoneH) min 1.2) / 40)";
        h = "3.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
        font = "RobotoCondensed";
        sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
    };
    class ActiveMarker
    {
        color[] = {0.3,0.1,0.9,1};
        size = 50;
    };
    class Command
    {
        color[] = {1,1,1,1};
        icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
        size = 18;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
    };
    class Task
    {
        colorCreated[] = {1,1,1,1};
        colorCanceled[] = {0.7,0.7,0.7,1};
        colorDone[] = {0.7,1,0.3,1};
        colorFailed[] = {1,0.3,0.2,1};
        color[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
        icon = "\A3\ui_f\data\map\mapcontrol\taskIcon_CA.paa";
        iconCreated = "\A3\ui_f\data\map\mapcontrol\taskIconCreated_CA.paa";
        iconCanceled = "\A3\ui_f\data\map\mapcontrol\taskIconCanceled_CA.paa";
        iconDone = "\A3\ui_f\data\map\mapcontrol\taskIconDone_CA.paa";
        iconFailed = "\A3\ui_f\data\map\mapcontrol\taskIconFailed_CA.paa";
        size = 27;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
    };
    class CustomMark
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\custommark_ca.paa";
        size = 24;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
    };
    class Tree
    {
        color[] = {0.45,0.64,0.33,0.4};
        icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
        size = 12;
        importance = "0.9 * 16 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class SmallTree
    {
        color[] = {0.45,0.64,0.33,0.4};
        icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
        size = 12;
        importance = "0.6 * 12 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class Bush
    {
        color[] = {0.45,0.64,0.33,0.4};
        icon = "\A3\ui_f\data\map\mapcontrol\bush_ca.paa";
        size = "14/2";
        importance = "0.2 * 14 * 0.05 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class Church
    {
        color[] = {1,1,1,1};
        icon = "\A3\ui_f\data\map\mapcontrol\church_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class Chapel
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\Chapel_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class Cross
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\Cross_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class Rock
    {
        color[] = {0.1,0.1,0.1,0.8};
        icon = "\A3\ui_f\data\map\mapcontrol\rock_ca.paa";
        size = 12;
        importance = "0.5 * 12 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class Bunker
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
        size = 14;
        importance = "1.5 * 14 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class Fortress
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\bunker_ca.paa";
        size = 16;
        importance = "2 * 16 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class Fountain
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\fountain_ca.paa";
        size = 11;
        importance = "1 * 12 * 0.05";
        coefMin = 0.25;
        coefMax = 4;
    };
    class ViewTower
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\viewtower_ca.paa";
        size = 16;
        importance = "2.5 * 16 * 0.05";
        coefMin = 0.5;
        coefMax = 4;
    };
    class Lighthouse
    {
        color[] = {1,1,1,1};
        icon = "\A3\ui_f\data\map\mapcontrol\lighthouse_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class Quay
    {
        color[] = {1,1,1,1};
        icon = "\A3\ui_f\data\map\mapcontrol\quay_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class Fuelstation
    {
        color[] = {1,1,1,1};
        icon = "\A3\ui_f\data\map\mapcontrol\fuelstation_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class Hospital
    {
        color[] = {1,1,1,1};
        icon = "\A3\ui_f\data\map\mapcontrol\hospital_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class BusStop
    {
        color[] = {1,1,1,1};
        icon = "\A3\ui_f\data\map\mapcontrol\busstop_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class Transmitter
    {
        color[] = {1,1,1,1};
        icon = "\A3\ui_f\data\map\mapcontrol\transmitter_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class Stack
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\stack_ca.paa";
        size = 20;
        importance = "2 * 16 * 0.05";
        coefMin = 0.9;
        coefMax = 4;
    };
    class Ruin
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\ruin_ca.paa";
        size = 16;
        importance = "1.2 * 16 * 0.05";
        coefMin = 1;
        coefMax = 4;
    };
    class Tourism
    {
        color[] = {0,0,0,1};
        icon = "\A3\ui_f\data\map\mapcontrol\tourism_ca.paa";
        size = 16;
        importance = "1 * 16 * 0.05";
        coefMin = 0.7;
        coefMax = 4;
    };
    class Watertower
    {
        color[] = {1,1,1,1};
        icon = "\A3\ui_f\data\map\mapcontrol\watertower_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
    };
    class Waypoint
    {
        color[] = {0,0,0,1};
        size = 24;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
        icon = "\A3\ui_f\data\map\mapcontrol\waypoint_ca.paa";
    };
    class WaypointCompleted
    {
        color[] = {0,0,0,1};
        size = 24;
        importance = 1;
        coefMin = 1;
        coefMax = 1;
        icon = "\A3\ui_f\data\map\mapcontrol\waypointCompleted_ca.paa";
    };
    moveOnEdges = 0;//1;
    x = "SafeZoneXAbs";
    y = "SafeZoneY + 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    w = "SafeZoneWAbs";
    h = "SafeZoneH - 1.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    shadow = 0;
    ptsPerSquareSea = 5;
    ptsPerSquareTxt = 3;
    ptsPerSquareCLn = 10;
    ptsPerSquareExp = 10;
    ptsPerSquareCost = 10;
    ptsPerSquareFor = 9;
    ptsPerSquareForEdge = 9;
    ptsPerSquareRoad = 6;
    ptsPerSquareObj = 9;
    showCountourInterval = 0;
    scaleMin = 0.001;
    scaleMax = 1;
    scaleDefault = 0.16;
    maxSatelliteAlpha = 0.85;
    alphaFadeStartScale = 0.35;
    alphaFadeEndScale = 0.4;
    fontLabel = "RobotoCondensed";
    sizeExLabel = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
    fontGrid = "TahomaB";
    sizeExGrid = 0.02;
    fontUnits = "TahomaB";
    sizeExUnits = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
    fontNames = "RobotoCondensed";
    sizeExNames = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8) * 2";
    fontInfo = "RobotoCondensed";
    sizeExInfo = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
    fontLevel = "TahomaB";
    sizeExLevel = 0.02;
    text = "#(argb,8,8,3)color(1,1,1,1)";
    //text = "\a3\ui_f\data\map_background2_co.paa";
    class power
    {
        icon = "\A3\ui_f\data\map\mapcontrol\power_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
        color[] = {1,1,1,1};
    };
    class powersolar
    {
        icon = "\A3\ui_f\data\map\mapcontrol\powersolar_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
        color[] = {1,1,1,1};
    };
    class powerwave
    {
        icon = "\A3\ui_f\data\map\mapcontrol\powerwave_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
        color[] = {1,1,1,1};
    };
    class powerwind
    {
        icon = "\A3\ui_f\data\map\mapcontrol\powerwind_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
        color[] = {1,1,1,1};
    };
    class shipwreck
    {
        icon = "\A3\ui_f\data\map\mapcontrol\shipwreck_CA.paa";
        size = 24;
        importance = 1;
        coefMin = 0.85;
        coefMax = 1;
        color[] = {1,1,1,1};
    };
    class LineMarker
    {
        lineDistanceMin = 3e-005;
        lineLengthMin = 5;
        lineWidthThick = 0.014;
        lineWidthThin = 0.008;
        textureComboBoxColor = "#(argb,8,8,3)color(1,1,1,1)";
    };
};

class Life_RscCombo {
    type = CT_COMBO;
    style = ST_LEFT + LB_TEXTURES + ST_NO_RECT;
    x = 0;
    y = 0;
    w = 0.12;
    h = 0.035;
    shadow = 0;
    colorSelect[] = {0, 0, 0, 1};
    soundExpand[] = {"",0.1,1};
    colorText[] = {0.95, 0.95, 0.95, 1};
    soundCollapse[] = {"",0.1,1};
    maxHistoryDelay = 1;
    colorBackground[] = {0.4,0.4,0.4,0.4};
    colorSelectBackground[] = {1, 1, 1, 0.7};
    colorScrollbar[] = {1, 0, 0, 1};
    soundSelect[] = {
            "", 0.000000, 1
    };
    arrowEmpty = "\a3\3DEN\Data\Controls\ctrlCombo\arrowEmpty_ca.paa";
    arrowFull = "\a3\3DEN\Data\Controls\ctrlCombo\arrowFull_ca.paa";
    wholeHeight = 0.45;
    color[] = {1, 1, 1, 1};
    colorActive[] = {1, 0, 0, 1};
    colorDisabled[] = {1, 1, 1, 0.25};
    font = "RobotoCondensed";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";

    class ComboScrollBar : Life_RscScrollBar {
        arrowEmpty = "\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
        arrowFull = "\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
        border = "\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
        thumb = "\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
    };
};

class Life_RscToolbox {
    type = 6;
    rows = 1;
    columns = 1;
    colorText[] = {0.95, 0.95, 0.95, 1};
    color[] = {0.95, 0.95, 0.95, 1};
    colorTextSelect[] = {0.95, 0.95, 0.95, 1};
    colorSelect[] = {0.95, 0.95, 0.95, 1};
    colorTextDisable[] = {0.4, 0.4, 0.4, 1};
    colorDisable[] = {0.4, 0.4, 0.4, 1};
    colorSelectedBg[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
    font = "RobotoCondensed";
    sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
};

class Life_RscButtonCenter : Life_RscButtonMenu {
    style = 2;
};

class ULP_RscButtonClean : Life_RscButtonCenter {
    fade = 0;
	animTextureOver = "#(argb,8,8,3)color(0.6,0.6,0.6,0.8)";
    animTextureFocused = "#(argb,8,8,3)color(0.6,0.6,0.6,0.8)";
    animTexturePressed = "#(argb,8,8,3)color(0.6,0.6,0.6,0.8)";
    colorText[] = {1, 1, 1, 1};
	color2[] = {1, 1, 1, 1};
	colorFocused[] = {1, 1, 1, 1};
	colorBackgroundFocused[] = {0.2, 0.2, 0.2, 0.8};
    colorBackground[] = {0.15, 0.15, 0.15, 0.7};
	colorBackground2[] = {0.2, 0.2, 0.2, 0.8};
};

class ULP_RscButtonIcon : Life_RscButton {
    type = 1;
    style = 0x800 + 0x02 + 0x30;
    shadow = 0;
    animTextureOver = "#(argb,8,8,3)color(0.6,0.6,0.6,0.8)";
    animTextureFocused = "#(argb,8,8,3)color(0.6,0.6,0.6,0.8)";
    animTexturePressed = "#(argb,8,8,3)color(0.6,0.6,0.6,0.8)";
    colorText[] = {1, 1, 1, 1};
	color2[] = {1, 1, 1, 1};
	colorFocused[] = {1, 1, 1, 1};
    colorDisabled[] = {1, 1, 1, 0.6};
    colorBackgroundActive[] = {0.2, 0.2, 0.2, 0.8};
	colorBackgroundFocused[] = {0.2, 0.2, 0.2, 0.8};
    colorBackgroundDisabled[] = {0.2, 0.2, 0.2, 0.8};
    colorBackground[] = {0.15, 0.15, 0.15, 0.7};
	colorBackground2[] = {0.2, 0.2, 0.2, 0.8};
};


class ULP_RscButtonIconNoAnim : Life_RscButton {
    type = 1;
    style = 0x800 + 0x02 + 0x30;
    shadow = 0;
    colorText[] = {1, 1, 1, 1};
	color2[] = {1, 1, 1, 1};
	colorFocused[] = {1, 1, 1, 1};
    colorDisabled[] = {1, 1, 1, 0.6};
    colorBackgroundActive[] = {0.2, 0.2, 0.2, 0.8};
	colorBackgroundFocused[] = {0.2, 0.2, 0.2, 0.8};
    colorBackgroundDisabled[] = {0.2, 0.2, 0.2, 0.8};
    colorBackground[] = {0.15, 0.15, 0.15, 0.7};
	colorBackground2[] = {0.2, 0.2, 0.2, 0.8};
};

class ULP_ctrlOptionsHeader : Life_RscTextHeader {
    w = 32.25 * GUI_GRID_CENTER_W;
    h = SIZE_M * GUI_GRID_CENTER_H;
};

class ULP_ctrlOption : Life_RscControlsGroupNoScrollbars {
    w = 32.25 * GUI_GRID_CENTER_W;
    h = SIZE_M * GUI_GRID_CENTER_H;

    class Controls {
        class OptionName: Life_RscText {
            idc = 101;
            w = (32 / 2) * GUI_GRID_CENTER_W;
            h = SIZE_M * GUI_GRID_CENTER_H;
        };
        class OptionsList : Life_RscCombo {
            idc = 102;
            x = ((32 - (32 / 3)) - 1.45) * GUI_GRID_CENTER_W;
            w = (32 / 3) * GUI_GRID_CENTER_W;
            h = SIZE_M * GUI_GRID_H;
        };
        class OptionReset: ULP_RscButtonIcon {
            idc = 103;
            text = "\a3\ui_f_curator\Data\CfgCurator\waypointCycle_ca.paa";
            x = (32 - 1.25) * GUI_GRID_CENTER_W;
            w = SIZE_M * GUI_GRID_W;
            h = SIZE_M * GUI_GRID_H;
        };
    };
};

class ULP_ctrlOptionSlider : ULP_ctrlOption {
    class Controls : Controls {
        class OptionName: OptionName {};
        class OptionsList : life_RscXSliderH {
            idc = 102;
            x = ((32 - (32 / 3)) - 1.2) * GUI_GRID_CENTER_W;
            w = (32 / 3) * GUI_GRID_CENTER_W;
            h = SIZE_M * GUI_GRID_H;
        };
        class OptionReset : OptionReset {};
    };
};

class ULP_ctrlProfession : Life_RscControlsGroupNoScrollbars {
    y = (1 * GUI_GRID_CENTER_H) / 2;
    x = (1 * GUI_GRID_CENTER_W) / 2;
    w = (31 / 2) * GUI_GRID_CENTER_W;
    h = 5 * GUI_GRID_CENTER_H;

    class Controls {
        class Background: Life_RscText {
            idc = -1;
            colorBackground[] = HEADER_COLOUR_SOLID;
            w = (31 / 2) * GUI_GRID_CENTER_W;
            h = 5 * GUI_GRID_CENTER_H;
        };

        class XPBar : Life_RscProgress {
            idc = 104;
            colorBar[] = { 0.451, 0, 0.902, 1 };
            colorBackground[] = HEADER_COLOUR_SOLID;
            w = 5 * GUI_GRID_CENTER_W;
            h = 5 * GUI_GRID_CENTER_H;
        };

        class ProfessionIcon: Life_RscPictureKeepAspect {
            idc = 101;
            w = 5 * GUI_GRID_CENTER_W;
            h = 5 * GUI_GRID_CENTER_H;
        };
        class ProfessionName: Life_RscStructuredText {
            idc = 102;
            x = 5 * GUI_GRID_CENTER_W;
            w = 10.5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class ProfessionDescription: Life_RscStructuredText {
            idc = 103;
            style = ST_MULTI;
            colorBackground[] = FOOTER_COLOUR;
            x = 5 * GUI_GRID_CENTER_W;
            y = 1 * GUI_GRID_CENTER_H;
            w = 10.5 * GUI_GRID_CENTER_W;
            h = 4 * GUI_GRID_CENTER_H;
        };
    };
};

class ULP_ctrlGroupPerk : ULP_ctrlProfession {
    x = 0;
    
    class Controls : Controls {
        class Background : Background {};
        class PerkIcon: ProfessionIcon {};
        class PerkName : ProfessionName {};
        class PerkDescription : ProfessionDescription {};
        class Overlay : PerkName {
            idc = 105;
            text = "";
            colorBackground[] = { 0.1, 0.1, 0.1, 0.9 };
            x = 0;
            w = 15.5 * GUI_GRID_CENTER_W;
            h = 5 * GUI_GRID_CENTER_H;
        };
    };
};

class ULP_ctrlGroupBuff : ULP_ctrlGroupPerk {
    h = 3 * GUI_GRID_CENTER_H;

    class Controls {
        class Background: Life_RscText {
            idc = -1;
            colorBackground[] = HEADER_COLOUR_SOLID;
            w = 15.5 * GUI_GRID_CENTER_W;
            h = 3 * GUI_GRID_CENTER_H;
        };
        class BuffIcon: Life_RscPictureKeepAspect {
            idc = 101;
            w = 3 * GUI_GRID_CENTER_W;
            h = 3 * GUI_GRID_CENTER_H;
        };
        class BuffName: Life_RscStructuredText {
            idc = 102;
            x = 3 * GUI_GRID_CENTER_W;
            y = 0.5 * GUI_GRID_CENTER_H;
            w = 12.5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class PercBackground: Life_RscText {
            idc = -1;
            colorBackground[] = FOOTER_COLOUR;
            x = 3 * GUI_GRID_CENTER_W;
            y = 1.75 * GUI_GRID_CENTER_H;
            w = 12.5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class XPBar : Life_RscProgress {
            idc = 103;
            colorBar[] = { 0.451, 0, 0.902, 1 };
            x = 3 * GUI_GRID_CENTER_W;
            y = 1.75 * GUI_GRID_CENTER_H;
            w = 12.5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class BuffText : BuffName {
            idc = 104;
            text = "<t align='center'>0%</t>";
            y = 1.75 * GUI_GRID_CENTER_H;
        };
    };
};

class ULP_ctrlAchievement : Life_RscControlsGroupNoScrollbars {
    y = (1 * GUI_GRID_CENTER_H) / 2;
    x = (1 * GUI_GRID_CENTER_W) / 2;
    w = 5.885 * GUI_GRID_CENTER_W;
    h = 5.885 * GUI_GRID_CENTER_H;

    class Controls {
        class Background: Life_RscText {
            idc = -1;
            colorBackground[] = FOOTER_COLOUR;
            w = 5.885 * GUI_GRID_CENTER_W;
            h = 5.885 * GUI_GRID_CENTER_H;
        };

        class AchievementIcon: Life_RscPictureKeepAspect {
            idc = 101;
            w = 5.885 * GUI_GRID_CENTER_W;
            h = 4.885 * GUI_GRID_CENTER_H;
        };

        class AchievementName: Life_RscStructuredText {
            idc = 102;
            colorBackground[] = HEADER_COLOUR;
            y = 4.885 * GUI_GRID_CENTER_H;
            w = 5.885 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };

        class Cover : Life_RscText {
            idc = 103;
            colorBackground[] = { 0.06,0.06,0.06,0.9 };
            w = 5.885 * GUI_GRID_CENTER_W;
            h = 5.885 * GUI_GRID_CENTER_H;
        };
    };
};

class ULP_ctrlPerk : ULP_ctrlAchievement {
    class Controls : Controls {
        class Background : Background {};
        class PerkIcon : AchievementIcon {};
        class PerkName : AchievementName {};
        class SelectButton : ULP_RscButtonClean {
            idc = 104;
            colorBackground[] = {0, 0, 0, 0};
            y = 4.885 * GUI_GRID_CENTER_H;
            w = 5.885 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class PerkLevel: Life_RscStructuredText {
            idc = 105;
            colorBackground[] = HEADER_COLOUR;
            x = 4.32375 * GUI_GRID_CENTER_W;
            w = 1.57125 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
        class Cover : Cover {};
    };
};

class ULP_ctrlGoalsHeader : ULP_ctrlOptionsHeader {
    colorBackground[] = HEADER_COLOUR_SOLID;
    y = (1 * GUI_GRID_CENTER_H) / 2;
    x = (1 * GUI_GRID_CENTER_W) / 2;
    w = 31 * GUI_GRID_CENTER_W;
};

class ULP_ctrlGoal : ULP_ctrlProfession {
    w = 31 * GUI_GRID_CENTER_W;

    class Controls {
        class Background: Life_RscText {
            idc = -1;
            colorBackground[] = HEADER_COLOUR_SOLID;
            w = 31 * GUI_GRID_CENTER_W;
            h = 5 * GUI_GRID_CENTER_H;
        };

        class GoalIcon: Life_RscPictureKeepAspect {
            idc = 101;
            w = 5 * GUI_GRID_CENTER_W;
            h = 5 * GUI_GRID_CENTER_H;
        };

        class GoalName: Life_RscStructuredText {
            idc = 102;
            x = 5 * GUI_GRID_CENTER_W;
            w = 26 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };

        class GoalDescription: Life_RscStructuredText {
            idc = 103;
            style = ST_MULTI;
            colorBackground[] = FOOTER_COLOUR;
            x = 5 * GUI_GRID_CENTER_W;
            y = 1 * GUI_GRID_CENTER_H;
            w = 26 * GUI_GRID_CENTER_W;
            h = 4 * GUI_GRID_CENTER_H;
        };

        class ProgressBackground: Life_RscText {
            idc = -1;
            colorBackground[] = HEADER_COLOUR_SOLID;
            x = 5.25 * GUI_GRID_CENTER_W;
            y = 3.75 * GUI_GRID_CENTER_H;
            w = 25.5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };

        class ProgressBar : Life_RscProgress {
            idc = 104;
            colorBar[] = { 0.451, 0, 0.902, 1 };
            colorBackground[] = HEADER_COLOUR_SOLID;
            x = 5.25 * GUI_GRID_CENTER_W;
            y = 3.75 * GUI_GRID_CENTER_H;
            w = 25.5 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };

        class ProgressText: ProgressBackground {
            idc = 105;
            colorBackground[] = {0,0,0,0};
        };
    };
};

class ULP_CartelHud : Life_RscControlsGroupNoScrollbars {
    SAFEZONE_Y(MARGIN_Y);
    x = ((0.5) * safezoneW + safezoneX) - ((14.75 * GUI_GRID_CENTER_W) / 2);
    w = 14.75 * GUI_GRID_CENTER_W;
    h = 3 * GUI_GRID_CENTER_H;

    class Controls {
        class BarBackground: Life_RscText {
            idc = 101;
            colorBackground[] = {0.1, 0.1, 0.1, 0.5};
            w = 11.75 * GUI_GRID_CENTER_W;
            h = 1.5 * GUI_GRID_CENTER_H;
        };

        class ProgressBar : Life_RscProgress {
            idc = 102;
            colorBar[] = {0, 0.3, 0.6, 0.65};
            w = 11.75 * GUI_GRID_CENTER_W;
            h = 1.5 * GUI_GRID_CENTER_H;
        };

        class StatusText : Life_RscStructuredText {
            idc = 103;
            text = "<t align='center' size='1.25'>ATTACKING</t>";
            colorBackground[] = {0, 0, 0, 0};
            y = 0.15 * GUI_GRID_CENTER_H;
            w = 11.75 * GUI_GRID_CENTER_W;
            h = 1.5 * GUI_GRID_CENTER_H;
        };

        class ScoreBackground: Life_RscText {
            idc = 104;
            colorBackground[] = {0.1, 0.1, 0.1, 0.5};
            x = 11.75 * GUI_GRID_CENTER_W;
            w = 2 * GUI_GRID_CENTER_W;
            h = 1.5 * GUI_GRID_CENTER_H;
        };

        class ZoneScoreText : Life_RscStructuredText {
            idc = 105;
            text = "<t align='center' size='1.5'>-1</t>";
            colorBackground[] = {0, 0.3, 0.6, 0.65};
            x = 11.75 * GUI_GRID_CENTER_W;
            w = 2 * GUI_GRID_CENTER_W;
            h = 1.5 * GUI_GRID_CENTER_H;
        };

        class TimerBackground: Life_RscText {
            idc = 106;
            colorBackground[] = {0.1, 0.1, 0.1, 0.5};
            y = 1.65 * GUI_GRID_CENTER_H;
            w = 11.75 * GUI_GRID_CENTER_W;
            h = 0.25 * GUI_GRID_CENTER_H;
        };

        class TimerBar : Life_RscProgress {
            idc = 107;
            colorBar[] = { 0.06, 0.06, 0.06, 0.7 };
            y = 1.65 * GUI_GRID_CENTER_H;
            w = 11.75 * GUI_GRID_CENTER_W;
            h = 0.25 * GUI_GRID_CENTER_H;
        };
    };
};

class ULP_Notification : Life_RscControlsGroupNoScrollbars {
    SAFEZONE_X(0.86);
    SAFEZONE_Y(0.09);
    SAFEZONE_W(0.14);
    h = 1.75 * GUI_GRID_CENTER_H;

    class Controls {
        class Header : Life_RscStructuredText {
            idc = 101;
            text = "<t size='0.75'>Header</t>";
            colorBackground[] = HEADER_COLOUR_SOLID;
            w = 11 * GUI_GRID_CENTER_W;
            h = 0.75 * GUI_GRID_CENTER_H;
        };
        class Body : Header {
            idc = 102;
            style = "0x10";
            text = "This is a notification";
            colorBackground[] = {0.1, 0.1, 0.1, 0.8};
            y = 0.75 * GUI_GRID_CENTER_H;
            h = 1 * GUI_GRID_CENTER_H;
        };
    };
};

class ULP_NotificationNoHeader : ULP_Notification {
    h = 1 * GUI_GRID_CENTER_H;

    class Controls {
        class Body : Life_RscStructuredText {
            idc = 102;
            style = "0x10";
            text = "This is a notification";
            colorBackground[] = {0.1, 0.1, 0.1, 0.8};
            w = 11 * GUI_GRID_CENTER_W;
            h = 1 * GUI_GRID_CENTER_H;
        };
    };
};