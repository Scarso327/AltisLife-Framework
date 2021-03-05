#include "..\UI_Macros.hpp"

#define UI_X 0.29375
#define UI_WIDTH 0.4125
#define INNER_UI_WIDTH (UI_WIDTH - MARGIN_X)
#define BODY_HEIGHT 0.407

class DialogGarage {
	idd = 3500;
    name= "DialogGarage";
    movingEnable = 1;
    enableSimulation = 1;
	onunload = "[""GarageRetrieved"", (_this select 0) getVariable [""GarageRetrievedEvent"", -1]] call ULP_fnc_removeEventHandler;";

	class ControlsBackground {
		class Header : Life_RscText {
            idc = -1;
            colorBackground[] = HEADER_COLOUR;
            text = "Garage";
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.269);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.022);
        };

		class Body : Life_RscText {
            idc = -1;
            colorBackground[] = BODY_COLOUR;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.291);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BODY_HEIGHT);
        };

		class Footer : Life_RscText {
            idc = -1;
            colorBackground[] = FOOTER_COLOUR;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.698);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.033);
        };
	};

	class Controls {
		class VehicleList : Life_RscListBox {
			idc = 3501;
			text = "";	
			onLBSelChanged = "_this call ULP_fnc_onGarageSwitch;";
			rowHeight = 0.075;
			sizeEx = 0.025;
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(UI_X + MARGIN_X);
            SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(0.1478125);
			SAFEZONE_H(0.385);
		};

		class VehicleSettings : Life_RscStructuredText {
			idc = 3502;
			text = "";
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(0.451875);
			SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(0.352);
		};

		class VehicleInformation : Life_RscStructuredText {
			idc = 3503;
			text = "";
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(0.5790625);
			SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(0.385);
		};

		class Texture : Life_RscStructuredText {
            idc = 3504;
			onLBSelChanged = "<t align = 'center'>Default</t>";
			colorBackground[] = INNER_BODY_COLOUR;
            SAFEZONE_X(0.451875);
			SAFEZONE_Y(((0.291 + MARGIN_Y + BODY_HEIGHT) - (MARGIN_Y * 2)) - BUTTON_H);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(BUTTON_H);
        };

		class RetrieveButton : Life_RscButtonCenter {
            idc = 3505;
            text = "<t align = 'center'>Retrieve</t>";
			onButtonClick = "_this call ULP_fnc_retrieveGarage;";
            SAFEZONE_X(0.64265625);
            SAFEZONE_Y(0.698 + BUTTON_MARGIN_Y);
			SAFEZONE_W(0.0584375);
			SAFEZONE_H(BUTTON_H);
        };
	};
};