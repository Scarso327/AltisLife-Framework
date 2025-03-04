class CfgSpawns {
    class BaseSpawn {
        factions[] = { "Civilian" };
        buildings[] = {};
        radius = 100;
        conditions = "true";
    };
    class Police : BaseSpawn { factions[] = { "Police" }; };
    class HATO : BaseSpawn { factions[] = { "Hato" }; };
    class Medic : BaseSpawn { factions[] = { "Medic" }; };
    class Civilian : BaseSpawn {
        buildings[] = {
            "Land_i_Shop_01_V1_F",
            "Land_i_Shop_02_V1_F",
            "Land_i_Shop_03_V1_F",
            "Land_i_Stone_HouseBig_V1_F",
            "Land_Chapel_V1_F",
            "Land_Chapel_V2_F",
            "Land_u_House_Big_02_V1_F",
            "Land_u_House_Big_01_V1_F",
            "Land_d_Stone_HouseBig_V1_F",
            "Land_d_Stone_HouseSmall_V1_F",
            "Land_d_House_Big_01_V1_F"
        };
    };

    class Altis {
        // Altis Police Service
        class KavalaStation : Police {
            displayName = "Kavala Headquarters";
            marker = "apc_spawn_kavala";
            icon = "Data\UI\Spawns\kavala.paa";
        };
        class KavalaStationNCA : Civilian {
            displayName = "NCA Frontline Headquarters";
            marker = "apc_spawn_nca";
            icon = "Data\UI\Spawns\kavala.paa";
            radius = 1;
            conditions = "[] call ULP_fnc_isUndercover";
        };
        class AthiraStation : Police {
            displayName = "Athira Station";
            marker = "apc_spawn_athira";
            icon = "Data\UI\Spawns\athira.paa";
        };
        class PyrgosStation : Police {
            displayName = "Pyrgos Station";
            marker = "apc_spawn_pyrgos";
            icon = "Data\UI\Spawns\pyrgos.paa";
        };
        class AgiosStation : Police {
            displayName = "Agios Station";
            marker = "apc_spawn_agios";
            icon = "Data\UI\Spawns\agios.paa";
        };
         class NpasBase : Police {
            displayName = "NPAS Base";
            marker = "apc_spawn_npas";
            icon = "Data\UI\Spawns\warehouse.paa";
            conditions = "[""Police_NPAS"", 1] call ULP_fnc_hasAccess";
        };
        class SegKavala : BaseSpawn {
            displayName = "10 Kavala Street";
            marker = "civ_spawn_seg_kav";
            icon = "Data\UI\Spawns\government.paa";
            conditions = "[""Police_SEG"", 1] call ULP_fnc_hasAccess";
        };
        class SegHouse : SegKavala {
            displayName = "SEG Safehouse";
            marker = "apc_spawn_seg";
        };
        class UndercoverHeadquarters : SegHouse {
            displayName = "NCA Covert Headquarters";
            marker = "apc_spawn_uc";
            icon = "Data\UI\Spawns\neochori.paa";
            conditions = "[] call ULP_fnc_isUndercover";
        };

        // Altis Ambulance Service
        class KavalaHospital : Medic {
            displayName = "Kavala Hospital";
            marker = "nhs_spawn_kavala";
            icon = "Data\UI\Spawns\kavala.paa";
        };
        class AthiraClinic : Medic {
            displayName = "Athira Clinic";
            marker = "nhs_spawn_athira";
            icon = "Data\UI\Spawns\athira.paa";
        };
        class PyrgosClinic : Medic {
            displayName = "Pyrgos Clinic";
            marker = "nhs_spawn_pyrgos";
            icon = "Data\UI\Spawns\pyrgos.paa";
        };
        class AgiosClinic : Medic {
            displayName = "Agios Clinic";
            marker = "nhs_spawn_agios";
            icon = "Data\UI\Spawns\agios.paa";
        };
        class SofiaClinic : Medic {
            displayName = "Sofia Clinic";
            marker = "nhs_spawn_sofia";
            icon = "Data\UI\Spawns\sofia.paa";
        };
        class AirAmbulance : Medic {
            displayName = "Air Ambulance Station";
            marker = "nhs_spawn_aa";
            icon = "Data\UI\Spawns\warehouse.paa";
            conditions = "[""Medic_AA"", 1] call ULP_fnc_hasAccess";
        };

        // Altis Police Service / Altis Ambulance Service
        class MarineStation : Police {
            displayName = "Marine Base";
            factions[] = { "Police", "Medic" };
            marker = "joint_spawn_marine";
            icon = "Data\UI\Spawns\marine.paa";
        };

        // HATO
        class HatoKavala : HATO {
            displayName = "Kavala Facility";
            marker = "hato_spawn_kavala";
            icon = "Data\UI\Spawns\kavala.paa";
        };
        class HatoAgios : HATO {
            displayName = "Agios Facility";
            marker = "hato_spawn_agios";
            icon = "Data\UI\Spawns\agios.paa";
        };

        // Government
        class GovernorResidence : BaseSpawn {
            displayName = "10 Kavala Street";
            marker = "civ_spawn_residence";
            icon = "Data\UI\Spawns\government.paa";
            conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection }";
        };
        class GovernmentOffices : GovernorResidence {
            displayName = "Government Offices";
            marker = "civ_spawn_government";
        };
        class KavalaSafehouse : GovernorResidence {
            displayName = "Kavala Safehouse";
            marker = "civ_spawn_kavSafehouse";
            conditions = "[] call ULP_fnc_isGovernor || { [] call ULP_fnc_isProtection && { [""GovernmentSafehouses""] call ULP_fnc_hasGroupPerk } }";
        };
        class PyrgosSafehouse : KavalaSafehouse {
            displayName = "Pyrgos Safehouse";
            marker = "civ_spawn_pyrSafehouse";
        };
        
        // Civilian
        class Kavala : Civilian {
            displayName = "Kavala";
            marker = "civ_spawn_kavala";
            icon = "Data\UI\Spawns\kavala.paa";
        };
        class Athira : Civilian {
            displayName = "Athira";
            marker = "civ_spawn_athira";
            icon = "Data\UI\Spawns\athira.paa";
        };
        class Pyrgos : Civilian {
            displayName = "Pyrgos";
            marker = "civ_spawn_pyrgos";
            icon = "Data\UI\Spawns\pyrgos.paa";
        };
        class Sofia : Civilian {
            displayName = "Sofia";
            marker = "civ_spawn_sofia";
            icon = "Data\UI\Spawns\sofia.paa";
            conditions = "[""WideTraveller""] call ULP_fnc_hasPerk";
        };
        class Agios : Sofia {
            displayName = "Agios";
            marker = "civ_spawn_agios";
            icon = "Data\UI\Spawns\agios.paa";
        };
        class Neochori : Sofia {
            displayName = "Neochori";
            marker = "civ_spawn_neochori";
            icon = "Data\UI\Spawns\neochori.paa";
        };

        class Taxi : BaseSpawn {
            displayName = "Taxi Altis";
            marker = "civ_spawn_taxi";
            icon = "Data\UI\Spawns\taxi.paa";
            conditions = "[""Taxi""] call ULP_fnc_hasLicense";
        };
        class Solicitor : BaseSpawn {
            displayName = "Altis Solicitors";
            marker = "civ_spawn_solicitor";
            icon = "Data\UI\Spawns\solicitor.paa";
            conditions = "[""Solicitor""] call ULP_fnc_hasLicense";
        };
        class News : BaseSpawn {
            displayName = "AAN World News";
            marker = "civ_spawn_news";
            icon = "Data\UI\Spawns\news.paa";
            conditions = "[""News""] call ULP_fnc_hasLicense";
        };
        class IDAP : BaseSpawn {
            displayName = "IDAP HQ";
            marker = "civ_spawn_idap";
            icon = "Data\UI\Spawns\idap.paa";
            conditions = "[""IDAP""] call ULP_fnc_hasLicense && { ULP_Reputation >= 750 }";
        };

        // Rebel/Blackmarket
        class Rebel_01 : BaseSpawn {
            displayName = "Rebel Outpost";
            marker = "civ_spawn_rebel_01";
            icon = "Data\UI\Spawns\rebel.paa";
            conditions = "[""Rebel""] call ULP_fnc_hasLicense && { missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false] }";
        };
        class Rebel_02 : Rebel_01 { marker = "civ_spawn_rebel_02"; };
        class Rebel_03 : Rebel_01 { 
            displayName = "Rebel FOB";
            marker = "civ_spawn_rebel_03"; 
        };
        class Blackmarket : Rebel_01 {
            displayName = "Blackmarket";
            marker = "civ_spawn_blackmarket";
            conditions = "[""Blackmarket""] call ULP_fnc_hasLicense && { missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false] } && { [""Blackmarketer""] call ULP_fnc_hasPerk || { [""Blackmarket""] call ULP_fnc_hasGroupPerk } }";
        };

        // Civilian Faction
        class DMS_Safehouse : Rebel_01 {
            displayName = "Dunamis Safehouse";
            marker = "dms_spawn_01";
            conditions = "[] call ULP_fnc_isDunamis";
        };
        class DMS_Camp : DMS_Safehouse {
            displayName = "Dunamis Camp";
            marker = "dms_spawn_02";
        };
        class DMS_FOB : DMS_Safehouse {
            displayName = "Dunamis FOB";
            marker = "dms_spawn_03";
            conditions = "[] call ULP_fnc_isDunamis && { ([] call ULP_fnc_getGroupRank) >= 2 }";
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

        class LaTriniteHospital : Medic {
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