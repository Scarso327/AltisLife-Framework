class CfgItems {
    class water {
        variable = "water";
        displayName = "Bottle of Water";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 60;
        };
        icon = "";
        conditions = "";
    };

    class soda {
        variable = "soda";
        displayName = "Bottle of Soda";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 50;
        };
        icon = "";
        conditions = "";
    };

    class energy_drink {
        variable = "energy_drink";
        displayName = "Energy Drink";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 20;
        };
        icon = "";
        conditions = "";
    };

    class apple {
        variable = "apple";
        displayName = "Apple";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Both"};
            value = 10;
        };
        icon = "";
        conditions = "";
    };

    class mango {
        variable = "mango";
        displayName = "Mango";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Both"};
            value = 10;
        };
        icon = "";
        conditions = "";
    };

    class coconut {
        variable = "coconut";
        displayName = "Coconut";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Both"};
            value = 10;
        };
        icon = "";
        conditions = "";
    };

    class baguette {
        variable = "baguette";
        displayName = "Baguette";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 60;
        };
        icon = "";
        conditions = "";
    };

    class croissant {
        variable = "croissant";
        displayName = "Croissant";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class crepe {
        variable = "crepe";
        displayName = "Crepe";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 20;
        };
        icon = "";
        conditions = "";
    };

    class energy_bar {
        variable = "energy_bar";
        displayName = "Energy Bar";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 50;
        };
        icon = "";
        conditions = "";
    };

    class first_aid_kit {
        variable = "first_aid_kit";
        displayName = "First Aid Kit";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class lockpick {
        variable = "lockpick";
        displayName = "Lockpick";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class pickaxe {
        variable = "pickaxe";
        displayName = "Pickaxe";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class fuel_can {
        variable = "fuel_can";
        displayName = "Fuel Can";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class empty_fuel_can {
        variable = "empty_fuel_can";
        displayName = "Empty Fuel Can";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class empty_barrel {
        variable = "empty_barrel";
        displayName = "Empty Barrel";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class small_container {
        variable = "small_container";
        displayName = "Small Container";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class large_container { // Premium Membership
        variable = "large_container";
        displayName = "Large Container";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class red_bush {
        variable = "red_bush";
        displayName = "Red Bush Tea";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 60;
        };
        icon = "";
        conditions = "";
    };

    class pg_tips {
        variable = "pg_tips";
        displayName = "PG Tips";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 60;
        };
        icon = "";
        conditions = "";
    };

    class earl_grey {
        variable = "earl_grey";
        displayName = "Earl Grey Tea";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 60;
        };
        icon = "";
        conditions = "";
    };

    class green_tea {
        variable = "green_tea";
        displayName = "Green Tea";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 60;
        };
        icon = "";
        conditions = "";
    };

    class coffee {
        variable = "coffee";
        displayName = "Coffee";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 60;
        };
        icon = "";
        conditions = "";
    };

    class english_breakfast {
        variable = "english_breakfast";
        displayName = "English Breakfast";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 100;
        };
        icon = "";
        conditions = "";
    };

    class tea_cake {
        variable = "tea_cake";
        displayName = "Tea Cake";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 35;
        };
        icon = "";
        conditions = "";
    };

    class crumpet {
        variable = "crumpet";
        displayName = "Crumpet";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 35;
        };
        icon = "";
        conditions = "";
    };

    class toast {
        variable = "toast";
        displayName = "Toast";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class scone {
        variable = "scone";
        displayName = "Scone";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 30;
        };
        icon = "";
        conditions = "";
    };

    class cheesy_chips {
        variable = "cheesy_chips";
        displayName = "Cheesy Chips";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class fish_chips {
        variable = "fish_chips";
        displayName = "Fish and Chips";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 55;
        };
        icon = "";
        conditions = "";
    };

    class pasty_chips {
        variable = "pasty_chips";
        displayName = "Pasty and Chips";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 55;
        };
        icon = "";
        conditions = "";
    };

    class burger {
        variable = "burger";
        displayName = "Full Beef Burger";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 60;
        };
        icon = "";
        conditions = "";
    };

    class raw_salema {
        variable = "raw_salema";
        displayName = "Raw Salema";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cooked_salema {
        variable = "cooked_salema";
        displayName = "Cooked Salema";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class raw_ornate {
        variable = "raw_ornate";
        displayName = "Raw Ornate";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cooked_ornate {
        variable = "cooked_ornate";
        displayName = "Cooked Ornate";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class raw_mackerel {
        variable = "raw_mackerel";
        displayName = "Raw Mackerel";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cooked_mackerel {
        variable = "cooked_mackerel";
        displayName = "Cooked Mackerel";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class raw_tuna {
        variable = "raw_tuna";
        displayName = "Raw Tuna";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cooked_tuna {
        variable = "cooked_tuna";
        displayName = "Cooked Tuna";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class raw_mullet {
        variable = "raw_mullet";
        displayName = "Raw Mullet";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cooked_mullet {
        variable = "cooked_mullet";
        displayName = "Cooked Mullet";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class raw_catshark {
        variable = "raw_catshark";
        displayName = "Raw Catshark";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cooked_catshark {
        variable = "cooked_catshark";
        displayName = "Cooked Catshark";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class apple_schnapps {
        variable = "apple_schnapps";
        displayName = "Apple Schnapps";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 45;
        };
        icon = "";
        conditions = "";
    };

    class mango_schnapps {
        variable = "mango_schnapps";
        displayName = "Mango Schnapps";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 45;
        };
        icon = "";
        conditions = "";
    };

    class cococut_schnapps {
        variable = "cococut_schnapps";
        displayName = "Coconut Schnapps";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 45;
        };
        icon = "";
        conditions = "";
    };

    class cider {
        variable = "cider";
        displayName = "Bottle of Cider";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 40;
        };
        icon = "";
        conditions = "";
    };

    class beer {
        variable = "beer";
        displayName = "Bottle of Beer";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 20;
        };
        icon = "";
        conditions = "";
    };

    class whisky {
        variable = "whisky";
        displayName = "Bottle of Whisky";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 20;
        };
        icon = "";
        conditions = "";
    };

    class wine {
        variable = "wine";
        displayName = "Bottle of Wine";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 20;
        };
        icon = "";
        conditions = "";
    };

    class 1k_chip {
        variable = "1k_chip";
        displayName = "1K Chip";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class 5k_chip {
        variable = "5k_chip";
        displayName = "5K Chip";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class 10k_chip {
        variable = "10k_chip";
        displayName = "10K Chip";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class 25k_chip {
        variable = "25k_chip";
        displayName = "25K Chip";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class 50k_chip {
        variable = "50k_chip";
        displayName = "50K Chip";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class 100k_chip {
        variable = "100k_chip";
        displayName = "100K Chip";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class blindfold {
        variable = "blindfold";
        displayName = "Blindfold";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class gag {
        variable = "gag";
        displayName = "Gag";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class ear_clots {
        variable = "ear_clots";
        displayName = "Ear Clots";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class gps_tracker {
        variable = "gps_tracker";
        displayName = "GPS Tracker";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class bolt_cutter {
        variable = "bolt_cutter";
        displayName = "Bolt Cutter";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class explosive_charge {
        variable = "explosive_charge";
        displayName = "Explosive Charge";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class branded_gold_bar {
        variable = "branded_gold_bar";
        displayName = "Branded Gold Bar";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class unbranded_gold_bar {
        variable = "unbranded_gold_bar";
        displayName = "Unbranded Gold Bar";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class coal {
        variable = "coal";
        displayName = "Coal";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class coral {
        variable = "coral";
        displayName = "Coral";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class tin_ore {
        variable = "tin_ore";
        displayName = "Tin Ore";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class tin_bar {
        variable = "tin_bar";
        displayName = "Tin Bar";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class copper_ore {
        variable = "copper_ore";
        displayName = "Copper Ore";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class copper_bar {
        variable = "copper_bar";
        displayName = "Copper Bar";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class silver_ore {
        variable = "silver_ore";
        displayName = "Silver Ore";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class silver_bar {
        variable = "silver_bar";
        displayName = "Silver Bar";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class iron_ore {
        variable = "iron_ore";
        displayName = "Iron Ore";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class iron_bar {
        variable = "iron_bar";
        displayName = "Iron Bar";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class platinum_ore {
        variable = "platinum_ore";
        displayName = "Platinum Ore";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class platinum_bar {
        variable = "platinum_bar";
        displayName = "Platinum Bar";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class rock {
        variable = "rock";
        displayName = "Rock";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cement {
        variable = "cement";
        displayName = "Cement";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class crude_oil {
        variable = "crude_oil";
        displayName = "Crude Oil";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class refined_oil {
        variable = "refined_oil";
        displayName = "Refined Oil";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class iridium_ore {
        variable = "iridium_ore";
        displayName = "Iridium Ore";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class iridium_bar {
        variable = "iridium_bar";
        displayName = "Iridium Bar";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = true;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class uncut_opal {
        variable = "uncut_opal";
        displayName = "Uncut Opal";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cut_opal {
        variable = "cut_opal";
        displayName = "Cut Opal";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class uncut_sapphire {
        variable = "uncut_sapphire";
        displayName = "Uncut Sapphire";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cut_shappire {
        variable = "cut_shappire";
        displayName = "Cut Sapphire";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class uncut_ruby {
        variable = "uncut_ruby";
        displayName = "Uncut Ruby";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cut_ruby {
        variable = "cut_ruby";
        displayName = "Cut Ruby";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class uncut_emerald {
        variable = "uncut_emerald";
        displayName = "Uncut Emerald";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cut_emerald {
        variable = "cut_emerald";
        displayName = "Cut Emerald";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class uncut_diamond {
        variable = "uncut_diamond";
        displayName = "Uncut Diamond";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cut_diamond {
        variable = "cut_diamond";
        displayName = "Cut Diamond";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cannabis {
        variable = "cannabis";
        displayName = "Cannabis Leaf";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class marijuana {
        variable = "marijuana";
        displayName = "Marijuana";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class refined_marijuana {
        variable = "refined_marijuana";
        displayName = "Refined Marijuana";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class opium {
        variable = "opium";
        displayName = "Opium Poppy";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class heroin {
        variable = "heroin";
        displayName = "Heroin";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class refined_heroin {
        variable = "refined_heroin";
        displayName = "Refined Heroin";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class coca {
        variable = "coca";
        displayName = "Coca Leaf";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cocaine {
        variable = "cocaine";
        displayName = "Cocaine";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class refined_cocaine {
        variable = "refined_cocaine";
        displayName = "Refined Cocaine";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class ephedrine {
        variable = "ephedrine";
        displayName = "Ephedrine Barrel";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class methamphetamine {
        variable = "methamphetamine";
        displayName = "Methamphetamine";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class refined_methamphetamine {
        variable = "refined_methamphetamine";
        displayName = "Refined Methamphetamine";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class raw_turtle {
        variable = "raw_turtle";
        displayName = "Raw Turtle";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class cooked_turtle {
        variable = "cooked_turtle";
        displayName = "Cooked Turtle";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = false;
        taxed = false;
        class dynmarket {
            dynmaic = true;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class blood_bag {
        variable = "blood_bag";
        displayName = "Blood Bag";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class stretcher {
        variable = "stretcher";
        displayName = "Stretcher";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class stretcher {
        variable = "stretcher";
        displayName = "Stretcher";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class jaws_of_life {
        variable = "jaws_of_life";
        displayName = "Jaws of Life";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class breathalyzer {
        variable = "breathalyzer";
        displayName = "Breathalyzer";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class stinger {
        variable = "stinger";
        displayName = "Stinger";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = false;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class road_barrier {
        variable = "road_barrier";
        displayName = "Road Barrier";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class road_cone {
        variable = "road_cone";
        displayName = "Road Cone";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class defibrillator {
        variable = "defibrillator";
        displayName = "Defibrillator";
        weight = 0;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        class dynmarket {
            dynmaic = false;
            prices[] = {0, 0};
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };
};