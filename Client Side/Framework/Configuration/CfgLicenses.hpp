class CfgLicenses {
    class BaseLicense {
        buyPrice = 0;
        factions[] = { "Civilian" };
        class Settings {
            isVisible = true; // Whether it's displayed when your licenses are checked...
            isRemovable = false; // Whether it can be removed by Police...
        };
        conditions = "true";
    };

    class Driving : BaseLicense {
        displayName = "Driving Licence";
        class Settings {
            isRemovable = true;
        };
    };
};