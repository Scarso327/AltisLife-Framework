class CfgRandomEvents {
	/* TESTING SPAWN VALUES
	SpawnCondition = "true";
	NotifyDelay = 1 * 60;
	Cooldown = 2 * 60;
	RandomAddition = 2 * 60;*/

	InitialDelay = 3 * 60;
	
	class Airdrop {
		SpawnCondition = "(count ([""Civilian""] call ULP_fnc_allMembers)) >= 30";
		NotifyDelay = 10 * 60;
		Cooldown = 40 * 60;
		RandomAddition = 20 * 60;
		class BaseWars {
			SpawnCondition = "(count ([""Civilian""] call ULP_fnc_allMembers)) >= 15";
			NotifyDelay = 5 * 60;
			Cooldown = 20 * 60;
			RandomAddition = 5 * 60;
		};
		class Debug {
			SpawnCondition = "true";
			NotifyDelay = 2 * 60;
			Cooldown = 5 * 60;
			RandomAddition = 1 * 60;
		};
		class Events {
			class OnWarning { code = "_this params [[""_message"", """", [""""]]]; [_message] call ULP_fnc_hint;"; };
			class OnSpawn { code = "_this call ULP_fnc_onAirdropSpawn;"; };
			class OnClaimed { code = "_this params [[""_message"", """", [""""]]]; [_message] call ULP_fnc_hint;"; };
		};
		class ServerFunctions {
			onSpawn = "_this call ULP_SRV_fnc_airdrop;";
			onCompleted = "[_this] call ULP_SRV_fnc_spawnEvent;";
		};
		class Locations {
			// Drops INSIDE redzone
			class D_1 {
				position[] = {9165.79,8538.05,77.361};
				radius = 0;
			};
			class D_2 : D_1 { position[] = {9786.08,9421.7,55.6239}; };
			class D_3 : D_1 { position[] = {12377.5,9304.05,79.3657}; };
			class D_4 : D_1 { position[] = {12687.2,8225.15,9.85319}; };
			class D_5 : D_1 { position[] = {11718.9,8308.91,85.8831}; };
			class D_6 : D_1 { position[] = {11405.5,8240.43,134.813}; };
			class D_7 : D_1 { position[] = {10810.6,8105.16,105.331}; };
			class D_8 : D_1 { position[] = {10674.3,8427.96,72.9035}; };
			class D_9 : D_1 { position[] = {10211.3,8089.07,52.5622}; };
			class D_10 : D_1 { position[] = {9899.53,7495.14,100.983}; };
			class D_11 : D_1 { position[] = {10533.8,7132.13,143.591}; };
			class D_12 : D_1 { position[] = {10983.7,6891.62,149.694}; };
			class D_13 : D_1 { position[] = {13335.3,6591.93,36.947}; };
			class D_14 : D_1 { position[] = {12029.5,6733.74,81.2849}; };
			class D_15 : D_1 { position[] = {11848,7171.81,177.635}; };
			class D_16 : D_1 { position[] = {12151.5,7591.27,219.947}; };
			class D_17 : D_1 { position[] = {9774.65,8282.19,82.6306}; };
			class D_18 : D_1 { position[] = {11282.7,9202.61,79.3864}; };
			class D_19 : D_1 { position[] = {10149.5,9360.57,60.7545}; };
			class D_20 : D_1 { position[] = {12005.5,8911.8,65.3659}; };
			class D_21 : D_1 { position[] = {12084.9,9548.04,53.2381}; };
			class D_22 : D_1 { position[] = {12110.1,9705.98,29.1991}; };
			class D_23 : D_1 { position[] = {12385.1,10008.6,5.2118}; };
			class D_24 : D_1 { position[] = {11911.9,10445.5,12.1701}; };
			class D_25 : D_1 { position[] = {12789.9,9660.04,9.26665}; };
			class D_26 : D_1 { position[] = {10623.9,10072.3,17.0309}; };
			class D_27 : D_1 { position[] = {13170.9,7526.69,12.7628}; };
			class D_28 : D_1 { position[] = {10820.1,8891.23,62.7135}; };
			class D_29 : D_1 { position[] = {10482.7,9071.13,27.7921}; };
			class D_30 : D_1 { position[] = {10561.8,9225.02,36.2736}; };

			// Drops OUTSIDE redzone
			class D_31 {
				position[] = {21991.9,5405.2,9.4972};
				radius = 300;
			};
			class D_32 : D_31 { position[] = {21378.3,6078.43,29.702}; };
			class D_33 : D_31 { position[] = {21617.2,6409.82,18.0052}; };
			class D_34 : D_31 { position[] = {23096.3,6994.18,14.2764}; };
			class D_35 : D_31 { position[] = {23013.4,7496.05,18.3002}; };
			class D_36 : D_31 { position[] = {17416.7,9111.36,79.9217}; };
			class D_37 : D_31 { position[] = {17083.2,9129.42,92.0351}; };
			class D_38 : D_31 { position[] = {16755.4,9549.69,84.5089}; };
			class D_39 : D_31 { position[] = {16262.4,9546.67,19.3067}; };
			class D_40 : D_31 { position[] = {16513.3,9124.51,17.4657}; };
			class D_41 : D_31 { position[] = {18100,9500.49,114.426}; };
			class D_42 : D_31 { position[] = {18738.9,9727.68,123.674}; };
			class D_43 : D_31 { position[] = {19499.1,9925.84,164.749}; };
			class D_44 : D_31 { position[] = {22319,8244.17,34.1884}; };
			class D_45 : D_31 { position[] = {19172,9169.18,83.8668}; };
			class D_46 : D_31 { position[] = {18903.1,9383.18,142.241}; };
			class D_47 : D_31 { position[] = {19865.3,9320.71,73.9923}; };
			class D_48 : D_31 { position[] = {20144.7,8049.88,40.447}; };
			class D_49 : D_31 { position[] = {18444.1,8339.25,13.2348}; };
			class D_50 : D_31 { position[] = {21625.4,8800.08,54.836}; };
		};
	};

	class Shipwreck : Airdrop {
		SpawnCondition = "(count ([""Civilian""] call ULP_fnc_allMembers)) >= 20";
		NotifyDelay = 10 * 60;
		Cooldown = 15 * 60;
		RandomAddition = 15 * 60;
		class Events : Events {
			class OnSpawn { code = "_this call ULP_fnc_onShipwreckSpawn;"; };
			class OnClaimed : OnWarning {};
		};
		class ServerFunctions : ServerFunctions {
			onSpawn = "_this call ULP_SRV_fnc_shipwreck;";
		};
		class Locations {
			class S_1 { position[] = {14857.2,14729.8,-57.795}; };
			class S_2 { position[] = {16086.8,14331.9,-65.5553}; };
			class S_3 { position[] = {15603,13635.9,-82.0443}; };
			class S_4 { position[] = {13927,14006.1,-47.0784}; };
			class S_5 { position[] = {15816.5,15064.2,-63.2164}; };
			class S_6 { position[] = {15499.1,12599,-116.909}; };
			class S_7 { position[] = {13722.8,10480,-145.37}; };
			class S_8 { position[] = {15098.7,9792.66,-56.0804}; };
			class S_9 { position[] = {14121.8,8937.76,-174.156}; };
			class S_10 { position[] = {15641.7,8696.38,-115.562}; };
			class S_11 { position[] = {16862.1,8208.88,-95.4975}; };
			class S_12 { position[] = {17329.8,7046.91,-101.64}; };
			class S_13 { position[] = {15361.7,7696.47,-166.676}; };
			class S_14 { position[] = {16271.1,5895.68,-161.293}; };
			class S_15 { position[] = {12652.9,11423.9,-42.2609}; };
			class S_16 { position[] = {17610.4,5273.2,-164.772}; };
			class S_17 { position[] = {996.547,10097.8,-144.508}; };
			class S_18 { position[] = {1540.51,11261.9,-129.763}; };
			class S_19 { position[] = {1882.28,12129.8,-123.455}; };
			class S_20 { position[] = {2343.05,10633.5,-61.2276}; };
			class S_21 { position[] = {1586.08,9034.17,-139.048}; };
			class S_22 { position[] = {731.788,12547.4,-187.761}; };
			class S_23 { position[] = {1780.23,13943.4,-180.012}; };
			class S_24 { position[] = {1337.5,15589.7,-186.649}; };
			class S_25 { position[] = {2830.89,15897.7,-159.086}; };
			class S_26 { position[] = {2836.11,14970.3,-137.391}; };
			class S_27 { position[] = {1892.86,17074.1,-141.861}; };
			class S_28 { position[] = {3201.38,7993.27,-172.275}; };
			class S_29 { position[] = {1228.26,7368.81,-185.97}; };
			class S_30 { position[] = {5201.15,8153.25,-133.185}; };
		};
	};

	class PopupCartel : Airdrop {
		SpawnCondition = "([[""Civilian""]] call ULP_fnc_onlineFaction) >= 20";
		NotifyDelay = 10 * 60;
		Cooldown = 25 * 60;
		RandomAddition = 10 * 60;
		SyndicateChance = 0.4;
		SyndicateCondition = "([[""Civilian""]] call ULP_fnc_onlineFaction) >= 50";
		class Events : Events {
			class OnSpawn { code = "_this call ULP_fnc_onPopupCartelSpawn;"; };
			class OnClaimed { code = "_this params [[""_message"", """", [""""]], [""_reward"", -1, [0]]]; [_reward, false, ""Popup Cartel""] call ULP_fnc_addMoney; if (_reward > 0) then { [400, ""Captured Popup Cartel""] call ULP_fnc_addXP; }; [_message] call ULP_fnc_hint;"; };
		};
		class ServerFunctions : ServerFunctions {
			onSpawn = "_this call ULP_SRV_fnc_popupCartel;";
		};
		class Locations {
			class C_1 {
				position[] = {9210.5,19276.3,0};
				captureRadius = 50;
				radius = 200;
			};
			class C_2 : C_1 { position[] = {14206.9,21219,0}; };
			class C_3 : C_1 { position[] = {16598.7,19040,0}; };
			class C_4 : C_1 { position[] = {12811.7,16674.4,0}; };
			class C_5 : C_1 { position[] = {12445.1,15198.7,0}; };
			class C_6 : C_1 { position[] = {11432.2,14245,0}; };
			class C_7 : C_1 { position[] = {7889.41,14626.5,0}; };
			class C_8 : C_1 { position[] = {4215.98,15055.8,0}; };
			class C_9 : C_1 { position[] = {3058.21,13196.5,0}; };
			class C_10 : C_1 { position[] = {8316.54,10060.8,0}; };
			class C_11 : C_1 { position[] = {8228.12,10893.9,0}; };
			class C_12 : C_1 { position[] = {18371.3,15505.3,0}; };
			class C_13 : C_1 { position[] = {23008.3,7254.5,0}; };
			class C_14 : C_1 { position[] = {21329.2,17220.2,0}; };
			class C_15 : C_1 { position[] = {23624.4,21077,0}; };
		};
	};
};