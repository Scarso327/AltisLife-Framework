class CfgSettings {
    developers[] = { "76561198092567307", "76561197971322689" };
    
    framework_version = "1.0.6";

    total_maxWeight = 5;

    sync_delay = 5 * 60;
    abort_delay = 10;

    starting_bank = 100000;
    paycheck_period = 15;

    buffedSellIncrease = 1.5;

    class DonationRewards {
        sellIncrease = 1.25;
        profChanceIncrease = 1.30;
        xpIncrease = 1.25;
        payIncrease = 1.25;
    };

    class CfgMedical {
        /* Bleed Out */
        AllowBleedoutPercentage = 0.75;
        BleedOutTime = 20 * 60;
        RedzonePercentage = 0.1;

        /* Blood */
        BloodBagIncrease = 90;
    };

    class CfgCredits {
        screenTime = 10;
        
        class Hello {
            items[] = {"""Welcome to""", """AscensionRP's Altis Life!"""};
            condition = "true";
        };
        class Forums : Hello {
            items[] = {"""Join us:""", """ascensionrp.co.uk"""};
        };
        class Development : Hello {
            items[] = {"""Development Team""", """Scarso and Lewis"""};
        };
        class Governor  {
            items[] = {"(missionNamespace getVariable [""ULP_SRV_Setting_Governor"", []]) param [0, """"]"};
            condition = "!((missionNamespace getVariable [""ULP_SRV_Setting_Governor"", []]) isEqualTo [])";
        };
        class Events {
            title = "Active Events";
            items[] = {
                { """Gang Wars""", "missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false]" },
                { """Elections""", "missionNamespace getVariable [""ULP_SRV_Setting_Election"", false]" }  
            };
            condition = "missionNamespace getVariable [""ULP_SRV_Setting_BaseBidsActive"", false] || { missionNamespace getVariable [""ULP_SRV_Setting_Election"", false] }";
        };
    };

    class NLR {
        nlrTimer = 15 * 60;
        nlrDistance = 1500;
    };
    
    class Police {
        impoundTime = 30;
        ticketFee[] = { 100, 300000 };
        impoundFee[] = { 5000, 150000 };
        clampFee[] = { 5000, 50000 };
        crushTime = 60;
    };
    
    garageDelay = 15;

    communicationDevices[] = { "ItemRadio", "ItemGPS", "B_UavTerminal", "O_UavTerminal", "I_UavTerminal" };

    doesntThreaten[] = { "", "Binocular", "Rangefinder", "hgun_Pistol_Signal_F" };
    taserWeapons[] = { "hgun_P07_F", "hgun_P07_blk_F" };
    rubberWeapons[] = { "arifle_Mk20C_plain_F" };
    rubberBullets[] = { "B_556x45_Ball_Tracer_Green" };

    allowedCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";

    threatLevels[] = { "Low", "Moderate", "Substantial", "Severe", "Critical" };
    
    class Remotes {
        class Sound {
            maxDistance = 50;
            sounds[] = { "taserSound", "unlockCarSound", "lockCarSound", "panicButton" };
        };
    };

    class Player {
        aimPrecision = false;
        loadCoef = 0.75;
    };

    class Identity {
        nameLength = 24;
    };

    class Gates {
        class Land_BarGate_F { anim = "Door_1_rot"; };
        class Land_RoadBarrier_01_F : Land_BarGate_F {};
        class Land_ConcreteWall_01_m_gate_F { anim = "Door_1_move"; };
        class Land_ConcreteWall_01_l_gate_F : Land_ConcreteWall_01_m_gate_F {};
    };
};

#include "CfgSurvival.hpp"
