class CfgProcess {
    class apple {
        MaterialsReq[] = {{"apple",1}};
        MaterialsGive[] = {{"apple_schnapps",1}};
        Text = "Processing Schnapps...";
        RequiredLicense = "schnapps";
        NoLicenseCost = 250;
    };

    class mango {
        MaterialsReq[] = {{"mango",1}};
        MaterialsGive[] = {{"mango_schnapps",1}};
        Text = "Processing Schnapps...";
        RequiredLicense = "schnapps";
        NoLicenseCost = 250;
    };

    class coconut {
        MaterialsReq[] = {{"coconut",1}};
        MaterialsGive[] = {{"coconut_schnapps",1}};
        Text = "Processing Schnapps...";
        RequiredLicense = "schnapps";
        NoLicenseCost = 250;
    };

    class cider {
        MaterialsReq[] = {{"apple",1}};
        MaterialsGive[] = {{"cider",1}};
        Text = "Processing Cider...";
        RequiredLicense = "schnapps";
        NoLicenseCost = 250;
    };

    class salema {
        MaterialsReq[] = {{"raw_salema",1}};
        MaterialsGive[] = {{"cooked_salema",1}};
        Text = "Cooking Salema...";
        RequiredLicense = "fish";
        NoLicenseCost = 300;
    };

    class ornate {
        MaterialsReq[] = {{"raw_ornate",1}};
        MaterialsGive[] = {{"cooked_ornate",1}};
        Text = "Cooking Ornate...";
        RequiredLicense = "fish";
        NoLicenseCost = 300;
    };

    class mackerel {
        MaterialsReq[] = {{"raw_mackerel",1}};
        MaterialsGive[] = {{"cooked_mackerel",1}};
        Text = "Cooking Mackerel...";
        RequiredLicense = "fish";
        NoLicenseCost = 300;
    };

    class tuna {
        MaterialsReq[] = {{"raw_tuna",1}};
        MaterialsGive[] = {{"cooked_tuna",1}};
        Text = "Cooking Tuna...";
        RequiredLicense = "fish";
        NoLicenseCost = 300;
    };

    class mullet {
        MaterialsReq[] = {{"raw_mullet",1}};
        MaterialsGive[] = {{"raw_mullet",1}};
        Text = "Cooking Mullet...";
        RequiredLicense = "fish";
        NoLicenseCost = 300;
    };

    class catshark {
        MaterialsReq[] = {{"raw_catshark",1}};
        MaterialsGive[] = {{"cooked_catshark",1}};
        Text = "Cooking Catshark...";
        RequiredLicense = "fish";
        NoLicenseCost = 300;
    };

    class turtle {
        MaterialsReq[] = {{"raw_turtle",1}};
        MaterialsGive[] = {{"cooked_turtle",1}};
        Text = "Cooking Turtle...";
        RequiredLicense = "fish";
        NoLicenseCost = 2500;
    };

    class lumber {
        MaterialsReq[] = {{"wood",1}};
        MaterialsGive[] = {{"lumber",1}};
        Text = "Processing Wood...";
        RequiredLicense = "lumber";
        NoLicenseCost = 1250;
    };

    class tin {
        MaterialsReq[] = {{"tin_ore",1}};
        MaterialsGive[] = {{"tin_bar",1}};
        Text = "Processing Tin...";
        RequiredLicense = "tin";
        NoLicenseCost = 3700;
    };

    class copper {
        MaterialsReq[] = {{"copper_ore",1}};
        MaterialsGive[] = {{"copper_bar",1}};
        Text = "Processing Copper...";
        RequiredLicense = "copper";
        NoLicenseCost = 4500;
    };

    class silver {
        MaterialsReq[] = {{"silver_ore",1}};
        MaterialsGive[] = {{"silver_bar",1}};
        Text = "Processing Silver...";
        RequiredLicense = "silver";
        NoLicenseCost = 4650;
    };

    class iron {
        MaterialsReq[] = {{"iron_ore",1}};
        MaterialsGive[] = {{"iron_bar",1}};
        Text = "Processing Iron...";
        RequiredLicense = "iron";
        NoLicenseCost = 5300;
    };

    class platinum {
        MaterialsReq[] = {{"platinum_ore",1}};
        MaterialsGive[] = {{"platinum_bar",1}};
        Text = "Processing Platinum...";
        RequiredLicense = "platinum";
        NoLicenseCost = 10500;
    };

    class cement {
        MaterialsReq[] = {{"rock",1}};
        MaterialsGive[] = {{"cement",1}};
        Text = "Processing Cement...";
        RequiredLicense = "rock";
        NoLicenseCost = 5000;
    };

