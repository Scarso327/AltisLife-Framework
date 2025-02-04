class CfgLicenses {
    class BaseLicense {
        factions[] = { "Civilian" };
        description = "The base requirement for the processing of goods";
        class Settings {
            isVisible = false;
            isRemovable = false;
        };
        conditions = "true";
    };

    class Driving : BaseLicense {
        displayName = "Driving Licence";
        description = "The base requirement for purchasing a car/van";
        buyPrice = 1000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Trucking : Driving {
        displayName = "Trucking Licence";
        description = "The base requirement for purchasing a goods vehicle";
        buyPrice = 75000;
        class Settings : Settings {};
    };

    class Boating : Driving {
        displayName = "Boating Licence";
        description = "The base requirement for purchasing a boat";
        buyPrice = 6500;
        class Settings : Settings {};
    };

    class Piloting : Driving {
        displayName = "Piloting Licence";
        description = "The base requirement for purchasing a helicopter/plane";
        buyPrice = 600000;
        class Settings : Settings {};
    };

    class Home : Driving {
        displayName = "Homeowner's Approval";
        description = "The base requirement for purchasing a property";
        buyPrice = 5000000;
        class Settings : Settings {};
    };

    class Taxi : Driving {
        displayName = "Taxi Altis Worker";
        description = "Approved to operate as a taxi driver on Altis";
        buyPrice = 35000;
        onBought = "[""Employment""] call ULP_fnc_achieve;";
        class Settings : Settings {};
        conditions = "[""CompletedCV""] call ULP_fnc_hasPerk";
    };

    class Solicitor : Taxi {
        displayName = "Altis Solicitors";
        description = "Approved to operate as a solicitor on Altis";
        buyPrice = 2000000;
        class Settings : Settings {};
    };

    class News : Taxi {
        displayName = "AAN World News Reporter";
        description = "Approved to operate as a news reporter on Altis";
        buyPrice = 700000;
        class Settings : Settings {};
    };

    class IDAP : Driving {
        displayName = "IDAP Volunteer";
        description = "Volunteered yourself to work with IDAP";
        buyPrice = 0;
        class Settings : Settings {};
    };

    class Handgun : Driving {
        displayName = "Handgun Certificate";
        description = "Certification permitting the ownership of a handgun";
        buyPrice = 85000;
        class Settings : Settings {};
    };

    class Security : Driving {
        displayName = "Security Contractor";
        description = "Certification as a Security Contractor for a company";
        buyPrice = 350000;
        class Settings : Settings {};
        conditions = "[""SecurityContactors""] call ULP_fnc_hasGroupPerk";
    };

    class Protection : Driving {
        displayName = "Protection Officer";
        description = "Certification as a Protection Officer for a political party";
        buyPrice = 350000;
        class Settings : Settings {};
        conditions = "[""PersonalProtection""] call ULP_fnc_hasGroupPerk";
    };

    class Hunting : Driving {
        displayName = "Hunting Certificate";
        description = "Certification permitting the hunting of wild animals";
        buyPrice = 1140000;
        class Settings : Settings {};
    };

    class Rebel : BaseLicense {
        displayName = "Rebel Access";
        description = "Purchased access to utilise rebel supplies on Altis";
        buyPrice = 5000000;
        onBought = "[""JoinRebel""] call ULP_fnc_achieve;";
        class Settings {};
    };

    class Blackmarket : BaseLicense {
        displayName = "Blackmarket Access";
        description = "Purchased access to utilise blackmarket supplies on Altis";
        buyPrice = 15000000;
        class Settings {};
        conditions = "[""Rebel""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
    };

    // Processing Sites
    class Schnapps : BaseLicense {
        displayName = "Schnapps Processing";
        buyPrice = 15000;
        class Settings {};
    };

    class Tobacco : BaseLicense {
        displayName = "Tobacco Processing";
        buyPrice = 30000;
        class Settings {};
    };

    class Copper : BaseLicense {
        displayName = "Copper Processing";
        buyPrice = 25000;
        class Settings {};
    };

    class Silver : BaseLicense {
        displayName = "Silver Processing";
        buyPrice = 40000;
        class Settings {};
    };

    class Iron : BaseLicense {
        displayName = "Iron Processing";
        buyPrice = 500000;
        class Settings {};
    };

    class Salt : BaseLicense {
        displayName = "Salt Processing";
        buyPrice = 350000;
        class Settings {};
    };

    class Sand : BaseLicense {
        displayName = "Sand Processing";
        buyPrice = 100000;
        class Settings {};
    };

    class Oil : BaseLicense {
        displayName = "Oil Processing";
        buyPrice = 800000;
        class Settings {};
    };

    class Diamond : BaseLicense {
        displayName = "Diamond Processing";
        buyPrice = 750000;
        class Settings {};
    };

    class Uranium : BaseLicense {
        displayName = "Uranium Processing";
        buyPrice = 1750000;
        class Settings {};
    };

    class Weed : BaseLicense {
        displayName = "Weed Processing";
        buyPrice = 150000;
        class Settings {};
    };

    class Heroin : BaseLicense {
        displayName = "Heroin Processing";
        buyPrice = 500000;
        class Settings {};
    };

    class Cocaine : BaseLicense {
        displayName = "Cocaine Processing";
        buyPrice = 800000;
        class Settings {};
    };

    class Meth : BaseLicense {
        displayName = "Meth Processing";
        buyPrice = 1000000;
        class Settings {};
    };

    class Moonshine : BaseLicense {
        displayName = "Moonshine Processing";
        buyPrice = 1300000;
        class Settings {};
    };

    class Weapons : BaseLicense {
        displayName = "Weapons Processing";
        buyPrice = 2000000;
        class Settings {};
    };
};