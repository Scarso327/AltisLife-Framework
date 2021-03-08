class CfgGroups {
	class Tag {
		MinLength = 1;
		MaxLength = 4;
		Blacklisted[] = { "APC", "NHS", "HATO" };
	};
	
	class Name {
		MinLength = 6;
    	MaxLength = 30;
		Blacklisted[] = { "Altis Police Contabulary", "National Health Service", "Civilian" };
	};
};