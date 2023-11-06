class CfgAchievements {
	class FirstSpawn {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\BasicWalk_ca.paa";
		displayName = "First Steps";
		description = "Spawned for the first time.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class FirstDrink {
		icon = "Data\UI\Achievements\firstDrink.paa";
		displayName = "Big Drink";
		description = "Taken your frist drink of alcohol.";
		onUnlocked = "[""FirstDrink""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class FirstDrug {
		icon = "Data\UI\Achievements\firstDrug.paa";
		displayName = "Druggie";
		description = "Had your first drug experience.";
		onUnlocked = "[""FirstDrug""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class GirlsBestFriend {
		icon = "Data\UI\Achievements\girlsBestFriend.paa";
		displayName = "Girl's Best Friend";
		description = "Aquired a finely cut diamond.";
		onUnlocked = "[""GirlsBestFriend""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// TODONOW
	class Salty {
		icon = "Data\UI\Achievements\salty.paa";
		displayName = "Extremely Salty";
		description = "Held a vast amount of salt on your person.";
		onUnlocked = "[""Salty""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Captain {
		icon = "Data\UI\Achievements\captain.paa";
		displayName = "Ship Captain";
		description = "Visited the command deck of the HMS Liberty.";
		onUnlocked = "[""Captain""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Archaeologist {
		icon = "Data\UI\Achievements\archaeologist.paa";
		displayName = "Archaeologist";
		description = "Carried out your first archaeological dig.";
		onUnlocked = "[""Archaeologist""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinRebel {
		icon = "Data\UI\Achievements\rebel.paa";
		displayName = "The Rebellion";
		description = "Joined the Rebellion. Hope.";
		onUnlocked = "[""JoinRebel""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinGroup {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
		displayName = "Group Member";
		description = "Joined a group for the first time.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinStaff {
		icon = "Data\UI\Achievements\staff.paa";
		displayName = "Staff Team";
		description = "You have joined the community's Staff Team.";
		onUnlocked = "[""JoinStaff""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinAPC {
		icon = "Data\UI\Achievements\APC.paa";
		displayName = "Constable";
		description = "Joined the Altis Police.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinCOL {
		icon = "Data\UI\Achievements\COL.paa";
		displayName = "College Instructor";
		description = "Joined the College of Policing.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinNPAS {
		icon = "Data\UI\Achievements\NPAS.paa";
		displayName = "Police Pilot";
		description = "Joined the NPAS.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinSCO19 {
		icon = "Data\UI\Achievements\SCO.paa";
		displayName = "Firearms Officer";
		description = "Joined the SCO19.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinNCA {
		icon = "Data\UI\Achievements\NCA.paa";
		displayName = "Intel Officer";
		description = "Joined the NCA.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinMPU {
		icon = "Data\UI\Achievements\MPU.paa";
		displayName = "Police Marine";
		description = "Joined the MPU.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinRPU {
		icon = "Data\UI\Achievements\RPU.paa";
		displayName = "Pursuit Specialist";
		description = "Joined the RPU.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinSFO {
		icon = "Data\UI\Achievements\SFO.paa";
		displayName = "Confused AFO";
		description = "Trained as a Police SFO.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinUC {
		icon = "Data\UI\Achievements\UC.paa";
		displayName = "Secret Constable";
		description = "Trained as a Police Covert Officer.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstTicket {
		icon = "Data\UI\Achievements\firstTicket.paa";
		displayName = "Ticketer";
		description = "Issued a Fixed Pelenty Notice to an individual.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstArrest {
		icon = "Data\UI\Achievements\firstArrest.paa";
		displayName = "Law Enforcer";
		description = "Sentenced an individual to serve time in the HMP.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinNHS {
		icon = "Data\UI\Achievements\NHS.paa";
		displayName = "Paramedic";
		description = "Joined the Altis Ambulance Service.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinHR {
		icon = "Data\UI\Achievements\HR.paa";
		displayName = "Desk Worker";
		description = "Joined the NHS Human Resources Dept.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinAA {
		icon = "Data\UI\Achievements\AA.paa";
		displayName = "Air Saviour";
		description = "Joined the Altis Air Ambulance.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class LifeSaver {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Injury_ca.paa";
		displayName = "Life Saver";
		description = "Sucessfully revived another person.";
		onUnlocked = "[""LifeSaver""] call ULP_fnc_unlockTitle;";
		leveling[] = { 350, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class JoinHATO {
		icon = "Data\UI\Achievements\HATO.paa";
		displayName = "Traffic Officer";
		description = "Joined the Highways Agency.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstImpound {
		icon = "Data\UI\Achievements\firstImpound.paa";
		displayName = "Street Cleaner";
		description = "Impounded a vehicle for the first time.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class FirstCrush {
		icon = "Data\UI\Achievements\firstCrush.paa";
		displayName = "Vehicle Scrapper";
		description = "Crushed/Chopped a vehicle for the first time.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Governor {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Rules_ca.paa";
		displayName = "Governor";
		description = "Win an election and become the Governor.";
		onUnlocked = "[""Governor""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Employment {
		icon = "Data\UI\Achievements\employment.paa";
		displayName = "Employment";
		description = "Successfully become employemented.";
		onUnlocked = "[""Employment""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class Convict {
		icon = "Data\UI\Achievements\convict.paa";
		displayName = "Convict";
		description = "Have been sent to prison by a constable.";
		onUnlocked = "[""Convict""] call ULP_fnc_unlockTitle;";
		leveling[] = { 10, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class SuccessfulRobber {
		icon = "Data\UI\Achievements\successfulRobber.paa";
		displayName = "Successful Robber";
		description = "Successfully carried out a site robbery.";
		onUnlocked = "[""SuccessfulRobber""] call ULP_fnc_unlockTitle;";
		leveling[] = { 10, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class TaskMaster {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Tasks_ca.paa";
		displayName = "Task Master";
		description = "Completed a task for the first time.";
		onUnlocked = "[""TaskMaster""] call ULP_fnc_unlockTitle;";
		leveling[] = { 75, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class CartelLord {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Miss_icon_ca.paa";
		displayName = "Cartel Lord";
		description = "Sucessfully recieved a payout from a cartel.";
		onUnlocked = "[""Cartel""] call ULP_fnc_unlockTitle;";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class BuyVehicle {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Driving_ca.paa";
		displayName = "First Ride";
		description = "Bought your first vehicle.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class BuyHouse {
		icon = "Data\UI\Achievements\house.paa";
		displayName = "First House";
		description = "Bought your first house.";
		leveling[] = { 50, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class BuyWarehouse {
		icon = "Data\UI\Achievements\warehouse.paa";
		displayName = "First Warehouse";
		description = "Bought your first warehouse.";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class OneMillion {
		icon = "Data\UI\Achievements\money1.paa";
		displayName = "£1,000,000";
		description = "Had a total of £1,000,000 in your bank.";
		onUnlocked = "[""OneMillion""] call ULP_fnc_unlockTitle;";
		leveling[] = { 100, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class TenMillion {
		icon = "Data\UI\Achievements\money10.paa";
		displayName = "£10,000,000";
		description = "Had a total of £10,000,000 in your bank.";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	class HundredMillion {
		icon = "Data\UI\Achievements\money100.paa";
		displayName = "£100,000,000";
		description = "Had a total of £100,000,000 in your bank.";
		leveling[] = { 300, "Achievement Unlocked", 100 };
		isMystery = false;
	};

	// MYSTERY ---------------------------------------------------------
	class Barrel {
		icon = "Data\UI\Achievements\barrel.paa";
		displayName = "The Barrel";
		description = "Found the mysterious hidden barrel.";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};
	
	class Prestige {
		icon = "Data\UI\Achievements\prestige.paa";
		displayName = "Prestigious";
		description = "Prestiged for the first time.";
		onUnlocked = "[""Prestige""] call ULP_fnc_unlockTitle;";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	// TODO
	class FanGirl {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\PilotingQuadrotor_ca.paa";
		displayName = "Fan Girl";
		description = "You have discovered the pleasure in Belle Delphine.";
		onUnlocked = "[""FanGirl""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Uncharted {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Map_ca.paa";
		displayName = "Explorer";
		description = "You have chosen to leave this island, but returned.";
		onUnlocked = "[""Uncharted""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Radiation {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Chat_ca.paa";
		displayName = "Goodbye Fatherhood";
		description = "Experienced the effects of radation poisoning.";
		onUnlocked = "[""Radiation""] call ULP_fnc_unlockTitle;";
		leveling[] = { 200, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Protest {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Voice_ca.paa";
		displayName = "Protester";
		description = "You have taken a simple protest to the extreme...";
		onUnlocked = "[""Protest""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class MileHighClub {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\TakeOff_ca.paa";
		displayName = "Mile High Club";
		description = "You have flown exactly 1-Mile or higher in the sky.";
		onUnlocked = "[""MileHighClub""] call ULP_fnc_unlockTitle;";
		leveling[] = { 500, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Stonehenge {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Direction_ca.paa";
		displayName = "Stonehenge";
		description = "You have discovered the Stonehenge on Altis.";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class PirateDen {
		icon = "\A3\ui_f\data\GUI\Cfg\Hints\Death_ca.paa";
		displayName = "Pirate Den";
		description = "You have discovered a Pirate Den on Altis.";
		onUnlocked = "[""PirateDen""] call ULP_fnc_unlockTitle;";
		leveling[] = { 2000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Atlantis {
		icon = "Data\UI\Achievements\atlantis.paa";
		displayName = "Atlantis";
		description = "You have discovered Atlantis on Altis.";
		onUnlocked = "[""Atlantis""] call ULP_fnc_unlockTitle;";
		leveling[] = { 3000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	// PERSONAL ACHIEVEMENTS
	class Scarso {
		icon = "Data\UI\Achievements\scarso.paa";
		displayName = "The Workspace";
		description = "You have discovered the workspace of Scarso.";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Lewis {
		icon = "Data\UI\Achievements\lewis.paa";
		displayName = "Bushmaker";
		description = "You have climbed the statue of Lewis 'Bushmaker' Holloway.";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Oliver {
		icon = "Data\UI\Achievements\oliver.paa";
		displayName = "Nationalist";
		description = "You have visited the metropolitan hub of the North. Home of Oliver Lawson.";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Ace {
		icon = "Data\UI\Achievements\ace.paa";
		displayName = "Norwegian Retreat";
		description = "You have located the hidden retreat of Ace Boyden.";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};

	class Jetan {
		icon = "Data\UI\Achievements\jetan.paa";
		displayName = "Boat Boy";
		description = "You have boarded the home of one Jetan Holo.";
		leveling[] = { 1000, "Achievement Unlocked", 100 };
		isMystery = true;
	};
};