    class oil {
        MaterialsReq[] = {{"crude_oil",1}};
        MaterialsGive[] = {{"refined_oil",1}};
        Text = "Processing Oil...";
        RequiredLicense = "oil";
        NoLicenseCost = 13000;
    };

    class iridium {
        MaterialsReq[] = {{"iridium_ore",1}};
        MaterialsGive[] = {{"iridium_bar",1}};
        Text = "Processing Iridium...";
        RequiredLicense = "iridium";
        NoLicenseCost = 17500;
    };

    class opal {
        MaterialsReq[] = {{"uncut_opal",1}};
        MaterialsGive[] = {{"uncut_opal",1}};
        Text = "Processing Opal...";
        RequiredLicense = "gem";
        NoLicenseCost = 9500;
    };

    class sapphire {
        MaterialsReq[] = {{"uncut_sapphire",1}};
        MaterialsGive[] = {{"uncut_sapphire",1}};
        Text = "Processing Sapphire...";
        RequiredLicense = "gem";
        NoLicenseCost = 9500;
    };

    class ruby {
        MaterialsReq[] = {{"uncut_ruby",1}};
        MaterialsGive[] = {{"cut_ruby",1}};
        Text = "Processing Ruby...";
        RequiredLicense = "gem";
        NoLicenseCost = 9500;
    };

    class emerald {
        MaterialsReq[] = {{"uncut_emerald",1}};
        MaterialsGive[] = {{"cut_emerald",1}};
        Text = "Processing Emerald...";
        RequiredLicense = "gem";
        NoLicenseCost = 9500;
    };

    class diamond {
        MaterialsReq[] = {{"uncut_diamond",1}};
        MaterialsGive[] = {{"cut_diamond",1}};
        Text = "Processing Diamond...";
        RequiredLicense = "gem";
        NoLicenseCost = 9500;
    };

    class marijuana {
        MaterialsReq[] = {{"cannabis",1}};
        MaterialsGive[] = {{"marijuana",1}};
        Text = "Processing Marijuana...";
        RequiredLicense = "marijuana";
        NoLicenseCost = 6500;
    };

    class heroin {
        MaterialsReq[] = {{"opium",1}};
        MaterialsGive[] = {{"heroin",1}};
        Text = "Processing Heroin...";
        RequiredLicense = "heroin";
        NoLicenseCost = 1000;
    };

    class cocaine {
        MaterialsReq[] = {{"coca",1}};
        MaterialsGive[] = {{"cocaine",1}};
        Text = "Processing Cocaine...";
        RequiredLicense = "cocaine";
        NoLicenseCost = 14000;
    };

    class ephedrine {
        MaterialsReq[] = {{"empty_fuel_can",1}};
        MaterialsGive[] = {{"ephedrine",1}};
        Text = "Processing Ephedrine...";
        RequiredLicense = "";
        NoLicenseCost = 0;
    };

    class methamphetamine {
        MaterialsReq[] = {{"ephedrine",1}};
        MaterialsGive[] = {{"methamphetamine",1}};
        Text = "Processing Methamphetamine...";
        RequiredLicense = "methamphetamine";
        NoLicenseCost = 24600;
    };

    class refined_marijuana {
        MaterialsReq[] = {{"marijuana",1}};
        MaterialsGive[] = {{"refined_marijuana",1}};
        Text = "Refining Marijuana...";
        RequiredLicense = "drug_refining";
        NoLicenseCost = 13000;
    };

    class refined_heroin {
        MaterialsReq[] = {{"heroin",1}};
        MaterialsGive[] = {{"refined_heroin",1}};
        Text = "Refining Heroin...";
        RequiredLicense = "drug_refining";
        NoLicenseCost = 20000;
    };

    class refined_cocaine {
        MaterialsReq[] = {{"cocaine",1}};
        MaterialsGive[] = {{"refined_cocaine",1}};
        Text = "Refining Cocaine...";
        RequiredLicense = "drug_refining";
        NoLicenseCost = 28000;
    };

    class refined_methamphetamine {
        MaterialsReq[] = {{"methamphetamine",1}};
        MaterialsGive[] = {{"refined_methamphetamine",1}};
        Text = "Refining Methamphetamine...";
        RequiredLicense = "drug_refining";
        NoLicenseCost = 48000;
    };

    class gold_debranding {
        MaterialsReq[] = {{"branded_gold_bar",1}};
        MaterialsGive[] = {{"unbranded_gold_bar",1}};
        Text = "Debranding Gold...";
        RequiredLicense = "";
        NoLicenseCost = 50000;
    };
};