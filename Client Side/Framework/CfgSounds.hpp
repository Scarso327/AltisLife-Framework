class CfgSounds {
    sounds[] = {};
	
    class britishSiren {
        name = "britishSiren";
        sound[] = {"\Data\Sounds\britishSiren.ogg", 1.0, 1};
        titles[] = {};
    };

    class Siren1 {
        name = "siren1";
        sound[] = {"\Data\Sounds\Sirens\siren_1.ogg", 1.0, 1};
        titles[] = {};
    };

    class Siren2 : Siren1 {
        name = "siren1";
        sound[] = {"\Data\Sounds\Sirens\siren_2.ogg", 1.0, 1};
    };

    class Siren3 : Siren1 {
        name = "siren1";
        sound[] = {"\Data\Sounds\Sirens\siren_3.ogg", 1.0, 1};
    };

    class Siren4 : Siren1 {
        name = "siren1";
        sound[] = {"\Data\Sounds\Sirens\siren_4.ogg", 1.0, 1};
    };

    class taserSound {
        name = "taserSound";
        sound[] = {"\Data\Sounds\taser.ogg", 0.5, 1};
        titles[] = {};
    };

    class lockCarSound {
        name = "lockCarSound";
        sound[] = {"\Data\Sounds\carLock.ogg", 1.0, 1};
        titles[] = {};
    };

    class unlockCarSound {
        name = "unlockCarSound";
        sound[] = {"\Data\Sounds\carUnlock.ogg", 0.75, 1};
        titles[] = {};
    };

    class metalDetector {
        name = "metalDetector";
        sound[] = {"\Data\Sounds\metalDetector.ogg", 0.75, 1}; 
        titles[] = {};
    };

    class panicButton {
        name = "panicButton";
        sound[] = {"\Data\Sounds\panicButton.ogg", 1.0, 1};
        titles[] = {};
    };

    class messageNotification {
        name = "messageNotification";
        sound[] = {"\Data\Sounds\messageNotification.ogg", 1.0, 1};
        titles[] = {};
    };

    class handCuff {
        name = "handCuff";
        sound[] = {"\Data\Sounds\handCuff.ogg", 0.5, 1};
        titles[] = {};
    };
};