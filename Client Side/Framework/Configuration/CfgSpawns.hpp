class CfgSpawns {
    class Altis {
        class Police {};
        class Medic {};
        class Civilian {};
    };

     class Tanoa {
        class Police {};
        class Medic {};
        class Civilian {};

    class Malden {
        class Police {
            class latrinite {
                displayName = "La Trinité Constabulary";
                spawnMarker = "cop_spawn_1";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "";
            };

            class leport {
                displayName = "Le Port Constabulary";
                spawnMarker = "cop_spawn_2";
                icon = "\a3\ui_f\data\map\MapControl\lighthouse_CA.paa";
                conditions = "";
            };

            class sfomarine {
                displayName = "SFO Marine Base";
                spawnMarker = "cop_spawn_3";
                icon = "\a3\ui_f\data\map\Markers\NATO\c_ship.paa";
                conditions = "[""Police_SFO"", 1] call ULP_fnc_hasAccess;";
            };
        };
        
        class Medic {
            class latrinite {
                displayName = "La Trinité HQ";
                spawnMarker = "medic_spawn";
                icon = "\a3\ui_f\data\map\VehicleIcons\pictureLogic_ca.paa";
                conditions = "";
            };
        };

        class Civilian {
            class latrinite {
                displayName = "La Trinité";
                spawnMarker = "civ_spawn_1";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "";
            };

            class leport {
                displayName = "Le Port";
                spawnMarker = "civ_spawn_2";
                icon = "\a3\ui_f\data\map\MapControl\lighthouse_CA.paa";
                conditions = "";
            };

            class lapessagne {
                displayName = "La Pessagne";
                spawnMarker = "civ_spawn_3";
                icon = "\a3\ui_f\data\map\MapControl\fountain_CA.paa";
                conditions = "";
            };
        };
    };
};