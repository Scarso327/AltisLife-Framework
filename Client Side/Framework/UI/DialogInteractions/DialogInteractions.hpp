#include "..\UI_Macros.hpp"

#define UI_WIDTH 0.12375012375
#define UI_X 0.5 - (UI_WIDTH / 2)
#define UI_Y 0.5 - (BUTTON_H / 2)

class DialogInteractions {
	idd = 3600;
    name= "DialogInteractions";
    movingEnable = 0;
    enableSimulation = 0;

	class ControlsBackground {
		class Header : Life_RscText {
            idc = 3601;
            colorBackground[] = HEADER_COLOUR;
            text = "Interactions";
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(UI_Y - MARGIN_Y);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BUTTON_H);
        };
	};

	class Controls {
		class CloseButton : Life_RscButtonCenter {
            idc = 3602;
            text = "<t align = 'center'>Close</t>";
			onButtonClick = "closeDialog 0;";
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(UI_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BUTTON_H);
        };
	};
};