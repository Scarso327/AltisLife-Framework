#define UI_WIDTH 0.14
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.400
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DialogLicenses {
    idd = 3900;
    movingEnable = 0;
    enableSimulation = 0;

    class ControlsBackground {
		class Header : Life_RscText {
			idc = 3901;
			colorBackground[] = HEADER_COLOUR;
			text = "Licenses";
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
		
		#define LIST_HEIGHT (BODY_HEIGHT - 0.022) - (MARGIN_Y * 3)

		class LicenseList : Life_RscListBox {
			idc = 3903;
			colorBackground[] = INNER_BODY_COLOUR;
			rowHeight = 0.09;
			sizeEx = 0.033;
			onLBSelChanged = "_this call ULP_fnc_onLicenseSwitch";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(LIST_HEIGHT);
		};

		class LicensePrice : Life_RscStructuredText {
            idc = 3904;
            text = "";
            colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y((BODY_Y + LIST_HEIGHT) + (MARGIN_Y * 2));
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(0.022);
        };

		class Select : Life_RscButtonCenter {
			idc = 3902;
			text = "<t align = 'center'>Buy</t>";
			onButtonClick = "_this call ULP_fnc_buyLicense";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};

class DialogSeizeLicenses : DialogLicenses {
    idd = 5100;
    movingEnable = 0;
    enableSimulation = 0;

    class ControlsBackground : ControlsBackground {
		class Header : Header {
			idc = 5101;
			text = "Licenses";
		};

		class Body : Body {};
		class Footer : Footer {};
	};

	class Controls : Controls {
		class LicenseList : LicenseList {
			idc = 5102;
			onLBSelChanged = "";
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));
		};

		class Select : Select {
			idc = 5103;
			text = "<t align = 'center'>Seize</t>";
			onButtonClick = "_this call ULP_fnc_seizeLicense;";
		};
	};
};