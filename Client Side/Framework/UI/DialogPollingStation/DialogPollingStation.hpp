#define UI_WIDTH 0.2
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.350
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DialogPollingStation {
    idd = 5200;
    movingEnable = 0;
    enableSimulation = 0;
	onunload = "[""CandidatesReceived"", (_this select 0) getVariable [""candidates_received"", -1]] call ULP_fnc_removeEventHandler;";

    class ControlsBackground {
		class Header : Life_RscText {
			idc = 5201;
			colorBackground[] = HEADER_COLOUR;
			text = "Polling Station";
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
		class CandidateList : Life_RscListBox {
			idc = 5202;
			colorBackground[] = INNER_BODY_COLOUR;
			rowHeight = 0.09;
			sizeEx = 0.033;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BODY_HEIGHT - 0.022);
		};

		class Select : Life_RscButtonCenter {
			idc = 5203;
			text = "<t align = 'center'>Submit</t>";
			onButtonClick = "_this call ULP_fnc_vote";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};