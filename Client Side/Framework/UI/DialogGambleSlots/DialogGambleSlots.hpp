#define UI_WIDTH 0.35
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.3
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)
#define SLOT_WIDTH ((UI_WIDTH - (MARGIN_X * 4)) / 3)

class DialogGambleSlots {
    idd = 5900;
    movingEnable = 0;
    enableSimulation = 0;

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = -1;
			colorBackground[] = HEADER_COLOUR;
			text = "Slot Machine";
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

		class SlotOneBackground : Life_RscText {
			idc = -1;
			colorBackground[] = INNER_BODY_COLOUR;
			text = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y((BODY_Y + MARGIN_Y));
			SAFEZONE_W(SLOT_WIDTH);
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));
		};

		class SlotTwoBackground : SlotOneBackground {
			SAFEZONE_X((UI_X + (MARGIN_X * 2)) + SLOT_WIDTH);
		};

		class SlotThreeBackground : SlotOneBackground {
			SAFEZONE_X((UI_X + (MARGIN_X * 3)) + (SLOT_WIDTH * 2));
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

		class SlotOne : Life_RscPictureKeepAspect {
			idc = 5902;
			text = "Data\Icons\airdropTrigger.paa";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y((BODY_Y + MARGIN_Y));
			SAFEZONE_W(SLOT_WIDTH);
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));
		};

		class SlotTwo : SlotOne {
			idc = 5903;
			text = "Data\Icons\airdropTrigger.paa";
			SAFEZONE_X((UI_X + (MARGIN_X * 2)) + SLOT_WIDTH);
		};

		class SlotThree : SlotOne {
			idc = 5904;
			text = "Data\Icons\airdropTrigger.paa";
			SAFEZONE_X((UI_X + (MARGIN_X * 3)) + (SLOT_WIDTH * 2));
		};
		
		class CraftButton : Life_RscButtonCenter {
			idc = 5901;
			text = "<t align = 'center'>Spin</t>";
			onButtonClick = "_this call ULP_UI_fnc_DialogGambleSlots_Spin;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};