#define UI_WIDTH 0.175
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.1
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DisplayGroupCreation {
    idd = 3700;
    movingEnable = 0;
    enableSimulation = 0;
	onUnload = "_this call { private _params = ((_this select 0) getVariable ""params""); _params append [(_this select 0), ctrlText ((_this select 0) displayCtrl 3701), ctrlText ((_this select 0) displayCtrl 3702), (((_this select 0) displayCtrl 3703) lbData (lbCurSel ((_this select 0) displayCtrl 3703)))]; if ((_this select 1) isEqualTo 1) then { ((_this select 0) getVariable ""params"") call ((_this select 0) getVariable ""onSelect""); }; };";

    class ControlsBackground {
		class TabletBackground : Life_RscBackground {
			idc = -1;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0.29375);
			SAFEZONE_Y(0.243);
			SAFEZONE_W(0.4150);
			SAFEZONE_H(0.505);
		};

		class Header : Life_RscText {
			idc = -1;
			colorBackground[] = HEADER_COLOUR;
			text = "Group Creation";
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y - 0.022);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.022);
		};

		class Body : Life_RscText {
			idc = -1;
			colorBackground[] = BODY_COLOUR;
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BODY_HEIGHT);
		};

		class Footer : Life_RscText {
			idc = -1;
			colorBackground[] = FOOTER_COLOUR;
			SAFEZONE_X(UI_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT));
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.033);
		};
	};

	class Controls {

		#define ITEM_HEIGHTS VERTICAL_GRID_H((BODY_HEIGHT - (MARGIN_Y * 2)), 3, (MARGIN_Y / 2))

		class TagBackground : Life_RscText {
			idc = -1;
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 0, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class NameBackground : TagBackground {
			idc = -1;
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 1, (MARGIN_Y / 2)));
		};

		class TagPlaceholder : Life_RscText {
			style = "0x10";
			idc = 3706;
			text = "Type group tag here...";
			colorText[] = {1, 1, 1, 0.4};
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 0, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class NamePlaceholder : TagPlaceholder {
			idc = 3707;
			text = "Type group name here...";
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 1, (MARGIN_Y / 2)));
		};

		class TagInput: Life_RscEdit {
			style = "0x10 + 0x200";
			idc = 3701;
			text = "";
			colorFrame[] = {0,0,0,0};
			colorBackground[] = {0,0,0,0};
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 0, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class NameInput: TagInput {
			idc = 3702;
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 1, (MARGIN_Y / 2)));
		};

		class TypeSelect : Life_RscCombo {
			idc = 3703;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 2, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class No : Life_RscButtonCenter {
			idc = 3704;
			text = "<t align = 'center'>Cancel</t>";
			onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 2;";
			SAFEZONE_X(((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - (UI_WIDTH / 4)) - (MARGIN_X * 2));
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};

		class Yes : Life_RscButtonCenter {
			idc = 3705;
			text = "<t align = 'center'>Create</t>";
			onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 1;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};