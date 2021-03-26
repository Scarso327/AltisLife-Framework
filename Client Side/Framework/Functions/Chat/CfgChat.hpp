class CfgChat {
	class Messages {
		class Injured {
			message = "%1 was seriously injured";
			params = 1;
		};
		class Bleedout : Injured {
			message = "%1 bled out...";
		};
		class Executed : InjuredBy {
			message = "%1 was executed by %2";
			params = 2;
		};
		class InjuredBy {
			message = "%1 was seriously injured by %2";
		};
	};
};