class InventoryPages : Life_RscToolbox {
	idc = 23014;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_inventory;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
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

#define INV_SECTION_H HORIZONTAL_GRID_W(UI_WIDTH, 2)

class ItemsList : Life_RscListBox {
	idc = 23016;
	onLBSelChanged = "_this call ULP_fnc_invLbChange;";
	colorBackground[] = INNER_BODY_COLOUR;
	rowHeight = 0.1;
	sizeEx = 0.03;
	SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, INV_SECTION_H, 0));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(INV_SECTION_H);
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 6));
};

class ItemInformation : Life_RscStructuredText {
	idc = 23017;
	text = "";
	colorBackground[] = INNER_BODY_COLOUR;
	SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, INV_SECTION_H, 1));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(INV_SECTION_H);
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 6));
};

class Use : ULP_RscButtonClean {
	idc = 23018;
	text = "<t align = 'center'>Use</t>";
	onButtonClick = "_this call ULP_fnc_useItem;";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + UI_HEIGHT) - (MARGIN_Y * 2));
	SAFEZONE_W((UI_WIDTH / 2) / 3);
	SAFEZONE_H(MARGIN_Y * 2);
};

class Remove : ULP_RscButtonClean {
	idc = 23019;
	text = "<t align = 'center'>Remove</t>";
	onButtonClick = "_this call ULP_fnc_removeItem;";
	SAFEZONE_X((UI_X + UI_WIDTH) - (UI_WIDTH / 2) / 3);
	SAFEZONE_Y((UI_Y + UI_HEIGHT) - (MARGIN_Y * 2));
	SAFEZONE_W((UI_WIDTH / 2) / 3);
	SAFEZONE_H(MARGIN_Y * 2);
};