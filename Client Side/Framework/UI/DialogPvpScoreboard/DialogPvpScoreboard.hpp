#define UI_WIDTH 0.25
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.5
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

class DialogPvpScoreboard {
    idd = 6400;
    movingEnable = 0;
    enableSimulation = 0;
    onLoad = "_this call ULP_UI_fnc_DialogPvpScoreboard_OnLoad";
	onUnload = "_this call ULP_UI_fnc_DialogPvpScoreboard_OnUnload";

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = 6401;
			colorBackground[] = HEADER_COLOUR;
			text = "PVP Scoreboard";
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
		class BannerText : Life_RscStructuredText {
			idc = 6402;
			text = "<t size='1.25'>Mode<br/><t size ='1'>Location</t></t>";
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(MARGIN_Y * 5);
		};

		
		class TimerText : Life_RscStructuredText {
			idc = 6407;
			text = "<t align='right' size='2.25'>00:00</t>";
			SAFEZONE_X(UI_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(MARGIN_Y * 5);
		};

		class ScoreboardHeaderBackground : Life_RscText {
			idc = 6403;
			colorBackground[] = { 0, 0, 0, 1 };
			text = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y * 6);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BUTTON_H);
		};

		class ScoreboardListHeader: Life_RscListNBox {
			idc = 6404;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y * 6);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BUTTON_H);
			text = "";	
			rowHeight = 0.04;
			sizeEx = 0.038;
			columns[] = { 0, 0.5 };
			drawSideArrows = false;
			idcLeft = -1;
			idcRight = -1;
			disableOverflow = 1;

			class Items {
				class Group {
					text = "Group";
					value = 0;
				};
				class Points {
					text = "Points";
					value = -1;
					data = "data";
				};
			};
		};

		class ScoreboardListBackground : Life_RscText {
			idc = 6405;
			colorBackground[] = INNER_BODY_COLOUR;
			text = "";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y * 6 + BUTTON_H);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 7) - BUTTON_H);
		};

		class ScoreboardList : Life_RscListNBox {
			idc = 6406;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y * 6 + BUTTON_H);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 2));
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 7) - BUTTON_H);
			text = "";	
			rowHeight = 0.04;
			sizeEx = 0.038;
			columns[] = { 0, 0.5 };
			drawSideArrows = false;
			idcLeft = -1;
			idcRight = -1;
		};
	};
};