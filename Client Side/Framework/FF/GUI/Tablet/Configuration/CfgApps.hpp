class CfgApps {

    class Inventroy {
        title = "Inventroy";
        icon = "\a3\ui_f_curator\Data\RscCommon\RscAttributeInventory\filter_10_ca.paa";
        onButtonClick = "[23200, ""Inventory""] call FF_fnc_switchApp";
        conditions = "";
        disableIF = "";
        tooltip = "Inventroy";
    };

    class Licenses {
        title = "Licenses";
        icon = "\a3\ui_f_curator\Data\RscCommon\RscAttributeInventory\filter_10_ca.paa";
        onButtonClick = "[23300, ""Licenses""] call FF_fnc_switchApp";
        conditions = "playerSide != west";
        disableIF = "";
        tooltip = "Licenses";
    };

    class Trainings {
        title = "Authorisations";
        icon = "\a3\ui_f_curator\Data\RscCommon\RscAttributeInventory\filter_10_ca.paa";
        onButtonClick = "";
        conditions = "playerSide isEqualTo west";
        disableIF = "";
        tooltip = "Completed Trainings";
    };

    class KeyChain {
        title = "Key Chain";
        icon = "\a3\ui_f_curator\Data\RscCommon\RscAttributeInventory\filter_10_ca.paa";
        onButtonClick = "createDialog ""Life_key_management"";";
        conditions = "";
        disableIF = "";
        tooltip = "View all vehicle and house keys...";
    };

    class Mobile {
        title = "Mobile";
        icon = "\a3\3den\data\Cfg3DEN\Comment\texture_ca.paa";
        onButtonClick = "createDialog ""Life_cell_phone"";";
        conditions = "";
        disableIF = "";
        tooltip = "Mobile";
    };

    class Group {
        title = "Group";
        icon = "\a3\3den\data\Cfg3DEN\Group\iconCustomComposition_ca.paa";
        onButtonClick = "if (isNil ""life_action_gangInUse"") then {if (isNil {(group player) getVariable ""gang_owner""}) then {createDialog ""Life_Create_Gang_Diag"";} else {[] spawn life_fnc_gangMenu;};};";
        conditions = "playerSide isEqualTo civilian";
        disableIF = "";
        tooltip = "Group Management";
    };

    class WantedList {
        title = "Wanted List";
        icon = "\a3\ui_f_curator\Data\RscCommon\RscAttributeInventory\filter_10_ca.paa";
        onButtonClick = "[] call life_fnc_wantedMenu;";
        conditions = "playerSide isEqualTo west";
        disableIF = "";
        tooltip = "Police National Computer";
    };

    class Market {
        title = "Market";
        icon = "\a3\3den\data\Displays\Display3DEN\ToolBar\vert_ATL_ca.paa";
        onButtonClick = "";
        conditions = "";
        disableIF = "";
        tooltip = "View Buy/Sell Prices on the Island";
    };

    class Perks {
        title = "Perks";
        icon = "\a3\ui_f\data\GUI\Rsc\RscDisplayMain\profile_player_ca.paa";
        onButtonClick = "";
        conditions = "";
        disableIF = "";
        tooltip = "Perk Management";
    };

    class Professions {
        title = "Professions";
        icon = "\a3\ui_f\data\GUI\Rsc\RscDisplayMain\profile_player_ca.paa";
        onButtonClick = "";
        conditions = "";
        disableIF = "";
        tooltip = "View Professions...";
    };

    class Settings {
        title = "Settings";
        icon = "\a3\ui_f\data\GUI\Rsc\RscDisplayMain\menu_options_ca.paa";
        onButtonClick = "[] call life_fnc_settingsMenu;";
        conditions = "";
        disableIF = "";
        tooltip = "Configure your experiance!";
    };

    class SyncData {
        title = "Save Data";
        icon = "\a3\ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_saveas_ca.paa";
        onButtonClick = "[] call SOCK_fnc_syncData;";
        conditions = "";
        disableIF = "";
        tooltip = "Save your data to the server...";
    };
};