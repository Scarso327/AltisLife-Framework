class CfgPvpModes {
	days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
	time[] = { 20, 00 }; // Hour, Minute
	voteDuration = 3 * 30; // In Seconds
	
	redzoneKillMoney = 50000;
	redzoneKillXP = 30;

	class Modes {
		class Conflict {
			displayName = "Conflict";
			markerColour = "Color3_FD_F";
			maxScore = 4000;
			maxDuration = 2 * 60 * 60; // In Seconds
			tickDuration = 2 * 60; // In Seconds
			baseReward = 10000000;
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
						position[] = { 4384.06,21063.3,0 };
						class Nodes {
							class Castle {
								displayName = "Castle";
								position[] = { 4878.77,21926.9,0 };
								radius = 20;
							};
							class Workshop {
								displayName = "Workshop";
								position[] = { 3780.638,21495.266,0 };
								radius = 30;
							};
							class Church {
								displayName = "Church";
								position[] = { 4552.239,21492.094,0 };
								radius = 15;
							};
							class HilltopView : Workshop {
								displayName = "Hilltop View";
								position[] = { 3532.749,19977.338,0 };
							};
							class Construction : Workshop {
								displayName = "Construction";
								position[] = { 5841.403,20129.89,0 };
							};
							class CrashSite : Workshop {
								displayName = "Crash Site";
								position[] = { 5183.470,21050.637,0 };
							};
							class ValleyFacility : Workshop {
								displayName = "Valley Facility";
								position[] = { 4876.875,19445.928,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_oreokastro_border_1 {
								position[] = { { 2313.128,22690.467,0 }, 81.842 };
                                size[] = { 75, 500 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_oreokastro_border_2 : redzone_oreokastro_border_1 { position[] = { { 3298.003,22772.078,0 }, 88.654 }; };
							class redzone_oreokastro_border_3 : redzone_oreokastro_border_1 { position[] = { { 4287.993,22828.736,0 }, 84.750 }; };
							class redzone_oreokastro_border_4 : redzone_oreokastro_border_1 { position[] = { { 5126.227,22583.896,0 }, 127.928 }; };
							class redzone_oreokastro_border_5 : redzone_oreokastro_border_1 { position[] = { { 5754.187,21868.72,0 }, 329.478 }; };
							class redzone_oreokastro_border_6 : redzone_oreokastro_border_1 { position[] = { { 6229.973,20997.525,0 }, 333.268 }; };
							class redzone_oreokastro_border_7 : redzone_oreokastro_border_1 { position[] = { { 6210.73,20187.477,0 }, 29.533 }; };
							class redzone_oreokastro_border_8 : redzone_oreokastro_border_1 { position[] = { { 5599.746,19451.377,0 }, 49.916 }; };
							class redzone_oreokastro_border_9 : redzone_oreokastro_border_1 { position[] = { { 4779.455,19210.785,0 }, 97.411 }; };
							class redzone_oreokastro_border_10 : redzone_oreokastro_border_1 { position[] = { { 3844.669,19466.049,0 }, 113.183 }; };
							class redzone_oreokastro_border_11 : redzone_oreokastro_border_1 { position[] = { { 2924.190,19851.211,0 }, 112.298 }; };
							class redzone_oreokastro_border_12 : redzone_oreokastro_border_1 { 
								position[] = { { 2561.031,20667.270,0 }, 6.569 }; 
								size[] = { 75, 705.806 };
							};
							class redzone_oreokastro_border_13 : redzone_oreokastro_border_1 { position[] = { { 2239.671,21527.46,0 }, 297.973 }; };
							class redzone_oreokastro_border_14 : redzone_oreokastro_border_1 { position[] = { { 1860.436,22191.426,0 }, 2.529 }; };

							// AREA
							class redzone_oreokastro_area_1 {
								position[] = { { 4794.995,20661.934,0 }, 0 };
                                size[] = { 1500, 1500 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 0;
							};
							class redzone_oreokastro_area_2 : redzone_oreokastro_area_1 { 
								position[] = { { 3734.656,20278.652,0 }, 0 }; 
								size[] = { 750, 750 };
							};
							class redzone_oreokastro_area_3 : redzone_oreokastro_area_2 { position[] = { { 3203.512,20453.836,0 }, 0 }; };
							class redzone_oreokastro_area_4 : redzone_oreokastro_area_2 { position[] = { { 3316.991,20935.494,0 }, 0 }; };
							class redzone_oreokastro_area_5 : redzone_oreokastro_area_2 { position[] = { { 4928.403,21840.81,0 }, 0 }; };
							class redzone_oreokastro_area_6 : redzone_oreokastro_area_2 { position[] = { { 4502.224,22113.16,0 }, 0 }; };
							class redzone_oreokastro_area_7 : redzone_oreokastro_area_2 { position[] = { { 3788.562,22080.377,0 }, 0 }; };
							class redzone_oreokastro_area_8 : redzone_oreokastro_area_2 { position[] = { { 3069.857,22052.637,0 }, 0 }; };
							class redzone_oreokastro_area_9 : redzone_oreokastro_area_2 { 
								position[] = { { 2340.505,22263.377,0 }, 0 }; 
								size[] = { 500, 500 };
							};
							class redzone_oreokastro_area_10 : redzone_oreokastro_area_9 { position[] = { { 2359.273,21980.738,0 }, 0 }; };
							class redzone_oreokastro_area_11 : redzone_oreokastro_area_9 { position[] = { { 2869.955,21670.57,0 }, 0 }; };

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
							class greenzone_oreokastro_3 : greenzone_oreokastro_1 { position[] = { { 5607.52,21731.8,0 }, 0 }; };
						};
					};

					class PefkasBay {
						displayName = "Pefkas Bay";
						teleportLocation = "conflict_spawn_pefkasBay_1";
						position[] = { 20943,19413.1,0 };
						class Nodes {
							class Watchtower {
								displayName = "Watchtower";
								position[] = { 20603.873,20124.188,0 };
								radius = 15;
							};
							class ResearchFacility {
								displayName = "Research Facility";
								position[] = { 20894.148,19227.314,0 };
								radius = 20;
							};
							class Bunker : ResearchFacility {
								displayName = "Bunker";
								position[] = { 20344.756,18774.428,0 };
							};
							class OldFarm : ResearchFacility {
								displayName = "Old Farm";
								position[] = { 19720.22,18787.377,0 };
							};
							class HillsideSlums {
								displayName = "Hillside Slums";
								position[] = { 21480.434,19539.506,0 };
								radius = 25;
							};
							class OldTown {
								displayName = "Old Town";
								position[] = { 22425.54,20037.393,0 };
								radius = 30;
							};
							class GhostHotel : ResearchFacility {
								displayName = "Ghost Hotel";
								position[] = { 21977.496,21032.58,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_pefkasBay_border_1 {
								position[] = { { 19217.852,19997.123,0 }, 43.205 };
                                size[] = { 75, 500 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_pefkasBay_border_2 : redzone_pefkasBay_border_1 { position[] = { { 19993.648,20541.34,0 }, 66.684 }; };
							class redzone_pefkasBay_border_3 : redzone_pefkasBay_border_1 { position[] = { { 20786,21073.186,0 }, 45.597 }; };
							class redzone_pefkasBay_border_4 : redzone_pefkasBay_border_1 { position[] = { { 21590.88,21405.678,0 }, 89.477 }; };
							class redzone_pefkasBay_border_5 : redzone_pefkasBay_border_1 { 
								position[] = { { 22378.617,21077.574,0 }, 316.095 }; 
								size[] = { 75, 493.959 };
							};
							class redzone_pefkasBay_border_6 : redzone_pefkasBay_border_1 { 
								position[] = { { 22794.066,20303.082,0 }, 348.390 }; 
								size[] = { 75, 464.061 };
							};
							class redzone_pefkasBay_border_7 : redzone_pefkasBay_border_1 { position[] = { { 22705.38,19435.549,0 }, 21.962 }; };
							class redzone_pefkasBay_border_8 : redzone_pefkasBay_border_1 { position[] = { { 22188.877,18634.146,0 }, 43.693 }; };
							class redzone_pefkasBay_border_9 : redzone_pefkasBay_border_1 { position[] = { { 21500.22,17910.945,0 }, 43.415 }; };
							class redzone_pefkasBay_border_10 : redzone_pefkasBay_border_1 { position[] = { { 20709.926,17437.164,0 }, 74.688 }; };
							class redzone_pefkasBay_border_11 : redzone_pefkasBay_border_1 { position[] = { { 19876.66,17576.84,0 }, 124.283 }; };
							class redzone_pefkasBay_border_12 : redzone_pefkasBay_border_1 { position[] = { { 19354.998,18297.238,0 }, 343.953 }; };
							class redzone_pefkasBay_border_13 : redzone_pefkasBay_border_1 { position[] = { { 19055.174,19236.34,0 }, 340.884 }; };

							// AREA
							class redzone_pefkasBay_area_1 {
								position[] = { { 20621.06,19148.127,0 }, 0 };
                                size[] = { 1500, 1500 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 0;
							};
							class redzone_pefkasBay_area_2 : redzone_pefkasBay_area_1 { 
								position[] = { { 20370.215,18377.656,0 }, 0 }; 
								size[] = { 1000, 1000 };
							};
							class redzone_pefkasBay_area_3 : redzone_pefkasBay_area_2 { position[] = { { 21594.49,19440.844,0 }, 0 }; };
							class redzone_pefkasBay_area_4 : redzone_pefkasBay_area_2 { position[] = { { 21629.637,20454.242,0 }, 0 }; };
							class redzone_pefkasBay_area_5 : redzone_pefkasBay_area_2 { position[] = { { 21902.025,20038.34,0 }, 0 }; };

							// SPAWN
							class greenzone_pefkasBay_1 {
								position[] = { { 21824.5,19304.1,0 }, 0 };
                                size[] = { 50, 50 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorGUER";
								alpha = 1;
							};
							class greenzone_pefkasBay_2 : greenzone_pefkasBay_1 { position[] = { { 20866.814,18200.355,0 }, 0 }; };
						};
					};

					class MolosBay {
						displayName = "Molos Bay";
						teleportLocation = "conflict_spawn_molosBay_1";
						position[] = { 26991.4,23823,0 };
						class Nodes {
							class MolosIndustrial {
								displayName = "Molos Industrial";
								position[] = { 27058.025,22694.998,0 };
								radius = 20;
							};
							class HousingDevelopment {
								displayName = "Housing Development";
								position[] = { 26914.686,24308.117,0 };
								radius = 40;
							};
							class SeasideChurch {
								displayName = "Seaside Church";
								position[] = { 26195.023,24183.344,0 };
								radius = 15;
							};
							class MilitaryBase : MolosIndustrial {
								displayName = "Military Base";
								position[] = { 25712.867,22913.186,0 };
							};
							class EasternCoast : MolosIndustrial {
								displayName = "Eastern Coast";
								position[] = { 27741.072,23494.992,0 };
							};
							class NorthernLighthouse {
								displayName = "Northern Lighthouse";
								position[] = { 28308.95,25778.387,0 };
								radius = 25;
							};
							class OldSaltProcessing : MolosIndustrial {
								displayName = "Old Salt Processing";
								position[] = { 27363.74,24458.799,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_molosBay_border_1 {
								position[] = { { 25597.902,23951.162,0 }, 34.718 };
                                size[] = { 75, 500 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_molosBay_border_2 : redzone_molosBay_border_1 { position[] = { { 26195.738,24739.957,0 }, 39.653 }; };
							class redzone_molosBay_border_3 : redzone_molosBay_border_1 { position[] = { { 26916.166,25375.295,0 }, 57.622 }; };
							class redzone_molosBay_border_4 : redzone_molosBay_border_1 { position[] = { { 27779.55,25850.82,0 }, 64.410 }; };
							class redzone_molosBay_border_5 : redzone_molosBay_border_1 { 
								position[] = { { 28478.156,25737.83,0 }, 330.945 }; 
								size[] = { 75, 481.474 };
							};
							class redzone_molosBay_border_6 : redzone_molosBay_border_1 { position[] = { { 28657.38,24863.797,0 }, 4.856 }; };
							class redzone_molosBay_border_7 : redzone_molosBay_border_1 { position[] = { { 28510.188,23889.424,0 }, 12.326 }; };
							class redzone_molosBay_border_8 : redzone_molosBay_border_1 { position[] = { { 28172.29,22982.629,0 }, 28.5 }; };
							class redzone_molosBay_border_9 : redzone_molosBay_border_1 { position[] = { { 27556.793,22267.31,0 }, 52.910 }; };
							class redzone_molosBay_border_10 : redzone_molosBay_border_1 { position[] = { { 26701.213,21962.16,0 }, 87.834 }; };
							class redzone_molosBay_border_11 : redzone_molosBay_border_1 { position[] = { { 25941.982,22299.71,0 }, 320.067 }; };
							class redzone_molosBay_border_12 : redzone_molosBay_border_1 { position[] = { { 25480.002,23131.422,0 }, 341.708 }; };

							// AREA
							class redzone_molosBay_area_1 {
								position[] = { { 26599.885,23401.625,0 }, 0 };
                                size[] = { 1200, 1200 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 0;
							};
							class redzone_molosBay_area_2 : redzone_molosBay_area_1 { position[] = { { 27212.678,24125.379,0 }, 0 }; };
							class redzone_molosBay_area_3 : redzone_molosBay_area_1 { 
								position[] = { { 27696.857,24730.604,0 }, 0 }; 
								size[] = { 1000, 1000 };
							};
							class redzone_molosBay_area_4 : redzone_molosBay_area_3 { position[] = { { 27298.42,23328.494,0 }, 0 }; };
							class redzone_molosBay_area_5 : redzone_molosBay_area_3 { position[] = { { 26731.02,22887.184,0 }, 0 }; };
							class redzone_molosBay_area_6 : redzone_molosBay_area_3 { 
								position[] = { { 28102.146,25521.754,0 }, 0 }; 
								size[] = { 500, 500 };
							};

							// SPAWN
							class greenzone_molosBay_1 {
								position[] = { { 26664.3,23413.6,0 }, 0 };
                                size[] = { 50, 50 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorGUER";
								alpha = 1;
							};
							class greenzone_molosBay_2 : greenzone_molosBay_1 { position[] = { { 27806.8,25021.1,0 }, 0 }; };
						};
					};

					class MaziBay {
						displayName = "Mazi Bay";
						teleportLocation = "conflict_spawn_maziBay_1";
						position[] = { 20683.1,7598.8,0 };
						class Nodes {
							class HilltopFOB {
								displayName = "Hilltop FOB";
								position[] = { 23038.086,7248.06,0 };
								radius = 20;
							};
							class SlumDistrict {
								displayName = "Slum District";
								position[] = { 20782.811,6677.967,0 };
								radius = 30;
							};
							class CoastalSlums : HilltopFOB {
								displayName = "Coastal Slums";
								position[] = { 18323.123,7889.507,0 };
							};
							class FeresIndustrial : HilltopFOB {
								displayName = "Feres Industrial";
								position[] = { 21669.04,7793.098,0 };
							};
							class PanagiaIndustrial : SlumDistrict {
								displayName = "Panagia Industrial";
								position[] = { 20254.29,8827.530,0 };
							};
							class OldManor : SlumDistrict {
								displayName = "Old Manor";
								position[] = { 18920.639,6713.967,0 };
							};
							class CoastalRuins : HilltopFOB {
								displayName = "Coastal Ruins";
								position[] = { 22290.078,5082.461,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_maziBay_border_1 {
								position[] = { { 18408.363,8269.902,0 }, 57.712 };
                                size[] = { 75, 500 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_maziBay_border_2 : redzone_maziBay_border_1 { position[] = { { 19256.285,8794.182,0 }, 58.815 }; };
							class redzone_maziBay_border_3 : redzone_maziBay_border_1 { position[] = { { 20138.242,9227.153,0 }, 68.900 }; };
							class redzone_maziBay_border_4 : redzone_maziBay_border_1 { position[] = { { 21079.316,9529.240,0 }, 75.522 }; };
							class redzone_maziBay_border_5 : redzone_maziBay_border_1 { position[] = { { 21825.027,9306.355,0 }, 317.740 }; };
							class redzone_maziBay_border_6 : redzone_maziBay_border_1 { position[] = { { 22535.738,8620.838,0 }, 310.222 }; };
							class redzone_maziBay_border_7 : redzone_maziBay_border_1 { position[] = { { 23158.82,7888.427,0 }, 329.016 }; };
							class redzone_maziBay_border_8 : redzone_maziBay_border_1 { position[] = { { 23300.871,7026.325,0 }, 12.289 }; };
							class redzone_maziBay_border_9 : redzone_maziBay_border_1 { position[] = { { 23034.984,6074.065,0 }, 18.883 }; };
							class redzone_maziBay_border_10 : redzone_maziBay_border_1 { position[] = { { 22620.22,5189.101,0 }, 31.333 }; };
							class redzone_maziBay_border_11 : redzone_maziBay_border_1 { position[] = { { 21922.488,4779.213,0 }, 87.836 }; };
							class redzone_maziBay_border_12 : redzone_maziBay_border_1 { position[] = { { 20966.482,4892.945,0 }, 105.730 }; };
							class redzone_maziBay_border_13 : redzone_maziBay_border_1 { position[] = { { 20019.887,5194.219,0 }, 109.500 }; };
							class redzone_maziBay_border_14 : redzone_maziBay_border_1 { position[] = { { 19072.703,5500.813,0 }, 106.330 }; };
							class redzone_maziBay_border_15 : redzone_maziBay_border_1 { position[] = { { 18407.684,6047.466,0 }, 332.495 }; };
							class redzone_maziBay_border_16 : redzone_maziBay_border_1 { position[] = { { 17910.848,6901.813,0 }, 327.171 }; };
							class redzone_maziBay_border_17 : redzone_maziBay_border_1 { 
								position[] = { { 17825.865,7644.127,0 }, 25.359 }; 
								size[] = { 75, 434.617 };
							};

							// AREA
							class redzone_maziBay_area_1 {
								position[] = { { 21854.193,07186.747,0 }, 0 };
                                size[] = { 1500, 1500 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 0;
							};
							class redzone_maziBay_area_2 : redzone_maziBay_area_1 { position[] = { { 21254.18,6322.877,0 }, 0 }; };
							class redzone_maziBay_area_3 : redzone_maziBay_area_1 { position[] = { { 20256.572,6666.255,0 }, 0 }; };
							class redzone_maziBay_area_4 : redzone_maziBay_area_1 { position[] = { { 19924.037,7486.754,0 }, 0 }; };
							class redzone_maziBay_area_5 : redzone_maziBay_area_1 { 
								position[] = { { 21846.963,5712.019,0 }, 0 }; 
								size[] = { 1000, 1000 };
							};
							class redzone_maziBay_area_6 : redzone_maziBay_area_5 { position[] = { { 19237.275,6496.373,0 }, 0 }; };
							class redzone_maziBay_area_7 : redzone_maziBay_area_5 { position[] = { { 18734.855,7360.245,0 }, 0 }; };
							class redzone_maziBay_area_8 : redzone_maziBay_area_5 { position[] = { { 20310.785,8303.637,0 }, 0 }; };
							class redzone_maziBay_area_9 : redzone_maziBay_area_5 { position[] = { { 21212.928,8608.659,0 }, 0 }; };

							// SPAWN
							class greenzone_maziBay_1 {
								position[] = { { 21483,8401.89,0 }, 0 };
                                size[] = { 50, 50 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorGUER";
								alpha = 1;
							};
							class greenzone_maziBay_2 : greenzone_maziBay_1 { position[] = { { 19638.2,7770.83,0 }, 0 }; };
							class greenzone_maziBay_3 : greenzone_maziBay_1 { position[] = { { 21879.5,6624.61,0 }, 0 }; };
						};
					};

					class Frini {
						displayName = "Frini";
						teleportLocation = "conflict_spawn_frini_1";
						position[] = { 14610.4,21899.1,0 };
						class Nodes {
							class MilitaryBase {
								displayName = "Military Base";
								position[] = { 14209.157,21206.473,0 };
								radius = 30;
							};
							class TownCentre : MilitaryBase {
								displayName = "Town Centre";
								position[] = { 14611.727,20773.826,0 };
							};
							class ForestCamp {
								displayName = "Forest Camp";
								position[] = { 14283.402,21832.576,0 };
								radius = 10;
							};
							class OldHouse {
								displayName = "Old House";
								position[] = { 13445.446,22652.21,0 };
								radius = 15;
							};
							class Ruins : MilitaryBase {
								displayName = "Ruins";
								position[] = { 15835.58,21266.387,0 };
							};
							class CoastalDefence : MilitaryBase {
								displayName = "Coastal Defence";
								position[] = { 15028.732,22741.316,0 };
							};
							class RandomHouse : OldHouse {
								displayName = "Random House";
								position[] = { 13445.246,21614.92,0 };
							};
						};
						class Markers {
							// BORDER
							class redzone_frini_border_1 {
								position[] = { { 17295.238,22223.703,0 }, 327.570 };
                                size[] = { 75, 500 };
								shape = "RECTANGLE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 1;
							};
							class redzone_frini_border_2 : redzone_frini_border_1 { position[] = { { 17212.45,21550.764,0 }, 46.4 }; };
							class redzone_frini_border_3 : redzone_frini_border_1 { position[] = { { 16420.078,20999.63,0 }, 64.054 }; };
							class redzone_frini_border_4 : redzone_frini_border_1 { position[] = { { 15527.152,20562.26,0 }, 63.729 }; };
							class redzone_frini_border_5 : redzone_frini_border_1 { position[] = { { 14612.598,20302.215,0 }, 84.574 }; };
							class redzone_frini_border_6 : redzone_frini_border_1 { position[] = { { 13763.214,20536.396,0 }, 126.352 }; };
							class redzone_frini_border_7 : redzone_frini_border_1 { position[] = { { 13008.367,21170.697,0 }, 133.704 }; };
							class redzone_frini_border_8 : redzone_frini_border_1 { position[] = { { 12698.009,21956.697,0 }, 3.208 }; };
							class redzone_frini_border_9 : redzone_frini_border_1 { position[] = { { 13022.678,22800.604,0 }, 38.979 }; };
							class redzone_frini_border_10 : redzone_frini_border_1 { position[] = { { 13753.7,23406.39,0 }, 61.692 }; };
							class redzone_frini_border_11 : redzone_frini_border_1 { position[] = { { 14658.131,23652.39,0 }, 87.823 }; };
							class redzone_frini_border_12 : redzone_frini_border_1 { 
								position[] = { { 15511.483,23315.885,0 }, 132.95 }; 
								size[] = { 75, 557.886 };
							};
							class redzone_frini_border_13 : redzone_frini_border_1 { 
								position[] = { { 16478.234,22782.566,0 }, 105.929 }; 
								size[] = { 75, 614.904 };
							};

							// AREA
							class redzone_frini_area_1 {
								position[] = { { 14621.484,21751.717,0 }, 0 };
                                size[] = { 1500, 1500 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorEAST";
								alpha = 0;
							};
							class redzone_frini_area_2 : redzone_frini_area_1 { 
								position[] = { { 13653.126,21885.37,0 }, 0 }; 
								size[] = { 1000, 1000 };
							};
							class redzone_frini_area_3 : redzone_frini_area_2 { position[] = { { 13872.520,22311.553,0 }, 0 }; };
							class redzone_frini_area_4 : redzone_frini_area_2 { position[] = { { 14379.394,22626.768,0 }, 0 }; };
							class redzone_frini_area_5 : redzone_frini_area_2 { position[] = { { 14881.227,22629.295,0 }, 0 }; };
							class redzone_frini_area_6 : redzone_frini_area_2 { position[] = { { 15786.542,21961.025,0 }, 0 }; };
							class redzone_frini_area_7 : redzone_frini_area_2 { position[] = { { 15718.457,21718.934,0 }, 0 }; };
							class redzone_frini_area_8 : redzone_frini_area_2 { 
								position[] = { { 16575.855,21897.982,0 }, 0 }; 
								size[] = { 750, 750 };
							};

							// SPAWN
							class greenzone_frini_1 {
								position[] = { { 13931.5,20873.3,0 }, 0 };
                                size[] = { 50, 50 };
								shape = "ELLIPSE";
								brush = "DiagGrid";
								colour = "ColorGUER";
								alpha = 1;
							};
							class greenzone_frini_2 : greenzone_frini_1 { position[] = { { 13031.1,22146.4,0 }, 0 }; };
							class greenzone_frini_3 : greenzone_frini_1 { position[] = { { 15822.8,21724.2,0 }, 0 }; };
						};
					};
				};
			};
		};
	};
};