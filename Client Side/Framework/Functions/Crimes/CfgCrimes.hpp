class CfgCrimes {
	class Altis {
		class HMTreasury {
			title = "HM Treasury";
			factions[] = { "Civilian" };
			cooldown = 1000;
			class Stages {
				class Hack {
					displayName = "Hacking Vault Security";
					time = 300;
					onStarted = "private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""The Vault Security System at HM Treasury is being tampered with!""], _targets] call ULP_fnc_sendMessage; [""You have begun disabling the vault security, police has been notified!""] call ULP_fnc_hint;"; // Notify Police...
					onCompleted = "[""HMTreasury"", 1] remoteExecCall [""ULP_SRV_fnc_toggleVaults"", 2]; [""You have successfully disabled the vault security system...""] call ULP_fnc_hint;"; // Call to fill vaults, allow vaults to be drilled...
					onEachFrame = "";
					onFail = "[(switch (false) do { case ((count ([""Police""] call ULP_fnc_allMembers)) >= 10) : { ""There must be at least 10 police officers to start this crime..."" }; case ([""HackingDevice""] call ULP_fnc_hasItem < 1) : { ""You need a hacking device to perform this action..."" }; default { ""Vault Security has already been disabled..."" }; })] call ULP_fnc_hint;";
					condition = "!(missionNamespace getVariable [""ULP_SRV_Crime_HMTreasury"", false]) && { [""HackingDevice""] call ULP_fnc_hasItem > 0 } && { (count [""Police""] call ULP_fnc_allMembers) >= 10 }";
				};
			};
			class Buildings {
				class MilitaryOfficeOne {
					classname = "Land_MilOffices_V1_F";
					position[] = {16009.7, 16900.3, 0.372055};
					class BreakIn {
						breakIn = 240;
						onBreakIn = "if ((random 1) < 0.8) exitWith {}; private _cfg = missionConfigFile >> ""CfgMessages"" >> ""BreakIn""; private _targets = getText (_cfg >> ""targets""); [_cfg, format [""A Security Office at HM Treasury has been broken into!""], _targets] call ULP_fnc_sendMessage; [""You accidently tripped an alarm while breaking the lock, police have been alerted!""] call ULP_fnc_hint;";
						onFail = "[""There must be at least 10 police officers to start this crime...""] call ULP_fnc_hint;";
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
				class VaultFour : VaultTwo { position[] = {16146.8, 16951.2, 0}; };
				class VaultSix : VaultTwo { position[] = {16076.4, 16917.9, 0}; };
			};
			class Items {
				class MarkedGold {
					amount = 20;
					extra = "((count playableUnits) / 4) + ((time / 2) / 240)"; // Scripted extra...
				};
			};
		};
	};
};