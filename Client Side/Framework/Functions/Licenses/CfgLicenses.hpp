class CfgLicenses {
    class BaseLicense {
        factions[] = { "Civilian" };
        class Settings {
            isVisible = false;
            isRemovable = false;
        };
        conditions = "true";
    };

    class Driving : BaseLicense {
        displayName = "Driving Licence";
        buyPrice = 1000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Trucking : BaseLicense {
        displayName = "Trucking Licence";
        buyPrice = 60000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Boating : BaseLicense {
        displayName = "Boating Licence";
        buyPrice = 6500;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Piloting : BaseLicense {
        displayName = "Piloting Licence";
        buyPrice = 320000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Home : BaseLicense {
        displayName = "Homeowner's Approval";
        buyPrice = 3000000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Taxi : BaseLicense {
        displayName = "Taxi Altis Worker";
        buyPrice = 35000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Solicitor : BaseLicense {
        displayName = "Altis Solicitors";
        buyPrice = 1700000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class News : BaseLicense {
        displayName = "AAN World News Reporter";
        buyPrice = 700000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class IDAP : BaseLicense {
        displayName = "IDAP Volunteer";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Handgun : BaseLicense {
        displayName = "Handgun Certificate";
        buyPrice = 65000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Hunting : BaseLicense {
        displayName = "Hunting Certificate";
        buyPrice = 14000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Rebel : BaseLicense {
        displayName = "Rebel Access";
        buyPrice = 5000000;
        class Settings {};
    };

    class Blackmarket : BaseLicense {
        displayName = "Blackmarket Access";
        buyPrice = 15000000;
        class Settings {};
        conditions = "[""Rebel""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk }";
    };

    // Processing Sites
    class Schnapps : BaseLicense {
        displayName = "Schnapps Processing";
        buyPrice = 15000;
        class Settings {};
    };

    class Tobacco : BaseLicense {
        displayName = "Tobacco Processing";
        buyPrice = 45000;
        class Settings {};
    };

    class Copper : BaseLicense {
        displayName = "Copper Processing";
        buyPrice = 30000;
        class Settings {};
    };

    class Silver : BaseLicense {
        displayName = "Silver Processing";
        buyPrice = 35000;
        class Settings {};
    };

    class Iron : BaseLicense {
        displayName = "Iron Processing";
        buyPrice = 290000;
        class Settings {};
    };

    class Salt : BaseLicense {
        displayName = "Salt Processing";
        buyPrice = 140000;
        class Settings {};
    };

    class Sand : BaseLicense {
        displayName = "Sand Processing";
        buyPrice = 155000;
        class Settings {};
    };

    class Oil : BaseLicense {
        displayName = "Oil Processing";
        buyPrice = 265000;
        class Settings {};
    };

    class Diamond : BaseLicense {
        displayName = "Diamond Processing";
        buyPrice = 310000;
        class Settings {};
    };

    class Uranium : BaseLicense {
        displayName = "Uranium Processing";
        buyPrice = 800000;
        class Settings {};
    };

    class Weed : BaseLicense {
        displayName = "Weed Processing";
        buyPrice = 80000;
        class Settings {};
    };

    class Heroin : BaseLicense {
        displayName = "Heroin Processing";
        buyPrice = 195000;
        class Settings {};
    };

    class Cocaine : BaseLicense {
        displayName = "Cocaine Processing";
        buyPrice = 710000;
        class Settings {};
    };

    class Meth : BaseLicense {
        displayName = "Meth Processing";
        buyPrice = 785000;
        class Settings {};
    };

    class Moonshine : BaseLicense {
        displayName = "Moonshine Processing";
        buyPrice = 1050000;
        class Settings {};
    };
};