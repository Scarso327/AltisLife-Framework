class CfgCrimes {
	class Altis {
		class HMTreasury {
			title = "HM Treasury";
			description = "Located near the island’s main airfield, the HM Treasury of Altis is a heavily fortified hub of economic governance. Housed within a modern, reinforced concrete structure, it oversees public finances, currency stability, and economic policy for the island.<br /><br />Protected by high-security measures, the treasury ensures the safety of vital financial operations while maintaining close ties to Altis’s strategic infrastructure. Despite its utilitarian design, the institution symbolizes resilience and stability, safeguarding the island’s economic future amidst a volatile geopolitical landscape.";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Hack {
					displayName = "Hacking Vault Security";
					description = "To breach the vault’s defenses, two outer military offices must first be accessed using <font color='#B92DE0'>bolt cutters</font>. Inside, a <font color='#B92DE0'>hacking device</font> can be deployed to disable the vault’s main security system. Once disabled, the inner domes can be bolt cut and entered, granting access to the vault's contents.";
					time = 600;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""The Vault Security System at HM Treasury is being tampered with!""], _targets] call ULP_fnc_sendMessage; [""You have begun disabling the vault security, police has been notified!""] call ULP_fnc_hint;"; // Notify Police...
					onCompleted = "[""HMTreasury"", 1] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""You have successfully disabled the vault security system...""] call ULP_fnc_hint;"; // Call to fill vaults, allow vaults to be drilled...
					onEachFrame = "";
					onProgressStop = "";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 10) : { ""There must be at least <t color='#B92DE0'>10 police officers</t> to start this crime..."" }; case ([""HackingDevice""] call ULP_fnc_hasItem < 1) : { ""You need a hacking device to perform this action..."" }; default { ""Vault Security has already been disabled..."" }; })] call ULP_fnc_hint;";
					condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_HMTreasury"", false]) && { [""HackingDevice""] call ULP_fnc_hasItem > 0 } && { (count [""Police""] call ULP_fnc_allMembers) >= 10 }";
				};
			};
			class Buildings {
				class MilitaryOfficeOne {
					classname = "Land_MilOffices_V1_F";
					position[] = {16009.7, 16900.3, 0.372055};
					class BreakIn {
						breakIn = 240;
						onBreakIn = "if (([""SilentLocksmith"", (random 1)] call ULP_fnc_activatePerk) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""A Security Office at HM Treasury has been broken into!""], _targets] call ULP_fnc_sendMessage; [""You accidently tripped an alarm while breaking the lock, police have been alerted!""] call ULP_fnc_hint;";
						onFail = "[""There must be at least <t color='#B92DE0'>10 police officers</t> to start this crime...""] call ULP_fnc_hint;";
						condition = "(count [""Police""] call ULP_fnc_allMembers) >= 10 || { missionNamespace getVariable [""ULP_SRV_Crime_HMTreasury"", false] }";
					};
				};
				class MilitaryOfficeTwo : MilitaryOfficeOne { position[] = {16216.4, 17071.3, 0.0516109}; };

				class DomeOne : MilitaryOfficeOne {
					classname = "Land_Dome_Big_F";
					position[] = {16019, 16953.4, 0};
					class BreakIn : BreakIn {
						breakIn = 300;
					};
				};
				class DomeTwo : DomeOne { position[] = {16015.1, 17043.1, 0}; };
				class DomeThree : DomeOne { position[] = {16084, 17082.7, 0}; };
				class DomeFour : DomeOne { position[] = {16152.7, 17044.1, 0}; };
				class DomeFive : DomeOne { position[] = {16152.6, 16961.7, 0}; };
				class DomeSix : DomeOne { position[] = {16084.9, 16915.2, 0}; };

				class VaultOne {
					classname = "Land_Research_house_V1_F";
					position[] = {16015.1, 16958.1, 0};
					vaults[] = { { "Land_CargoBox_V1_F", {-1.71973, 3.15625, 0.0583897}, 0.16 } };
				};
				class VaultThree : VaultOne { position[] = {16092.7, 17092.8, 0}; };
				class VaultFive : VaultOne { position[] = {16146.8, 16951.2, 0}; };

				class VaultTwo : VaultOne {
					classname = "Land_Research_HQ_F";
					position[] = {16023.7, 17031.4, 0};
					vaults[] = { { "Land_CargoBox_V1_F", {6.24316, 5.4707, -3.1177}, 0.16 } };
				};
				class VaultFour : VaultTwo { position[] = {16151.8, 17044.7, 0}; };
				class VaultSix : VaultTwo { position[] = {16076.4, 16917.9, 0}; };
			};
			class Items {
				class MarkedGold {
					amount = 20;
					extra = "((count playableUnits) / 4) + ((time / 2) / 240)";
				};
			};
		};
		class HMSLiberty {
			title = "HMS Liberty";
			description = "The HMS Liberty, a British Navy destroyer, now lies abandoned after colliding with treacherous rocks off the coast of Altis. Once a symbol of naval power, the vessel’s rusting hull juts from the shallow waters, a stark reminder of its untimely demise.<br /><br />Amidst the wreckage lies a server housing valuable encrypted drives, a potential goldmine for those daring enough to retrieve them. These drives can be sold as-is for their raw value or decrypted to unlock and sell their sensitive data for an even greater reward. The HMS Liberty’s perilous location and decaying structure make it a challenging but lucrative target for opportunists.";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Hack {
					displayName = "Disabling Server Security";
					description = "On the bridge of the abandoned HMS Liberty, a server containing valuable drives awaits. To access it, a <font color='#B92DE0'>hacking device</font> must be used to disable the server’s security systems, unlocking the drives for retrieval.";
					time = 1200;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""Systems on HM Liberty are being tampered with!""], _targets] call ULP_fnc_sendMessage; [""You have begun disabling the server's security systems, police has been notified!""] call ULP_fnc_hint;";
					onCompleted = "[""HMSLiberty"", 1, hms_liberty_server] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""You have successfully disabled the server's security system...""] call ULP_fnc_hint;";
					onEachFrame = "hms_liberty_server animateSource [""server_move_source"", (_this / 100)];";
					onProgressStop = "hms_liberty_server animateSource [""server_move_source"", 0]";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 10) : { ""There must be at least <t color='#B92DE0'>10 police officers</t> to start this crime..."" }; case ([""HackingDevice""] call ULP_fnc_hasItem < 1) : { ""You need a hacking device to perform this action..."" }; default { ""Server Security has already been disabled..."" }; })] call ULP_fnc_hint;";
					condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_HMSLiberty"", false]) && { [""HackingDevice""] call ULP_fnc_hasItem > 0 }";
				};
			};
			class Buildings {
				class Ship {
					classname = "Land_Destroyer_01_interior_02_F";
					position[] = {14054.8, 11509.4, -2.1181};
					class BreakIn {
						breakIn = 360;
						onBreakIn = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""The bridge of the HMS Liberty has been illegally accessed!""], _targets] call ULP_fnc_sendMessage; [""You accidently tripped an alarm while breaking the lock, police have been alerted!""] call ULP_fnc_hint;";
						onFail = "[""There must be at least <t color='#B92DE0'>10 police officers</t> to start this crime...""] call ULP_fnc_hint;";
						condition = "true";
					};
				};
			};
			class Items {
				class EncryptedDrive {
					amount = 8;
					extra = "(random 24) max 1";
				};
			};
		};
		class PoliceEvidenceStorage {
			title = "Police Evidence Storage";
			description = "Located south of Kavala, the Police Evidence Locker is a heavily guarded facility storing all the island's confiscated evidence. Within its walls lies a trove of contraband, ranging from illegal substances to rare items, all of which fetch a high price on the black market.<br /><br />Breaking into the locker requires bypassing reinforced security systems and evading patrols. For those bold enough to succeed, the rewards can be immense, making it a prime target for opportunistic criminals.";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Drill {
					displayName = "Drilling into Evidence Vault";
					description = "To access the vault, an <font color='#B92DE0'>industrial drill</font> is required to breach its reinforced walls, adding an extra layer of difficulty to the heist. For those daring enough to break in, the payoff can be substantial, but the risks are just as high.";
					time = 600;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""The Police Evidence Storage Vault is being illegally accessed!""], _targets] call ULP_fnc_sendMessage; [""You have begun drilling into the evidence storage vault, police has been notified!""] call ULP_fnc_hint;";
					onCompleted = "[""PoliceEvidenceStorage"", 1, evidence_storage_vault] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""You have successfully disabled the server's security system...""] call ULP_fnc_hint;";
					onEachFrame = "";
					onProgressStop = "";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 10) : { ""There must be at least <t color='#B92DE0'>10 police officers</t> to start this crime..."" }; case ([""IndustrialDrill""] call ULP_fnc_hasItem < 1) : { ""You need an industrial drill to perform this action..."" }; default { ""Valut security has already been disabled..."" }; })] call ULP_fnc_hint;";
					condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_PoliceEvidenceStorage"", false]) && { [""IndustrialDrill""] call ULP_fnc_hasItem > 0 }";
				};
			};
			class Buildings {
				class MilitaryOffice {
					classname = "Land_MilOffices_V1_F";
					position[] = {3266.77, 12448.9, 0.117};
					class BreakIn {
						breakIn = 240;
						onBreakIn = "if (([""SilentLocksmith"", (random 1)] call ULP_fnc_activatePerk) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""A door at the Police Evidence Storage facility has been broken into!""], _targets] call ULP_fnc_sendMessage; [""You accidently tripped an alarm while breaking the lock, police have been alerted!""] call ULP_fnc_hint;";
						onFail = "[""There must be at least 10 police officers to start this crime...""] call ULP_fnc_hint;";
						condition = "(count [""Police""] call ULP_fnc_allMembers) >= 10 || { missionNamespace getVariable [""ULP_SRV_Crime_PoliceEvidenceStorage"", false] }";
					};
				};
			};
			class Items {
				class SeizedContraband {
					amount = 30;
					extra = "((count playableUnits) / 2) + ((time / 2) / 240)";
				};
			};
		};
		class ResearchFacility {
			title = "Research Storage";
			description = "Hidden beneath the waves of the Pygros Gulf, this secretive underwater research facility is shrouded in mystery, rumored to be conducting experiments on alien technology. Accessible only by diving or specialized submersibles, the facility’s reinforced structure is designed to withstand immense pressure and conceal its operations.<br /><br />Inside, advanced labs and secured compartments hint at groundbreaking discoveries, with whispers of extraterrestrial artifacts locked behind high-security doors. For those willing to brave the depths, the potential to uncover and profit from the facility’s secrets is as alluring as it is dangerous.";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Drill {
					displayName = "Drilling into Storage Vault";
					description = "Accessing the vault requires the use of an <font color='#B92DE0'>industrial drill</font> to breach its reinforced walls. Inside, the contents can be sold to foreign agents for an extraordinary profit, making it a high-risk but highly lucrative target for daring infiltrators.";
					time = 1200;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""The Underwater Research Facility is being illegally accessed!""], _targets] call ULP_fnc_sendMessage; [""You have begun drilling into the underwater research facility, police has been notified!""] call ULP_fnc_hint;";
					onCompleted = "[""ResearchFacility"", 1, researchFacilityCapsule] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""You have successfully disabled the server's security system...""] call ULP_fnc_hint;";
					onEachFrame = "";
					onProgressStop = "";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 10) : { ""There must be at least <t color='#B92DE0'>10 police officers</t> to start this crime..."" }; case ([""IndustrialDrill""] call ULP_fnc_hasItem < 1) : { ""You need an industrial drill to perform this action..."" }; default { ""Valut security has already been disabled..."" }; })] call ULP_fnc_hint;";
					condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false]) && { [""IndustrialDrill""] call ULP_fnc_hasItem > 0 }";
				};
			};
			class Buildings {
				class OuterDome {
					classname = "Land_Dome_Big_F";
					position[] = {24842,13219.9,0};
					class BreakIn {
						breakIn = 300;
						onBreakIn = "if (([""SilentLocksmith"", (random 1)] call ULP_fnc_activatePerk) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""A door at the underwater research facility has been broken into!""], _targets] call ULP_fnc_sendMessage; [""You accidently tripped an alarm while breaking the lock, police have been alerted!""] call ULP_fnc_hint;";
						onFail = "[""There must be at least 10 police officers to start this crime...""] call ULP_fnc_hint;";
						condition = "(count [""Police""] call ULP_fnc_allMembers) >= 10 || { missionNamespace getVariable [""ULP_SRV_Crime_ResearchFacility"", false] }";
					};
				};
				class InnerDome {
					classname = "Land_Dome_Small_F";
					position[] = {24844.1,13219.7,0};
				};
				class InnerVault {
					classname = "Land_Research_HQ_F";
					position[] = {24844.1,13219.7,0};
				};
			};
			class Items {
				class SpaceCapsuleDataDrive {
					amount = 1;
					extra = "(random 2) max 1";
				};
			};
		};
	};
};