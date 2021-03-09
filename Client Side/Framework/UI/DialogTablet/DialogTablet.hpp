#define UI_X 0.298906
#define UI_Y 0.291
#define UI_WIDTH 0.402187
#define UI_HEIGHT 0.451
#define TABLET_BUTTON_W HORIZONTAL_GRID_W(UI_WIDTH, 5)
#define TABLET_BUTTON_H VERTICAL_GRID_H(UI_HEIGHT, 3)

class TabletApp : Life_RscButtonCenter {
    fade = 0;
	animTextureOver = "#(argb,8,8,3)color(0.6,0.6,0.6,0.8)";
    animTextureFocused = "#(argb,8,8,3)color(0.6,0.6,0.6,0.8)";
    animTexturePressed = "#(argb,8,8,3)color(0.6,0.6,0.6,0.8)";
    colorText[] = {1, 1, 1, 1};
	color2[] = {1, 1, 1, 1};
	colorFocused[] = {1, 1, 1, 1};
	colorBackgroundFocused[] = {0.2, 0.2, 0.2, 0.8};
    colorBackground[] = {0.15, 0.15, 0.15, 0.7};
	colorBackground2[] = {0.2, 0.2, 0.2, 0.8};
};

class DialogTablet {
    idd = 23000;
    onload = "uiNamespace setVariable ['DialogTablet', _this select 0]";
	onunload = "[((_this select 0) getVariable [""blur"", -1])] call ULP_fnc_destroyEffect;";

    // Main Body...
    class ControlsBackground {
        class TabletImage : life_RscPicture {
            idc = 23013;
            text = "data\ui\tablet.paa"; 
            x = 0.278281 * safezoneW + safezoneX;
            y = 0.082 * safezoneH + safezoneY;
            w = 0.443438 * safezoneW;
            h = 0.836 * safezoneH;
        };

		class Background : Life_RscText {
			idc = 23012;
			text = "";
			/*SET_GUI_GRID_CENTER_X(0);
			SET_GUI_GRID_CENTER_Y(0);
			SET_GUI_GRID_CENTER_W(1);
			SET_GUI_GRID_CENTER_H(1);*/
			
			colorBackground[] = {0.086,0.082,0.102,1};
		};
    };

	class Controls {
		class Title : Life_RscStructuredText {
            idc = 23001;
            text = "<t align='left'>Scarso</t><t align='right'>£1,000</t>";
            colorBackground[] = NO_COLOUR;
            SAFEZONE_X(UI_X);
            SAFEZONE_Y(0.258);
			SAFEZONE_W(UI_WIDTH);
			SAFEZONE_H(0.033);
        };

		class Profile : TabletApp {
			idc = 23002;
			text = "<br/><br/><br/><img image='\a3\ui_f\data\GUI\Rsc\RscDisplayMain\menu_singleplayer_ca.paa' align='center' size='7' color='#808080'/><br/><t align = 'center'>Profile</t>";
			onButtonClick = "[""Profile""] call ULP_fnc_setScreen;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 1));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 0));
			SAFEZONE_W(((TABLET_BUTTON_W * 2) + MARGIN_X));
			SAFEZONE_H(((TABLET_BUTTON_H * 2) + MARGIN_Y));
		};

		class Inventory : TabletApp {
			idc = 23003;
			text = "<br/><img image='\a3\ui_f_curator\Data\RscCommon\RscAttributeInventory\filter_10_ca.paa' align='center' size='4' color='#808080'/><br/><t align = 'center'>Inventory</t>";
			onButtonClick = "[""Inventory""] call ULP_fnc_setScreen;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 3));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 0));
			SAFEZONE_W(((TABLET_BUTTON_W * 2) + MARGIN_X));
			SAFEZONE_H(TABLET_BUTTON_H);
		};

		class Messaging : TabletApp {
			idc = 23004;
			text = "<br/><img image='\a3\3den\data\Cfg3DEN\Comment\texture_ca.paa' align='center' size='4' color='#808080'/><br/><t align = 'center'>Messaging</t>";
			onButtonClick = "[""Messaging""] call ULP_fnc_setScreen;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 3));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 1));
			SAFEZONE_W(((TABLET_BUTTON_W * 2) + MARGIN_X));
			SAFEZONE_H(TABLET_BUTTON_H);
		};

