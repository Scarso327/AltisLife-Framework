#define WIDTH 0.12375012375
#define XP_WIDTH (WIDTH + (WIDTH / 4))

class DisplayAdmin {
    name = "DisplayAdmin";
    idd = 600;
    onLoad=" [""Load"", _this] call ULP_fnc_adminCamera;";
	onUnload=" [""Unload"", _this] call ULP_fnc_adminCamera;";
    objects[]={};

    class ControlsBackground {
        class MouseArea : Life_RscText {
            idc = 603;
            style = 0x10;
			SAFEZONE_X(0);
			SAFEZONE_Y(0);
			SAFEZONE_W(1);
			SAFEZONE_H(1);
        };
        
        class ToolboxBackground : Life_RscText {
            idc = -1;
            colorBackground[] = {0, 0, 0, 0.3};
            SAFEZONE_X(0.45);
            SAFEZONE_Y(0);
            SAFEZONE_W(0.1);
            SAFEZONE_H(0.022);
        };

        class MapView : Life_RscMapControl {
            idc = 601;
			SAFEZONE_X(0);
			SAFEZONE_Y(0);
			SAFEZONE_W(1);
			SAFEZONE_H(1);
            maxSatelliteAlpha = 0.75;
            alphaFadeStartScale = 1.15;
            alphaFadeEndScale = 1.29;
        };
    };
    class Controls {
        class LeftList : Life_RscControlsGroupNoScrollbars {
            idc = 602;
			SAFEZONE_X(0);
			SAFEZONE_Y(0);
			SAFEZONE_W(0.2);
			SAFEZONE_H(1);

            class Controls {
                class PlayerList : Life_RscTree {
                    idc = 101;
                    fade = 0.8;
                    colorBackground[] = {0, 0, 0, 0};
                    w = 15 * GUI_GRID_CENTER_W;
                    h = 45.5 * GUI_GRID_CENTER_H;
                };
            };
        };

        class ViewToolbox : Life_RscToolbox {
            idc = 604;
            style = 2;
            colorBackground[] = NO_COLOUR;
            colorSelectedBg[] = INNER_BODY_COLOUR;
            SAFEZONE_X(0.45);
            SAFEZONE_Y(0);
            SAFEZONE_W(0.1);
            SAFEZONE_H(0.022);
            columns = 2;
            fade = 0;
            strings[] = {
                "Camera",
                "First Person"
            };
            tooltips[] = {
                "Camera",
                "First Person"
            };
        };

        #define BUTTON_GROUP_W 0.2
        #define BUTTON_W HORIZONTAL_GRID_W(BUTTON_GROUP_W, 4)

        class TPToButton : Life_RscButtonCenter {
            idc = 605;
            text = "<t align = 'center'>Go To</t>";
			onButtonClick = "[""action"", [""To""]] call ULP_fnc_adminCamera;";
            SAFEZONE_X(HORIZONTAL_GRID_X(0.5 - (BUTTON_GROUP_W / 2), BUTTON_W, 0));
			SAFEZONE_Y(((1 - (BUTTON_H * 2)) - (MARGIN_Y * 2)));
            SAFEZONE_W(BUTTON_W);
			SAFEZONE_H(BUTTON_H);
        };

        class TPHereButton : TPToButton {
            idc = 606;
            text = "<t align = 'center'>Bring Here</t>";
			onButtonClick = "[""action"", [""Here""]] call ULP_fnc_adminCamera;";
            SAFEZONE_X(HORIZONTAL_GRID_X(0.5 - (BUTTON_GROUP_W / 2), BUTTON_W, 1));
        };

        class VehicleTPButton : TPToButton {
            idc = 607;
            text = "<t align = 'center'>Join Veh</t>";
			onButtonClick = "[""action"", [""Vehicle""]] call ULP_fnc_adminCamera;";
            SAFEZONE_X(HORIZONTAL_GRID_X(0.5 - (BUTTON_GROUP_W / 2), BUTTON_W, 2));
        };

        class VehicleEjectButton : TPToButton {
            idc = 608;
            text = "<t align = 'center'>Eject</t>";
			onButtonClick = "[""action"", [""Eject""]] call ULP_fnc_adminCamera;";
            SAFEZONE_X(HORIZONTAL_GRID_X(0.5 - (BUTTON_GROUP_W / 2), BUTTON_W, 3));
        };

        class TargetText : Life_RscStructuredText {
            idc = 609;
            text = "No Target";
            x = 0.386562 * safezoneW + safezoneX;
            y = 0.895 * safezoneH + safezoneY;
            w = 0.226875 * safezoneW;
            h = 0.022 * safezoneH;
			class Attributes
			{
				align = "center";
			};
        };
    };
};