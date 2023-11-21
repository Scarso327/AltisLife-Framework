class CfgPlaceables {
	maxPlaceables = 20;

	class Objects {
		class SpikeStrip {
			displayName = "Stinger";
			className = "Land_Razorwire_F";
			positioning[] = { { 0, 5.5, 0 }, 90 };
			placementTime = 2;
			onPlaced = "(_this select 0) setDamage 1; _this remoteExecCall [""ULP_SRV_fnc_registerStinger"", 2];";
		};

		class RoadCone {
			displayName = "Road Cone";
			className = "RoadCone_F";
			positioning[] = { { 0, 3, 0.5 }, 0 };
			placementTime = 2;
			onPlaced = "";
		};

		class RoadConeWithLight : RoadCone {
			displayName = "Road Cone With Light";
			className = "RoadCone_L_F";
		};

		class SinglePortableLight : RoadCone {
			displayName = "Portable Light (Single)";
			className = "Land_PortableLight_single_F";
		};

		class DoublePortableLight : RoadCone {
			displayName = "Portable Light (Double)";
			className = "Land_PortableLight_double_F";
		};

		class TapeSign : RoadCone {
			displayName = "Red-White Tape";
			className = "TapeSign_F";
		};
	};
};