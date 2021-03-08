if (isClass (configFile >> "CfgPatches" >> "ULPServer")) then {
	[] call ULP_SRV_fnc_init;
};