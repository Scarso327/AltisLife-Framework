#include "macros.hpp"

class RscPlayerMenu {
    idd = IDD_TABLET_MAIN;
    movingEnable = true;
    enableSimulation = true;
    onload = "";

    // Main Body...
    class ControlsBackground {
        class TabletImage : life_RscPicture {
            idc = -1;
            text = "data\ui\tablet.paa"; //--- ToDo: Localize;
            x = 0.2525 * safezoneW + safezoneX;
            y = 0.06 * safezoneH + safezoneY;
            w = 0.495 * safezoneW;
            h = 0.858 * safezoneH;
            moving = true; // Allows it to be dragged around
        };
    };

    // Inner Tablet...
    class Controls {
        // Include all pages...
        #include "RscMainMenu.hpp"
        #include "RscInventoryMenu.hpp"
        #include "RscLicenseMenu.hpp"
        #include "RscKeyMenu.hpp"
    };
};