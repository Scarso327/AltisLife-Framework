class BannerText : Life_RscStructuredText {
    idc = 23024;
    text = "<t size='1.25'>Scarso<br/><t size ='1'>Developer</t></t>";
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(MARGIN_Y * 5);
};

class PrestigeText : Life_RscStructuredText {
    idc = 23025;
    text = "<t size ='1' align='center'><t size ='1.25'>10</t><br/>Prestige</t>";
    SAFEZONE_X(UI_X + (UI_WIDTH - ((UI_WIDTH / 8) * 3)));
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(UI_WIDTH / 8);
	SAFEZONE_H(MARGIN_Y * 5);
};

class PrestigeButton : ULP_RscButtonIcon {
    idc = 23031;
	onButtonClick = "_this call ULP_fnc_prestige;";
    text = "\a3\ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
	tooltip = "Pressing this will prestige your account and wipe your progression.";
	colorText[] = {1, 0.843, 0, 1};
	color2[] = {1, 0.843, 0, 1};
	colorFocused[] = {1, 0.843, 0, 0.6};
    colorDisabled[] = {1, 0.843, 0, 0.6};
    SAFEZONE_X(UI_X + (UI_WIDTH - ((UI_WIDTH / 8) * 3)));
	SAFEZONE_Y(UI_Y);
	w = 1 * GUI_GRID_CENTER_W;
	h = 1 * GUI_GRID_CENTER_H;
};

class LevelText : Life_RscStructuredText {
    idc = 23026;
    text = "<t size ='1' align='center'><t size ='1.25'>50</t><br/>Level</t>";
    SAFEZONE_X(UI_X + (UI_WIDTH - ((UI_WIDTH / 8) * 2)));
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(UI_WIDTH / 8);
	SAFEZONE_H(MARGIN_Y * 5);
};

class RepText : Life_RscStructuredText {
    idc = 23027;
    text = "<t size ='1' align='center'><t size ='1.25'>2000</t><br/>Reputation</t>";
    SAFEZONE_X(UI_X + (UI_WIDTH - (UI_WIDTH / 8)));
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(UI_WIDTH / 8);
	SAFEZONE_H(MARGIN_Y * 5);
};

class ProfilePages : Life_RscToolbox {
	idc = 23028;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_profile;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 5));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(MARGIN_Y * 3);
	columns = 4;
	fade = 0;
	strings[] = {
		"Professions",
		"Achievements",
		"Personal Goals",
		"Player Tag"
	};
	tooltips[] = {
		"Professions",
		"Achievements",
		"Personal Goals",
		"Player Tag"
	};
};

class FullViewBackground : Life_RscText {
    idc = 23029;
	colorBackground[] = INNER_BODY_COLOUR;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 8));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 8));
};

class FullView : Life_RscControlsGroup {
    idc = 23030;
	colorBackground[] = INNER_BODY_COLOUR;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 8));
	SAFEZONE_W(UI_WIDTH);
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 8));

    class Controls {};
};

class PreviewText : Life_RscStructuredText {
	idc = 23057;
	text = "<t align='center' color='#75ffffff'>Preview</t>";
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 8));
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H);
};

class PlayerIcon : Life_RscPictureKeepAspect {
	idc = 23053;
	text = "";
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y(((UI_Y + (MARGIN_Y * 2)) + (UI_HEIGHT / 2)) - (BUTTON_H * 2));
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H * 2);
};

class PlayerName : Life_RscStructuredText {
	idc = 23054;
	text = "<t align='center'>Player Name</t>";
	size = 0.045;
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y(((UI_Y + (MARGIN_Y * 2)) + (UI_HEIGHT / 2)));
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H);
};

class PlayerSubtitle : Life_RscStructuredText {
	idc = 23055;
	text = "<t align='center'>Subtitle</t>";
	size = 0.04;
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y(((UI_Y + (MARGIN_Y * 2)) + (UI_HEIGHT / 2)) + BUTTON_H);
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H);
};

class PlayerTitle : Life_RscStructuredText {
	idc = 23058;
	text = "<t align='center'>Title</t>";
	size = 0.04;
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y(((UI_Y + (MARGIN_Y * 2)) + (UI_HEIGHT / 2)) + (BUTTON_H * 2));
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H);
};

