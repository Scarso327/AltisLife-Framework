class CfgSurvival {
	class ULP_Survival_Thirst {
		delay = 600;
		decrease = 10;
		max = 100;
		onZero = "player setDamage 1;";
	};
	class ULP_Survival_Hunger {
		delay = 850;
		decrease = 10;
		max = 100;
		onZero = "player setDamage 1;";
	};
};