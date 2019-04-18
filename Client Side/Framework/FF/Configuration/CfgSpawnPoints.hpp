class CfgSpawnPoints {
    class Tanoa {
        class Civilian {
            class civ_eorgetown {
                displayName = "Georgetown";
                spawnMarker = "civ_spawn_1";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "";
            };

            class civ_la_rochelle {
                displayName = "La Rochelle";
                spawnMarker = "civ_spawn_2";
                icon = "\a3\ui_f\data\map\MapControl\lighthouse_CA.paa";
                conditions = "";
            };

            class civ_lijnhaven {
                displayName = "Lijnhaven";
                spawnMarker = "civ_spawn_3";
                icon = "\a3\ui_f\data\map\MapControl\fountain_CA.paa";
                conditions = "";
            };
        };

        class Cop {
            class tpc_georgetown {
                displayName = "Georgetown HQ";
                spawnMarker = "cop_spawn_1";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "";
            };

            class tpc_la_rochelle {
                displayName = "La Rochelle HQ";
                spawnMarker = "cop_spawn_2";
                icon = "\a3\ui_f\data\map\MapControl\lighthouse_CA.paa";
                conditions = "";
            };

            class tpc_lijnhaven {
                displayName = "Lijnhaven HQ";
                spawnMarker = "cop_spawn_3";
                icon = "\a3\ui_f\data\map\MapControl\fountain_CA.paa";
                conditions = "";
            };

            class tpc_docks {
                displayName = "Southern Docks";
                spawnMarker = "cop_spawn_5";
                icon = "\a3\ui_f\data\map\Markers\NATO\c_ship.paa";
                conditions = "license_cop_sfo1 || license_cop_sfo2 || license_cop_sfo3";
            };
        };

        class Medic {
            class nhs_georgetown {
                displayName = "Georgetown Clinic";
                spawnMarker = "medic_spawn_1";
                icon = "\a3\ui_f\data\map\VehicleIcons\pictureLogic_ca.paa";
                conditions = "";
            };

            class nhs_airbase {
                displayName = "Southen Airbase";
                spawnMarker = "medic_spawn_1";
                icon = "\a3\ui_f\data\map\Markers\NATO\c_air.paa";
                conditions = "license_med_taa";
            };
        };
    };

    class Altis {
        class Civilian {
            class Kavala {
                displayName = "Kavala";
                spawnMarker = "civ_spawn_1";
                icon = "\a3\ui_f\data\map\MapControl\watertower_ca.paa";
                conditions = "";
            };

            class Athira {
                displayName = "Athira";
                spawnMarker = "civ_spawn_3";
                icon = "\a3\ui_f\data\map\MapControl\watertower_ca.paa";
                conditions = "";
            };

            class Pyrgos {
                displayName = "Pyrgos";
                spawnMarker = "civ_spawn_2";
                icon = "\a3\ui_f\data\map\MapControl\watertower_ca.paa";
                conditions = "";
            };

            class Sofia {
                displayName = "Sofia";
                spawnMarker = "civ_spawn_4";
                icon = "\a3\ui_f\data\map\MapControl\watertower_ca.paa";
                conditions = "";
            };
        };

        class Cop {
            class Kavala {
                displayName = "Kavala HQ";
                spawnMarker = "cop_spawn_1";
                icon = "\a3\ui_f\data\map\MapControl\watertower_ca.paa";
                conditions = "";
            };

            class Athira {
                displayName = "Athira HQ";
                spawnMarker = "cop_spawn_3";
                icon = "\a3\ui_f\data\map\MapControl\fuelstation_ca.paa";
                conditions = "";
            };

            class Pyrgos {
                displayName = "Pyrgos HQ";
                spawnMarker = "cop_spawn_2";
                icon = "\a3\ui_f\data\map\GroupIcons\badge_rotate_0_gs.paa";
                conditions = "";
            };

            class Air {
                displayName = $STR_MAR_Police_Air_HQ;
                spawnMarker = "cop_spawn_4";
                icon = "\a3\ui_f\data\map\Markers\NATO\b_air.paa";
                conditions = "call life_coplevel >= 2 && {license_cop_cAir}";
            };

            class HW {
                displayName = $STR_MAR_Highway_Patrol;
                spawnMarker = "cop_spawn_5";
                icon = "\a3\ui_f\data\map\GroupIcons\badge_rotate_0_gs.paa";
                conditions = "call life_coplevel >= 3";
            };
        };

        class Medic {
            class Kavala {
                displayName = $STR_SP_EMS_Kav;
                spawnMarker = "medic_spawn_1";
                icon = "\a3\ui_f\data\map\MapControl\hospital_ca.paa";
                conditions = "";
            };

            class Athira {
                displayName = $STR_SP_EMS_Ath;
                spawnMarker = "medic_spawn_2";
                icon = "\a3\ui_f\data\map\MapControl\hospital_ca.paa";
                conditions = "";
            };

            class Pyrgos {
                displayName = $STR_SP_EMS_Pyr;
                spawnMarker = "medic_spawn_3";
                icon = "\a3\ui_f\data\map\MapControl\hospital_ca.paa";
                conditions = "";
            };
        };
    };
};
