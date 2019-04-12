class CfgGather {
    class Resources {
        class apple {
            text = "Gathering apples...";
            amount = 5;
            zones[] = { "apple_area_1" };
            item = "apple";
            profession[] = { "Prof_Gathering", 1, 50 };
            zoneSize = 30;
        };

        class mango {
            text = "Gathering mangos...";
            amount = 5;
            zones[] = { "mango_area_1", "mango_area_2", "mango_area_3", "mango_area_4" };
            item = "mango";
            profession[] = { "Prof_Gathering", 1, 50 };
            zoneSize = 30;
        };

        class coconut {
            text = "Gathering coconuts...";
            amount = 5;
            zones[] = { "coconut_area_1", "coconut_area_2", "coconut_area_3" };
            item = "coconut";
            profession[] = { "Prof_Gathering", 1, 50 };
            zoneSize = 30;
        };

        class cannabis {
            text = "Gathering cannabis...";
            amount = 3;
            zones[] = { "cannabis_area" };
            item = "cannabis";
            profession[] = { "Prof_Gathering", 1, 50 };
            zoneSize = 30;
        };

        class opium {
            text = "Gathering opium...";
            amount = 3;
            zones[] = { "opium_area" };
            item = "opium";
            profession[] = { "Prof_Gathering", 1, 50 };
            zoneSize = 30;
        };

        class coca {
            text = "Gathering coca...";
            amount = 3;
            zones[] = { "coca_area" };
            item = "coca";
            profession[] = { "Prof_Gathering", 1, 50 };
            zoneSize = 30;
        };
    };

/*
This block can be set using percent,if you want players to mine only one resource ,just leave it as it is.
Example:
        class copper_unrefined
    {
            amount = 2;
        zones[] = { "copper_mine" };
        item = "pickaxe";
        mined[] = { "copper_unrefined" };
This will make players mine only copper_unrefined
Now let's go deeper
Example 2:
        class copper_unrefined
    {
            amount = 2;
        zones[] = { "copper_mine" };
        item = "pickaxe";
        mined[] = { {"copper_unrefined",0,25},{"iron_unrefined",25,95},{"diamond_uncut",95,100} };
    };
    This will give :
    25(±1)% to copper_unrefined;
    70(±1)% to iron_unrefined;
    5%(±1)% to diamond_uncut;

                                                         ! Watch Out !
 If percents are used,you MUST put more than 1 resource in the mined parameter
 mined[] = { {"copper_unrefined",0,25} }; NOT OK (But the script will work)
 mined[] = { {"copper_unrefined",0,45 },{"iron_unrefined",45} };  NOT OK (The script won't work )
 mined[] = { {"copper_unrefined",0,45},{"copper_unrefined",80,100} }; NOT OK
 mined[] = { "copper_unrefined" }; OK
 mined[] = { {"copper_unrefined",0,35} , { "iron_unrefined" ,35,100 } }; OK
*/

    class Minerals {
        class coal {
            amount = 1;
            zones[] = { "coal_area" };
            item = "pickaxe";
            mined[] = {"coal"};
            zoneSize = 30;
        };

        class tin_ore {
            amount = 2;
            zones[] = { "tin_area" };
            item = "pickaxe";
            mined[] = {"tin_ore"};
            zoneSize = 30;
        };

        class copper_ore {
            amount = 2;
            zones[] = { "copper_area" };
            item = "pickaxe";
            mined[] = {"copper_ore"};
            zoneSize = 30;
        };

        class silver_ore {
            amount = 2;
            zones[] = { "silver_area" };
            item = "pickaxe";
            mined[] = {"silver_ore"};
            zoneSize = 30;
        };

        class iron_ore {
            amount = 2;
            zones[] = { "iron_area" };
            item = "pickaxe";
            mined[] = {"iron_ore"};
            zoneSize = 30;
        };

        class platinum_ore {
            amount = 2;
            zones[] = { "platinum_area" };
            item = "pickaxe";
            mined[] = {"platinum_ore"};
            zoneSize = 30;
        };

        class rock {
            amount = 1;
            zones[] = { "rock_area" };
            item = "pickaxe";
            mined[] = {"rock"};
            zoneSize = 30;
        };

        class crude_oil {
            amount = 3;
            zones[] = { "oil_rig" };
            item = "";
            mined[] = { "crude_oil" };
            zoneSize = 30;
        };

        class iridium_ore {
            amount = 3;
            zones[] = { "iridium_area" };
            item = "";
            mined[] = { "iridium_ore" };
            zoneSize = 30;
        };
    };
};