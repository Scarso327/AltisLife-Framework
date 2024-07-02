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
                default = "0"; // Default should be in the format it would be saved in the database and use text type in config
                constant = true;
                global = true;
            };
            class ThreatLevel {
                type = "NUMBER";
                bounds[] = { 0, 4 }; // Number min / max...
                default = "0";
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
            class Election {
                type = "BOOL";
                default = "0";
                constant = false;
                global = true;
            };
            class NextElection {
                type = "STRING";
                default = "2021-01-01";
                constant = false;
                global = false;
            };
            class BaseBidsActive {
                type = "BOOL";
                default = "0";
                constant = false;
                global = true;
            };
        };
        
        class EventLogs {
            class Dispute { 
                params = 1;
            };
            class Revive : Dispute {};
            class CaptureHideout : Dispute {};
            class SeizeComms : Dispute {};
            class NLR : Dispute {};

            class Spawn {
                params = 2;
            };
            class Goal : Spawn {};
            class Mission : Spawn {};
            class Ticketed : Spawn {};
            class Imprisoned : Spawn {};
            class Robbery : Spawn {};
            class Craft : Spawn {};

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
            class Election : Spawn {};
            class BaseBid : Spawn {};
            class Cartel : Dispute {};
            class Misc : Dispute {};

            class Mail {
                params = 6;
            };
        };

        #include "Functions\Gathering\CfgGathering.hpp"
    };
};

#include "CfgFunctions.hpp"