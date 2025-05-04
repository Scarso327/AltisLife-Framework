#define UI_WIDTH 0.5
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.5
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DialogMailBox {
    idd = 5300;
    movingEnable = 0;
    enableSimulation = 0;
	onunload = "[""MailReceived"", (_this select 0) getVariable [""mail_received"", -1]] call ULP_fnc_removeEventHandler; [""MailClaimed"", (_this select 0) getVariable [""mail_claimed"", -1]] call ULP_fnc_removeEventHandler; player setVariable [""claiming_mail"", nil];";

    class ControlsBackground {
		class Header : Life_RscText {
			idc = 5301;
			colorBackground[] = HEADER_COLOUR;
			text = "Mail Box";
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

		class MailBoxHeaderBackground : Life_RscText {
			idc = -1;
			colorBackground[] = { 0, 0, 0, 1 };
			text = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BUTTON_H);
		};
				
		class MailBoxListBackground : Life_RscText {
			idc = -1;
			colorBackground[] = INNER_BODY_COLOUR;
			text = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y + BUTTON_H);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BODY_HEIGHT - (BUTTON_H * 2));
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

		class MailBoxHeader: Life_RscListNBox {
			idc = 5302;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BUTTON_H);
			text = "";	
			rowHeight = 0.04;
			sizeEx = 0.038;
			columns[] = { 0, 0.5, 0.75 };
			drawSideArrows = false;
			idcLeft = -1;
			idcRight = -1;
			disableOverflow = 1;
			class Items {
				class ItemName {
					text = "Item";
					data = "data";
				};
				class Quantity {
					text = "Item";
				};
				class DaysUntilExpiry {
					text = "Expires In";
				};
			};
		};

		class MailBoxList: Life_RscListNBox {
			idc = 5303;
			colorBackground[] = INNER_BODY_COLOUR;
			onLBSelChanged = "";
			rowHeight = 0.09;
			sizeEx = 0.033;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y + BUTTON_H);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BODY_HEIGHT - (BUTTON_H * 2));
			columns[] = { 0, 0.5, 0.75 };
			drawSideArrows = false;
			idcLeft = -1;
			idcRight = -1;
		};

		class Select : Life_RscButtonCenter {
			idc = 5304;
			text = "<t align = 'center'>Claim</t>";
			onButtonClick = "_this call ULP_fnc_claimMail";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};