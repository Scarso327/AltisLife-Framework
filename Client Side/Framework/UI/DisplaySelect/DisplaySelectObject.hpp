#define UI_WIDTH 0.13
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.407
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DisplaySelectObject {
    idd = 4500;
    movingEnable = 0;
    enableSimulation = 0;
	onunload = "_this call { private _params = ((_this select 0) getVariable ""params""); _params pushBack (_this select 0); if ((_this select 1) isEqualTo 1) then { ((_this select 0) getVariable ""params"") call ((_this select 0) getVariable ""onSelect""); }; };";

    class ControlsBackground {
		class TabletBackground : Life_RscBackground {
			idc = 4507;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0.29375);
			SAFEZONE_Y(0.243);
			SAFEZONE_W(0.4150);
			SAFEZONE_H(0.505);
		};

		class FullBackground : Life_RscBackground {
			idc = 4508;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0);
			SAFEZONE_Y(0);
			SAFEZONE_W(1);
			SAFEZONE_H(1);
		};

		class Header : Life_RscText {
			idc = 4501;
			colorBackground[] = HEADER_COLOUR;
			text = "Select Option";
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

		class ObjectList : Life_RscListBox {
			idc = 4509;
			rowHeight = 0.065;
			sizeEx = 0.03;
			colorBackground[] = INNER_BODY_COLOUR;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));
		};

		class Select : Life_RscButtonCenter {
			idc = 4506;
			text = "<t align = 'center'>Select</t>";
			onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 1;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};