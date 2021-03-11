#define true 1
#define false 0

class CfgPatches {
    class ULPServer {
        requiredVersion = 2.02;
        requiredAddons[] = {};
        units[] = {};
        weapons[] = {};

        class Settings {
            class DonationGoal {
                type = "BOOL";
                default = false;
                global = true;
            };
        };
    };
};

#include "CfgFunctions.hpp"