		class Group : TabletApp {
			idc = 23005;
			text = "<br/><img image='\a3\ui_f\data\GUI\Rsc\RscDisplayMain\menu_multiplayer_ca.paa' align='center' size='4' color='#808080'/><br/><t align = 'center'>Group</t>";
			onButtonClick = "[] call ULP_fnc_openGroup;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 0));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 0));
			SAFEZONE_W(TABLET_BUTTON_W);
			SAFEZONE_H(TABLET_BUTTON_H);
		};

		class Keys : TabletApp {
			idc = 23006;
			text = "<br/><img image='data\ui\keys.paa' align='center' size='4' color='#808080'/><br/><t align = 'center'>Keys</t>";
			onButtonClick = "[""Keys""] call ULP_fnc_setScreen;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 0));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 1));
			SAFEZONE_W(TABLET_BUTTON_W);
			SAFEZONE_H(TABLET_BUTTON_H);
		};

		class Dispute : TabletApp {
			idc = 23007;
			text = "<br/><img image='data\ui\dispute.paa' align='center' size='4' color='#808080'/><br/><t align = 'center'>Dispute</t>";
			onButtonClick = "[""Dispute""] call ULP_fnc_setScreen;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 0));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 2));
			SAFEZONE_W(TABLET_BUTTON_W);
			SAFEZONE_H(TABLET_BUTTON_H);
		};

		class Market : TabletApp {
			idc = 23008;
			text = "<br/><img image='\a3\3den\data\Displays\Display3DEN\ToolBar\vert_ATL_ca.paa' align='center' size='4' color='#808080'/><br/><t align = 'center'>Market</t>";
			onButtonClick = "[""Market""] call ULP_fnc_setScreen;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 1));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 2));
			SAFEZONE_W(TABLET_BUTTON_W);
			SAFEZONE_H(TABLET_BUTTON_H);
		};

		class Goals : TabletApp {
			idc = 23009;
			text = "<br/><br/><img image='\a3\ui_f_curator\Data\CfgMPGameTypes\zsc_ca.paa' align='center' size='3' color='#808080'/><br/><t align = 'center'>Goals</t>";
			onButtonClick = "[""Goals""] call ULP_fnc_setScreen;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 2));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 2));
			SAFEZONE_W(TABLET_BUTTON_W);
			SAFEZONE_H(TABLET_BUTTON_H);
		};

		class Perks : TabletApp {
			idc = 23010;
			text = "<br/><br/><img image='\a3\ui_f_curator\Data\RscCommon\RscAttributePunishmentAnimation\PushupsLegs.paa' align='center' size='3' color='#808080'/><br/><t align = 'center'>Perks</t>";
			onButtonClick = "[""Perks""] call ULP_fnc_setScreen;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 3));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 2));
			SAFEZONE_W(TABLET_BUTTON_W);
			SAFEZONE_H(TABLET_BUTTON_H);
		};

		class Settings : TabletApp {
			idc = 23011;
			text = "<br/><img image='\a3\ui_f\data\GUI\Rsc\RscDisplayMain\menu_options_ca.paa' align='center' size='4' color='#808080'/><br/><t align = 'center'>Settings</t>";
			onButtonClick = "[""Settings""] call ULP_fnc_setScreen;";
			SAFEZONE_X(HORIZONTAL_GRID_X(UI_X, TABLET_BUTTON_W, 4));
			SAFEZONE_Y(VERTICAL_GRID_Y(UI_Y, TABLET_BUTTON_H, 2));
			SAFEZONE_W(TABLET_BUTTON_W);
			SAFEZONE_H(TABLET_BUTTON_H);
		};

		#include "Screens\Inventory.hpp"
		#include "Screens\Keys.hpp"
	};
};

// ["0.29375 * safezoneW + safezoneX","0.243 * safezoneH + safezoneY","0.4150 * safezoneW","0.505 * safezoneH"]