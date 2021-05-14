class CfgDebriefing {
    class Abort {
        title = "Left the Game";
        subtitle = "Thanks For Playing!";
        description = "Your data has been synced and you've returned to the lobby.";
        pictureBackground = "";
        picture = "\A3\ui_f\data\GUI\Cfg\Hints\Doors_ca.paa";
        pictureColor[] = {1,1,1,1};
    };
    class NotWhitelisted : Abort {
        title = "Unable to Join";
        subtitle = "You are not currently whitelisted";
        description = "Please contact a member of this faction's command for more information";
    };
    class Blacklisted : Abort {
        title = "Unable to Join";
        subtitle = "You are currently blacklisted";
        description = "Please contact a member of this faction's command for more information";
    };

    // Fini Anti-Cheat
	class BadName : Abort {
        title = "Forbidden Player Name";
        subtitle = "Change your player name";
        description = "Your player name contains non standard A-Z letters that cannot be used on this server.";
    };
    class GlobalBan : Abort {
        title = "You are Global Banned";
        subtitle = "Please contact Fini to resolve this";
        description = "You are global banned and cannot play on this server.";
    };
    class LoadFailed : Abort {
        title = "Loading client scripts failed";
        subtitle = "Please rejoin";
        description = "Some client side scripts failed to load. Please do not alt+tab while joining. If this issue persists, contact a developer.";
    };
};