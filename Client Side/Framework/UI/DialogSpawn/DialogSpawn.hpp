#define UI_X (MARGIN_X * 2)
#define UI_WIDTH 0.13234375
#define BODY_HEIGHT 0.407

class DialogSpawn {
    idd = 3000;
    name= "DialogSpawn";
    movingEnable = 0;
    enableSimulation = 1;

    class ControlsBackground {
		class MapView : Life_RscMapControl {
            idc = 3001;
			SAFEZONE_X(0);
			SAFEZONE_Y(0);
			SAFEZONE_W(1);
			SAFEZONE_H(1);
            maxSatelliteAlpha = 0.75;
            alphaFadeStartScale = 1.15;
            alphaFadeEndScale = 1.29;
        };

		class Header : Life_RscText {
            idc = -1;
            colorBackground[] = HEADER_COLOUR;
            text = "Spawn Menu";
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.269);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.022);
        };

		class Body : Life_RscText {
            idc = -1;
            colorBackground[] = BODY_COLOUR;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.291);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(BODY_HEIGHT);
        };

		class Footer : Life_RscText {
            idc = -1;
            colorBackground[] = FOOTER_COLOUR;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.698);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.033);
        };
	};

	class Controls {
		class SpawnList : Life_RscListBox {
            idc = 3002;
            colorBackground[] = INNER_BODY_COLOUR;
			rowHeight = 0.04;
			sizeEx = 0.038;
			SAFEZONE_X(UI_X + MARGIN_X);
			SAFEZONE_Y(0.291 + MARGIN_Y);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(0.385);
        };

		class SpawnButton : Life_RscButtonCenter {
            idc = 3003;
            text = "<t align = 'center'>Spawn</t>";
			onButtonClick = "_this call ULP_fnc_spawn;";
            SAFEZONE_X(UI_X + MARGIN_X);
            SAFEZONE_Y(0.698 + BUTTON_MARGIN_Y);
			SAFEZONE_W(0.12203125);
			SAFEZONE_H(BUTTON_H);
        };
	};
};