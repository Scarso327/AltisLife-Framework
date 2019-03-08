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

    class Group {
        title = "Group";
        icon = "\a3\3den\data\Cfg3DEN\Group\iconCustomComposition_ca.paa";
        onButtonClick = "";
        conditions = "playerSide isEqualTo civilian";
        disableIF = "";
        tooltip = "Group Management";
    };

    class WantedList {
        title = "Wanted List";
        icon = "\a3\ui_f_curator\Data\RscCommon\RscAttributeInventory\filter_10_ca.paa";
        onButtonClick = "";
        conditions = "playerSide isEqualTo west";
        disableIF = "";
        tooltip = "Police National Computer";
    };

    class Mobile {
        title = "Mobile";
        icon = "\a3\3den\data\Cfg3DEN\Comment\texture_ca.paa";
        onButtonClick = "";
        conditions = "";
        disableIF = "";
        tooltip = "Mobile";
    };

    class Perks {
        title = "Perks";
        icon = "\a3\ui_f\data\GUI\Rsc\RscDisplayMain\profile_player_ca.paa";
        onButtonClick = "";
        conditions = "";
        disableIF = "";
        tooltip = "Perk Management";
    };

};