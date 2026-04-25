class CfgFunctions {

    class ULPCore_Functions {
        tag = "ULP_CRE";

		class Root {
			file = "\ulp_core";
			class init {};
		};
    };

    class ULPCore_Persistence {
        tag = "ULP_DB";

        class Root {
            file = "\ulp_core\Persistence";
            class initDb {};
        };

        class MySQL {
            file = "\ulp_core\Persistence\MySQL";
            class asyncCall {};
            class mresToArray {};
            class mresArray {};
            class mresString {};
        };
    };
};