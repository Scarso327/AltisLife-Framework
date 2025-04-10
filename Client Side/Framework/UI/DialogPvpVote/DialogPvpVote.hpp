#define UI_WIDTH 0.5
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.5
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

#define PERSON_LIST_W ((UI_WIDTH * 0.25) - (MARGIN_X * 2))

class DialogPvpVote {
    idd = 6300;
    movingEnable = 0;
    enableSimulation = 0;
    onLoad = "_this call ULP_UI_fnc_DialogPvpVote_OnLoad";
	onUnload = "_this call ULP_UI_fnc_DialogPvpVote_OnUnload";

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = 6301;
			colorBackground[] = HEADER_COLOUR;
			text = "PVP Voting";
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

		class MapView : Life_RscMapControl {
            idc = 6302;
			onDraw = "_this call ULP_UI_fnc_DialogPvpVote_OnMapDraw";
			SAFEZONE_X(UI_X + (MARGIN_X * 2) + PERSON_LIST_W);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH - (MARGIN_X * 3) - PERSON_LIST_W);
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));
            maxSatelliteAlpha = 0.75;
            alphaFadeStartScale = 1.15;
            alphaFadeEndScale = 1.29;
			showMarkers = 0;
            drawObjects = 0;
            drawShaded = 0;
			colorSea[] = INNER_BODY_COLOUR;
			colorOutside[] = INNER_BODY_COLOUR;
			colorCountlines[] = NO_COLOUR;
			colorMainCountlines[] = NO_COLOUR;
			colorCountlinesWater[] = NO_COLOUR;
			colorMainCountlinesWater[] = NO_COLOUR;
            class LineMarker: LineMarker {
                lineWidthThin = 0;
                lineWidthThick = 0;
            };
            class ActiveMarker: ActiveMarker { size = 0; };
            class Task: Task { size = 0; };
            class Waypoint: Waypoint { size = 0; };
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
		class ModeList : Life_RscTree {
			idc = 6303;
			colorBackground[] = INNER_BODY_COLOUR;
			onTreeSelChanged = "_this call ULP_UI_fnc_DialogPvpVote_OnListChanged;";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(PERSON_LIST_W);
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));
		};

		class AssignButton : Life_RscButtonCenter {
			idc = 6305;
			text = "<t align = 'center'>Vote</t>";
			onButtonClick = "_this call ULP_UI_fnc_DialogPvpVote_Vote;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};