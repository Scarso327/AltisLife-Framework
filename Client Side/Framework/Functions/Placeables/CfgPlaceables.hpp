class CfgPlaceables {
	maxPlaceables = 20;

	class Objects {
		// Spikes
		class SpikeStrip { // Filtered
			displayName = "Stinger";
			className = "Land_Razorwire_F";
			positioning[] = { { 0, 5.5, 0 }, 90 };
			placementTime = 2;
			onPlaced = "(_this select 0) setDamage 1; _this remoteExecCall [""ULP_SRV_fnc_registerStinger"", 2];";
		};

		// Medical
		class Stretcher { // Filtered
			displayName = "Stretcher";
			className = "Land_Stretcher_01_F";
			positioning[] = { { 0, 1.5, 0.5 }, 90 };
			placementTime = 5;
			onPlaced = "private _stretcher = _this param [0, objNull, [objNull]]; if (isNull _stretcher) exitWith {}; _stretcher allowDammage false; _stretcher enableSimulation false;";
			onRemoved = "private _attachedUnit = (_this select 0) getVariable [""unitAttached"", objNull]; if !(isNull _attachedUnit) then { detach _attachedUnit; };";
		};

		// Cones
		class RoadCone_F { // Filtered
			displayName = "Road Cone";
			className = "RoadCone_F";
			positioning[] = { { 0, 3, 0.5 }, 0 };
			placementTime = 2;
			onPlaced = "";
		};
		class RoadCone_L_F : RoadCone_F { // Filtered
			displayName = "Road Cone (Light";
			className = "RoadCone_L_F";
		};
		class Pole_F : RoadCone_F { // Filtered
			displayName = "Pole";
			className = "Pole_F";
		};

		// Portable Lights
		class Land_PortableLight_single_F : RoadCone_F {
			displayName = "Portable Light (Single)";
			className = "Land_PortableLight_single_F";
		};
		class Land_PortableLight_double_F : RoadCone_F {
			displayName = "Portable Light (Double)";
			className = "Land_PortableLight_double_F";
		};
		class Land_PortableLight_02_single_yellow_F : RoadCone_F {
			displayName = "Portable Lamp (Single, Yellow)";
			className = "Land_PortableLight_02_single_yellow_F";
		};
		class Land_PortableLight_02_double_yellow_F : RoadCone_F {
			displayName = "Portable Lamp (Double, Yellow)";
			className = "Land_PortableLight_02_double_yellow_F";
		};
		class Land_PortableLight_02_quad_yellow_F : RoadCone_F {
			displayName = "Portable Lamp (Quad, Yellow)";
			className = "Land_PortableLight_02_quad_yellow_F";
		};

		// Gates
		class Land_BarGate_F : RoadCone_F {
			displayName = "Bar Gate";
			className = "Land_BarGate_F";
		};
		class Land_RoadBarrier_01_F : RoadCone_F {
			displayName = "Bar Gate (V2)";
			className = "Land_RoadBarrier_01_F";
		};

		// Barriers
		class TapeSign_F : RoadCone_F { // Filtered
			displayName = "Red-White Tape";
			className = "TapeSign_F";
		};
		class RoadBarrier_F : RoadCone_F { // Filtered
			displayName = "Road Barrier";
			className = "RoadBarrier_F";
		};
		class RoadBarrier_small_F : RoadCone_F { // Filtered
			displayName = "Road Barrier (Small)";
			className = "RoadBarrier_small_F";
		};
		class PlasticBarrier_03_orange_F : RoadCone_F { // Filtered
			displayName = "Plastic Barrier (Large, Orange)";
			className = "PlasticBarrier_03_orange_F";
		};
		class PlasticBarrier_03_blue_F : RoadCone_F { // Filtered
			displayName = "Plastic Barrier (Large, Blue)";
			className = "PlasticBarrier_03_blue_F";
		};
		class PlasticBarrier_02_yellow_F : RoadCone_F { // Filtered
			displayName = "Plastic Barrier (Medium, Yellow)";
			className = "PlasticBarrier_02_yellow_F";
		};
		class PlasticBarrier_02_grey_F : RoadCone_F { // Filtered
			displayName = "Plastic Barrier (Medium, Grey)";
			className = "PlasticBarrier_02_grey_F";
		};
		class Land_CncBarrier_F : RoadCone_F {
			displayName = "Concrete Barrier";
			className = "Land_CncBarrier_F";
		};
		class Land_CncBarrier_stripes_F : RoadCone_F {
			displayName = "Concrete Barrier (Stripes)";
			className = "Land_CncBarrier_stripes_F";
		};

		// Sandbags
		class Land_SandbagBarricade_01_half_F : RoadCone_F {
			displayName = "Sandbag Barricade (Short)";
			className = "Land_SandbagBarricade_01_half_F";
		};
		class Land_BagFence_Long_F : RoadCone_F {
			displayName = "Sandbag Wall (Long)";
			className = "Land_BagFence_Long_F";
		};
		class Land_BagFence_Short_F : RoadCone_F {
			displayName = "Sandbag Wall (Short)";
			className = "Land_BagFence_Short_F";
		};
		class Land_BagFence_Round_F : RoadCone_F {
			displayName = "Sandbag Wall (Round)";
			className = "Land_BagFence_Round_F";
		};

		// Hedgehogs
		class Land_CzechHedgehog_01_old_F : RoadCone_F {
			displayName = "Czech Hedgehog";
			className = "Land_CzechHedgehog_01_old_F";
		};

		// Camping
		class Land_CampingTable_white_F : RoadCone_F {
			displayName = "Camping Table (White)";
			className = "Land_CampingTable_white_F";
		};
		class Land_CampingTable_small_white_F : RoadCone_F {
			displayName = "Camping Table (Small, White)";
			className = "Land_CampingTable_small_white_F";
		};
		class Land_CampingChair_V2_white_F : RoadCone_F {
			displayName = "Camping Chair (White)";
			className = "Land_CampingChair_V2_white_F";
		};
		class Land_FieldToilet_F : RoadCone_F {
			displayName = "Field Toilet";
			className = "Land_FieldToilet_F";
		};

		// Targets
		class Target_F : RoadCone_F { // Filtered
			displayName = "Simple Target";
			className = "Target_F";
		};
		class Land_Target_Dueling_01_F : RoadCone_F {
			displayName = "Dueling Target";
			className = "Land_Target_Dueling_01_F";
		};
		class Scarecrow_01_F : RoadCone_F { // Filtered
			displayName = "Scarecrow";
			className = "Scarecrow_01_F";
		};

		// Flags
		class Flag_UK_F : RoadCone_F { // Filtered
			displayName = "Flag (UK)";
			className = "Flag_UK_F";
		};
		class Flag_AltisColonial_F : RoadCone_F { // Filtered
			displayName = "Flag (Altis Colonial)";
			className = "Flag_AltisColonial_F";
		};
		class Flag_RedCrystal_F : RoadCone_F { // Filtered
			displayName = "Flag (Red Crystal)";
			className = "Flag_RedCrystal_F";
		};

		// Lights
		class PortableHelipadLight_01_yellow_F : RoadCone_F {
			displayName = "Portable Light (Yellow)";
			className = "PortableHelipadLight_01_yellow_F";
		};
		class PortableHelipadLight_01_white_F : RoadCone_F {
			displayName = "Portable Light (White)";
			className = "PortableHelipadLight_01_white_F";
		};
		class PortableHelipadLight_01_red_F : RoadCone_F {
			displayName = "Portable Light (Red)";
			className = "PortableHelipadLight_01_red_F";
		};
		class PortableHelipadLight_01_green_F : RoadCone_F {
			displayName = "Portable Light (Green)";
			className = "PortableHelipadLight_01_green_F";
		};
		class PortableHelipadLight_01_blue_F : RoadCone_F {
			displayName = "Portable Light (Blue)";
			className = "PortableHelipadLight_01_blue_F";
		};
		class PortableHelipadLight_01_F : RoadCone_F {
			displayName = "Portable Light (Pink)";
			className = "PortableHelipadLight_01_F";
		};
	};
};