class GroupPages : Life_RscToolbox {
	idc = 23061;
	style = 2;
	onToolboxSelChanged = "(ctrlParent (_this select 0)) call ULP_fnc_group;";
	colorBackground[] = NO_COLOUR;
	colorSelectedBg[] = INNER_BODY_COLOUR;
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y);
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(MARGIN_Y * 3);
	columns = 3;
	fade = 0;
	strings[] = {
		"Overview",
		"Progression",
		"Settings"
	};
	tooltips[] = {
		"Overview",
		"Progression",
		"Settings"
	};
};

class GroupMemberBackground : Life_RscText {
	idc = 23065;
	colorBackground[] = INNER_BODY_COLOUR;
	text = "";
    SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H((UI_HEIGHT - 0.022) - (MARGIN_Y * 3));
};

class GroupMemberHeaderBackground : Life_RscText {
	idc = 23064;
	colorBackground[] = { 0, 0, 0, 1 };
	text = "";
	SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(0.022);
};

class GroupMemberListHeader: Life_RscListNBox {
	idc = 23063;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y(UI_Y + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H(0.022);
	text = "";	
	rowHeight = 0.04;
	sizeEx = 0.038;
	columns[] = { 0, 0.6 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
	disableOverflow = 1;

	class Items {
		class Member {
			text = "Member";
			value = 0;
		};
		class Rank {
			text = "Rank";
			value = -1;
			data = "data";
		};
	};
};

class GroupMemberList: Life_RscListNBox {
    idc = 23062;
	colorBackground[] = INNER_BODY_COLOUR;
	onLBSelChanged = "";
    rowHeight = 0.09;
    sizeEx = 0.033;
    SAFEZONE_X(UI_X);
	SAFEZONE_Y((UI_Y + 0.022) + (MARGIN_Y * 3));
	SAFEZONE_W(((UI_WIDTH - 0.01) / 2) - (MARGIN_X / 2));
	SAFEZONE_H((UI_HEIGHT - 0.022) - (MARGIN_Y * 3));
	columns[] = { 0, 0.6 };
	drawSideArrows = false;
	idcLeft = -1;
	idcRight = -1;
};