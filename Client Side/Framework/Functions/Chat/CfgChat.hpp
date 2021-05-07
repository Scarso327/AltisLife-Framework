class CfgChat {
	class Messages {
		class Injured {
			message = "%1 was seriously injured";
			params = 1;
			condition = "[[""EnableMessagesIncapacitated"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class Bleedout : Injured {
			message = "%1 bled out...";
		};
		class Executed {
			message = "%1 was executed by %2";
			params = 2;
			condition = "[[""EnableMessagesBleedout"", ""Chat""] call ULP_fnc_getOption] call ULP_fnc_bool";
		};
		class InjuredBy : Executed {
			message = "%1 was seriously injured by %2";
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
	};
	class Commands {
		class Players {
			action = "[""Total Players:"", format [""%1"", count allPlayers]]";
			condition = "true";
		};
		class ARPID {
			action = "[""ARP ID:"", format [""%1"", [ULP_ID] call ULP_fnc_numberText]]";
			condition = "(missionNamespace getVariable [""ULP_ID"", -1]) > -1";
		};
		class SteamID : Players {
			action = "[""Steam ID:"", format [""%1"", getPlayerUID player]]";
		};
	};
};