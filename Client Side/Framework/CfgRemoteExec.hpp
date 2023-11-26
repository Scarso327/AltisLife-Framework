#define ANYONE 0
#define CLIENT 1
#define SERVER 2

class CfgRemoteExec {
    class Commands {
        mode = 1;
        jip = 0;
        
        class switchMove {};
    };

    class Functions {
        mode = 1;
        jip = 0;

        class ULP_fnc_setFuel {};
        class ULP_fnc_lock {};
        class ULP_fnc_say3D {};

        class ULP_fnc_chatMessage {};
        class ULP_fnc_restrain {};
        class ULP_fnc_onKnocked {};
        class ULP_fnc_setPlayerInfo {};
        class ULP_fnc_initVehicle {};
        class ULP_fnc_vehicleLights {};
        class ULP_fnc_invokeEvent {
            validJipEvents[] = { "OnSpawnAirdrop", "OnSpawnShipwreck", "OnSpawnPopupCartel" };
            jip = 1; // Used for stuff like airdrops
        };
        class ULP_fnc_receiveMessage {};
        class ULP_fnc_lockForFactions {};
        class ULP_fnc_receivedBlood {};
        class ULP_fnc_applyTextures {};
        class ULP_fnc_spikeVehicle {};
        class ULP_fnc_flipVehicle {};

        class ULP_fnc_createVehicle {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_cartelHud {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_imprison {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_recieveMoney {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_revived {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_robMoney {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_checkMoney {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_putVehicleUnit {
            allowedTargets = CLIENT;
        };
        class ULP_fnc_recieveItem {
            allowedTargets = CLIENT;
        };

        class ULP_SRV_fnc_queryPlayerInfo {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_savePlayerInfo {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_savePlayerState {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_createVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_storeVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_getGarage {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_retrieveVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_destroyVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_transferVehicle {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_createGroup {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_registerCargoUser {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_unregisterCargoUser {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_logPlayerEvent {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_buyHouse {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_sellHouse {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_setHouseShared {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_setHouseName {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_handleGroupFunds {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_reputation {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_hidePlayer {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_disbandGroup {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_claimAirdrop {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_claimShipwreck {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_toggleVaults {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_setGroupId {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_setGroupOwner {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_addGroupXP {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_addGroupBuff {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_addWarrant {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_saveLegislation {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_enlistCandidate {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_getCandidates {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_submitVote {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_addBaseBid {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_registerStinger {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_fetchWarrants {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_clearWarrants {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_deleteCrime {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_getStorage {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_saveStorage {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_setGroupTax {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_addGroupMember {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_getMail {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_updateMail {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_rigPollingStation {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_spawnEvent {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_getCommunityGoals {
            allowedTargets = SERVER;
        };
        class ULP_SRV_fnc_addCommunityGoalContribution {
            allowedTargets = SERVER;
        };

        class bis_fnc_debugconsoleexec {};
    };
};