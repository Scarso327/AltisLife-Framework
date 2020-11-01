/*
*    Format:
*        3: STRING (Conditions) - Must return boolean :
*            String can contain any amount of conditions, aslong as the entire
*            string returns a boolean. This allows you to check any levels, licenses etc,
*            in any combination. For example:
*                "[""Police_Main"", 1] call ULP_fnc_hasAccess;"
*            This will also let you call any other function.
*
*/
class CfgSpawns {

    class Altis {
        class Police {};
        class Medic {};
        class Civilian {};
    };

    class Tanoa {
        class Police {
            class tpc_georgetown {
                displayName = "Georgetown HQ";
                spawnMarker = "cop_spawn_1";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "";
            };
        };
        class Medic {
            class tas_georgetown {
                displayName = "Georgetown Clinic";
                spawnMarker = "medic_spawn_1";
                icon = "\a3\ui_f\data\map\VehicleIcons\pictureLogic_ca.paa";
                conditions = "";
            };
        };
        class Civilian {
            class civ_eorgetown {
                displayName = "Georgetown";
                spawnMarker = "civ_spawn_1";
                icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
                conditions = "";
            };
        };
    };
};