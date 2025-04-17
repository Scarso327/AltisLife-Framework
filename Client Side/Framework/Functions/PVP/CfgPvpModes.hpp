class CfgPvpModes {
	days[] = { "Sunday", "Wednesday", "Friday" };
	time[] = { 19, 15 }; // Hour, Minute
	voteDuration = 2 * 60; // In Seconds
	
	redzoneKillMoney = 50000;
	redzoneKillXP = 30;

	class Modes {
		class Conflict {
			displayName = "Conflict";
			markerColour = "Color3_FD_F";
			maxScore = 3000;
			maxDuration = 1 * 60 * 75; // In Seconds
			tickDuration = 2 * 60; // In Seconds
			baseReward = 5000000;
			multipliedReward = 5000;
			class NodeTypes {
				class LowTier {
					displayName = "Low Tier";
					marker = "mil_circle";
					score = 200;
				};
				class MidTier {
					displayName = "Mid Tier";
					marker = "mil_objective";
					score = 400;
				};
				class HighTier {
					displayName = "High Tier";
					marker = "mil_warning";
					score = 600;
				};
			};
			class Events {
				onConflictNodeSpawned = "_this call ULP_fnc_onConflictNodeSpawned";
				onConflictNodeCaptured = "_this call ULP_fnc_onConflictNodeCaptured";
				onConflictNodeDepleted = "_this call ULP_fnc_onConflictNodeDepleted";
				onStart = "_this call ULP_fnc_onConflictStarted";
				onStop = "_this call ULP_fnc_onConflictEnded";
			};
			class ServerEvents {
				onStart = "_this call ULP_SRV_fnc_startConflict";
				onStop = "_this call ULP_SRV_fnc_stopConflict";
			};
			class Locations {
				class Altis {
					class Oreokastro {
						displayName = "Oreokastro";
						teleportLocation = "conflict_spawn_oreokastro_1";
						position[] = { 4590.34,21425.2,0 };
						class Nodes {
							class NorthernHouse {
								displayName = "Northern House";
								position[] = { 4670.74,22328.2,0 };
								radius = 50;
							};
							class Castle {
								displayName = "Castle";
								position[] = { 4884.71,21926,0 };
								radius = 100;
							};
							class HilltopCamp : Castle {
								displayName = "Hilltop Camp";
								position[] = { 3789.02,21498.7,0 };
							};
							class ValleyCamp : Castle {
								displayName = "Valley Camp";
								position[] = { 5178.12,21059.3,0 };
							};
							class SouthernHouse : Castle {
								displayName = "Southern House";
								position[] = { 3524.75,19978.7,0 };
							};
							class SouthernCamp : Castle {
								displayName = "Southern Camp";
								position[] = { 4876.21,19453.5,0 };
							};
							class RoadsideDump : Castle {
								displayName = "Roadside Dump";
								position[] = { 5875.43,20106.9,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_oreokastro_1 {
								position[] = { { 2381.14,22816.4,0 }, 83.705 };
                                size[] = { 75, 450 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_oreokastro_2 : redzone_oreokastro_1 { position[] = { { 3264.22,22898.6,0 }, 85.579 }; };
							class redzone_oreokastro_3 : redzone_oreokastro_1 { position[] = { { 4146.43,22954.8,0 }, 87.618 }; };
							class redzone_oreokastro_4 : redzone_oreokastro_1 { position[] = { { 5030.94,22953.3,0 }, 92.444 }; };
							class redzone_oreokastro_5 : redzone_oreokastro_1 { position[] = { { 5901.06,22864,0 }, 99.437 }; };
							class redzone_oreokastro_6 : redzone_oreokastro_1 { position[] = { { 6322.45,22410.8,0 }, 354.979 }; };
							class redzone_oreokastro_7 : redzone_oreokastro_1 { position[] = { { 6349.1,21527.9,0 }, 1.553 }; };
							class redzone_oreokastro_8 : redzone_oreokastro_1 { position[] = { { 6292.2,20649.3,0 }, 5.991 }; };
							class redzone_oreokastro_9 : redzone_oreokastro_1 { position[] = { { 5933.25,19952.6,0 }, 48.472 }; };
							class redzone_oreokastro_10 : redzone_oreokastro_1 { position[] = { { 5219.94,19444.6,0 }, 60.318 }; };
							class redzone_oreokastro_11 : redzone_oreokastro_1 { position[] = { { 4428.33,19289.1,0 }, 96.707 }; };
							class redzone_oreokastro_12 : redzone_oreokastro_1 { position[] = { { 3546.86,19350.4,0 }, 91.057 }; };
							class redzone_oreokastro_13 : redzone_oreokastro_1 { 
								position[] = { { 2742.27,19468,0 }, 106.742 }; 
								size[] = { 75, 400 };
							};
							class redzone_oreokastro_14 : redzone_oreokastro_1 { position[] = { { 2446.04,19944.5,0 }, 15.071 }; };
							class redzone_oreokastro_15 : redzone_oreokastro_1 { 
								position[] = { { 2597.14,20538.4,0 }, 12.684 }; 
								size[] = { 75, 250 };
							};
							class redzone_oreokastro_16 : redzone_oreokastro_1 { position[] = { { 2444.09,21135.9,0 }, 333.662 }; };
							class redzone_oreokastro_17 : redzone_oreokastro_1 { position[] = { { 1923.08,21805.7,0 }, 310.491 }; };
							class redzone_oreokastro_18 : redzone_oreokastro_1 { position[] = { { 1798.19,22409.3,0 }, 26.312 }; };

							// AREA
							class redzone_oreokastro_19 : redzone_oreokastro_1 {
								position[] = { { 3179.8,20619.2,0 }, 286.395 };
                                size[] = { 1200, 500 };
								alpha = 0;
							};
							class redzone_oreokastro_20 : redzone_oreokastro_19 { 
								position[] = { { 2979.57,21190.8,0 }, 340.141 }; 
								size[] = { 500, 500 };
							};
							class redzone_oreokastro_21 : redzone_oreokastro_19 { 
								position[] = { { 4946.23,22588.8,0 }, 4.526 }; 
								size[] = { 1400, 300 };
							};
							class redzone_oreokastro_22 : redzone_oreokastro_19 { 
								shape = "ELLIPSE";
								position[] = { { 3185.95,22011.1,0 }, 11.187 }; 
								size[] = { 1500, 900 };
							};
							class redzone_oreokastro_23 : redzone_oreokastro_22 { 
								position[] = { { 4946.23,22588.8,0 }, 4.526 }; 
								size[] = { 1400, 300 };
							};
							class redzone_oreokastro_24 : redzone_oreokastro_22 { 
								position[] = { { 4001.12,21841.5,0 }, 53.391 }; 
								size[] = { 1200, 1000 };
							};
							class redzone_oreokastro_25 : redzone_oreokastro_22 { 
								position[] = { { 5419.92,21666.4,0 }, 359.847 }; 
								size[] = { 1000, 1000 };
							};
							class redzone_oreokastro_26 : redzone_oreokastro_25 { position[] = { { 5341.39,20744.3,0 }, 359.847 }; };
							class redzone_oreokastro_27 : redzone_oreokastro_25 { position[] = { { 4715.297,20208.03,0 }, 359.847 }; };
							class redzone_oreokastro_28 : redzone_oreokastro_25 { position[] = { { 3874.543,20278.207,0 }, 359.847 }; };

							// SPAWN
							class greenzone_oreokastro_1 {
								position[] = { { 4072.19,20780.4,0 }, 0 };
                                size[] = { 50, 50 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorGUER";
								alpha = 1;
							};
							class greenzone_oreokastro_2 : greenzone_oreokastro_1 { position[] = { { 5091.51,20217.4,0 }, 0 }; };
						};
					};

					class Frini {
						displayName = "Frini";
						teleportLocation = "conflict_spawn_frini_1";
						position[] = { 14452.3,21756.9,0 };
						class Nodes {
							class EasternChurch {
								displayName = "Eastern Church";
								position[] = { 16697.1,21230.6,0 };
								radius = 100;
							};
							class FriniTown : EasternChurch {
								displayName = "Frini Town";
								position[] = { 14600.2,20776.4,0 };
							};
							class MilitaryCompound : EasternChurch {
								displayName = "Military Compound";
								position[] = { 14207.9,21222.5,0 };
							};
							class BrokenHouse : EasternChurch {
								displayName = "Broken House";
								position[] = { 13446.7,21621,0 };
							};
							class ForestHouse : EasternChurch {
								displayName = "Forest House";
								position[] = { 14194.2,22157.1,0 };
							};
							class NorthernView : EasternChurch {
								displayName = "Northern View";
								position[] = { 13438.7,22648.7,0 };
							};
							class NorthernChurch : EasternChurch {
								displayName = "Northern Church";
								position[] = { 15034.6,22759,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_frini_1 {
								position[] = { { 12565,23438.9,0 }, 80.603 };
                                size[] = { 75, 450 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_frini_2 : redzone_frini_1 { position[] = { { 13447.868,23541.334,0 }, 86.130 }; };
							class redzone_frini_3 : redzone_frini_1 { position[] = { { 14231.913,23814.81,0 }, 55.418 }; };
							class redzone_frini_4 : redzone_frini_1 { position[] = { { 14849.956,23776.178,0 }, 311.775 }; };
							class redzone_frini_5 : redzone_frini_1 { position[] = { { 15478.29,23161.64,0 }, 137.017 }; };
							class redzone_frini_6 : redzone_frini_1 { position[] = { { 16159.360,22635.453,0 }, 118.237 }; };
							class redzone_frini_7 : redzone_frini_1 { position[] = { { 16965.303,22433.664,0 }, 89.820 }; };
							class redzone_frini_8 : redzone_frini_1 { position[] = { { 17410.338,20649.3,0 }, 5.991 }; };
							class redzone_frini_9 : redzone_frini_1 { position[] = { { 5933.25,22056.82,0 }, 8.719 }; };
							class redzone_frini_10 : redzone_frini_1 { position[] = { { 17079.783,21311.025,0 }, 39.144 }; };
							class redzone_frini_11 : redzone_frini_1 { position[] = { { 16428.463,20753.039,0 }, 59.865 }; };
							class redzone_frini_12 : redzone_frini_1 { position[] = { { 15627.515,20419.17,0 }, 74.946 }; };
							class redzone_frini_13 : redzone_frini_1 { position[] = { { 14772.59,20349.146,0 }, 95.558 }; };
							class redzone_frini_14 : redzone_frini_1 { position[] = { { 13912.123,20310.203,0 }, 79.04 }; };
							class redzone_frini_15 : redzone_frini_1 { position[] = { { 13116.952,20415.875,0 }, 116.178 }; };
							class redzone_frini_16 : redzone_frini_1 { position[] = { { 12669.28,21002.27,0 }, 169.018 }; };
							class redzone_frini_17 : redzone_frini_1 { position[] = { { 12472.232,21858.979,0 }, 344.667 }; };
							class redzone_frini_18 : redzone_frini_1 { position[] = { { 12237.77,23007.23,0 }, 353.208 }; };
							class redzone_frini_26 : redzone_frini_1 { 
								position[] = { { 12321.235,22430.76,0 }, 346.549 }; 
								size[] = { 75, 150 };
							};

							// AREA
							class redzone_frini_19 : redzone_frini_1 {
								position[] = { { 13461.3,22755.8,0 }, 349.752 };
                                size[] = { 1200, 800 };
								alpha = 0;
							};
							class redzone_frini_20 : redzone_frini_19 { position[] = { { 14866.674,22641.512,0 }, 42.837 }; };
							class redzone_frini_21 : redzone_frini_19 { 
								shape = "ELLIPSE";
								position[] = { { 14002.9,21896.6,0 }, 0 }; 
								size[] = { 1500, 1500 };
							};
							class redzone_frini_22 : redzone_frini_21 { 
								position[] = { { 15522.836,21580.283,0 }, 0 }; 
								size[] = { 1200, 1200 };
							};
							class redzone_frini_23 : redzone_frini_21 { 
								position[] = { { 16384.754,21522.078,0 }, 315.917 }; 
								size[] = { 1200, 700 };
							};
							class redzone_frini_24 : redzone_frini_23 { position[] = { { 14887.055,20995.43,0 }, 358.438 }; };
							class redzone_frini_25 : redzone_frini_21 { 
								position[] = { { 13364.468,20830.455,0 }, 118.675 }; 
								size[] = { 500, 700 };
							};

							// SPAWN
							class greenzone_frini_1 {
								position[] = { { 15824.4,21724.7,0 }, 0 };
                                size[] = { 50, 50 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorGUER";
								alpha = 1;
							};
							class greenzone_frini_2 : greenzone_frini_1 { position[] = { { 12782.9,21801.7,0 }, 0 }; };
						};
					};

					class Molos {
						displayName = "Molos";
						teleportLocation = "conflict_spawn_molos_1";
						position[] = { 26993.3,23201.6,0 };
						class Nodes {
							class SolarFarm {
								displayName = "Solar Farm";
								position[] = { 27048.4,21478.1,0 };
								radius = 100;
							};
							class ScrapYard : SolarFarm {
								displayName = "Scrap Yard";
								position[] = { 27806.6,22251.1,0 };
							};
							class MolosChurch : SolarFarm {
								displayName = "Molos Church";
								position[] = { 26985.1,23270.7,0 };
							};
							class NorthernLighthouse : SolarFarm {
								displayName = "Northern Lighthouse";
								position[] = { 28315.3,25777.4,0 };
							};
							class OldProcessing : SolarFarm {
								displayName = "Old Processing";
								position[] = { 27361.6,24454.7,0 };
							};
							class CoastalChurch : SolarFarm {
								displayName = "Coastal Church";
								position[] = { 26191.2,24184.9,0 };
							};
							class Limnichori : SolarFarm {
								displayName = "Limnichori";
								position[] = { 25781.9,23458.6,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_molos_1 {
								position[] = { { 25631.543,23927.94,0 }, 43.217 };
                                size[] = { 75, 450 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_molos_2 : redzone_molos_1 { position[] = { { 26206.895,24603.477,0 }, 37.513 }; };
							class redzone_molos_3 : redzone_molos_1 { position[] = { { 26819.912,25219.992,0 }, 52.103 }; };
							class redzone_molos_4 : redzone_molos_1 { position[] = { { 27571.605,25659.727,0 }, 67.299 }; };
							class redzone_molos_5 : redzone_molos_1 { position[] = { { 28382.3,25981.697,0 }, 70.024 }; };
							class redzone_molos_6 : redzone_molos_1 { position[] = { { 28730.328,25618.64,0 }, 3.377 }; };
							class redzone_molos_7 : redzone_molos_1 { position[] = { { 28662.426,24722.906,0 }, 5.121 }; };
							class redzone_molos_8 : redzone_molos_1 { position[] = { { 28547.084,23839.615,0 }, 9.885 }; };
							class redzone_molos_9 : redzone_molos_1 { position[] = { { 28333.057,22991.756,0 }, 18.117 }; };
							class redzone_molos_10 : redzone_molos_1 { position[] = { { 28265.047,22159.68,0 }, 351.289 }; };
							class redzone_molos_11 : redzone_molos_1 { position[] = { { 28246.203,21307.338,0 }, 11.511 }; };
							class redzone_molos_12 : redzone_molos_1 { position[] = { { 27786.584,20756.121,0 }, 67.975 }; };
							class redzone_molos_13 : redzone_molos_1 { position[] = { { 26945.307,20514.811,0 }, 80.044 }; };
							class redzone_molos_14 : redzone_molos_1 { position[] = { { 26459.926,20815.146,0 }, 343.543 }; };
							class redzone_molos_15 : redzone_molos_1 { position[] = { { 26101.506,21607.16,0 }, 327.716 }; };
							class redzone_molos_16 : redzone_molos_1 { position[] = { { 25686.31,22388.89,0 }, 336.346 }; };
							class redzone_molos_17 : redzone_molos_1 { position[] = { { 25426.662,23223.715,0 }, 349.049 }; };

							// AREA
							class redzone_molos_19 : redzone_molos_1 {
								position[] = { { 27054.688,21641.564,0 }, 72.156 };
                                size[] = { 1000, 900 };
								alpha = 0;
							};
							class redzone_molos_20 : redzone_molos_19 { 
								position[] = { { 27942.838,21969.44,0 }, 349.725 }; 
								size[] = { 300, 600 };
							};
							class redzone_molos_26 : redzone_molos_20 { position[] = { { 26135.78,22232.32,0 }, 334.752 }; };
							class redzone_molos_21 : redzone_molos_19 { 
								shape = "ELLIPSE";
								position[] = { { 26368.344,23284.754,0 }, 0 }; 
								size[] = { 1000, 1000 };
							};
							class redzone_molos_22 : redzone_molos_21 { position[] = { { 27466.523,23354.096,0 }, 0 }; };
							class redzone_molos_23 : redzone_molos_21 { position[] = { { 26985.65,24092.184,0 }, 315.917 }; };
							class redzone_molos_24 : redzone_molos_23 { position[] = { { 27585.063,24532.797,0 }, 359.847 }; };
							class redzone_molos_25 : redzone_molos_21 { 
								position[] = { { 28015.223,25251.584,0 }, 322.120 }; 
								size[] = { 700, 600 };
							};

							// SPAWN
							class greenzone_molos_1 {
								position[] = { { 27838.1,23613.2,0 }, 0 };
                                size[] = { 50, 50 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorGUER";
								alpha = 1;
							};
							class greenzone_molos_2 : greenzone_molos_1 { position[] = { { 26283.2,21597.3,0 }, 0 }; };
						};
					};

					class Blackmarket {
						displayName = "Blackmarket";
						teleportLocation = "conflict_spawn_blackmarket_1";
						position[] = { 20708.2,7877.76,0 };
						class Nodes {
							class WindFarm {
								displayName = "Wind Farm";
								position[] = { 20636.8,5922.89,0 };
								radius = 100;
							};
							class CoastalChurch : WindFarm {
								displayName = "Coastal Church";
								position[] = { 18524.2,6248.73,0 };
							};
							class CoastalShack : WindFarm {
								displayName = "Coastal Shack";
								position[] = { 18324.8,7895.94,0 };
							};
							class PanagiaIndustrial : WindFarm {
								displayName = "Pangaia Industrial";
								position[] = { 20255.8,8829.08,0 };
							};
							class FeresIndustrial : WindFarm {
								displayName = "Feres Industrial";
								position[] = { 21672.9,7793.53,0 };
							};
							class MilitaryBase : WindFarm {
								displayName = "Military Base";
								position[] = { 23017.7,7256.97,0 };
							};
							class HilltopHouse : WindFarm {
								displayName = "Hilltop House";
								position[] = { 22668.6,7792.37,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_blackmarket_1 {
								position[] = { { 18770.67,8646.401,0 }, 57.947 };
                                size[] = { 75, 450 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_blackmarket_2 : redzone_blackmarket_1 { position[] = { { 19515.281,9142.918,0 }, 37.513 }; };
							class redzone_blackmarket_3 : redzone_blackmarket_1 { position[] = { { 20258.807,9637.519,0 }, 57.947 }; };
							class redzone_blackmarket_4 : redzone_blackmarket_1 { position[] = { { 21037.455,10057.643,0 }, 65.369 }; };
							class redzone_blackmarket_5 : redzone_blackmarket_1 { position[] = { { 21660.166,9936.761,0 }, 321.694 }; };
							class redzone_blackmarket_6 : redzone_blackmarket_1 { position[] = { { 22110.33,9330.948,0 }, 325.191 }; };
							class redzone_blackmarket_7 : redzone_blackmarket_1 { position[] = { { 22669.43,8655.2,0 }, 315.346 }; };
							class redzone_blackmarket_8 : redzone_blackmarket_1 { position[] = { { 23266.436,8004,0 }, 320.053 }; };
							class redzone_blackmarket_9 : redzone_blackmarket_1 { position[] = { { 23433.537,7290.326,0 }, 13.731 }; };
							class redzone_blackmarket_10 : redzone_blackmarket_1 { position[] = { { 22623.434,5875.025,0 }, 12.943 }; };
							class redzone_blackmarket_11 : redzone_blackmarket_1 { position[] = { { 22342.855,5047.973,0 }, 24.663 }; };
							class redzone_blackmarket_12 : redzone_blackmarket_1 { position[] = { { 21770.74,4661.468,0 }, 87.105 }; };
							class redzone_blackmarket_13 : redzone_blackmarket_1 { position[] = { { 20914.723,4758.937,0 }, 105.875 }; };
							class redzone_blackmarket_14 : redzone_blackmarket_1 { position[] = { { 20063.980,5031.341,0 }, 109.658 }; };
							class redzone_blackmarket_15 : redzone_blackmarket_1 { position[] = { { 19221.686,5332.403,0 }, 109.658 }; };
							class redzone_blackmarket_16 : redzone_blackmarket_1 { position[] = { { 18556.95,5811.866,0 }, 321.886 }; };
							class redzone_blackmarket_17 : redzone_blackmarket_1 { position[] = { { 18006.107,6515.253,0 }, 321.775 }; };
							class redzone_blackmarket_18 : redzone_blackmarket_1 { position[] = { { 17861.803,7235.196,0 }, 15.568 }; };
							class redzone_blackmarket_32 : redzone_blackmarket_1 { position[] = { { 18194.396,8043.208,0 }, 29.362 }; };

							// AREA
							class redzone_blackmarket_19 : redzone_blackmarket_1 {
								position[] = { { 20477.9,5946.37,0 }, 16.846 };
                                size[] = { 1000, 1000 };
								alpha = 0;
							};
							class redzone_blackmarket_20 : redzone_blackmarket_19 { 
								position[] = { { 21585.979,8768.274,0 }, 321.219 }; 
								size[] = { 800, 1300 };
							};
							class redzone_blackmarket_21 : redzone_blackmarket_19 { 
								shape = "ELLIPSE";
								position[] = { { 19361.1,6343.923,0 }, 0 }; 
								size[] = { 1000, 1000 };
							};
							class redzone_blackmarket_22 : redzone_blackmarket_21 { position[] = { { 18780.852,7068.432,0 }, 0 }; };
							class redzone_blackmarket_23 : redzone_blackmarket_21 { position[] = { { 21596.895,5645.583,0 }, 0 }; };
							class redzone_blackmarket_24 : redzone_blackmarket_23 { position[] = { { 21808.723,6505.507,0 }, 0 }; };
							class redzone_blackmarket_25 : redzone_blackmarket_21 { position[] = { { 22494.17,7441.488,0 }, 0 }; };
							class redzone_blackmarket_26 : redzone_blackmarket_21 { position[] = { { 20718.461,7166.979,0 }, 0 }; };
							class redzone_blackmarket_27 : redzone_blackmarket_21 { position[] = { { 21137.11,8100.7,0 }, 0 }; };
							class redzone_blackmarket_28 : redzone_blackmarket_21 { position[] = { { 20934.025,8967.627,0 }, 0 }; };
							class redzone_blackmarket_29 : redzone_blackmarket_21 { position[] = { { 20374.873,8582.928,0 }, 0 }; };
							class redzone_blackmarket_30 : redzone_blackmarket_21 { position[] = { { 19697.711,8097.495,0 }, 0 }; };
							class redzone_blackmarket_31 : redzone_blackmarket_21 { position[] = { { 19066.164,7655.094,0 }, 0 }; };

							// SPAWN
							class greenzone_blackmarket_1 {
								position[] = { { 21483.1,8404.15,0 }, 0 };
                                size[] = { 50, 50 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorGUER";
								alpha = 1;
							};
							class greenzone_blackmarket_2 : greenzone_blackmarket_1 { position[] = { { 19642.2,7771.16,0 }, 0 }; };
						};
					};

					class Pefkas {
						displayName = "Pefkas";
						teleportLocation = "conflict_spawn_pefkas_1";
						position[] = { 21615.6,19933.3,0 };
						class Nodes {
							class GhostHotel {
								displayName = "Ghost Hotel";
								position[] = { 21969.4,21021.2,0 };
								radius = 100;
							};
							class BrokenTown : GhostHotel {
								displayName = "Broken Town";
								position[] = { 22434,20026,0 };
							};
							class HillsideChurch : GhostHotel {
								displayName = "Hillside Church";
								position[] = { 22256.2,19361,0 };
							};
							class HillsideSlums : GhostHotel {
								displayName = "Hillside Slums";
								position[] = { 21470.8,19548,0 };
							};
							class ResearchFacility : GhostHotel {
								displayName = "Research Facility";
								position[] = { 20893.2,19227.1,0 };
							};
							class Watchtower : GhostHotel {
								displayName = "Watchtower";
								position[] = { 20597.5,20114.3,0 };
							};
							class ObservationPost : GhostHotel {
								displayName = "Observation Post";
								position[] = { 20344.4,18768.7,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_pefkas_1 {
								position[] = { { 20802.752,21371.658,0 }, 62.284 };
                                size[] = { 75, 500 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_pefkas_2 : redzone_pefkas_1 { position[] = { { 21711.69,21725.85,0 }, 74.958 }; };
							class redzone_pefkas_3 : redzone_pefkas_1 { position[] = { { 22339.285,21450.72,0 }, 332.696 }; };
							class redzone_pefkas_4 : redzone_pefkas_1 { position[] = { { 22852.28,20609.521,0 }, 324.599 }; };
							class redzone_pefkas_5 : redzone_pefkas_1 { position[] = { { 222968.586,19798.05,0 }, 19.048 }; };
							class redzone_pefkas_6 : redzone_pefkas_1 { position[] = { { 22495.871,18969.143,0 }, 40.333 }; };
							class redzone_pefkas_7 : redzone_pefkas_1 { position[] = { { 21811.033,18258.46,0 }, 47.546 }; };
							class redzone_pefkas_8 : redzone_pefkas_1 { position[] = { { 20987.732,17841.61,0 }, 78.772 }; };
							class redzone_pefkas_9 : redzone_pefkas_1 { position[] = { { 20358.111,18152.215,0 }, 153.755 }; };
							class redzone_pefkas_10 : redzone_pefkas_1 { position[] = { { 19860.645,19002.805,0 }, 325.628 }; };
							class redzone_pefkas_11 : redzone_pefkas_1 { position[] = { { 19666.877,19855.881,0 }, 8.766 }; };
							class redzone_pefkas_12 : redzone_pefkas_1 { position[] = { { 20019.744,20714.906,0 }, 36.454 }; };
							class redzone_pefkas_13 : redzone_pefkas_1 { 
								position[] = { { 20334.246,21122.715,0 }, 55.887 }; 
								size[] = { 75, 50 };
							};

							// AREA
							class redzone_pefkas_19 : redzone_pefkas_1 {
								shape = "ELLIPSE";
								position[] = { { 21052.275,18850.484,0 }, 0 };
                                size[] = { 1000, 1000 };
								alpha = 0;
							};
							class redzone_pefkas_20 : redzone_pefkas_19 { position[] = { { 20585.584,19695.893,0 }, 0 }; };
							class redzone_pefkas_21 : redzone_pefkas_19 { position[] = { { 21722.1,19487.352,0 }, 0 }; };
							class redzone_pefkas_22 : redzone_pefkas_19 { position[] = { { 22073.646,20042.498,0 }, 0 }; };
							class redzone_pefkas_23 : redzone_pefkas_19 { position[] = { { 21666.813,20757.86,0 }, 0 }; };
							class redzone_pefkas_24 : redzone_pefkas_19 { position[] = { { 21285.803,20527.29,0 }, 0 }; };
							class redzone_pefkas_25 : redzone_pefkas_19 { position[] = { { 20825.158,20215.81,0 }, 0 }; };

							// SPAWN
							class greenzone_pefkas_1 {
								position[] = { { 21824.6,19304.2,0 }, 0 };
                                size[] = { 50, 50 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorGUER";
								alpha = 1;
							};
							class greenzone_pefkas_2 : greenzone_pefkas_1 { position[] = { { 20344.1,17806.7,0 }, 0 }; };
						};
					};
				};
			};
		};
	};
};