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
	text = "Data\Tags\Ranks\Police\SI.paa";
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y(((UI_Y + (MARGIN_Y * 2)) + (UI_HEIGHT / 2)) - (BUTTON_H * 2));
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H * 2);
};

class PlayerName : Life_RscStructuredText {
	idc = 23054;
	text = "<t align='center'>Jack Williams</t>";
	size = 0.045;
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y(((UI_Y + (MARGIN_Y * 2)) + (UI_HEIGHT / 2)));
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H);
};

class PlayerSubtitle : Life_RscStructuredText {
	idc = 23055;
	text = "<t align='center'>Civilian</t>";
	size = 0.04;
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y(((UI_Y + (MARGIN_Y * 2)) + (UI_HEIGHT / 2)) + BUTTON_H);
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H);
};

class PlayerTitle : Life_RscStructuredText {
	idc = 23058;
	text = "";
	size = 0.04;
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y(((UI_Y + (MARGIN_Y * 2)) + (UI_HEIGHT / 2)) + (BUTTON_H * 2));
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H);
};

class TitleList : Life_RscCombo {
	idc = 23056;
	onLBSelChanged = "_this params [ ""_ctrl"", ""_index"" ]; private _display = ctrlParent _ctrl; if (isNull _display) exitWith {}; [_display, [""_name"", [player] call ULP_fnc_getName, [""""]], [""_subtitle"", player getVariable [""subtitle"", """"], [""""]], getText (missionConfigFile >> ""CfgTitles"" >> (_ctrl lbData _index) >> ""displayName"")] call ULP_fnc_updateTagPreview;";
	SAFEZONE_X((UI_X + UI_WIDTH) - ((UI_WIDTH / 4) + ((UI_WIDTH / 4) / 2)));
	SAFEZONE_Y((UI_Y + UI_HEIGHT) - (BUTTON_H + (BUTTON_H / 2)));
	SAFEZONE_W((UI_WIDTH / 4));
	SAFEZONE_H(BUTTON_H);
};