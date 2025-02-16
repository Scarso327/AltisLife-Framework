class CfgAchievements {
	class BaseAchivement100 {
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};
	class BaseAchivement200 : BaseAchivement100 { leveling[] = { 200, "Achievement Unlocked", 100 }; };
	class BaseMysteryAchivement200 : BaseAchivement200 { isMystery = true; };
	class BaseMysteryAchivement1000 : BaseMysteryAchivement200 { leveling[] = { 1000, "Achievement Unlocked", 100 }; };

	// Normal
	class BuyVehicle : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Driving_ca.paa";
		displayName = "First Ride";
		description = "Bought your first vehicle";
		leveling[] = { 50, "Achievement Unlocked", 100 };
	};
	class FirstDrink : BuyVehicle {
		icon = "Data\UI\Achievements\firstDrink.paa";
		displayName = "Big Drink";
		description = "Taken your first drink of alcohol";
		onUnlocked = "[""FirstDrink""] call ULP_fnc_unlockTitle;";
	};
	class FirstSpawn : BuyVehicle {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa";
		displayName = "First Steps";
		description = "Spawned for the first time";
	};
	class Vegan : BuyVehicle {
		icon = "Data\UI\Achievements\vegan.paa";
		displayName = "Veegan";
		description = "I've also eaten... erm... VEEgan sausage rolls";
		onUnlocked = "[""Vegan""] call ULP_fnc_unlockTitle;";
	};

	class Blindfold : BaseAchivement100 {
		icon = "\A3\ui_f_orange\data\CfgHints\codeofconduct3_ca.paa";
		displayName = "Blind Man Walking";
		description = "Some point, by someone, you've been blindfolded";
		onUnlocked = "[""BlindManWalking""] call ULP_fnc_unlockTitle;";
	};
	class BuyHouse : BaseAchivement100 {
		icon = "Data\UI\Achievements\house.paa";
		displayName = "First House";
		description = "Bought your first house";
	};
	class CartelLord : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Miss_icon_ca.paa";
		displayName = "Cartel Lord";
		description = "Successfully received a payout from a cartel";
		onUnlocked = "[""Cartel""] call ULP_fnc_unlockTitle;";
	};
	class ChopVeh : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\VehicleGetOut_CA.paa";
		displayName = "Vehicle Chopper";
		description = "Torn apart a vehicle for money";
	};
	class ClampVeh : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\ShootingBoxes_ca.paa";
		displayName = "Traffic Warden";
		description = "Can't park there Sir...";
		onUnlocked = "[""TrafficWarden""] call ULP_fnc_unlockTitle;";
	};
	class Convict : BaseAchivement100 {
		icon = "\A3\ui_f_orange\data\CfgHints\codeofconduct4_ca.paa";
		displayName = "Convict";
		description = "Served at His Majesty's Pleasure";
		onUnlocked = "[""Convict""] call ULP_fnc_unlockTitle;";
	};
	class FirstDrug : BaseAchivement100 {
		icon = "Data\UI\Achievements\firstDrug.paa";
		displayName = "Druggie";
		description = "Had your first drug experience";
		onUnlocked = "[""FirstDrug""] call ULP_fnc_unlockTitle;";
	};
	class FirstImpound : BaseAchivement100 {
		icon = "Data\UI\Achievements\firstImpound.paa";
		displayName = "Street Cleaner";
		description = "Impounded a vehicle for the first time";
	};
	class FirstTicket : BaseAchivement100 {
		icon = "Data\UI\Achievements\firstTicket.paa";
		displayName = "Ticketer";
		description = "Issued a Fixed Penalty Notice";
	};
	class GirlsBestFriend : BaseAchivement100 {
		icon = "Data\UI\Achievements\girlsBestFriend.paa";
		displayName = "Girl's Best Friend";
		description = "Acquired a finely cut diamond";
		onUnlocked = "[""GirlsBestFriend""] call ULP_fnc_unlockTitle;";
	};
	class GivenBlood : BaseAchivement100 {
		icon = "Data\UI\Perks\bloodCarrier.paa";
		displayName = "Blood Donor";
		description = "You've given someone blood. Not sure who's blood...";
		onUnlocked = "[""BloodDonor""] call ULP_fnc_unlockTitle;";
	};
	class IssueWarrant : BaseAchivement100 {
		icon = "Data\UI\Perks\completedCV.paa";
		displayName = "Keyboard Warrior";
		description = "Issued a warrant using the PNC";
		onUnlocked = "[""KeyboardWarrior""] call ULP_fnc_unlockTitle;";
	};
	class JoinGroup : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
		displayName = "Group Member";
		description = "Joined a group for the first time";
	};
	class KnockOut : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Switch_ca.paa";
		displayName = "Professional Boxer";
		description = "Hit someone so hard it knocked them out";
		onUnlocked = "[""ProfessionalBoxer""] call ULP_fnc_unlockTitle;";
	};
	class LockpickVeh : BaseAchivement100 {
		icon = "Data\UI\GroupBuffs\lockpicking.paa";
		displayName = "Locksmith";
		description = "Successfully broken a lock using lockpicks";
		onUnlocked = "[""Locksmith""] call ULP_fnc_unlockTitle;";
	};
	class Overweight : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Fatigue_ca.paa";
		displayName = "Over-Encumbered";
		description = "You tried carrying more than you can handle";
	};
	class Placeables : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicMove_ca.paa";
		displayName = "World Builder";
		description = "You've placed an object. You're basically a map dev";
		onUnlocked = "[""WorldBuilder""] call ULP_fnc_unlockTitle;";
	};
	class RepairVeh : BaseAchivement100 {
		icon = "Data\UI\Perks\scrapDealer.paa";
		displayName = "Mechanic";
		description = "You managed to repair a vehicle by yourself";
	};
	class Restrain : BaseAchivement100 {
		icon = "Data\UI\Achievements\convict.paa";
		displayName = "Bondage Kink";
		description = "Apparently you like to restrain people";
		onUnlocked = "[""BondageEnthusiast""] call ULP_fnc_unlockTitle;";
	};
	class SafetyFirst : BaseAchivement100 {
		icon = "Data\UI\Perks\secondNature.paa";
		displayName = "Safety First";
		description = "You put your seatbelt on in a car";
	};
	class SeizedComms : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\ActionMenu_ca.paa";
		displayName = "Phone Snatcher";
		description = "You stole someone's communications while vulnerable";
		onUnlocked = "[""PhoneSnatcher""] call ULP_fnc_unlockTitle;";
	};
	class SuccessfulRobber : BaseAchivement100 {
		icon = "Data\UI\Achievements\successfulRobber.paa";
		displayName = "Successful Robber";
		description = "Successfully carried out a robbery";
		onUnlocked = "[""SuccessfulRobber""] call ULP_fnc_unlockTitle;";
	};
	class Surrender : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Checkpoints_ca.paa";
		displayName = "Basically French";
		description = "You placed your hands on your head";
		onUnlocked = "[""Frenchman""] call ULP_fnc_unlockTitle;";
	};
	class TakeLicense : BaseAchivement100 {
		icon = "\A3\ui_f_orange\data\CfgHints\leaflets_ca.paa";
		displayName = "License Thief";
		description = "You have revoked a person's license";
	};
	class TaskMaster : BaseAchivement100 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Tasks_ca.paa";
		displayName = "Task Master";
		description = "Completed a task for the first time";
		onUnlocked = "[""TaskMaster""] call ULP_fnc_unlockTitle;";
	};

	class Archaeologist : BaseAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Waypoint_ca.paa";
		displayName = "Archaeologist";
		description = "Carried out your first archaeological dig";
		onUnlocked = "[""Archaeologist""] call ULP_fnc_unlockTitle;";
	};
	class BuyWarehouse : BaseAchivement200 {
		icon = "Data\UI\Achievements\warehouse.paa";
		displayName = "First Warehouse";
		description = "Bought your first warehouse";
	};
	class CombatMedic : BaseAchivement200 {
		icon = "\A3\ui_f_orange\data\CfgHints\codeofconduct3_ca.paa";
		displayName = "Combat Medic";
		description = "Entered the heart of the redzone as a medic";
		onUnlocked = "[""CombatMedic""] call ULP_fnc_unlockTitle;";
	};
	class Deconstructing : BaseAchivement200 {
		icon = "Data\UI\Perks\generalMechanic.paa";
		displayName = "Demolition Man";
		description = "You've broken down an item in your inventory";
		onUnlocked = "[""DemolitionMan""] call ULP_fnc_unlockTitle;";
	};
	class Employment : BaseAchivement200 {
		icon = "Data\UI\Achievements\employment.paa";
		displayName = "Employment";
		description = "Successfully become employed";
		onUnlocked = "[""Employment""] call ULP_fnc_unlockTitle;";
	};
	class FirstArrest : BaseAchivement200 {
		icon = "Data\UI\Achievements\firstArrest.paa";
		displayName = "Law Enforcer";
		description = "Sent someone to prison at His Majesty's Pleasure";
	};
	class FirstCrush : BaseAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Use_ca.paa";
		displayName = "Vehicle Scrapper";
		description = "Crushed/Chopped a vehicle for the first time";
	};
	class Forger : BaseAchivement200 {
		icon = "Data\UI\Perks\idForger.paa";
		displayName = "White-Collar Criminal";
		description = "You've expertly forged an ID card";
		onUnlocked = "[""WhiteCollarCriminal""] call ULP_fnc_unlockTitle;";
	};
	class JoinAA : BaseAchivement200 {
		icon = "Data\UI\Achievements\AA.paa";
		displayName = "Air Saviour";
		description = "Joined the Altis Air Ambulance";
	};
	class JoinCOL : BaseAchivement200 {
		icon = "Data\UI\Achievements\COL.paa";
		displayName = "College Instructor";
		description = "Joined the College of Policing";
	};
	class JoinHR : BaseAchivement200 {
		icon = "Data\UI\Achievements\HR.paa";
		displayName = "Desk Worker";
		description = "Joined the NHS Human Resources Dept.";
	};
	class JoinMPU : BaseAchivement200 {
		icon = "Data\UI\Achievements\MPU.paa";
		displayName = "Police Marine";
		description = "Joined MPU";
	};
	class JoinNCA : BaseAchivement200 {
		icon = "Data\UI\Achievements\NCA.paa";
		displayName = "Intel Officer";
		description = "Joined NCA";
	};
	class JoinNPAS : BaseAchivement200 {
		icon = "Data\UI\Achievements\NPAS.paa";
		displayName = "Police Pilot";
		description = "Joined NPAS";
	};
	class JoinRebel : BaseAchivement200 {
		icon = "Data\UI\Achievements\rebel.paa";
		displayName = "The Rebellion";
		description = "Joined the Rebellion. Hope";
		onUnlocked = "[""JoinRebel""] call ULP_fnc_unlockTitle;";
	};
	class JoinRPU : BaseAchivement200 {
		icon = "Data\UI\Achievements\RPU.paa";
		displayName = "Pursuit Specialist";
		description = "Joined RPU";
	};
	class JoinSCO19 : BaseAchivement200 {
		icon = "Data\UI\Achievements\SCO.paa";
		displayName = "Firearms Officer";
		description = "Joined SCO19";
	};
	class JoinSFO : BaseAchivement200 {
		icon = "Data\UI\Achievements\SFO.paa";
		displayName = "Confused AFO";
		description = "Trained as a Police AFO";
	};
	class JoinUC : BaseAchivement200 {
		icon = "Data\UI\Achievements\UC.paa";
		displayName = "Secret Constable";
		description = "Trained as a Police Covert Officer";
	};
	class Judge : BaseAchivement200 {
		icon = "\A3\ui_f_orange\data\CfgHints\loac_ca.paa";
		displayName = "Judging Others";
		description = "You have sat in judgement of another";
		onUnlocked = "[""Judge""] call ULP_fnc_unlockTitle;";
	};
	class LifeSaver : BaseAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Injury_ca.paa";
		displayName = "Life Saver";
		description = "Successfully saved a life";
		onUnlocked = "[""LifeSaver""] call ULP_fnc_unlockTitle;";
	};
	class OneMillion : BaseAchivement200 {
		icon = "Data\UI\Achievements\money1.paa";
		displayName = "£1,000,000";
		description = "Had a total of £1,000,000 in your bank";
		onUnlocked = "[""OneMillion""] call ULP_fnc_unlockTitle;";
	};
	class Voter : BaseAchivement200 {
		icon = "Data\UI\Perks\governmentBonus.paa";
		displayName = "I love Democracy";
		description = "I love Democracy... and I love the Republic";
	};
	class JoinAPC : BaseAchivement200 {
		icon = "Data\UI\Achievements\APC.paa";
		displayName = "Constable";
		description = "Joined the Altis Police";
		leveling[] = { 500, "Achievement Unlocked", 100 };
	};
	class JoinHATO : JoinAPC {
		icon = "Data\UI\Achievements\HATO.paa";
		displayName = "Traffic Officer";
		description = "Joined the Highways Agency";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = false;
	};
	class JoinNHS : JoinAPC {
		icon = "Data\UI\Achievements\NHS.paa";
		displayName = "Paramedic";
		description = "Joined the Altis Ambulance Service";
	};
	class JoinStaff : BaseAchivement200 {
		icon = "Data\UI\Achievements\staff.paa";
		displayName = "Staff Team";
		description = "You have joined the community's Staff Team";
		onUnlocked = "[""JoinStaff""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
	};
	class TenMillion : JoinStaff {
		icon = "Data\UI\Achievements\money10.paa";
		displayName = "£10,000,000";
		description = "Had a total of £10,000,000 in your bank";
	};
	class Governor : BaseAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Rules_ca.paa";
		displayName = "Governor";
		description = "Win an election and become the Governor";
		onUnlocked = "[""Governor""] call ULP_fnc_unlockTitle;";
		leveling[] = { 5000, "Achievement Unlocked", 100 };
	};
	class HundredMillion : Governor {
		icon = "Data\UI\Achievements\money100.paa";
		displayName = "£100,000,000";
		description = "Had a total of £100,000,000 in your bank";
		leveling[] = { 5000, "Achievement Unlocked", 100 };
	};

	// Mystery
	class BrokenNLR : BaseMysteryAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Timing_ca.paa";
		displayName = "Rule Breaker";
		description = "You have broken the rules. You should be banned";
		onUnlocked = "[""RuleBreaker""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
	};

	class Salty : BaseMysteryAchivement200 {
		icon = "Data\UI\Achievements\salty.paa";
		displayName = "Extremely Salty";
		description = "Held a vast amount of salt on your person";
		onUnlocked = "[""Salty""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
	};

	class Barrel : BaseMysteryAchivement200 {
		icon = "Data\UI\Achievements\barrel.paa";
		displayName = "The Barrel";
		description = "Found the mysterious hidden barrel";
	};
	class Bomb : BaseMysteryAchivement200 {
		icon = "\A3\ui_f_orange\data\CfgHints\uxo_ca.paa";
		displayName = "You idiot";
		description = "Who steps on what is clearly a bomb";
		onUnlocked = "[""Bomb""] call ULP_fnc_unlockTitle;";
	};
	class Captain : BaseMysteryAchivement200 {
		icon = "Data\UI\Achievements\captain.paa";
		displayName = "Ship Captain";
		description = "Visited the command deck of the HMS Liberty";
		onUnlocked = "[""Captain""] call ULP_fnc_unlockTitle;";
	};
	class DeathWish : BaseMysteryAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Targets_ca.paa";
		displayName = "Death Wish";
		description = "You have traveled to the heart of the red zone";
		onUnlocked = "[""DeathWish""] call ULP_fnc_unlockTitle;";
	};
	class DeepSeaDiver : BaseMysteryAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicDive_ca.paa";
		displayName = "Deep Sea Diver";
		description = "You taken a dive deep into the sea";
		onUnlocked = "[""DeepSeaDiver""] call ULP_fnc_unlockTitle;";
	};
	class DisguiseID : BaseMysteryAchivement200 {
		icon = "Data\UI\GroupPerks\blackmarket.paa";
		displayName = "Faceless Man";
		description = "All men must serve. Faceless Men most of all";
		onUnlocked = "[""FacelessMan""] call ULP_fnc_unlockTitle;";
	};
	class MileHighClub : BaseMysteryAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\TakeOff_ca.paa";
		displayName = "Mile High Club";
		description = "You have flown roughly a mile in the sky";
		onUnlocked = "[""MileHighClub""] call ULP_fnc_unlockTitle;";
	};
	class NLRPC : BaseMysteryAchivement200 {
		icon = "Data\UI\Achievements\nlrpc.paa";
		displayName = "NLRPC";
		description = "You have discovered a remnant of North London";
		onUnlocked = "[""NLRPC""] call ULP_fnc_unlockTitle;";
	};
	class Nothing : BaseMysteryAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicLook_ca.paa";
		displayName = "Nothingness";
		description = "You've found nothing surrounded by more nothing";
		onUnlocked = "[""Nothing""] call ULP_fnc_unlockTitle;";
	};
	class Panic : BaseMysteryAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\NormalDamage_ca.paa";
		displayName = "Fight or Flight";
		description = "You've been in an absolute state of panic... or misclicked";
		onUnlocked = "[""FightFlight""] call ULP_fnc_unlockTitle;";
	};
	class Racing : BaseMysteryAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Time_trials_ca.paa";
		displayName = "Racing Around";
		description = "You've visited the race track";
		onUnlocked = "[""Racing""] call ULP_fnc_unlockTitle;";
	};
	class Radiation : BaseMysteryAchivement200 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
		displayName = "Irradiated";
		description = "Experienced the effects of radiation poisoning";
		onUnlocked = "[""Radiation""] call ULP_fnc_unlockTitle;";
	};
	class Ace : BaseMysteryAchivement1000 {
		icon = "Data\UI\Achievements\ace.paa";
		displayName = "Norwegian Retreat";
		description = "You have located the hidden retreat of Ace Boyden";
		onUnlocked = "[""Ace""] call ULP_fnc_unlockTitle;";
	};
	class Atlantis : BaseMysteryAchivement1000 {
		icon = "Data\UI\Achievements\atlantis.paa";
		displayName = "Atlantis";
		description = "You have discovered Atlantis on Altis";
		onUnlocked = "[""Atlantis""] call ULP_fnc_unlockTitle;";
	};
	class Brick : BaseMysteryAchivement1000 {
		icon = "Data\UI\Perks\firstAider.paa";
		displayName = "Brick Hospital";
		description = "You have found the second home of Brick Haus";
		onUnlocked = "[""Brick""] call ULP_fnc_unlockTitle;";
	};
	class Carrier : BaseMysteryAchivement1000 {
		icon = "\A3\ui_f_jets\data\GUI\Cfg\Hints\AircraftLandCarrier_ca.paa";
		displayName = "Floating Fortress";
		description = "Landed on the USS Freedom";
		onUnlocked = "[""Carrier""] call ULP_fnc_unlockTitle;";
	};
	class FanGirl : BaseMysteryAchivement1000 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\PilotingQuadrotor_ca.paa";
		displayName = "Fan Girl";
		description = "You have discovered the pleasure in Belle Delphine.";
		onUnlocked = "[""FanGirl""] call ULP_fnc_unlockTitle;";
	};
	class Freddie : BaseMysteryAchivement1000 {
		icon = "Data\UI\Perks\muscleman.paa";
		displayName = "Chicken Deboner";
		description = "The aftermath of Freddie deboning a chicken";
		onUnlocked = "[""Freddie""] call ULP_fnc_unlockTitle;";
	};
	class Fulton : BaseMysteryAchivement1000 {
		icon = "Data\UI\GroupBuffs\hacking.paa";
		displayName = "1-0-ALPHA-NOVEMBER";
		description = "You have viewed the CPU of Fulton";
		onUnlocked = "[""Fulton""] call ULP_fnc_unlockTitle;";
	};
	class James : BaseMysteryAchivement1000 {
		icon = "Data\UI\Perks\improvedMetabolism.paa";
		displayName = "Uber Eats Boat";
		description = "You have identified James Johnson's daily food delivery";
		onUnlocked = "[""James""] call ULP_fnc_unlockTitle;";
	};
	class Jetan : BaseMysteryAchivement1000 {
		icon = "Data\UI\Achievements\jetan.paa";
		displayName = "Boat Boy";
		description = "You have boarded the home of one Jetan Holo";
		onUnlocked = "[""Jetan""] call ULP_fnc_unlockTitle;";
	};
	class Lewis : BaseMysteryAchivement1000 {
		icon = "Data\UI\Achievements\lewis.paa";
		displayName = "Bushmaker";
		description = "You have climbed the statue of Lewis 'Bushmaker' Holloway";
		onUnlocked = "[""Lewis""] call ULP_fnc_unlockTitle;";
	};
	class Oliver : BaseMysteryAchivement1000 {
		icon = "Data\UI\Achievements\oliver.paa";
		displayName = "Nationalist";
		description = "You have visited Oliver's 'metropolitan hub of the North'";
		onUnlocked = "[""Oliver""] call ULP_fnc_unlockTitle;";
	};
	class PirateDen : BaseMysteryAchivement1000 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Death_ca.paa";
		displayName = "Pirate Den";
		description = "You have discovered a Pirate Den on Altis";
		onUnlocked = "[""PirateDen""] call ULP_fnc_unlockTitle;";
	};
	class Protest : BaseMysteryAchivement1000 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Voice_ca.paa";
		displayName = "Protester";
		description = "You have taken a simple protest to the extreme...";
		onUnlocked = "[""Protest""] call ULP_fnc_unlockTitle;";
	};
	class Scarso : BaseMysteryAchivement1000 {
		icon = "Data\UI\Achievements\scarso.paa";
		displayName = "The Workspace";
		description = "You have discovered the workspace of Scarso";
		onUnlocked = "[""Scarso""] call ULP_fnc_unlockTitle;";
	};
	class Snoop : BaseMysteryAchivement1000 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Head_ca.paa";
		displayName = "Professional Snoop";
		description = "You clearly downloaded the mission.sqm";
		onUnlocked = "[""Snoop""] call ULP_fnc_unlockTitle;";
	};
	class Spawn : BaseMysteryAchivement1000 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Zeus_ca.paa";
		displayName = "Spawn";
		description = "You have discovered the spawn of mankind";
		onUnlocked = "[""SpawnCamp""] call ULP_fnc_unlockTitle;";
	};
	class Stonehenge : BaseMysteryAchivement1000 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Direction_ca.paa";
		displayName = "Stonehenge";
		description = "You have discovered the Stonehenge on Altis";
	};
	class Sub : BaseMysteryAchivement1000 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\SDV_ca.paa";
		displayName = "Submarine";
		description = "You have walked on top of the HMS Proteus";
		onUnlocked = "[""Sub""] call ULP_fnc_unlockTitle;";
	};
	class Uncharted : BaseMysteryAchivement1000 {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Map_ca.paa";
		displayName = "Explorer";
		description = "You have chosen to leave this island, but you will return";
		onUnlocked = "[""Uncharted""] call ULP_fnc_unlockTitle;";
	};
	class Prestige : BaseMysteryAchivement1000 {
		icon = "Data\UI\Achievements\prestige.paa";
		displayName = "Prestigious";
		description = "Prestiged for the first time";
		onUnlocked = "[""Prestige""] call ULP_fnc_unlockTitle;";
	};
};