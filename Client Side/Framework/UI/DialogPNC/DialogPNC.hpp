#define UI_WIDTH 0.35
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.400
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DialogPNC {
    idd = 4700;
    movingEnable = 0;
    enableSimulation = 0;
	onUnload = "[""WarrantsRetrievedEvent"", (_this select 0) getVariable [""WarrantsRetrieved"", -1]] call ULP_fnc_removeEventHandler;";

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
					x = 9.5 * GUI_GRID_CENTER_W;
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
					x = 9.5 * GUI_GRID_CENTER_W;
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
					w = 13.5 * GUI_GRID_CENTER_W;
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

				class WarrantList : Life_RscTree {
					idc = 102;
					colorBackground[] = INNER_BODY_COLOUR;
					x = 0;
					onTreeSelChanged = "_this call ULP_fnc_listCrimes;";
					y = 1 * GUI_GRID_CENTER_H;
					w = 13.5 * GUI_GRID_CENTER_W;
					h = 16.5 * GUI_GRID_CENTER_H;
				};

				class CrimesHeaderBackground : Life_RscText {
					idc = 103;
					colorBackground[] = { 0, 0, 0, 1 };
					text = "";
					x = 14 * GUI_GRID_CENTER_W;
					y = 0;
					w = 13.5 * GUI_GRID_CENTER_W;
					h = 1 * GUI_GRID_CENTER_H;
				};

				class CrimesListBackground : CrimesHeaderBackground {
					idc = 104;
					colorBackground[] = INNER_BODY_COLOUR;
					x = 14 * GUI_GRID_CENTER_W;
					y = 1 * GUI_GRID_CENTER_H;
					w = 13.5 * GUI_GRID_CENTER_W;
					h = 11 * GUI_GRID_CENTER_H;
				};

				class CrimeListHeader: Life_RscListNBox {
					idc = 105;
					x = 14 * GUI_GRID_CENTER_W;
					y = 0;
					w = 13.5 * GUI_GRID_CENTER_W;
					h = 1 * GUI_GRID_CENTER_H;
					text = "";	
					rowHeight = 0.04;
					sizeEx = 0.038;
					columns[] = { 0, 0.6 };
					drawSideArrows = false;
					idcLeft = -1;
					idcRight = -1;
					disableOverflow = 1;

					class Items {
						class Issuer {
							text = "Issuer";
							value = 0;
						};
						class Issued {
							text = "Issued";
							value = -1;
							data = "data";
						};
					};
				};

				class CrimeList : Life_RscListNBox {
					idc = 106;
					x = 14 * GUI_GRID_CENTER_W;
					y = 1 * GUI_GRID_CENTER_H;
					w = 13.5 * GUI_GRID_CENTER_W;
					h = 11 * GUI_GRID_CENTER_H;
					text = "";
					onLBSelChanged = "(((ctrlParent (_this select 0)) displayCtrl 4703) controlsGroupCtrl 107) ctrlSetStructuredText parseText ((_this select 0) lnbData [(_this select 1), 1])";
					rowHeight = 0.04;
					sizeEx = 0.038;
					columns[] = { 0, 0.6 };
					drawSideArrows = false;
					idcLeft = -1;
					idcRight = -1;
				};

				class CrimeNote : Life_RscStructuredText {
					idc = 107;
					style = ST_MULTI;
					colorBackground[] = INNER_BODY_COLOUR;
					x = 14 * GUI_GRID_CENTER_W;
					y = 12.5 * GUI_GRID_CENTER_H;
					w = 13.5 * GUI_GRID_CENTER_W;
					h = 5 * GUI_GRID_CENTER_H;
				};
			};
		};

		class IssueWarrant : Life_RscButtonCenter {
			idc = 4704;
			text = "<t align = 'center'>Issue Warrant</t>";
			onButtonClick = "";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};

		class ClearWarrants : IssueWarrant {
			idc = 4705;
			text = "<t align = 'center'>Clear Warrants</t>";
			onButtonClick = "_this call ULP_fnc_clearWarrants;";
			SAFEZONE_X((UI_X + UI_WIDTH - ((UI_WIDTH / 4) * 2)) - (MARGIN_X * 2));
		};
	};
};