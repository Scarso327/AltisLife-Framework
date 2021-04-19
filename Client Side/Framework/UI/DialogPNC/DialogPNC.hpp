#define UI_WIDTH 0.3
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.400
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DialogPNC {
    idd = 4700;
    movingEnable = 0;
    enableSimulation = 0;

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = 4701;
			colorBackground[] = HEADER_COLOUR;
			text = "Police National Computer<t align='right'>Happy</t>";
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

		class Login : Life_RscControlsGroupNoScrollbars {
			idc = 4702;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));

			class Controls {
				class Logo : Life_RscPictureKeepAspect {
					idc = -1;
					text = "Data\UI\apc.paa";
					x = 7.5 * GUI_GRID_CENTER_W;
					y = 3.25 * GUI_GRID_CENTER_H;
					w = 8.5 * GUI_GRID_CENTER_W;
					h = 8 * GUI_GRID_CENTER_H;
				};

				class UserInput: Life_RscEdit {
					style = "0x10 + 0x200";
					idc = 101;
					text = "Enter Username";
					colorFrame[] = {0,0,0,0};
					colorBackground[] = {0,0,0,0.8};
					x = 7.5 * GUI_GRID_CENTER_W;
					y = 12 * GUI_GRID_CENTER_H;
					w = 8.5 * GUI_GRID_CENTER_W;
					h = 1 * GUI_GRID_CENTER_H;
				};

				class PassInput: UserInput {
					idc = 102;
					text = "Enter Password";
					y = 13.25 * GUI_GRID_CENTER_H;
				};
			};
		};

		class Computer : Login {
			idc = 4703;
			class Controls {
				class Pages : Life_RscToolbox {
					idc = 101;
					style = 2;
					onToolboxSelChanged = "";
					colorBackground[] = NO_COLOUR;
					colorSelectedBg[] = INNER_BODY_COLOUR;
					x = 0;
					y = 0;
					w = 11 * GUI_GRID_CENTER_W;
					h = 1 * GUI_GRID_CENTER_H;
					columns = 1;
					fade = 0;
					strings[] = {
						"Warrants"
					};
					tooltips[] = {
						"Warrants"
					};
				};
			};
		};
	};
};