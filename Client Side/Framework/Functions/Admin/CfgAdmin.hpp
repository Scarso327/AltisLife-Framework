class CfgAdmin {
	class Power {
		class Suit {
			message = "You must be Events Team L1 or a Moderator to use the suit...";
			condition = "((call ULP_Staff) > 1) || { ((call ULP_Event) > 0) }";
		};
		class Camera {
			message = "You must either be Events Team L2 or a Moderator to use the camera...";
			condition = "((call ULP_Staff) > 1) || { ((call ULP_Event) > 1) }";
		};
		class Invis : Camera {};
		class Teleport {
			message = "You must either be Events Team L2 or an Administrator to use any teleport function...";
			condition = "((call ULP_Staff) > 2) || { ((call ULP_Event) > 1) }";
		};
		class Vehicle : Teleport {};
		class Compensate : Teleport {};
		class Heal : Teleport {};
		class Restrain : Teleport {};
		class Disconnect {
			condition = "((call ULP_Staff) isEqualTo 5)";
		};
	};
};