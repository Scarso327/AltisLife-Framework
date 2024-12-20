# AltisLife-Framework

A feature-rich framework for developing Life RPG modes for ArmA 3.

## Description

A highly configurable mission developed with inspiration from a variety of ArmA 3 Life Servers (End Days, PhoenixRP, Grand Theft Arma, and RPUK, just to name a few).

<details>
<summary>View Feature List</summary>

  - <b>Advanced Clothing Textures</b>
    - Support for multiple textures per classname.
    - No side-dependent filters so police clothing on a civilian looks like police clothing!
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
    - All players spawn with an ID card they can share with officers.
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
  - <b>Ace-Insipred Revival System</b>
    - Instead of clicking a button and waiting, random injuries are added that require bandages before you can be revived!
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
    - Storage (Both for virtual and physical items)
  - <b>Goals</b>
    - Personal
    - Community
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
    - All UI elements follow the same style and are designed to be easy on the eyes and to use!
    - Icons for everything! All follow the same style.
    - Consistent Map Markers, gathering zones, processors, stores, etc all share colours and icons depending on type and legality.

</details>

## Getting Started

### Dependencies

* EXTDB3 - Available in the `ServerSide/@extDB3` folder as the official repo is dead

### Setting Up
This is a very brief list of things you need to do to set up and play the mission.

* You need a database that supports MySQL 8.0.13 or later to run the `altislife_mysql_8_0_13.sql` file found in `ServerSide/Database`.
  - You must use mysql_native_password for the user as EXTDB3 doesn't support the new security stuff.
  - The version is set as that's what we've developed with so can ensure support, others might work but if you encounter issues please switch.
  - If you're updating from a previous version all database changes are included in `ServerSide/Database/Migrations`. These might also be setup for older syntax
* A setup and ready-to-go ArmA 3 Server on at least version 2.16.
  - Startup parameters for server `-servermod=@life_server;@extDB3`


## Help

Need help? Submit an issue and a maintainer will assist when they're able. If no reply has been received within 24 hours feel free to contact "Scarso" on Discord.

## Authors

Contributors names and contact info

- [@Scarso](https://twitter.com/ScarsoLP)
- [@Lewis](https://github.com/Lewis-Development)
- [@AceBoyden]

## License

This project is licensed under the MIT License - see the LICENSE.md file for details