class TitleList : Life_RscCombo {
	idc = 23056;
	onLBSelChanged = "_this params [ ""_ctrl"", ""_index"" ]; private _display = ctrlParent _ctrl; if (isNull _display) exitWith {}; [_display, ""."", """", """", getText (missionConfigFile >> ""CfgTitles"" >> (_ctrl lbData _index) >> ""displayName""), """"] call ULP_fnc_updateTagPreview;";
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y((UI_Y + UI_HEIGHT) - (BUTTON_H + (BUTTON_H / 2)));
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H);
};

class IconList : Life_RscTree {
	idc = 23069;
	onTreeSelChanged = "_this params [ ""_ctrl"", ""_index"" ]; private _display = ctrlParent _ctrl; if (isNull _display) exitWith {}; [_display, (_ctrl tvData _index), """", """", """", """"] call ULP_fnc_updateTagPreview;";
	colorBackground[] = FOOTER_COLOUR;
    SAFEZONE_X(UI_X + MARGIN_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 9));
	SAFEZONE_W((UI_WIDTH / 2));
	SAFEZONE_H(((UI_HEIGHT - (MARGIN_Y * 10)) - (UI_HEIGHT / 4)) - MARGIN_Y);
};

class TagColourBackground : Life_RscText {
	idc = 23071;
	text = "";
	colorBackground[] = FOOTER_COLOUR;
    SAFEZONE_X(UI_X + MARGIN_X);
	SAFEZONE_Y((((UI_Y + UI_HEIGHT) - MARGIN_Y) - (UI_HEIGHT / 4)) + 0.022);
	SAFEZONE_W((UI_WIDTH / 2));
	SAFEZONE_H((UI_HEIGHT / 4) - 0.022);
};

class TagColourHeader : TagColourBackground {
	idc = 23070;
	text = "Name Colouring";
	colorBackground[] = {0, 0, 0, 1};
	SAFEZONE_Y(((UI_Y + UI_HEIGHT) - MARGIN_Y) - (UI_HEIGHT / 4));
	SAFEZONE_H(0.022);
};

#define BASE_HEIGHT (((UI_HEIGHT / 4) - 0.022) - (MARGIN_Y * 2))
#define SLIDER_HEIGHT VERTICAL_GRID_H(BASE_HEIGHT, 3, (MARGIN_Y / 2))

class RedColourBar : life_RscXSliderH {
	idc = 23072;
	color[] = { 0.675, 0.067, 0, 0.7 };
	colorActive[] = { 0.675, 0.067, 0, 1 };
	onSliderPosChanged = "_this params [ ""_ctrl"", ""_index"" ]; private _display = ctrlParent _ctrl; if (isNull _display) exitWith {}; [_display, ""."", [player] call ULP_fnc_getName, """", """", [_display] call ULP_fnc_getTagRGB] call ULP_fnc_updateTagPreview;";
    SAFEZONE_X(UI_X + (MARGIN_X * 2));
	SAFEZONE_Y(VERTICAL_GRID_Y((((UI_Y + UI_HEIGHT) + 0.022) - (UI_HEIGHT / 4)), SLIDER_HEIGHT, 0, (MARGIN_Y / 2)));
	SAFEZONE_W((UI_WIDTH / 2) - (MARGIN_X * 2));
	SAFEZONE_H(SLIDER_HEIGHT);
};

class GreenColourBar : RedColourBar {
	idc = 23073;
	color[] = { 0.098, 0.318, 0.165, 0.7 };
	colorActive[] = { 0.098, 0.318, 0.165, 1 };
	SAFEZONE_Y(VERTICAL_GRID_Y((((UI_Y + UI_HEIGHT) + 0.022) - (UI_HEIGHT / 4)), SLIDER_HEIGHT, 1, (MARGIN_Y / 2)));
};

class BlueColourBar : RedColourBar {
	idc = 23074;
	color[] = { 0.141, 0.235, 0.565, 0.7 };
	colorActive[] = { 0.141, 0.235, 0.565, 1 };
	SAFEZONE_Y(VERTICAL_GRID_Y((((UI_Y + UI_HEIGHT) + 0.022) - (UI_HEIGHT / 4)), SLIDER_HEIGHT, 2, (MARGIN_Y / 2)));
};

class ResetTagColour: ULP_RscButtonIcon {
	idc = 23075;
	text = "\a3\ui_f_curator\Data\CfgCurator\waypointCycle_ca.paa";
	onButtonClick = "[ctrlParent (_this select 0)] call ULP_fnc_resetTagRGB;";
    SAFEZONE_X(((UI_X + MARGIN_X) + (UI_WIDTH / 2))) - 0.022 * safezoneH;
	SAFEZONE_Y(((UI_Y + UI_HEIGHT) - MARGIN_Y) - (UI_HEIGHT / 4));
	w = 0.022 * safezoneH;
	SAFEZONE_H(0.022);
};