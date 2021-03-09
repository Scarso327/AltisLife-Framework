class KeyPages : Life_RscToolbox {
	idc = 23021;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_keys;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 3);
	columns = 2;
	fade = 0;
	strings[] = {
		"Vehicles",
		"Properties"
	};
	tooltips[] = {
		"Vehicles",
		"Properties"
	};
};

class KeyList: Life_RscListBox {
    idc = 23022;
	colorBackground[] = INNER_BODY_COLOUR;
    rowHeight = 0.09;
    sizeEx = 0.033;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(UI_WIDTH - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 3));
};