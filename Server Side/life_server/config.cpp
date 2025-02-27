#define true 1
#define false 0

class CfgPatches {
    class ULPServer {
        requiredVersion = 2.02;
        requiredAddons[] = {};
        units[] = {};
        weapons[] = {};
        serverCommandPassword = "KqpdsYBdMstYfFt";

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
            class Season {
                type = "NUMBER";
                default = "1";
                constant = false;
                global = false;
            };
            class NextSeason {
                type = "STRING";
                default = "2025-02-23";
                constant = false;
                global = false;
            };
        };
        
        class EventLogs {
            class Dispute { 
                params[] = { "player" };
            };
            class Revive : Dispute {};

            class CaptureHideout {
                params[] = { "siteName" };
            };

            class NLR {
                params[] = { "position" };
            };
            class ReturnedToLobby : NLR {};

            class ScriptLog  {
                params[] = { "script" };
            };

            class Spawn {
                params[] = { "name", "position" };
            };


            class Goal {
                params[] = { "title", "tier" };
            };

            class Mission {
                params[] = { "title", "tier" };
            };

            class Ticketed {
                params[] = { "player", "fine" };
            };

            class Imprisoned {
                params[] = { "player", "duration" };
            };

            class Robbery {
                params[] = { "player", "cash" };
            };

            class Craft {
                params[] = { "item", "amount" };
            };

            class Injured {
                params[] = { "position", "loadout" };
            };

            class Loot {
                params[] = { "type", "loot" };
            };

            class Election {
                params[] = { "name", "steamid", "votes" };
            };

            class BaseBid {
                params[] = { "type", "groupid", "bid" };
            };

            class Group {
                params[] = { "type", "groupid", "funds" };
            };

            class Bleedout {
                params[] = { "position", "loadout", "isWounded" };
            };

            class Admin {
                params[] = { "type", "time", "params" };
            };

            class House {
                params[] = { "type", "position", "value" };
            };

            class InjuredBy {
                params[] = { "killer", "position", "loadout", "isRedzone" };
            };

            class Executed {
                params[] = { "killer", "position", "loadout", "isWounded" };
            };

            class Money {
                params[] = { "type", "action", "total", "amount", "reason" };
            };

            class Mail {
                params[] = { "id", "type", "className", "data", "totalAmount", "claimedAmount" };
            };

            class TransferVeh {
                params[] = { "veh", "player" };
            };

            class DestroyVeh {
                params[] = { "veh", "texture" };
            };
        };

        class Stats {
            class Kills {
                query = "SELECT COUNT(*) FROM `logs` WHERE `jsonContent` IS NOT NULL AND `season`='%1' AND `event`='InjuredBy' AND JSON_VALUE(`jsonContent`, '$.killer') = '%2' AND JSON_VALUE(`jsonContent`, '$.isRedzone') = 'true'";
            };
            class Deaths {
                query = "SELECT COUNT(*) FROM `logs` WHERE `jsonContent` IS NOT NULL AND `season`='%1' AND `event`='InjuredBy' AND `pid` = '%2' AND JSON_VALUE(`jsonContent`, '$.isRedzone') = 'true'";
            };
        };

        #include "Functions\Gathering\CfgGathering.hpp"
    };
};

#include "CfgFunctions.hpp"