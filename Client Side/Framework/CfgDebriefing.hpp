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
    class Blacklisted {
        title = "Unable to Join";
        subtitle = "You are currently blacklisted";
        description = "Please contact a member of this faction's command for more information";
    };
	class BadName {
    title = "Forbidden Player Name";
    subtitle = "You shall not pass!";
    description = "Your player name contains non standard A-Z letters that cannot be used on this server.";
    pictureBackground = "";
    picture = "";
    pictureColor[] = {0,0.3,0.6,1};
};

class GlobalBan {
    title = "You are Global Banned!";
    subtitle = "You shall not pass!";
    description = "You are global banned and cannot play on this server, sorry!";
    pictureBackground = "";
    picture = "";
    pictureColor[] = {0,0.3,0.6,1};
};

class LoadFailed {
    title = "Loading client scripts failed";
    subtitle = "Please rejoin";
    description = "Some client side scripts failed to load. Please do not alt+tab while joining. If this issue persists, contact a developer.";
    pictureBackground = "";
    picture = "";
    pictureColor[] = {0,0.3,0.6,1};
};

};