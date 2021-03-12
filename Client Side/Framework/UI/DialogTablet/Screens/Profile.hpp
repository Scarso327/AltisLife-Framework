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
	onToolboxSelChanged = "";
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
		"Loyalty",
		"Player Tag"
	};
	tooltips[] = {
		"Professions",
		"Achievements",
		"Loyalty",
		"Player Tag"
	};
};