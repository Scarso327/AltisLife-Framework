class Weight : Life_RscStructuredText {
	idc = 23015;
	style = 2;
	text = "<t align='right' valign='middle'>Weight : 0/0</t>";
	size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	colorBackground[] = NO_COLOUR;
	SAFEZONE_X(UI_X + MARGIN_X);
	SAFEZONE_Y((UI_Y_RAW + (MARGIN_Y / 1.5)) + (MARGIN_Y * 2));
	SAFEZONE_W(UI_WIDTH - MARGIN_X);
	SAFEZONE_H(MARGIN_Y * 2);
};

class InventoryPages : Life_RscToolbox {
	idc = 23014;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_inventory;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X + MARGIN_X);
	SAFEZONE_Y((UI_Y_RAW + (MARGIN_Y / 1.5)) + (MARGIN_Y * 2));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 3);
	columns = 2;
	fade = 0;
	strings[] = {
		"Virtual Items",
		"Licenses"
	};
	tooltips[] = {
		"Virtual Items",
		"Licenses"
	};
};

class ItemsList : Life_RscListBox {
	idc = 23016;
	onLBSelChanged = "_this call ULP_fnc_invLbChange;";
	colorBackground[] = INNER_BODY_COLOUR;
	rowHeight = 0.1;
	sizeEx = 0.03;
	SAFEZONE_X(UI_X + MARGIN_X);
	SAFEZONE_Y((UI_Y_RAW + (MARGIN_Y / 1.5)) + (MARGIN_Y * 5));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 8));
};

class ItemInformation : Life_RscStructuredText {
	idc = 23017;
	text = "";
	colorBackground[] = INNER_BODY_COLOUR;
	SAFEZONE_X((UI_X + (UI_WIDTH / 2)) + (MARGIN_X / 2));
	SAFEZONE_Y((UI_Y_RAW + (MARGIN_Y / 1.5)) + (MARGIN_Y * 5));
	SAFEZONE_W((UI_WIDTH / 2) - (MARGIN_X / 2));
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 8));
};

class Use : TabletApp {
	idc = 23018;
	text = "<t align = 'center'>Use</t>";
	onButtonClick = "";
	SAFEZONE_X(UI_X + MARGIN_X);
	SAFEZONE_Y(((UI_Y_RAW + (MARGIN_Y / 1.75)) + UI_HEIGHT) - (MARGIN_Y * 2));
	SAFEZONE_W((UI_WIDTH / 2) / 3);
	SAFEZONE_H(MARGIN_Y * 2);
};

class Remove : TabletApp {
	idc = 23019;
	text = "<t align = 'center'>Remove</t>";
	onButtonClick = "_this call ULP_fnc_removeItem;";
	SAFEZONE_X((UI_X + UI_WIDTH) - (UI_WIDTH / 2) / 3);
	SAFEZONE_Y(((UI_Y_RAW + (MARGIN_Y / 1.75)) + UI_HEIGHT) - (MARGIN_Y * 2));
	SAFEZONE_W((UI_WIDTH / 2) / 3);
	SAFEZONE_H(MARGIN_Y * 2);
};