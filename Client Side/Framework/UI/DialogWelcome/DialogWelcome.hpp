#define UI_WIDTH 0.45
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.4
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DialogWelcome {
    idd = 6000;
    movingEnable = 0;
    enableSimulation = 0;
    onInit = "_this call ULP_UI_fnc_DialogWelcome_OnInit";
    onLoad = "_this call ULP_UI_fnc_DialogWelcome_OnLoad";
	onUnload = "_this call ULP_UI_fnc_DialogWelcome_OnUnload";

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = -1;
			colorBackground[] = HEADER_COLOUR;
			text = "Welcome to Mantle's Altis Life";
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
		class WelcomeInfoGroup : Life_RscControlsGroup {
			idc = -1;
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BODY_HEIGHT);

			class Controls {
				class WelcomeInfo : Life_RscStructuredText {
					idc = 6001;
					text = "";
					colorBackground[] = INNER_BODY_COLOUR;
					y = 0;
					x = 0;
					SAFEZONE_W(UI_WIDTH);
					SAFEZONE_H(BODY_HEIGHT);
				};
			};
		};
		
		class ContinueButton : Life_RscButtonCenter {
			idc = 6002;
			text = "<t align = 'center'>Continue</t>";
			onButtonClick = "closeDialog 0; [] call ULP_fnc_spawnMenu;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 5)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 5));
			SAFEZONE_H(0.022);
		};
		
		class TutorialButton : Life_RscButtonCenter {
			idc = 6003;
			text = "<t align = 'center'>Tutorial</t>";
			onButtonClick = "closeDialog 0; ULP_DoTutorial = true; [] call ULP_fnc_spawnMenu;";
			SAFEZONE_X((UI_X + UI_WIDTH - ((UI_WIDTH / 5) * 2)) - (MARGIN_X * 2));
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 5));
			SAFEZONE_H(0.022);
		};
	};
};