#define UI_X 0.29375
#define UI_WIDTH 0.19
#define BODY_HEIGHT 0.066

class DisplayInputGroupInfo {
    idd = 3700;
    movingEnable = 0;
    enableSimulation = 0;
	onunload = "_this call { private _params = ((_this select 0) getVariable ""params""); _params append [(_this select 0), ctrlText ((_this select 0) displayCtrl 3705), ctrlText ((_this select 0) displayCtrl 3706)]; if ((_this select 1) isEqualTo 1) then { ((_this select 0) getVariable ""params"") call ((_this select 0) getVariable ""onSelect""); }; };";

    class ControlsBackground {
		class TabletBackground : Life_RscBackground {
			idc = 3701;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0.29375);
			SAFEZONE_Y(0.243);
			SAFEZONE_W(0.4150);
			SAFEZONE_H(0.505);
		};

		class FullBackground : Life_RscBackground {
			idc = 3702;
			colorBackground[] = { 0, 0, 0, 0.6 };
			SAFEZONE_X(0);
			SAFEZONE_Y(0);
			SAFEZONE_W(1);
			SAFEZONE_H(1);
		};

		class Header : Life_RscText {
			idc = 3201;
			colorBackground[] = HEADER_COLOUR;
			text = "Group Creation";
			SAFEZONE_X(UI_X + 0.1125);
			SAFEZONE_Y(0.434);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.022);
		};

		class Body : Life_RscText {
			idc = 3703;
			colorBackground[] = BODY_COLOUR;
			SAFEZONE_X(UI_X + 0.1125);
			SAFEZONE_Y(0.456);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BODY_HEIGHT);
		};

		class Footer : Life_RscText {
			idc = 3704;
			colorBackground[] = FOOTER_COLOUR;
			SAFEZONE_X(UI_X + 0.1125);
			SAFEZONE_Y(0.52);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.033);
		};
	};

	class Controls {
		class TagInput : life_RscEdit {
			idc = 3705;
			text = "Enter Group Tag...";
			SAFEZONE_X((UI_X + 0.1125) + MARGIN_X);
			SAFEZONE_Y(0.456 + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(0.022);
		};

		class NameInput : life_RscEdit {
			idc = 3706;
			text = "Enter Group Name...";
			SAFEZONE_X((UI_X + 0.1125) + MARGIN_X);
			SAFEZONE_Y((0.456 + 0.022) + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(0.022);
		};

		class Select : Life_RscButtonCenter {
			idc = 3707;
			text = "<t align = 'center'>Create</t>";
			onButtonClick = "(ctrlParent (_this select 0)) closeDisplay 1;";
			SAFEZONE_X(((UI_X + 0.1125) + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y(0.52 + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};