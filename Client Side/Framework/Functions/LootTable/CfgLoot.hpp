class CfgLoot {
	class Basic {
		class AlsdaVan {
			chance = 0.99;
			class C_Van_01_transport_F {
				amount = 1; // Amount is above 0 so it adds a vehicle of this class and texutre to their garage, ignoring unlocks and limits...
				texture = "Aldsa";
			};
		};

		class RidgeJeep {
			chance = 0.90;
			class C_Offroad_02_unarmed_F {
				amount = 0; // Amount 0 on vehicle means just unlock the texture...
				texture = "Ridge";
			};
		};

		class Taser {
			chance = 0.80;
			class hgun_P07_F {
				amount = 1;
			};
			class 10Rnd_9x21_Mag {
				amount = 5;
			};
		};

		class RandomVirtualItems {
			chance = 0;
			class BrokenTimepiece {
				amount = 1;
			};
			class AncientAmber {
				amount = 3;
			};
		};
	};
};