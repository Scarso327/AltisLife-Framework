class CfgGroups {
	class Tag {
		MinLength = 1;
		MaxLength = 4;
		Blacklisted[] = { "APC", "NHS", "HATO" };
	};
	
	class Name {
		MinLength = 6;
    	MaxLength = 30;
		Blacklisted[] = { "Altis Police Contabulary", "National Health Service", "Highways Agency", "Civilian" };
	};

	ranks[] = {
		"PRIVATE", "CORPORAL", "SERGEANT", "LIEUTENANT", "CAPTAIN", "MAJOR", "COLONEL"
	};

	class Permissions {
		deposit = 3;
		withdraw = 3;
		rank = 4;
	};

	class Types {
		class Criminal {
			displayName = "Criminal";
		};

		class Corporate {
			displayName = "Company";
		};

		class Party {
			displayName = "Political Party";
		};
	};
};