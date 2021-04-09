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
	};
};