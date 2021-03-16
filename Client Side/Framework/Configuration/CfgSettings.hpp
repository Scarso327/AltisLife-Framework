#define true 1
#define false 0

class CfgSettings {
    framework_version = "5.0.0";
    local_version = "1.0.0";

    total_maxWeight = 24;

    sync_delay = 5 * 60;
    abort_delay = 10;

    starting_bank = 50000;
    paycheck_period = 15;

    class DonationRewards {
        sellIncrease = 1.25;
        profChanceIncrease = 1.30;
        xpIncrease = 1.25;
        payIncrease = 1.25;
    };

    class CfgMedical {
        /* Bleed Out */
        WaitForBleedOutTime = 30;
        BleedOutTime = 300;

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
            items[] = {"URL:", "ascensionroleplay.co.uk"};
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
    
    doesntThreaten[] = { "", "Binocular", "Rangefinder" };
    taserWeapons[] = { "hgun_P07_F", "hgun_P07_blk_F" };
    allowedCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";
    threatLevels[] = { "Low", "Moderate", "Substantial", "Severe", "Critical" };
};

#include "CfgSurvival.hpp"