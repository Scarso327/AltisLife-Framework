class CfgSettings {
    developers[] = { "76561198092567307", "76561197971322689" };
    
    framework_version = "5.0.0";
    local_version = "1.0.0";

    total_maxWeight = 5;

    sync_delay = 5 * 60;
    abort_delay = 10;

    starting_bank = 100000;
    paycheck_period = 15;

    class DonationRewards {
        sellIncrease = 1.25;
        profChanceIncrease = 1.30;
        xpIncrease = 1.25;
        payIncrease = 1.25;
    };

    class CfgMedical {
        /* Bleed Out */
        AllowBleedoutPercentage = 0.5;
        BleedOutTime = 10 * 60;

        /* Blood */
        BloodBagIncrease = 90;

        /* Revival */
        RevivalFee = 2500;
        PoliceRevive = false;
    };

    class CfgCredits {
        screenTime = 10;
        
        class Hello {
            title = "Hello there!";
            items[] = {"Welcome to", "AscensionRP's Altis Life!"};
        };
        class Forums {
            title = "Forums and Teamspeak!";
            items[] = {"Join us:", "ascensionrp.co.uk"};
        };
        class Development {
            title = "Development Team!";
            items[] = {"Development Team", "Scarso and Lewis"};
        };
    };

    class NLR {
        nlrTimer = 15 * 60;
        nlrDistance = 1500;
    };
    
    class Police {
        impoundTime = 30;
        impoundFee[] = { 5000, 150000 };
        crushTime = 60;
    };
    
    garageDelay = 15;

    doesntThreaten[] = { "", "Binocular", "Rangefinder", "hgun_Pistol_Signal_F" };
    taserWeapons[] = { "hgun_P07_F", "hgun_P07_blk_F" };
    rubberWeapons[] = { "arifle_Mk20C_plain_F" };
    rubberBullets[] = { "B_556x45_Ball_Tracer_Green" };
    allowedCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";
    threatLevels[] = { "Low", "Moderate", "Substantial", "Severe", "Critical" };
    
    class Remotes {
        class Sound {
            maxDistance = 50;
            sounds[] = { "taserSound", "unlockCarSound", "lockCarSound", "Backup" };
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
