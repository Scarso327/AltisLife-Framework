class InventoryPages : Life_RscToolbox {
	idc = 23014;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_inventory;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(UI_WIDTH - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 3);
	columns = 3;
	fade = 0;
	strings[] = {
		"Virtual Items",
		"Licenses",
		"Crafting"
	};
	tooltips[] = {
		"Virtual Items",
		"Licenses",
		"Crafting"
	};
};

#define INV_SECTION_H HORIZONTAL_GRID_W((UI_WIDTH - (MARGIN_X / 2)), 2)

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

class Deconstruct : ULP_RscButtonClean {
	idc = 23015;
	text = "<t align = 'center'>Deconstruct</t>";
	onButtonClick = "private _display = ctrlParent (_this select 0); private _list = _display displayCtrl 23016; if (isNull _display || { isNull _list }) exitWith {}; private _item = (_list lbData (lbCurSel _list)); if (_item isEqualTo """") exitWith { [""You need to select an item first!""] call ULP_fnc_hint; }; [_item] call ULP_fnc_deconstruct;";
	SAFEZONE_X((UI_X + UI_WIDTH) - (((UI_WIDTH / 2) / 3) * 2) - MARGIN_X);
	SAFEZONE_Y((UI_Y + UI_HEIGHT) - (MARGIN_Y * 2));
	SAFEZONE_W((UI_WIDTH / 2) / 3);
	SAFEZONE_H(MARGIN_Y * 2);
};

class BlueprintList : Life_RscTree {
	idc = 23077;
	onTreeSelChanged = "_this call ULP_fnc_bpLbChange;";
	colorBackground[] = INNER_BODY_COLOUR;
	SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, INV_SECTION_H, 0));
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(INV_SECTION_H);
	SAFEZONE_H(UI_HEIGHT - (MARGIN_Y * 6));
};

class Craft : Remove {
	idc = 23078;
	text = "<t align = 'center'>Craft</t>";
	onButtonClick = "_this call ULP_fnc_craft;";
};