class CfgOptions {
	class General {
		title = "General";

		class EnableWelcome {
			name = "Enable Welcome Message";
			tooltip = "When enabled, text with server information will be displayed when first spawning.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
			condition = "true";
		};

		class EnableStreamerMode : EnableWelcome {
			name = "Enable Streamer Mode";
			tooltip = "When enabled, certain aspects of your game maybe hidden or censored for privacy.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 0 };
		};

		class EnableAutoDecline : EnableWelcome {
			name = "Enable Ignore Group Invites";
			tooltip = "When enabled, group invites will automatically be declined.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 0 };
		};

		class NightLight : EnableWelcome {
			name = "Ambient Night Light";
			tooltip = "This is the level of light that will light up the map during night.";
			type = "SLIDER";
			values[] = { { 0, 0.5 }, 0.5, { 0.1, 0.1 } };
		};

		class EnableAutoChatSwitch : EnableWelcome {
			name = "Enable Vehicle Chat Switch";
			tooltip = "When enabled, entering a vehicle will automatically switch channel.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};
	};

	class Audio {
		title = "Audio";

		class EffectsFade {
			name = "Effects Volume";
			tooltip = "This is the effects volume that will be used when using ear plugs.";
			type = "SLIDER";
			values[] = { { 0, 1 }, 0.25, { 0.1, 0.1 } };
			condition = "true";
		};
		
		class MusicFade : EffectsFade {
			name = "Music Volume";
			tooltip = "This is the music volume that will be used when using ear plugs.";
			type = "SLIDER";
			values[] = { { 0, 1 }, 0.25, { 0.1, 0.1 } };
		};

		class EnableMessageAlert : EffectsFade {
			name = "Enable Message Alert";
			tooltip = "When enabled, you will receive a audio alert when a message is recevied.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};

		class EnableAmbientSounds : EffectsFade {
			name = "Enable Ambient Sounds";
			tooltip = "When enabled, you will be able to hear ArmA's ambient sounds.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};
	};

	class HUD {
		title = "User Interface";

		class EnableHUD {
			name = "Enable HUD";
			tooltip = "When enabled, information such as health, water, etc are displayed on screen.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
			condition = "true";
		};

		class EnableXPBar : EnableHUD {
			name = "Enable XP Bar";
			tooltip = "If the hud is enabled as well as this, you'll have your xp displayed on screen.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};

		class EnablePlayerTags : EnableHUD  {
			name = "Enable Player Tags";
			tooltip = "When enabled, information about a player is displayed above their heads.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};

		class ShowOwnTags : EnableHUD  {
			name = "Show Own Player Tags";
			tooltip = "If player tags are enabled as well as this, you'll see your own player tag.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};

		class SideChat : EnableHUD  {
			name = "Show Side Chat";
			tooltip = "When enabled, messages in side chat will be displayed.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
		};
	};

	class Indicators {
		title = "Group Indicators";

		class EnableIndicators {
			name = "Enable Indicators";
			tooltip = "When enabled, hexagons showing location of group members will be shown.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
			condition = "true";
		};

		class EnableFactionColouring {
			name = "Enable Faction Colouring";
			tooltip = "When enabled, indicators will be coloured according to their uniform.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
			condition = "[player, [""Police"", ""Medic""]] call ULP_fnc_isFaction";
		};

		class EnableNamesOnIndicators : EnableIndicators {
			name = "Enable Names on Indicators";
			tooltip = "When enabled, group member's names with show under their hexagons.";
		};

		class IndicatorDistance : EnableIndicators {
			name = "Indicators Distance";
			tooltip = "This is the distance at which group indicators will be shown. (20 - 2000m)";
			type = "SLIDER";
			values[] = { { 20, 2000 }, 2000, { 1, 1, 1 } };
		};
	};

	class Cartels {
		title = "Cartels";

		class NotifyPayment {
			name = "Display Cartel Payments";
			tooltip = "When enabled, you'll be told exactly how much you and the group were paid from cartels.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
			condition = "true";
		};
	};

	class Chat {
		title = "Chat";

		class EnableMessagesIncapacitated {
			name = "Enable Incapacitated Messages";
			tooltip = "When enabled, incapacitated and injured messages will be display in chat.";
			type = "DROPDOWN";
			values[] = { { {"Enabled", 1}, {"Disabled", 0} }, 1 };
			condition = "true";
		};

		class EnableMessagesBleedout : EnableMessagesIncapacitated {
			name = "Enable Bleedout Messages";
			tooltip = "When enabled, bleedout and executed messages will be display in chat.";
		};

		class EnableMessagesTicket : EnableMessagesIncapacitated {
			name = "Enable Ticket Messages";
			tooltip = "When enabled, ticket messages will be display in chat.";
		};

		class EnableMessagesRevived : EnableMessagesIncapacitated {
			name = "Enable Revival Messages";
			tooltip = "When enabled, revival messages will be display in chat.";
		};

		class EnableMessagesPrisoned : EnableMessagesIncapacitated {
			name = "Enable Prison Messages";
			tooltip = "When enabled, prison messages will be display in chat.";
		};

		class EnableMessagesVehicle : EnableMessagesIncapacitated {
			name = "Enable Vehicle Messages";
			tooltip = "When enabled, garaged, impounded and crushed messages will be display in chat.";
		};
	};
};