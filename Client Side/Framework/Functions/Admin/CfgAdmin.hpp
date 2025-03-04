class CfgAdmin {
	class Power {
		// SUPPORT (L1)
		// ADMIN (L2)
		class Suit {
			message = "You must be in the Events Team or an Admin to use this ability";
			condition = "((call ULP_Staff) > 1) || { ((call ULP_Event) > 0) }";
		};
		class Camera : Suit {};
		class Teleport : Suit {};
		class Invis : Suit {};

		class Compensate : Suit { condition = "((call ULP_Staff) > 1)"; };
		class Vehicle : Compensate {};
		class Medical : Compensate {};
		class Restrain : Compensate {};
		class Imprison : Compensate {};
		class RemovePlaceable : Compensate {};

		// SENIOR (L3)
		class Housing {
			message = "You must be a Senior Admin to use this ability";
			condition = "((call ULP_Staff) > 2)";
		};
		class Disconnect : Housing { condition = "((call ULP_Staff) isEqualTo 5)"; };
	};
};