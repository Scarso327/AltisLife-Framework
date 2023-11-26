<b>Mantle Network</b> is an online community built entirely upon the needs of our player base and associated partners. Operating as the public image of our subsidiary, North London RPC, we aim to build bridges between groups who would usually remain apart. As a constantly growing collective, we are constantly forming networks with our partners and like-minded player bases, creating a well informed and relevant Network that is ready to meet the demands of people all who join. Backed by competent development and administration teams, we only move forward in supplying high quality and reliable services for our members to enjoy across all platforms.

# Development Team:
  - <b>Jack Farhall</b>, jackfarhall@gmail.com
  - <b>Lewis Mackinnon</b>, lewisallanmackinnon@gmail.com

# Art Team:
  - <b>Ace Boyden</b>
    
# Communication Methods:
  - Website: https://mantlenetwork.co.uk/
  - Discord: https://mantlenetwork.co.uk/discord

# Features
This framework has a wide range of features. We've listed a load but many more exist!
<details>

<summary>View Feature List</summary>

  - <b>Advanced Clothing Textures</b>
    - Support for multiple textures per classname.
    - No side dependent filters so police clothing on a civilian looks like police clothing!
  - <b>Queued Inventories</b>
    - Virtual inventories have a queue system allowing multiple people to view them while someone adds and takes items.
  - <b>Reputation</b>
    - Increases or decreases certain equipment prices
  - <b>Dynamic Locations</b>
    - Certain gather locations are configured to change location each restart.
  - <b>Non-Side Controlled Factions</b>
    - Factions aren't decided by ArmA 3's side system allowing for, in theory, unlimited factions.
    - Police
    - NHS
    - HATO
      - Vehicle Clamping!
    - Civilians
  - <b>Progression</b>
    - Leveling
    - Professions
    - Achievements
  - <b>Government System</b>
    - Elections for the island's Governor.
    - Tied into group system (Perks to allow members to become protection officers granting unique access).
  - <b>Crafting</b>
  - <b>Placeables</b>
  - <b>High Levels of Customisation</b>
    - Nearly everything can be configured via configs without code edits.
  - <b>Multiple Sirens</b>
    - Support for togglable sirens that stop without delay!
  - <b>Simple Identification System</b>
    - All players spawn with an ID card they can share to officers.
    - IDs can be forged and then used to change your displayed name.
  - <b>Unique Runs</b>
    - Freight Runs
    - Smuggling
    - Archeology
  - <b>Warrants</b>
    - Civilians can have warrants put out for their arrest.
    - Notes can be added for extra context, automatic warrants add automatic notes (Murder adds weapon used for example).
  - <b>Buffed Run</b>
    - Each restart a random run is buffed so the best runs won't always be the same!
  - <b>Transaction History</b>
    - Every in-out from your bank is recorded and available to view from any cashpoint.
  - <b>Groups</b>
    - Types
      - Political
      - Criminal
      - Company
    - Leveling
    - Shared Buffs
    - Ranks
      - Permissions
    - Offline Admin (Kick, Promote, Demote Players even while they're offline)
  - <b>Major Crimes</b>
    - All crimes provide unique rewards and requirements.
    - Variety
      - HM Treasury
      - HMS Liberty
      - Police Evidence Storage
      - Research Storage
  - <b>Ace-Insipred Revivial System</b>
    - Instead of clicking a button and waiting, random injuries are added that required bandages before you can be revived!
  - <b>Capturable Locations</b>
    - Static Cartels
      - Drug Cartels
        - Provides increased sell prices for your gang.
        - Your gang gets a cut of all drug sales on the island.
        - Access to drug purifier.
      - Arms Cartels
        - Discounts on illegal weapons.
        - Cut of all illegal weapon sales.
    - Criminal Hideouts
    - Gang Bases (Weekly bidding wars)
  - <b>Perks</b>
    - Personal
    - Group (Unique per Group Type)
  - <b>Vehicle Transfers</b>
    - Want to gift a vehicle to a friend? Go ahead!
  - <b>Housing</b>
    - Naming
    - Sharing (Can provide your group with access to your houses)
    - Storage (Both for virtual and phyiscal items)
  - <b>Goals</b>
    - Personal
  - <b>Random Events</b>
    - Airdrops
    - Popup Cartels
    - Shipwrecks
  - <b>Multi Map Support</b>
  - <b>Mail</b>
    - Allows rewards to be deposited and used later.
  - <b>Customisable Player Tags</b>
    - Player tags can be customised with unique icons, titles, and colours!
  - <b>Pleasing Design</b>
    - All UI elements follow the same style and designed to be easy on the eyes and to use!
    - Icons for everything! All following the same style.
    - Consistent Map Markers, gathering zones, processors, stores, etc all share colours and icons depending on type and legality.

</details>

# Mutli Server Support

Currently the framework isn't suitable for running multiple servers as certain features don't work and would introduce expliots / inconsistency. Below we've listed the features that would need work / considerations to support multiple servers. Future work will be completed to allow for this.

  - <b>Housing</b>
    - When houses are bought / sold they'll only be setup for one server but exist in same table allowing conflicts.