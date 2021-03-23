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
                constant = true;
                global = true;
            };
            class ThreatLevel {
                type = "NUMBER";
                bounds[] = { 0, 4 }; // Number min / max...
                default = 0;
                constant = true;
                global = true;
            };
            class Day {
                type = "STRING";
                default = "2021-01-01";
                constant = false;
                global = false;
            };
            class Week {
                type = "NUMBER";
                default = "12";
                constant = false;
                global = false;
            };
        };
    };
};

#include "CfgFunctions.hpp"