#define UI_WIDTH 0.3
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.450
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

#define BLUEPRINT_LIST_W (UI_WIDTH * 0.4) - (MARGIN_X * 2)
#define MAIN_H BODY_HEIGHT - (0.022 * 2) - (MARGIN_Y * 2)

class DialogSalvageFactory {
    idd = 5600;
    movingEnable = 0;
    enableSimulation = 0;
    onInit = "_this call ULP_UI_fnc_DialogSalvageFactory_OnInit";
    onLoad = "_this call ULP_UI_fnc_DialogSalvageFactory_OnLoad";
	onUnload = "_this call ULP_UI_fnc_DialogSalvageFactory_OnUnload";

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = 5601;
			colorBackground[] = HEADER_COLOUR;
			text = "%1 Factory";
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
		class ItemsView : Life_RscControlsGroup {
			idc = 5603;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(MAIN_H);

			class Controls {
				class ItemInformation : Life_RscStructuredText {
					idc = 5605;
					text = "";
					colorBackground[] = INNER_BODY_COLOUR;
					y = 0;
					x = 0;
					SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
					SAFEZONE_H(MAIN_H);
				};
			};
		};

		class Background: Life_RscText {
			idc = -1;
			colorBackground[] = {0.1,0.1,0.1,0.85};
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MAIN_H + 0.022 + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(0.022);
		};
	
		class ProgressBar: Life_RscProgress {
			idc = 5606;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MAIN_H + 0.022 + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(0.022);
		};

		class ProgressText: Life_RscStructuredText {
			idc = 5607;
			text = "No current order...";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MAIN_H + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(0.022);
			class Attributes
			{
				align = "center";
			};
		};
	};
};