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
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Trucking : BaseLicense {
        displayName = "Trucking Licence";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Boating : BaseLicense {
        displayName = "Boating Licence";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Piloting : BaseLicense {
        displayName = "Piloting Licence";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Home : BaseLicense {
        displayName = "Homeowner's Approval";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Taxi : BaseLicense {
        displayName = "Taxi Altis Worker";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Solicitor : BaseLicense {
        displayName = "Altis Solicitors";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class News : BaseLicense {
        displayName = "AAN World News Reporter";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Handgun : BaseLicense {
        displayName = "Handgun Certificate";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Hunting : BaseLicense {
        displayName = "Hunting Certificate";
        buyPrice = 0;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Rebel : BaseLicense {
        displayName = "Rebel Access";
        buyPrice = 0;
        class Settings {};
    };

    class Blacklist : BaseLicense {
        displayName = "Blackmarket Access";
        buyPrice = 0;
        class Settings {};
    };

    // Processing Sites
    class Schnaps : BaseLicense {
        displayName = "Schnaps Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Tobacco : BaseLicense {
        displayName = "Tobacco Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Copper : BaseLicense {
        displayName = "Copper Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Silver : BaseLicense {
        displayName = "Silver Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Iron : BaseLicense {
        displayName = "Iron Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Salt : BaseLicense {
        displayName = "Salt Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Sand : BaseLicense {
        displayName = "Sand Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Oil : BaseLicense {
        displayName = "Oil Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Diamond : BaseLicense {
        displayName = "Diamond Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Uranium : BaseLicense {
        displayName = "Uranium Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Weed : BaseLicense {
        displayName = "Weed Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Heroin : BaseLicense {
        displayName = "Heroin Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Cocaine : BaseLicense {
        displayName = "Cocaine Processing";
        buyPrice = 0;
        class Settings {};
    };

    class Meth : BaseLicense {
        displayName = "Meth Processing";
        buyPrice = 0;
        class Settings {};
    };
};