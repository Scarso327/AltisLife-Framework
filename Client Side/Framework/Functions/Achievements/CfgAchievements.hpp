class CfgAchievements {
	class FirstSpawn {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa";
		displayName = "First Steps";
		description = "Spawned for the first time";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class FirstDrink {
		icon = "Data\UI\Achievements\firstDrink.paa";
		displayName = "Big Drink";
		description = "Taken your first drink of alcohol";
		onUnlocked = "[""FirstDrink""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class FirstDrug {
		icon = "Data\UI\Achievements\firstDrug.paa";
		displayName = "Druggie";
		description = "Had your first drug experience";
		onUnlocked = "[""FirstDrug""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class GirlsBestFriend {
		icon = "Data\UI\Achievements\girlsBestFriend.paa";
		displayName = "Girl's Best Friend";
		description = "Acquired a finely cut diamond";
		onUnlocked = "[""GirlsBestFriend""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class Salty {
		icon = "Data\UI\Achievements\salty.paa";
		displayName = "Extremely Salty";
		description = "Held a vast amount of salt on your person";
		onUnlocked = "[""Salty""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Captain {
		icon = "Data\UI\Achievements\captain.paa";
		displayName = "Ship Captain";
		description = "Visited the command deck of the HMS Liberty";
		onUnlocked = "[""Captain""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Archaeologist {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Waypoint_ca.paa";
		displayName = "Archaeologist";
		description = "Carried out your first archaeological dig";
		onUnlocked = "[""Archaeologist""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinRebel {
		icon = "Data\UI\Achievements\rebel.paa";
		displayName = "The Rebellion";
		description = "Joined the Rebellion. Hope";
		onUnlocked = "[""JoinRebel""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinGroup {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
		displayName = "Group Member";
		description = "Joined a group for the first time";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinStaff {
		icon = "Data\UI\Achievements\staff.paa";
		displayName = "Staff Team";
		description = "You have joined the community's Staff Team";
		onUnlocked = "[""JoinStaff""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinAPC {
		icon = "Data\UI\Achievements\APC.paa";
		displayName = "Constable";
		description = "Joined the Altis Police";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinCOL {
		icon = "Data\UI\Achievements\COL.paa";
		displayName = "College Instructor";
		description = "Joined the College of Policing";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinNPAS {
		icon = "Data\UI\Achievements\NPAS.paa";
		displayName = "Police Pilot";
		description = "Joined NPAS";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinSCO19 {
		icon = "Data\UI\Achievements\SCO.paa";
		displayName = "Firearms Officer";
		description = "Joined SCO19";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinNCA {
		icon = "Data\UI\Achievements\NCA.paa";
		displayName = "Intel Officer";
		description = "Joined NCA";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinMPU {
		icon = "Data\UI\Achievements\MPU.paa";
		displayName = "Police Marine";
		description = "Joined MPU";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinRPU {
		icon = "Data\UI\Achievements\RPU.paa";
		displayName = "Pursuit Specialist";
		description = "Joined RPU";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinSFO {
		icon = "Data\UI\Achievements\SFO.paa";
		displayName = "Confused AFO";
		description = "Trained as a Police AFO";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinUC {
		icon = "Data\UI\Achievements\UC.paa";
		displayName = "Secret Constable";
		description = "Trained as a Police Covert Officer";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstTicket {
		icon = "Data\UI\Achievements\firstTicket.paa";
		displayName = "Ticketer";
		description = "Issued a Fixed Penalty Notice";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstArrest {
		icon = "Data\UI\Achievements\firstArrest.paa";
		displayName = "Law Enforcer";
		description = "Sent someone to prison at His Majesty's Pleasure";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinNHS {
		icon = "Data\UI\Achievements\NHS.paa";
		displayName = "Paramedic";
		description = "Joined the Altis Ambulance Service";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinHR {
		icon = "Data\UI\Achievements\HR.paa";
		displayName = "Desk Worker";
		description = "Joined the NHS Human Resources Dept.";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinAA {
		icon = "Data\UI\Achievements\AA.paa";
		displayName = "Air Saviour";
		description = "Joined the Altis Air Ambulance";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class LifeSaver {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Injury_ca.paa";
		displayName = "Life Saver";
		description = "Successfully saved a life";
		onUnlocked = "[""LifeSaver""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinHATO {
		icon = "Data\UI\Achievements\HATO.paa";
		displayName = "Traffic Officer";
		description = "Joined the Highways Agency";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstImpound {
		icon = "Data\UI\Achievements\firstImpound.paa";
		displayName = "Street Cleaner";
		description = "Impounded a vehicle for the first time";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstCrush {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Use_ca.paa";
		displayName = "Vehicle Scrapper";
		description = "Crushed/Chopped a vehicle for the first time";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Governor {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Rules_ca.paa";
		displayName = "Governor";
		description = "Win an election and become the Governor";
		onUnlocked = "[""Governor""] call ULP_fnc_unlockTitle;";
		leveling[] = { 5000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Employment {
		icon = "Data\UI\Achievements\employment.paa";
		displayName = "Employment";
		description = "Successfully become employed";
		onUnlocked = "[""Employment""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Convict {
		icon = "\A3\ui_f_orange\data\CfgHints\codeofconduct4_ca.paa";
		displayName = "Convict";
		description = "Served at His Majesty's Pleasure";
		onUnlocked = "[""Convict""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class SuccessfulRobber {
		icon = "Data\UI\Achievements\successfulRobber.paa";
		displayName = "Successful Robber";
		description = "Successfully carried out a robbery";
		onUnlocked = "[""SuccessfulRobber""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class TaskMaster {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Tasks_ca.paa";
		displayName = "Task Master";
		description = "Completed a task for the first time";
		onUnlocked = "[""TaskMaster""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class CartelLord {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Miss_icon_ca.paa";
		displayName = "Cartel Lord";
		description = "Successfully received a payout from a cartel";
		onUnlocked = "[""Cartel""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class BuyVehicle {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Driving_ca.paa";
		displayName = "First Ride";
		description = "Bought your first vehicle";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class BuyHouse {
		icon = "Data\UI\Achievements\house.paa";
		displayName = "First House";
		description = "Bought your first house";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class BuyWarehouse {
		icon = "Data\UI\Achievements\warehouse.paa";
		displayName = "First Warehouse";
		description = "Bought your first warehouse";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Carrier {
		icon = "\A3\ui_f_jets\data\GUI\Cfg\Hints\AircraftLandCarrier_ca.paa";
		displayName = "Floating Fortress";
		description = "Landed on the USS Freedom";
		onUnlocked = "[""Carrier""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Bomb {
		icon = "\A3\ui_f_orange\data\CfgHints\uxo_ca.paa";
		displayName = "You idiot";
		description = "Who steps on what is clearly a bomb";
		onUnlocked = "[""Bomb""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Judge {
		icon = "\A3\ui_f_orange\data\CfgHints\loac_ca.paa";
		displayName = "Judging Others";
		description = "You have sat in judgement of another";
		onUnlocked = "[""Judge""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class CombatMedic {
		icon = "\A3\ui_f_orange\data\CfgHints\codeofconduct3_ca.paa";
		displayName = "Combat Medic";
		description = "Entered the heart of the redzone as a medic";
		onUnlocked = "[""CombatMedic""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class OneMillion {
		icon = "Data\UI\Achievements\money1.paa";
		displayName = "£1,000,000";
		description = "Had a total of £1,000,000 in your bank";
		onUnlocked = "[""OneMillion""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class TenMillion {
		icon = "Data\UI\Achievements\money10.paa";
		displayName = "£10,000,000";
		description = "Had a total of £10,000,000 in your bank";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class HundredMillion {
		icon = "Data\UI\Achievements\money100.paa";
		displayName = "£100,000,000";
		description = "Had a total of £100,000,000 in your bank";
		leveling[] = { 5000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Barrel {
		icon = "Data\UI\Achievements\barrel.paa";
		displayName = "The Barrel";
		description = "Found the mysterious hidden barrel";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};
	
	class Prestige {
		icon = "Data\UI\Achievements\prestige.paa";
		displayName = "Prestigious";
		description = "Prestiged for the first time";
		onUnlocked = "[""Prestige""] call ULP_fnc_unlockTitle;";
		leveling[] = { 10000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	// TODO
	class FanGirl {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\PilotingQuadrotor_ca.paa";
		displayName = "Fan Girl";
		description = "You have discovered the pleasure in Belle Delphine.";
		onUnlocked = "[""FanGirl""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Uncharted {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Map_ca.paa";
		displayName = "Explorer";
		description = "You have chosen to leave this island, but you will return";
		onUnlocked = "[""Uncharted""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Radiation {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
		displayName = "Goodbye Fatherhood";
		description = "Experienced the effects of radiation poisoning";
		onUnlocked = "[""Radiation""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Protest {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Voice_ca.paa";
		displayName = "Protester";
		description = "You have taken a simple protest to the extreme...";
		onUnlocked = "[""Protest""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class MileHighClub {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\TakeOff_ca.paa";
		displayName = "Mile High Club";
		description = "You have flown roughly a mile in the sky";
		onUnlocked = "[""MileHighClub""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class DeepSeaDiver {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicDive_ca.paa";
		displayName = "Deep Sea Diver";
		description = "You taken a dive deep into the sea";
		onUnlocked = "[""DeepSeaDiver""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class DeathWish {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Targets_ca.paa";
		displayName = "Death Wish";
		description = "You have traveled to the heart of the red zone";
		onUnlocked = "[""DeathWish""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Racing {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Time_trials_ca.paa";
		displayName = "Racing Around";
		description = "You've visited the race track";
		onUnlocked = "[""Racing""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Nothing {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicLook_ca.paa";
		displayName = "Nothingness";
		description = "You've found nothing surrounded by more nothing";
		onUnlocked = "[""Nothing""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class NLRPC {
		icon = "Data\UI\Achievements\nlrpc.paa";
		displayName = "NLRPC";
		description = "You have discovered a remnant of North London";
		onUnlocked = "[""NLRPC""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Stonehenge {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Direction_ca.paa";
		displayName = "Stonehenge";
		description = "You have discovered the Stonehenge on Altis";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Sub {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\SDV_ca.paa";
		displayName = "Submarine";
		description = "You have walked on top of the HMS Proteus";
		onUnlocked = "[""Sub""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class PirateDen {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Death_ca.paa";
		displayName = "Pirate Den";
		description = "You have discovered a Pirate Den on Altis";
		onUnlocked = "[""PirateDen""] call ULP_fnc_unlockTitle;";
		leveling[] = { 2000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Atlantis {
		icon = "Data\UI\Achievements\atlantis.paa";
		displayName = "Atlantis";
		description = "You have discovered Atlantis on Altis";
		onUnlocked = "[""Atlantis""] call ULP_fnc_unlockTitle;";
		leveling[] = { 3000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Spawn {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Zeus_ca.paa";
		displayName = "Spawn";
		description = "You have discovered the spawn of mankind";
		onUnlocked = "[""SpawnCamp""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class BrokenNLR {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Timing_ca.paa";
		displayName = "Rule Breaker";
		description = "You have broken the rules. You should be banned";
		onUnlocked = "[""RuleBreaker""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Surrender {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Checkpoints_ca.paa";
		displayName = "Basically French";
		description = "You placed your hands on your head";
		onUnlocked = "[""Frenchman""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class KnockOut {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Switch_ca.paa";
		displayName = "Professional Boxer";
		description = "Hit someone so hard it knocked them out";
		onUnlocked = "[""ProfessionalBoxer""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Snoop {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Head_ca.paa";
		displayName = "Professional Snoop";
		description = "You clearly downloaded the mission.sqm";
		onUnlocked = "[""Snoop""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class SeizedComms {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\ActionMenu_ca.paa";
		displayName = "Phone Snatcher";
		description = "You stole someone's communications while vulnerable";
		onUnlocked = "[""PhoneSnatcher""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Restrain {
		icon = "Data\UI\Achievements\convict.paa";
		displayName = "Bondage Enthusiast";
		description = "Apparently you like to restrain people";
		onUnlocked = "[""BondageEnthusiast""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Overweight {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Fatigue_ca.paa";
		displayName = "Over-Encumbered";
		description = "You tried carrying more than you can handle";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class ClampVeh {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\ShootingBoxes_ca.paa";
		displayName = "Traffic Warden";
		description = "Can't park there Sir...";
		onUnlocked = "[""TrafficWarden""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class ChopVeh {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\VehicleGetOut_CA.paa";
		displayName = "Vehicle Chopper";
		description = "Torn apart a vehicle for money";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class LockpickVeh {
		icon = "Data\UI\GroupBuffs\lockpicking.paa";
		displayName = "Locksmith";
		description = "Successfully broken a lock using lockpicks";
		onUnlocked = "[""Locksmith""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class RepairVeh {
		icon = "Data\UI\Perks\scrapDealer.paa";
		displayName = "Mechanic";
		description = "You managed to repair a vehicle by yourself";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class IssueWarrant {
		icon = "Data\UI\Perks\completedCV.paa";
		displayName = "Keyboard Warrior";
		description = "Issued a warrant using the PNC";
		onUnlocked = "[""KeyboardWarrior""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Placeables {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicMove_ca.paa";
		displayName = "World Builder";
		description = "You've placed an object. You're basically a map dev";
		onUnlocked = "[""WorldBuilder""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class GivenBlood {
		icon = "Data\UI\Perks\bloodCarrier.paa";
		displayName = "Blood Donor";
		description = "You've given someone blood. Not sure who's blood...";
		onUnlocked = "[""BloodDonor""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class TakeLicense {
		icon = "\A3\ui_f_orange\data\CfgHints\leaflets_ca.paa";
		displayName = "License Thief";
		description = "You have revoked a person's license";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Blindfold {
		icon = "\A3\ui_f_orange\data\CfgHints\codeofconduct3_ca.paa";
		displayName = "Blind Man Walking";
		description = "Some point, by someone, you've been blindfolded";
		onUnlocked = "[""BlindManWalking""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class DisguiseID {
		icon = "Data\UI\GroupPerks\blackmarket.paa";
		displayName = "Faceless Man";
		description = "All men must serve. Faceless Men most of all";
		onUnlocked = "[""FacelessMan""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Panic {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\NormalDamage_ca.paa";
		displayName = "Fight or Flight";
		description = "You've been in an absolute state of panic... or misclicked";
		onUnlocked = "[""FightFlight""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class SafetyFirst {
		icon = "Data\UI\Perks\secondNature.paa";
		displayName = "Safety First";
		description = "You put your seatbelt on in a car";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Voter {
		icon = "Data\UI\Perks\governmentBonus.paa";
		displayName = "I love Democracy";
		description = "I love Democracy... and I love the Republic";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Forger {
		icon = "Data\UI\Perks\idForger.paa";
		displayName = "White-Collar Criminal";
		description = "You've expertly forged an ID card";
		onUnlocked = "[""WhiteCollarCriminal""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Deconstructing {
		icon = "Data\UI\Perks\generalMechanic.paa";
		displayName = "Demolition Man";
		description = "You've broken down an item in your inventory";
		onUnlocked = "[""DemolitionMan""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// PERSONAL ACHIEVEMENTS
	class Scarso {
		icon = "Data\UI\Achievements\scarso.paa";
		displayName = "The Workspace";
		description = "You have discovered the workspace of Scarso";
		onUnlocked = "[""Scarso""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Lewis {
		icon = "Data\UI\Achievements\lewis.paa";
		displayName = "Bushmaker";
		description = "You have climbed the statue of Lewis 'Bushmaker' Holloway";
		onUnlocked = "[""Lewis""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Oliver {
		icon = "Data\UI\Achievements\oliver.paa";
		displayName = "Nationalist";
		description = "You have visited Oliver's 'metropolitan hub of the North'";
		onUnlocked = "[""Oliver""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Ace {
		icon = "Data\UI\Achievements\ace.paa";
		displayName = "Norwegian Retreat";
		description = "You have located the hidden retreat of Ace Boyden";
		onUnlocked = "[""Ace""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Jetan {
		icon = "Data\UI\Achievements\jetan.paa";
		displayName = "Boat Boy";
		description = "You have boarded the home of one Jetan Holo";
		onUnlocked = "[""Jetan""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Brick {
		icon = "Data\UI\Perks\firstAider.paa";
		displayName = "Brick Hospital";
		description = "You have found the second home of Brick Haus";
		onUnlocked = "[""Brick""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class James {
		icon = "Data\UI\Perks\improvedMetabolism.paa";
		displayName = "Uber Eats Boat";
		description = "You have identified James Johnson's daily food delivery";
		onUnlocked = "[""James""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Fulton {
		icon = "Data\UI\GroupBuffs\hacking.paa";
		displayName = "1-0-ALPHA-NOVEMBER";
		description = "You have viewed the CPU of Fulton";
		onUnlocked = "[""Fulton""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Freddie {
		icon = "Data\UI\Perks\muscleman.paa";
		displayName = "Chicken Deboner";
		description = "The aftermath of Freddie deboning a chicken";
		onUnlocked = "[""Freddie""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};
};