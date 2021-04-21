#define UI_WIDTH 0.14
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.300
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DialogLegislation {
    idd = 4800;
    movingEnable = 0;
    enableSimulation = 0;
	onUnload = "[""LegislationChanged"", ((_this select 0) getVariable [""legislation_changed"", -1])] call ULP_fnc_removeEventHandler;";

    class ControlsBackground {
		class Header : Life_RscText {
			idc = -1;
			colorBackground[] = HEADER_COLOUR;
			text = "Legislation";
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

		class LegislationList : Life_RscListBox {
			idc = 4801;
			colorBackground[] = INNER_BODY_COLOUR;
			rowHeight = 0.09;
			sizeEx = 0.033;
			onLBSelChanged = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));
		};

		class Select : Life_RscButtonCenter {
			idc = 4802;
			text = "<t align = 'center'>Change</t>";
			onButtonClick = "_this call ULP_fnc_setLegislation";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};