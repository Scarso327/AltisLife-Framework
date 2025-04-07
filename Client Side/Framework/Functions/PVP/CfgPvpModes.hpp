class CfgPvpModes {
	days[] = { "Saturday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
	time[] = { 19, 15 }; // Hour, Minute
	voteDuration = 2 * 60; // In Seconds

	class Modes {
		class Conflict {
			displayName = "Conflict";
			markerColour = "Color3_FD_F";
			maxScore = 3000;
			maxDuration = 1 * 60 * 60; // In Seconds
			tickDuration = 3 * 60; // In Seconds
			class NodeTypes {
				class LowTier {
					displayName = "Low Tier";
					marker = "mil_circle";
					score = 300;
				};
				class MidTier {
					displayName = "Mid Tier";
					marker = "mil_objective";
					score = 600;
				};
				class HighTier {
					displayName = "High Tier";
					marker = "mil_warning";
					score = 1000;
				};
			};
			class Events {
				onConflictNodeSpawned = "_this call ULP_fnc_onConflictNodeSpawned";
				onConflictNodeCapturing = "_this call ULP_fnc_onConflictNodeCapturing";
				onConflictNodeCaptured = "_this call ULP_fnc_onConflictNodeCaptured";
				onStart = "_this call ULP_fnc_onConflictStarted";
				onStop = "_this call ULP_fnc_onConflictEnded";
			};
			class ServerEvents {
				onStart = "_this call ULP_SRV_fnc_startConflict";
				onStop = "_this call ULP_SRV_fnc_stopConflict";
			};
			class Locations {
				class Altis {
					class TestLocation {
						displayName = "Test Location";
						class Nodes {
							class LocationOne {
								displayName = "LocationOne";
								position[] = { 7288.51,13952.9,0.00151062 };
								radius = 100;
							};
							class LocationTwo : LocationOne {
								displayName = "LocationTwo";
								position[] = { 6455.57,13771.9,0.001297 };
							};
							class LocationThree : LocationOne {
								displayName = "LocationThree";
								position[] = { 8317.06,13449.4,0.00215912 };
							};
							class LocationFour : LocationOne {
								displayName = "LocationFour";
								position[] = { 6425.35,14577.9,0.00155258 };
							};
						};
						class Markers {

						};
					};
				};
			};
		};
	};
};