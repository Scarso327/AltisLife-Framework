class CfgOptions {
	class General {
		title = "General";

		class EnableWelcome {
			name = "Enable Welcome Message";
			tooltip = "When enabled, text with server information will be displayed when first spawning.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};

		// TODO
		class EnableStreamerMode {
			name = "Enable Streamer Mode";
			tooltip = "When enabled, certain aspects of your game maybe hidden or censored for privacy.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 0 };
		};
	};

	class Audio {
		title = "Audio";

		class EffectsFade {
			name = "Effects Volume";
			tooltip = "This is the effects volume that will be used when using ear plugs.";
			type = "SLIDER";
			values[] = { { 0, 1 }, 0.25, { 0.1, 0.1 } };
		};
		
		class MusicFade {
			name = "Music Volume";
			tooltip = "This is the music volume that will be used when using ear plugs.";
			type = "SLIDER";
			values[] = { { 0, 1 }, 0.25, { 0.1, 0.1 } };
		};
	};

	class HUD {
		title = "User Interface";

		class EnablePlayerTags {
			name = "Enable Player Tags";
			tooltip = "When enabled, information about a player is displayed above their heads.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};

		class ShowOwnTags {
			name = "Show Own Player Tags";
			tooltip = "If player tags are enabled as well as this, you'll see your own player tag.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};
	};
};