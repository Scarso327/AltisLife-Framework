class CfgSpawns {
    class Altis {
        class Police {};
        class Medic {};
        class Civilian {};
    };

     class Tanoa {
        class Police {
            // Default TPC Spawn Points
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

            // Specilised TPC Spawn Points
            class tpc_docks {
                displayName = "Southern Docks";
                spawnMarker = "cop_spawn_4";
                icon = "\a3\ui_f\data\map\Markers\NATO\c_ship.paa";
                conditions = "[""Police_ASO"", 1] call ULP_fnc_hasAccess || [""Police_SFO"", 1] call ULP_fnc_hasAccess";
            };

            class tpc_combinded {
                displayName = "Joint Marine HQ";
                spawnMarker = "cop_spawn_5";
                icon = "\a3\ui_f\data\map\Markers\NATO\c_ship.paa";
                conditions = "[""Police_ASO"", 1] call ULP_fnc_hasAccess || [""Police_SFO"", 1] call ULP_fnc_hasAccess";
            };
        };

        class Medic {
            // Default TAS Spawn Points
            class tas_georgetown {
                displayName = "Georgetown Clinic";
                spawnMarker = "medic_spawn_1";
                icon = "\a3\ui_f\data\map\VehicleIcons\pictureLogic_ca.paa";
                conditions = "";
            };

            class tas_combinded {
                displayName = "Joint Marine HQ";
                spawnMarker = "medic_spawn_2";
                icon = "\a3\ui_f\data\map\Markers\NATO\c_ship.paa";
                conditions = "";
            };

            // Specilised TAS Spawn Points
            class tas_airbase {
                displayName = "Southen Airbase";
                spawnMarker = "medic_spawn_3";
                icon = "\a3\ui_f\data\map\Markers\NATO\c_air.paa";
                conditions = "[""Medic_TAA"", 1] call ULP_fnc_hasAccess";
            };
        };

        class Civilian {
            // Default Civilian Spawn Points
            class civ_eorgetown {
                displayName = "Georgetown";
                spawnMarker = "civ_spawn_1";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "";
            };

            class civ_la_rochelle {
                displayName = "La Rochelle";
                spawnMarker = "civ_spawn_2";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "";
            };

            class civ_lijnhaven {
                displayName = "Lijnhaven";
                spawnMarker = "civ_spawn_3";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "";
            };

            // 'Wide Traveller' Spawn Points
            /*class civ_nicolet {
                displayName = "Nicolet";
                spawnMarker = "civ_spawn_4";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "(FF_Perks findIf { _x isEqualTo ""wideTraveller"" }) > -1";
            };

            class civ_oumere {
                displayName = "Ouméré";
                spawnMarker = "civ_spawn_5";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "(FF_Perks findIf { _x isEqualTo ""wideTraveller"" }) > -1";
            };

            class civ_moddergat {
                displayName = "Moddergat";
                spawnMarker = "civ_spawn_6";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "(FF_Perks findIf { _x isEqualTo ""wideTraveller"" }) > -1";
            };

            class civ_katkoula {
                displayName = "Katkoula";
                spawnMarker = "civ_spawn_7";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "(FF_Perks findIf { _x isEqualTo ""wideTraveller"" }) > -1";
            };

            class civ_tuvanaka {
                displayName = "Tuvanaka";
                spawnMarker = "civ_spawn_8";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "(FF_Perks findIf { _x isEqualTo ""wideTraveller"" }) > -1";
            };

            // Job Specific Spawn Points
            class civ_idap {
                displayName = "IDAP Camp";
                spawnMarker = "civ_spawn_idap";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "license_civ_idap";
            };

            class civ_aan {
                displayName = "AAN World News";
                spawnMarker = "civ_spawn_aan";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "license_civ_aan";
            };*/
        };
    };
};