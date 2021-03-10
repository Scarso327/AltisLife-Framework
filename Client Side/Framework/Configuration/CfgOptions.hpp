class CfgOptions {
	class General {
		title = "General";

		class EnableWelcome {
			name = "Enable Welcome Message";
			tooltip = "When enabled, text with server information will be displayed when first spawning.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};

		class EnableStreamerMode {
			name = "Enable Streamer Mode";
			tooltip = "When enabled, certain aspects of your game maybe hidden or censored for privacy.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 0 };
		};
	};

	class HUD {
		title = "User Interface";
	};
};