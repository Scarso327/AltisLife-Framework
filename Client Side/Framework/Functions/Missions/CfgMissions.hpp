class CfgMissions {
	class Delivery {
		name = "Delivery Mission";
		description = "You need to deliver the given package to %1";
		factions[] = { "Civilian" };
		eachFrame = "";
		onClaimed = "";
		onFinished = "";
		class Locations {
			class DP1 {
				pos = "DP_1";
				name = "Delivery Point 1";
			};
			class DP2 {
				pos = "DP_2";
				name = "Delivery Point 2";
			};
			class DP3 {
				pos = "DP_3";
				name = "Delivery Point 3";
			};
		};
		class Rewards {
			moneyReward = 10;
			xpReward = 150; // Flat rate...
		};
		class Messages {
			onFinishWithoutMission = "You don't have any packages to deliver here...";
			onAlreadyHas = "You already have a delivery mission active, complete it before requesting another...";
			onNoLocations = "There are currently no delivery missions available for pickup, please try again alter...";
			onAssigned = "You have been tasked to deliver this package to %1";
			onFinished = "You have successfully delivered the package, you have been paid £%1";
		};
	};

	class Patrol {
		name = "Patrol Mission";
		description = "You need to patrol %1";
		factions[] = { "Police" };
		eachFrame = "";
		onClaimed = "[ { (player distance _this) <= 10 }, _this, { [""Patrol""] call ULP_fnc_finishMission; } ] call ULP_fnc_waitUntilExecute;";
		onFinished = "";
		class Locations {
			class ArtDealer {
				pos = "art_dealer";
				name = "Art Dealer";
			};
			class KavalaDrugDealer {
				pos = "drug_dealer_2";
				name = "Kavala Drug Dealer";
			};
		};
		class Rewards {
			moneyReward = 5;
			xpReward = 100; // Flat rate...
		};
		class Messages {
			onFinishWithoutMission = "You can't complete a patrol as you haven't been assigned any...";
			onAlreadyHas = "You have already been assigned a patrol, please complete that before requesting another...";
			onNoLocations = "There are no patrols available, please try again later...";
			onAssigned = "You have been tasked to patrol %1";
			onFinished = "You have successfully completed you patrol assignment, you have been paid a bonus of £%1";
		};
	};

	class Response {
		name = "Response Mission";
		description = "You need to respond to %1";
		factions[] = { "Medic" };
		eachFrame = "";
		onClaimed = "[ { (player distance _this) <= 10 }, _this, { [""Response""] call ULP_fnc_finishMission; } ] call ULP_fnc_waitUntilExecute;";
		onFinished = "";
		class Locations {
			class ArtDealer {
				pos = "art_dealer";
				name = "Art Dealer";
			};
			class KavalaDrugDealer {
				pos = "drug_dealer_2";
				name = "Kavala Drug Dealer";
			};
		};
		class Rewards {
			moneyReward = 5;
			xpReward = 100; // Flat rate...
		};
		class Messages {
			onFinishWithoutMission = "You can't complete a response assignment as you haven't been assigned any...";
			onAlreadyHas = "You have already been assigned a response assignment, please complete that before requesting another...";
			onNoLocations = "There are no assignments available, please try again later...";
			onAssigned = "You have been tasked to respond to %1";
			onFinished = "You have successfully completed you response assignment, you have been paid a bonus of £%1";
		};
	};
};