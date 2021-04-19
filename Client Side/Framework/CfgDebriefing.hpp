class CfgDebriefing {
    class Abort {
        title = "Left the Game";
        subtitle = "Thanks For Playing!";
        description = "Your data has been synced and you've returned to the lobby.";
        pictureBackground = "";
        picture = "\A3\ui_f\data\GUI\Cfg\Hints\Tasks_ca.paa";
        pictureColor[] = {0,0.3,0.6,1};
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
};