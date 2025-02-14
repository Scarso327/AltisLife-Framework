class CfgChat {
	class Messages {
		class Injured {
			message = "%1 was seriously injured";
			params = 1;
			condition = "[[""EnableMessagesIncapacitated"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Bleedout : Injured {
			message = "%1 bled out...";
			condition = "[[""EnableMessagesBleedout"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Suicide : Bleedout {
			message = "%1 killed themselves...";
		};
		class ReturnedToLobby : Injured {
			message = "%1 returned to the lobby";
			condition = "true";
		};
		class Executed {
			message = "%1 was executed by %2";
			params = 2;
			condition = "[[""EnableMessagesBleedout"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class InjuredBy : Executed {
			message = "%1 was seriously injured by %2";
			condition = "[[""EnableMessagesIncapacitated"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Killed : Executed {
			message = "%1 was killed by %2";
		};
		class Revived : Executed {
			message = "%1 was revived by %2";
			condition = "[[""EnableMessagesRevived"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Prisoned {
			message = "%1 was imprisioned by %2 for %3 minutes";
			params = 3;
			condition = "[[""EnableMessagesPrisoned"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Garaged : Prisoned {
			message = "%1's %2 was garaged by %3";
			condition = "[[""EnableMessagesVehicle"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Crushed : Garaged {
			message = "%1's %2 was crushed by %3";
		};
		class Impounded : Garaged {
			message = "%1's %2 was impounded by %3 for %4";
			params = 4;
		};
		class IssuedFine : Prisoned {
			message = "%1 has issued %2 a fine of %3";
			condition = "[[""EnableMessagesTicket"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class FinePaid : IssuedFine {
			message = "%1 has paid a fine of %2";
			params = 2;
		};
		class FineRefused : FinePaid {
			message = "%1 has refused a fine of %2";
		};
		class FinePoor : FinePaid {
			message = "%1 can't afford a fine of %2";
		};
		class Restrained : FinePaid {
			message = "%1 was restrained by %2";
			condition = "[[""EnableMessagesRestrain"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class UnRestrained : Restrained {
			message = "%1 was unrestrained by %2";
		};
	};
	class Commands {
		class Players {
			action = "[""Total Players:"", format [""%1"", count allPlayers]]";
			condition = "true";
		};
		class Police : Players { action = "[""Total Police:"", format [""%1"", [[""Police""]] call ULP_fnc_onlineFaction]]"; };
		class Medics : Players { action = "[""Total Medics:"", format [""%1"", [[""Medic""]] call ULP_fnc_onlineFaction]]"; };
		class Cops : Police {};

		class Discord : Players { action = """Discord @ discord.gg/mantlenetwork"""; };
		class Teamspeak : Players { action = """Teamspeak @ ts3.mantlenetwork.co.uk"""; };
		class TS : Teamspeak {};
		class TS3 : Teamspeak {};

		class PID {
			action = "[""ARP ID:"", format [""%1"", [ULP_ID] call ULP_fnc_numberText]]";
			condition = "(missionNamespace getVariable [""ULP_ID"", -1]) > -1";
		};
		class SteamID : Players {
			action = "[""Steam ID:"", format [""%1"", getPlayerUID player]]";
		};
	};
};