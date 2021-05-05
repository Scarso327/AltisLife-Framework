class CfgAdmin {
	class Power {
		// SUPPORT (L1)
		// MODERATOR (L2)
		class Suit {
			message = "You must be in the Events Team or a Moderator to use this ability...";
			condition = "((call ULP_Staff) > 1) || { ((call ULP_Event) > 0) }";
		};
		class Camera : Suit {};
		class Invis : Camera {};

		// ADMINISTRATOR (L3)
		class Teleport {
			message = "You must be the Events Team Lead or an Administrator to use this ability...";
			condition = "((call ULP_Staff) > 2) || { ((call ULP_Event) > 1) }";
		};
		class Compensate : Teleport {};
		class Vehicle : Teleport {};
		class Medical : Teleport {};
		class Restrain : Teleport {};

		// HEAD ADMINISTRATOR (L4)
		// COMMUNITY BOARD (L5)
		class Disconnect { condition = "((call ULP_Staff) isEqualTo 5)"; };
	};
};