class Loadouts {
    class WEST {
        uniform[] = {
            {"U_Rangemaster", "[""Police_Main"", 0] call ULP_fnc_hasAccess;"}
        };
        headgear[] = {
            {"H_Cap_blk", "[""Police_Main"", 1] call ULP_fnc_hasAccess;"},
            {"H_Beret_blk", "[""Police_Main"", 2] call ULP_fnc_hasAccess;"},
            {"H_Beret_Colonel", "[""Police_Main"", 4] call ULP_fnc_hasAccess;"},
            {"H_Beret_02", "[""Police_Main"", 6] call ULP_fnc_hasAccess;"}
        };
        vest[] = {};
        backpack[] = {};
        weapon[] = {};
        mags[] = {};
        items[] = {};
        linkedItems[] = {
            {"ItemMap", "[""Police_Main"", 0] call ULP_fnc_hasAccess;"},
            {"ItemGPS", "[""Police_Main"", 0] call ULP_fnc_hasAccess;"},
            {"ItemCompass", "[""Police_Main"", 0] call ULP_fnc_hasAccess;"},
            {"ItemWatch", "[""Police_Main"", 0] call ULP_fnc_hasAccess;"}
        };
    };

    class GUER {
        uniform[] = {
            {"U_Rangemaster", "[""Medic_Main"", 0] call ULP_fnc_hasAccess;"}
        };
        headgear[] = {};
        vest[] = {};
        backpack[] = {};
        weapon[] = {};
        mags[] = {};
        items[] = {};
        linkedItems[] = {
            {"ItemMap", "[""Medic_Main"", 0] call ULP_fnc_hasAccess;"},
            {"ItemGPS", "[""Medic_Main"", 0] call ULP_fnc_hasAccess;"},
            {"ItemCompass", "[""Medic_Main"", 0] call ULP_fnc_hasAccess;"},
            {"ItemWatch", "[""Medic_Main"", 0] call ULP_fnc_hasAccess;"}
        };
    };

    class CIV {
        uniform[] = {
            {"U_C_Poor_1", "!life_is_arrested"}
        };
        headgear[] = {};
        vest[] = {};
        backpack[] = {};
        weapon[] = {};
        mags[] = {};
        items[] = {};
        linkedItems[] = {
            {"ItemMap", ""},
            {"ItemCompass", ""},
            {"ItemWatch", ""}
        };
    };
};
