class CfgMessages {
	length = 256;

	class Message {
		picture = "\a3\3den\data\Cfg3DEN\Comment\texture_ca.paa";
		displayName = "Private Message";
		sendTo[] = { "Police", "Medic", "Civilian" };
		ignoreStreamer = false;
		ignoreComms = false; // TODO
		canReply = true;
		sender = "%1";
		targets = "";
		condition = "true"; // TODO
	};

	class Reply : Message {
		displayName = "Reply";
		condition = "false";
	};

	class PoliceDispatch : Message {
		displayName = "Police Dispatch";
		targets = "[""Police""] call ULP_fnc_allMembers";
	};

	class NHSDispatch : Message {
		displayName = "NHS Dispatch";
		targets = "[""Medic""] call ULP_fnc_allMembers";
	};

	class PublicAnnoucement : Message {
		displayName = "Annoucement";
		ignoreStreamer = true;
		ignoreComms = true;
		canReply = false;
		sender = "Server";
		targets = "[""ULP_Staff"", 3] call ULP_fnc_hasAccess || { [""Police_Main"", 10] call ULP_fnc_hasAccess }";
	};

	class EventsAnnoucement : PublicAnnoucement {
		displayName = "Event Annoucement";
		sender = "Events Team";
		targets = "0";
		condition = "[""ULP_Staff"", 2] call ULP_fnc_hasAccess || { [""ULP_Event"", 1] call ULP_fnc_hasAccess }";
	};

	class Dispute : Message {
		displayName = "Dispute";
		ignoreStreamer = true;
		ignoreComms = true;
		condition = "false";
	};
};