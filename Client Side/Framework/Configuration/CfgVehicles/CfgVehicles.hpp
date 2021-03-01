class CfgVehicles {
	rentPerc = 0.4; // 40%;
	sellPerc = 0.3; // 30%
	retrievalPerc = 0.15; // 15%

	class Base {
		buyPrice = 1000;
		virtualSpace = 5;
		conditions = "true";
		class Textures {};
	};

	class BaseTexture {
		buyPrice = 0;
		textures[] = {};
		conditions = "true";
	};
	
	class C_SUV_01_F : Base {
		virtualSpace = 30;
		class Textures {
			class PoliceWhite : BaseTexture {
				textures[] = {
					"data\textures\vehicles\land\police\police_suv_white.paa"
				};
			};
		};
	};
};