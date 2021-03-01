class CfgSpawns {
    class BaseSpawn {
        factions[] = { "Civilian" };
        buildings[] = {};
        radius = 300;
        conditions = "true";
    };
    class Police : BaseSpawn { factions[] = { "Police" }; };
    class Medic : BaseSpawn { factions[] = { "Medic" }; };

    class Altis {
        // Altis Police Constabulary
        class KavalaStation : Police {
            displayName = "Kavala Station";
            marker = "apc_spawn_kavala";
            icon = "data\icons\ico_Kavala.paa";
        };
        class AthiraStation : Police {
            displayName = "Athira Station";
            marker = "apc_spawn_athira";
            icon = "data\icons\ico_Athira.paa";
        };
        class PyrgosStation : Police {
            displayName = "Pyrgos Station";
            marker = "apc_spawn_pyrgos";
            icon = "data\icons\ico_Pyrgos.paa";
        };
        class AgiosStation : Police {
            displayName = "Agios Station";
            marker = "apc_spawn_agios";
            icon = "data\icons\ico_Agios.paa";
        };
        class MarineStation : Police {
            displayName = "Marine Base";
            marker = "apc_spawn_marine";
            icon = "\a3\ui_f\data\map\MapControl\bunker_ca.paa";
        };

        // National Health Service
        class KavalaHospital : Medic {
            displayName = "Kavala Hospital";
            marker = "nhs_spawn_kavala";
            icon = "data\icons\ico_Kavala.paa";
        };
        class AthiraHospital : Medic {
            displayName = "Athira Hospital";
            marker = "nhs_spawn_athira";
            icon = "data\icons\ico_Athira.paa";
        };
        class PyrgosHospital : Medic {
            displayName = "Pyrgos Hospital";
            marker = "nhs_spawn_pyrgos";
            icon = "data\icons\ico_Pyrgos.paa";
        };

        // Civilian
        class Kavala : BaseSpawn {
            displayName = "Kavala";
            marker = "civ_spawn_kavala";
            icon = "data\icons\ico_Kavala.paa";
        };
        class Athira : BaseSpawn {
            displayName = "Athira";
            marker = "civ_spawn_athira";
            icon = "data\icons\ico_Athira.paa";
        };
        class Pyrgos : BaseSpawn {
            displayName = "Pyrgos";
            marker = "civ_spawn_pyrgos";
            icon = "data\icons\ico_Pyrgos.paa";
        };
        class Sofia : BaseSpawn {
            displayName = "Sofia";
            marker = "civ_spawn_sofia";
            icon = "data\icons\ico_Agios.paa"; // CHANGE
        };
        class Agios : BaseSpawn {
            displayName = "Agios";
            marker = "civ_spawn_agios";
            icon = "data\icons\ico_Agios.paa"; // CHANGE
        };
        class Neochori : BaseSpawn {
            displayName = "Neochori";
            marker = "civ_spawn_neochori";
            icon = "data\icons\ico_Agios.paa"; // CHANGE
        };
    };

    class Malden {
        class LaTriniteConstabulary : Police {
            displayName = "La Trinité Constabulary";
            marker = "cop_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class test : Police {
            displayName = "Another Option";
            marker = "cop_spawn_2";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };

        class LaTriniteHospital : NHS {
            displayName = "La Trinité HQ";
            marker = "medic_spawn";
            icon = "\a3\ui_f\data\map\VehicleIcons\pictureLogic_ca.paa";
        };

        class LaTrinite : BaseSpawn {
            displayName = "La Trinité";
            marker = "civ_spawn_1";
            icon = "\a3\ui_f\data\map\LocationTypes\vegetationBroadleaf_CA.paa";
        };
    };
};