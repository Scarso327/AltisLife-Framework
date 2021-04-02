class CfgRandomEvents {
	/* TESTING SPAWN VALUES
	SpawnCondition = "true";
	NotifyDelay = 1 * 60;
	SpawnDelay = 1 * 60;
	Cooldown = 2 * 60;
	RandomAddition = 2 * 60;*/
	class Airdrop {
		SpawnCondition = "(count ([""Civilian""] call ULP_fnc_allMembers)) >= 20";
		NotifyDelay = 10 * 60;
		SpawnDelay = 30 * 60;
		Cooldown = 60 * 60;
		RandomAddition = 20 * 60;
		class Events {
			class OnWarning { code = "_this params [[""_message"", """", [""""]]]; hint parseText _message;"; };
			class OnSpawn { code = "_this params [[""_message"", """", [""""]]]; hint parseText _message;"; };
		};
		class ServerFunctions {
			onSpawn = "_this call ULP_SRV_fnc_airdrop;";
			onCompleted = "_this call ULP_SRV_fnc_spawnEvent;";
		};
		class Locations {
			class Test {
				position[] = {8905.64, 7496.92, 0};
				radius = 300;
			};
		};
	};

	class Shipwreck : Airdrop {
		SpawnCondition = "(count ([""Civilian""] call ULP_fnc_allMembers)) >= 5";
		NotifyDelay = 10 * 60;
		SpawnDelay = 20 * 60;
		Cooldown = 40 * 60;
		RandomAddition = 30 * 60;
		class Events : Events {
			class OnSpawn : OnSpawn {};
			class OnClaimed : OnSpawn {};
		};
		class ServerFunctions : ServerFunctions {
			onSpawn = "_this call ULP_SRV_fnc_shipwreck;";
		};
		class Locations {
			class Test {
				position[] = {0, 0, 0};
			};
		};
	};
};