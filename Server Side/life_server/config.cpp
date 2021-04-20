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
            class Governor {
                type = "ARRAY";
                default = """[]""";
                constant = false;
                global = true;
            };
            class GovernorSettings {
                type = "HASHMAP";
                default = """[]""";
                constant = false;
                global = true;
            };
        };
        
        class EventLogs {
            class Dispute { 
                params = 1;
            };

            class Spawn {
                params = 2;
            };

            class Money {
                params = 5;
            };

            class Executed {
                params = 3;
            };

            class Loot : Spawn {};
            class Group : Executed {};
            class Admin : Executed {};
            class House : Executed {};
            class Bleedout : Spawn {};
            class Misc {};
        };

        #include "Functions\Gathering\CfgGathering.hpp"
    };
};

#include "CfgFunctions.hpp"