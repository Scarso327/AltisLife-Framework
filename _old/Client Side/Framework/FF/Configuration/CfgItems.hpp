/*
	@File: CfgItems.hpp
	@Author: Jack "Scarso" Farhall & Lewis Mackinnon
	@Description: Configures the settings behind the virtual items.
*/
class CfgItems {
    class water {
        variable = "water";
        displayName = "Bottle of Water";
        weight = 1;
        buyPrice = 50;
        sellPrice = 25;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 60;
        };
        icon = "ico_waterBottle.paa";
        conditions = "";
    };

    class soda {
        variable = "soda";
        displayName = "Bottle of Soda";
        weight = 1;
        buyPrice = 80;
        sellPrice = 40;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 50;
        };
        icon = "ico_sodaBottle.paa";
        conditions = "";
    };

    class energy_drink {
        variable = "energy_drink";
        displayName = "Energy Drink";
        weight = 1;
        buyPrice = 600;
        sellPrice = 300;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 20;
        };
        icon = "ico_redgull.paa";
        conditions = "";
    };

    class apple {
        variable = "apple";
        displayName = "Apple";
        weight = 1;
        buyPrice = 320;
        sellPrice = 160;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Both"};
            value = 10;
        };
        icon = "ico_apple.paa";
        conditions = "";
    };

    class mango {
        variable = "mango";
        displayName = "Mango";
        weight = 1;
        buyPrice = 220;
        sellPrice = 110;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Both"};
            value = 10;
        };
        icon = "ico_mango.paa";
        conditions = "";
    };

    class coconut {
        variable = "coconut";
        displayName = "Coconut";
        weight = 1;
        buyPrice = 245;
        sellPrice = 123;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 120;
        sellPrice = 60;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 110;
        sellPrice = 55;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "ico_croissant.paa";
        conditions = "";
    };

    class crepe {
        variable = "crepe";
        displayName = "Crepe";
        weight = 1;
        buyPrice = 105;
        sellPrice = 53;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 20;
        };
        icon = "ico_crepe.paa";
        conditions = "";
    };

    class energy_bar {
        variable = "energy_bar";
        displayName = "Energy Bar";
        weight = 1;
        buyPrice = 450;
        sellPrice = 225;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 50;
        };
        icon = "ico_energyBar";
        conditions = "";
    };

    class lockpick {
        variable = "lockpick";
        displayName = "Lockpick";
        weight = 1;
        buyPrice = 150;
        sellPrice = 75;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_lockpick.paa";
        conditions = "";
    };

    class pickaxe {
        variable = "pickaxe";
        displayName = "Pickaxe";
        weight = 3;
        buyPrice = 360;
        sellPrice = 180;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_pickaxe.paa";
        conditions = "";
    };

    class woodAxe {
        variable = "woodAxe";
        displayName = "Wood Axe";
        weight = 3;
        buyPrice = 340;
        sellPrice = 170;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 3;
        buyPrice = 750;
        sellPrice = 375;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_fuel.paa";
        conditions = "";
    };

    class empty_fuel_can {
        variable = "empty_fuel_can";
        displayName = "Empty Fuel Can";
        weight = 2;
        buyPrice = -1;
        sellPrice = 45;
        illegal = false;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_fuelempty.paa";
        conditions = "";
    };

    class empty_barrel {
        variable = "empty_barrel";
        displayName = "Empty Barrel";
        weight = 3;
        buyPrice = 1450;
        sellPrice = 725;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 5;
        buyPrice = 250000;
        sellPrice = 125000;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_smallContainer.paa";
        conditions = "";
    };

    class large_container { // Premium Membership
        variable = "large_container";
        displayName = "Large Container";
        weight = 10;
        buyPrice = 500000;
        sellPrice = 250000;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_largeContainer.paa";
        conditions = "";
    };

    class red_bush {
        variable = "red_bush";
        displayName = "Red Bush Tea";
        weight = 1;
        buyPrice = 60;
        sellPrice = 30;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 45;
        sellPrice = 23;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 80;
        sellPrice = 40;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 65;
        sellPrice = 33;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 55;
        sellPrice = 28;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 60;
        };
        icon = "ico_coffee.paa";
        conditions = "";
    };

    class english_breakfast {
        variable = "english_breakfast";
        displayName = "English Breakfast";
        weight = 2;
        buyPrice = 130;
        sellPrice = 65;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 10;
        sellPrice = 5;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 15;
        sellPrice = 8;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 5;
        sellPrice = 3;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 5;
        sellPrice = 3;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 2;
        buyPrice = 80;
        sellPrice = 40;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 2;
        buyPrice = 90;
        sellPrice = 45;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 55;
        };
        icon = "";
        conditions = "";
    };

    class sausage_supper {
        variable = "sausage_supper";
        displayName = "Sausage Supper";
        weight = 2;
        buyPrice = 85;
        sellPrice = 43;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 2;
        buyPrice = 95;
        sellPrice = 48;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 2;
        buyPrice = 100;
        sellPrice = 50;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 60;
        };
        icon = "";
        conditions = "";
    };

    class raw_hen {
        variable = "raw_hen";
        displayName = "Raw Hen";
        weight = 1;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class raw_rooster {
        variable = "raw_rooster";
        displayName = "Raw Rooster";
        weight = 1;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class raw_goat {
        variable = "raw_goat";
        displayName = "Raw Goat";
        weight = 1;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class raw_sheep {
        variable = "raw_sheep";
        displayName = "Raw Sheep";
        weight = 1;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_muttonLegRaw.paa";
        conditions = "";
    };

    class raw_rabbit {
        variable = "raw_rabbit";
        displayName = "Raw Rabbit";
        weight = 1;
        buyPrice = 0;
        sellPrice = 0;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_rabbitRaw.paa";
        conditions = "";
    };

    class raw_salema {
        variable = "raw_salema";
        displayName = "Raw Salema";
        weight = 1;
        buyPrice = 200;
        sellPrice = 400;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_salemaRaw.paa";
        conditions = "";
    };

    class cooked_salema {
        variable = "cooked_salema";
        displayName = "Cooked Salema";
        weight = 1;
        buyPrice = 400;
        sellPrice = 800;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "ico_cookedFish.paa";
        conditions = "";
    };

    class raw_ornate {
        variable = "raw_ornate";
        displayName = "Raw Ornate";
        weight = 1;
        buyPrice = 223;
        sellPrice = 445;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_ornateRaw.paa";
        conditions = "";
    };

    class cooked_ornate {
        variable = "cooked_ornate";
        displayName = "Cooked Ornate";
        weight = 1;
        buyPrice = 445;
        sellPrice = 890;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "ico_cookedFish.paa";
        conditions = "";
    };

    class raw_mackerel {
        variable = "raw_mackerel";
        displayName = "Raw Mackerel";
        weight = 1;
        buyPrice = 243;
        sellPrice = 485;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_mackerelRaw.paa";
        conditions = "";
    };

    class cooked_mackerel {
        variable = "cooked_mackerel";
        displayName = "Cooked Mackerel";
        weight = 1;
        buyPrice = 485;
        sellPrice = 970;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "ico_cookedFish.paa";
        conditions = "";
    };

    class raw_tuna {
        variable = "raw_tuna";
        displayName = "Raw Tuna";
        weight = 2;
        buyPrice = 338;
        sellPrice = 675;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_tunaRaw.paa";
        conditions = "";
    };

    class cooked_tuna {
        variable = "cooked_tuna";
        displayName = "Cooked Tuna";
        weight = 2;
        buyPrice = 675;
        sellPrice = 1350;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "ico_cookedFish.paa";
        conditions = "";
    };

    class raw_mullet {
        variable = "raw_mullet";
        displayName = "Raw Mullet";
        weight = 2;
        buyPrice = 400;
        sellPrice = 800;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_mulletRaw.paa";
        conditions = "";
    };

    class cooked_mullet {
        variable = "cooked_mullet";
        displayName = "Cooked Mullet";
        weight = 2;
        buyPrice = 800;
        sellPrice = 1600;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "ico_cookedFish.paa";
        conditions = "";
    };

    class raw_catshark {
        variable = "raw_catshark";
        displayName = "Raw Catshark";
        weight = 3;
        buyPrice = 800;
        sellPrice = 1600;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_catsharkRaw.paa";
        conditions = "";
    };

    class cooked_catshark {
        variable = "cooked_catshark";
        displayName = "Cooked Catshark";
        weight = 3;
        buyPrice = 1600;
        sellPrice = 3200;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 40;
        };
        icon = "ico_cookedFish.paa";
        conditions = "";
    };

    class apple_schnapps {
        variable = "apple_schnapps";
        displayName = "Apple Schnapps";
        weight = 1;
        buyPrice = 285;
        sellPrice = 570;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 293;
        sellPrice = 585;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Thirst"};
            value = 45;
        };
        icon = "";
        conditions = "";
    };

    class coconut_schnapps {
        variable = "coconut_schnapps";
        displayName = "Coconut Schnapps";
        weight = 1;
        buyPrice = 303;
        sellPrice = 605;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 320;
        sellPrice = 640;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 300;
        sellPrice = 600;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 490;
        sellPrice = 980;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 7500;
        sellPrice = 15000;
        illegal = false;
        save = true;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 1000;
        sellPrice = -1;
        illegal = false;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 5000;
        sellPrice = -1;
        illegal = false;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 10000;
        sellPrice = -1;
        illegal = false;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 25000;
        sellPrice = -1;
        illegal = false;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 50000;
        sellPrice = -1;
        illegal = false;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 100000;
        sellPrice = -1;
        illegal = false;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class ziptie {
        variable = "ziptie";
        displayName = "Ziptie";
        weight = 1;
        buyPrice = 17500;
        sellPrice = 8750;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_ziptie.paa";
        conditions = "";
    };

    class blindfold {
        variable = "blindfold";
        displayName = "Blindfold";
        weight = 1;
        buyPrice = 13000;
        sellPrice = 6500;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 12500;
        sellPrice = 6250;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = 14000;
        sellPrice = 7000;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
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
        weight = 4;
        buyPrice = 65000;
        sellPrice = 32500;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_boltCutter.paa";
        conditions = "";
    };

    class explosive_charge {
        variable = "explosive_charge";
        displayName = "Explosive Charge";
        weight = 7;
        buyPrice = 300000;
        sellPrice = 150000;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_blastingCharge.paa";
        conditions = "";
    };

    class branded_gold_bar {
        variable = "branded_gold_bar";
        displayName = "Branded Gold Bar";
        weight = 10;
        buyPrice = -1;
        sellPrice = 100000;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_goldbar.paa";
        conditions = "";
    };

    class unbranded_gold_bar {
        variable = "unbranded_gold_bar";
        displayName = "Unbranded Gold Bar";
        weight = 9;
        buyPrice = -1;
        sellPrice = 250000;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_goldbar.paa";
        conditions = "";
    };

    class bannana {
        variable = "bannana";
        displayName = "Bannana";
        weight = 1;
        buyPrice = 480;
        sellPrice = 240;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 20;
        };
        icon = "";
        conditions = "";
    };

    class sugarCane {
        variable = "sugarCane";
        displayName = "Sugar Cane";
        weight = 1;
        buyPrice = 530;
        sellPrice = 265;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class rice {
        variable = "rice";
        displayName = "Rice";
        weight = 1;
        buyPrice = 540;
        sellPrice = 270;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {true, "Hunger"};
            value = 30;
        };
        icon = "";
        conditions = "";
    };

    class wood {
        variable = "wood";
        displayName = "Wood";
        weight = 2;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {flase, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class lumber {
        variable = "lumber";
        displayName = "Lumber";
        weight = 2;
        buyPrice = 1960;
        sellPrice = 980;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {flase, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class coal {
        variable = "coal";
        displayName = "Coal";
        weight = 1;
        buyPrice = 620;
        sellPrice = 310;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_coal.paa";
        conditions = "";
    };

    class coral {
        variable = "coral";
        displayName = "Coral";
        weight = 1;
        buyPrice = 1120;
        sellPrice = 560;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 4;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_timOre.paa";
        conditions = "";
    };

    class tin_bar {
        variable = "tin_bar";
        displayName = "Tin Bar";
        weight = 3;
        buyPrice = 1990;
        sellPrice = 995;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_timBar.paa";
        conditions = "";
    };

    class copper_ore {
        variable = "copper_ore";
        displayName = "Copper Ore";
        weight = 4;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_copperore.paa";
        conditions = "";
    };

    class copper_bar {
        variable = "copper_bar";
        displayName = "Copper Bar";
        weight = 3;
        buyPrice = 2320;
        sellPrice = 1160;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_copper.paa";
        conditions = "";
    };

    class silver_ore {
        variable = "silver_ore";
        displayName = "Silver Ore";
        weight = 4;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 3;
        buyPrice = 2410;
        sellPrice = 1205;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 5;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_ironore.paa";
        conditions = "";
    };

    class iron_bar {
        variable = "iron_bar";
        displayName = "Iron Bar";
        weight = 4;
        buyPrice = 4690;
        sellPrice = 2345;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_iron.paa";
        conditions = "";
    };

    class platinum_ore {
        variable = "platinum_ore";
        displayName = "Platinum Ore";
        weight = 5;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 4;
        buyPrice = 11340;
        sellPrice = 5670;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 6;
        buyPrice = -1;
        sellPrice = 100;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_rock.paa";
        conditions = "";
    };

    class cement {
        variable = "cement";
        displayName = "Cement";
        weight = 5;
        buyPrice = 3360;
        sellPrice = 1680;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_cement.paa";
        conditions = "";
    };

    class crude_oil {
        variable = "crude_oil";
        displayName = "Crude Oil";
        weight = 3;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_oilUnprocessed.paa";
        conditions = "";
    };

    class refined_oil {
        variable = "refined_oil";
        displayName = "Refined Oil";
        weight = 0;
        buyPrice = 8650;
        sellPrice = 4325;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_oilProcessed.paa";
        conditions = "";
    };

    class iridium_ore {
        variable = "iridium_ore";
        displayName = "Iridium Ore";
        weight = 4;
        buyPrice = -1;
        sellPrice = -1;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 3;
        buyPrice = 18640;
        sellPrice = 9320;
        illegal = false;
        save = false;
        taxed = true;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = -1;
        sellPrice = 1430;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = -1;
        sellPrice = 2860;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = -1;
        sellPrice = 3980;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = -1;
        sellPrice = 7960;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = -1;
        sellPrice = 11340;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = -1;
        sellPrice = 22680;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = -1;
        sellPrice = 16800;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = -1;
        sellPrice = 33600;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 1;
        buyPrice = -1;
        sellPrice = 35400;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_diamondUncut.paa";
        conditions = "";
    };

    class cut_diamond {
        variable = "cut_diamond";
        displayName = "Cut Diamond";
        weight = 1;
        buyPrice = -1;
        sellPrice = 70800;
        illegal = false;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_diamondCut.paa";
        conditions = "";
    };

    class cannabis {
        variable = "cannabis";
        displayName = "Cannabis Leaf";
        weight = 3;
        buyPrice = -1;
        sellPrice = -1;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_cannabis.paa";
        conditions = "";
    };

    class marijuana {
        variable = "marijuana";
        displayName = "Marijuana";
        weight = 2;
        buyPrice = 3280;
        sellPrice = 1640;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_marijuana.paa";
        conditions = "";
    };

    class refined_marijuana {
        variable = "refined_marijuana";
        displayName = "Refined Marijuana";
        weight = 2;
        buyPrice = 4920;
        sellPrice = 2460;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 3;
        buyPrice = -1;
        sellPrice = -1;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_heroinUnprocessed.paa";
        conditions = "";
    };

    class heroin {
        variable = "heroin";
        displayName = "Heroin";
        weight = 2;
        buyPrice = 3920;
        sellPrice = 1960;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_heroinProcessed.paa";
        conditions = "";
    };

    class refined_heroin {
        variable = "refined_heroin";
        displayName = "Refined Heroin";
        weight = 2;
        buyPrice = 5880;
        sellPrice = 2940;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 4;
        buyPrice = -1;
        sellPrice = -1;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_cocaineUnprocessed.paa";
        conditions = "";
    };

    class cocaine {
        variable = "cocaine";
        displayName = "Cocaine";
        weight = 3;
        buyPrice = 9860;
        sellPrice = 4930;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_cocaineProcessed.paa";
        conditions = "";
    };

    class refined_cocaine {
        variable = "refined_cocaine";
        displayName = "Refined Cocaine";
        weight = 3;
        buyPrice = 14790;
        sellPrice = 7395;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 5;
        buyPrice = -1;
        sellPrice = -1;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 5;
        buyPrice = 29360;
        sellPrice = 14680;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 5;
        buyPrice = 44040;
        sellPrice = 22020;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
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
        weight = 2;
        buyPrice = -1;
        sellPrice = 90000;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_turtleRaw.paa";
        conditions = "";
    };

    class cooked_turtle {
        variable = "cooked_turtle";
        displayName = "Cooked Turtle";
        weight = 2;
        buyPrice = 340000;
        sellPrice = 170000;
        illegal = true;
        save = false;
        taxed = false;
        marketDisplay = true;
        class dynmarket {
            dynmaic = true;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_turtleSoup.paa";
        conditions = "";
    };

    class blood_bag {
        variable = "blood_bag";
        displayName = "Blood Bag";
        weight = 2;
        buyPrice = 1100;
        sellPrice = 550;
        illegal = false;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class spikeStrip {
        variable = "spikeStrip";
        displayName = "Stinger";
        weight = 3;
        buyPrice = 0;
        sellPrice = -1;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_spikestrip.paa";
        conditions = "";
    };

    class defusekit {
        variable = "defusekit";
        displayName = "Defusal Kit";
        weight = 5;
        buyPrice = 0;
        sellPrice = -1;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_defusekit.paa";
        conditions = "";
    };

    class defibrillator {
        variable = "defibrillator";
        displayName = "Defibrillator";
        weight = 4;
        buyPrice = 0;
        sellPrice = -1;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "ico_defibrillator.paa";
        conditions = "";
    };

    class rfidReader {
        variable = "rfidReader";
        displayName = "RFID Reader";
        weight = 1;
        buyPrice = 20240;
        sellPrice = 10120;
        illegal = true;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };

    class earPlugs {
        variable = "earPlugs";
        displayName = "Ear Plugs";
        weight = 1;
        buyPrice = 30;
        sellPrice = 15;
        illegal = false;
        save = true;
        taxed = false;
        marketDisplay = false;
        class dynmarket {
            dynmaic = false;
            driftPerc = 0.1;
        };
        class edibility {
            edible[] = {false, ""};
            value = -1;
        };
        icon = "";
        conditions = "";
    };
};