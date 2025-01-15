class CfgSettings {
    developers[] = { "76561198092567307", "76561197971322689" };
    
    framework_version = "1.2.4";

    total_maxWeight = 5;

    sync_delay = 5 * 60;
    abort_delay = 10;

    starting_bank = 125000;
    paycheck_period = 15;

    buffedSellIncrease = 1.5;

    disabledDamageInGreenzone = true;

    class DonationRewards {
        sellIncrease = 1.25;
        profChanceIncrease = 1.30;
        xpIncrease = 1.25;
        payIncrease = 1.25;
    };

    class CfgMedical {
        /* Bleed Out */
        // Left is no medics - right is medics
        AllowBleedoutPercentage[] = { 0.75, 0.4 };
        BleedOutTime = 20 * 60;
        RedzonePercentage = 0.1;

        /* Blood */
        BloodBagIncrease = 90;
    };

    class CfgCredits {
        screenTime = 10;
        
        class Hello {
            items[] = {"""Welcome to""", """Mantle Network's Altis Life!"""};
            condition = "true";
        };
        class Forums : Hello {
            items[] = {"""Join us:""", """mantlenetwork.co.uk"""};
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

    speedLimit: 100;
    
    garageDelay = 15;

    communicationDevices[] = { "ItemRadio", "ItemGPS", "B_UavTerminal", "O_UavTerminal", "I_UavTerminal" };

    doesntThreaten[] = { "", "Binocular", "Rangefinder", "hgun_Pistol_Signal_F" };

    allowedCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";

    threatLevels[] = { "Low", "Moderate", "Substantial", "Severe", "Critical" };
    
    class Remotes {
        class Sound {
            maxDistance = 100;
            sounds[] = { "taserSound", "unlockCarSound", "lockCarSound", "panicButton", "handCuff" };
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

    class Weather {
        maxFog = 0.1;
    };
};

#include "CfgSurvival.hpp"
