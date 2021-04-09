class CfgAdmin {
	class Power {
		class Suit {
			message = "You must be Events Team L1 or Moderator to use the suit...";
			condition = "((call ULP_Staff) > 1) || { ((call ULP_Event) > 0) }";
		};
		class Camera {
			message = "You must either be Events Team L2 or Moderator to use the camera...";
			condition = "((call ULP_Staff) > 1) || { ((call ULP_Event) > 1) }";
		};
		class Invis : Camera {};
		class Teleport {
			message = "You must either be Events Team L2 or Administrator to use any teleport function...";
			condition = "((call ULP_Staff) > 2) || { ((call ULP_Event) > 1) }";
		};
		class Vehicle : Teleport {};
		class Heal : Teleport {};
		class Disconnect {
			condition = "((call ULP_Staff) isEqualTo 5)";
		};
	};
};