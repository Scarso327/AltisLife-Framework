#define UI_X 0.29375
#define UI_X_INNER (UI_X + MARGIN_X)
#define UI_WIDTH 0.4125
#define INNER_UI_WIDTH (UI_WIDTH - MARGIN_X)
#define BODY_HEIGHT 0.407

class DialogVehicleStore {
	idd = 3400;
    name= "DialogVehicleStore";
    movingEnable = 1;
    enableSimulation = 1;

	class ControlsBackground {
		class Header : Life_RscText {
            idc = 3401;
            colorBackground[] = HEADER_COLOUR;
            text = "Vehicle Store";
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

		class ShareText : Life_RscStructuredText {
            idc = -1;
            text = "<t align = 'right'>Share Keys w/ Nearby Group</t>";
			enable = 0;
            colorBackground[] = INNER_BODY_COLOUR;
            SAFEZONE_X(0.5790625);
            SAFEZONE_Y(((0.291 + MARGIN_Y + BODY_HEIGHT) - (MARGIN_Y * 2)) - BUTTON_H);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(BUTTON_H);
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
			idc = 3402;
			text = "";	
			onLBSelChanged = "_this call ULP_fnc_vehicleChange;";
			rowHeight = 0.075;
			sizeEx = 0.025;
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(UI_X + MARGIN_X);
            SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(0.1478125);
			SAFEZONE_H(0.385);
		};

		class VehicleSettings : Life_RscStructuredText {
			idc = 3403;
			text = "";
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(0.451875);
			SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(0.352);
		};

		class VehicleInformationView : Life_RscControlsGroup {
			idc = -1;
			SAFEZONE_X(0.5790625);
			SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(0.308);

			class Controls {
				class VehicleInformation : Life_RscStructuredText {
					idc = 3404;
					text = "";
					colorBackground[] = INNER_BODY_COLOUR;
					y = 0;
					x = 0;
					SAFEZONE_W(0.12203125);
					SAFEZONE_H(0.308);
				};
			};
		};

		class SalePrice : Life_RscStructuredText {
			idc = 3405;
			text = "";
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(0.5790625);
			SAFEZONE_Y(0.61);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(BUTTON_H * 2);
		};

		/*class RentButton : Life_RscButtonCenter {
            idc = 3406;
            text = "<t align = 'center'>Rent</t>";
			onButtonClick = "";
            SAFEZONE_X(0.5790625);
            SAFEZONE_Y(0.698 + BUTTON_MARGIN_Y);
			SAFEZONE_W(0.0584375);
			SAFEZONE_H(BUTTON_H);
        };*/

		class PreviewButton : Life_RscButtonCenter {
            idc = 3410;
            text = "<t align = 'center'>Preview</t>";
			onButtonClick = "_this call ULP_fnc_previewTexture;";
            SAFEZONE_X(0.5790625);
            SAFEZONE_Y(0.698 + BUTTON_MARGIN_Y);
			SAFEZONE_W(0.0584375);
			SAFEZONE_H(BUTTON_H);
        };

		class BuyButton : Life_RscButtonCenter {
            idc = 3407;
            text = "<t align = 'center'>Buy</t>";
			onButtonClick = "_this call ULP_fnc_buyVehicle;";
            SAFEZONE_X(0.64265625);
            SAFEZONE_Y(0.698 + BUTTON_MARGIN_Y);
			SAFEZONE_W(0.0584375);
			SAFEZONE_H(BUTTON_H);
        };

		class TextureList : Life_RscCombo {
            idc = 3408;
			onLBSelChanged = "_this call ULP_fnc_switchTexture;";
            SAFEZONE_X(0.451875);
			SAFEZONE_Y(((0.291 + MARGIN_Y + BODY_HEIGHT) - (MARGIN_Y * 2)) - BUTTON_H);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(BUTTON_H);
        };

        class ShareTextCB : Life_Checkbox {
            idc = 3409;
            SAFEZONE_X(0.5790625);
            SAFEZONE_Y(((0.291 + MARGIN_Y + BODY_HEIGHT) - (MARGIN_Y * 2)) - BUTTON_H);
			SAFEZONE_W(MARGIN_X * 2);
			SAFEZONE_H(BUTTON_H);
        };
	};
};