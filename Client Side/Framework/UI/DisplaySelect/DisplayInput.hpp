#define UI_WIDTH 0.150
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.075
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DisplayInput {
    idd = 4400;
    movingEnable = 0;
    enableSimulation = 0;
	onUnload = "_this call { private _params = ((_this select 0) getVariable ""params""); _params append [(ctrlText ((_this select 0) displayCtrl 4402)), (_this select 0)]; if ((_this select 1) isEqualTo 1) then { ((_this select 0) getVariable ""params"") call ((_this select 0) getVariable ""onSelect""); }; };";

    class ControlsBackground {
		class TabletBackground : Life_RscBackground {
			idc = 4405;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0.29375);
			SAFEZONE_Y(0.243);
			SAFEZONE_W(0.4150);
			SAFEZONE_H(0.505);
		};

		class FullBackground : Life_RscBackground {
			idc = 4406;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0);
			SAFEZONE_Y(0);
			SAFEZONE_W(1);
			SAFEZONE_H(1);
		};

		class Header : Life_RscText {
			idc = 4401;
			colorBackground[] = HEADER_COLOUR;
			text = "Processing";
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

		class Text : life_RscEdit {
			style = "0x10";
			idc = 4402;
			text = "";
			colorBackground[] = {0, 0, 0, 0};
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));
		};

		class Placeholder : Life_RscText {
			style = "0x10";
			idc = 4407;
			text = "Type your text here...";
			colorText[] = {1, 1, 1, 0.4};
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BUTTON_H);
		};

		class No : Life_RscButtonCenter {
			idc = 4403;
			text = "<t align = 'center'>Cancel</t>";
			onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 2;";
			SAFEZONE_X(((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - (UI_WIDTH / 4)) - (MARGIN_X * 2));
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};

		class Yes : Life_RscButtonCenter {
			idc = 4404;
			text = "<t align = 'center'>Enter</t>";
			onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 1;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};