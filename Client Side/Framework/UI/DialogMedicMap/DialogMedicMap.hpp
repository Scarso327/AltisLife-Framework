#define UI_WIDTH 0.45
#define UI_X 0.5 - (UI_WIDTH / 2)
#define BODY_HEIGHT 0.500
#define BODY_Y 0.5 - (BODY_HEIGHT / 2)

#define PERSON_LIST_W (UI_WIDTH * 0.3) - (MARGIN_X * 2)

class DialogMedicMap {
    idd = 5400;
    movingEnable = 0;
    enableSimulation = 0;
    onLoad = "_this call ULP_UI_fnc_DialogMedicMap_OnLoad";
	onUnload = "_this call ULP_UI_fnc_DialogMedicMap_OnUnload";

    class ControlsBackground {
		class Header : Life_RscStructuredText {
			idc = 5401;
			colorBackground[] = HEADER_COLOUR;
			text = "NHS Dispatcher";
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
            idc = 5403;
			onDraw = "_this call ULP_UI_fnc_DialogMedicMap_OnMapDraw";
			SAFEZONE_X(UI_X + (MARGIN_X * 2) + PERSON_LIST_W);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(UI_WIDTH + MARGIN_X - PERSON_LIST_W);
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
		class PersonList : Life_RscTree {
			idc = 5402;
			colorBackground[] = INNER_BODY_COLOUR;
			onTreeSelChanged = "_this call ULP_UI_fnc_DialogMedicMap_OnListChanged;";
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(BODY_Y + MARGIN_Y);
			SAFEZONE_W(PERSON_LIST_W);
			SAFEZONE_H(BODY_HEIGHT - (MARGIN_Y * 2));
		};

		class AssignButton : Life_RscButtonCenter {
			idc = 5404;
			text = "<t align = 'center'>Assign</t>";
			onButtonClick = "_this call ULP_UI_fnc_DialogMedicMap_SetAssignedMedic;";
			SAFEZONE_X((UI_X + UI_WIDTH - (UI_WIDTH / 4)) - MARGIN_X);
			SAFEZONE_Y((BODY_Y + BODY_HEIGHT) + BUTTON_MARGIN_Y);
			SAFEZONE_W((UI_WIDTH / 4));
			SAFEZONE_H(0.022);
		};
	};
};