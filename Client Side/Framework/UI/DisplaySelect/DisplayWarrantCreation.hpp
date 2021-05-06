#define UI_WIDTH 0.175
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.1
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DisplayWarrantCreation {
    idd = 5000;
    movingEnable = 0;
    enableSimulation = 0;
	onUnload = "_this call { private _params = ((_this select 0) getVariable ""params""); _params append [(_this select 0), ctrlText ((_this select 0) displayCtrl 5001), (((_this select 0) displayCtrl 5003) lbData (lbCurSel ((_this select 0) displayCtrl 5003)))]; if ((_this select 1) isEqualTo 1) then { ((_this select 0) getVariable ""params"") call ((_this select 0) getVariable ""onSelect""); }; };";

    class ControlsBackground {
		class FullBackground : Life_RscBackground {
			idc = -1;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0);
			SAFEZONE_Y(0);
			SAFEZONE_W(1);
			SAFEZONE_H(1);
		};

		class Header : Life_RscText {
			idc = -1;
			colorBackground[] = HEADER_COLOUR;
			text = "Warrant Creation";
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

		#define ITEM_HEIGHTS VERTICAL_GRID_H((BODY_HEIGHT - (MARGIN_Y * 2)), 2, (MARGIN_Y / 2))

		class NoteBackground : Life_RscText {
			idc = -1;
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 0, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class NotePlaceholder : Life_RscText {
			style = "0x10";
			idc = 5002;
			text = "Input crime note here...";
			colorText[] = {1, 1, 1, 0.4};
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 0, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class NoteInput: Life_RscEdit {
			style = "0x10 + 0x200";
			idc = 5001;
			text = "";
			colorFrame[] = {0,0,0,0};
			colorBackground[] = {0,0,0,0};
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 0, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class TypeSelect : Life_RscCombo {
			idc = 5003;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(VERTICAL_GRID_Y((BODY_Y + MARGIN_Y), ITEM_HEIGHTS, 1, (MARGIN_Y / 2)));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(ITEM_HEIGHTS);
		};

		class No : Life_RscButtonCenter {
			idc = 5004;
			text = "<t align = 'center'>Cancel</t>";
			onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 2;";
			SAFEZONE_X(((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - (UI_WIDTH / 4)) - (MARGIN_X * 2));
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};

		class Yes : Life_RscButtonCenter {
			idc = 5005;
			text = "<t align = 'center'>Create</t>";
			onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 1;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};