class CfgWarrants {
    class CommonLaw {
        displayName = "Common Law";
        
        class EscapeFromAClosedEstablishmentOrSecureEscort {
			displayName = "Escape from a Closed Establishment or Secure Escort";
			bounty = 200000;
        };
        class PervertingTheCourseOfJustice {
			displayName = "Perverting the Course of Justice";
			bounty = 50000;
        };
    };

    class AccessoriesAndAbettors {
        displayName = "Accessories and Abettors Act 1861";

        class AidingAndAbetting {
			displayName = "Aiding and Abetting";
			bounty = 75000;
        };
    };

    class PublicOrder {
        displayName = "Public Order Act 1986";

        class Section1 {
            displayName = "Rioting";
            bounty = 75000;
        };
        class Section2 {
            displayName = "Violent Disorder";
            bounty = 80000;
        };
        class Section4 {
            displayName = "Fear or Provocation of Violence";
            bounty = 55000;
        };
    };

    class Treason {
        displayName = "Treason Act 1351";

        class Treason : Escape { displayName = "Treason"; };
    };

    class ProtectionFromHarassment {
        displayName = "Protection from Harassment Act 1997";

        class Section2 {
            displayName = "Harassment";
            bounty = 25000;
        };
        class Section2A {
            displayName = "Stalking";
            bounty = 30000;
        };
    };

    class Fraud {
        displayName = "Fraud Act 2006";

        class Section2 {
            displayName = "False Representation";
            bounty = 40000;
        };
        class Section3 {
            displayName = "Failure to Disclose Information";
            bounty = 20000;
        };
        class Section4 {
            displayName = "Abuse of Position";
            bounty = 75000;
        };
        class Section6 {
            displayName = "Possession of Items used for Fraud";
            bounty = 5000;
        };
    };

    class OffencesAgainstThePerson {
        displayName = "Offences Against the Person Act 1861";

        class Section1 : Escape { displayName = "Homicide"; };
        class Section4 {
            displayName = "Conspiracy or Soliciting to Commit Murder";
            bounty = 160000;
        };
        class Section5 : Escape { displayName = "Manslaughter"; };
        class Section16 : Escape { displayName = "Threats to Kill"; };
        class Section18 : Escape { displayName = "Shooting or attempting to shoot, or wounding with intent to do harm"; };
        class Section20 : Escape { displayName = "Inflicting bodily injury, with or without weapon"; };
        class Section66 {
            displayName = "Loitering with intent (day or night)";
            bounty = 75000;
        };
    };

    class CriminalAttempts {
        displayName = "Criminal Attempts Act 1981";

        class Section1 {
            displayName = "Attempting to Commit an Offence";
            bounty = 30000;
        };
    };

    class OfficialSecrets {
        displayName = "Official Secrets Act 1989";

        class Espionage : Escape { displayName = "Espionage"; };
    };

    class Prison {
        displayName = "Prison Act 1952";

        class AssistingPrisonerToEscape : Escape { displayName = "Assisting Prisoner to Escape"; };
        class SmugglingContrabandIntoOutPrison {
            displayName = "Smuggling Contraband into/out(of) Prison";
            bounty = 30000;
        };
    };

    class TakingOfHostages {
        displayName = "Taking of Hostages Act 1982";

        class HostageTaking : Escape { displayName = "Hostage-Taking"; };
    };

    class CriminalLaw {
        displayName = "Criminal Law Act 1967";

        class PreventionOfCrime {
            displayName = "Prevention of Crime";
            bounty = 25000;
        };
    };

    class Theft {
        displayName = "Theft Act 1968";

        class Section7 {
            displayName = "Theft";
            bounty = 20000;
        };
        class Section8 {
            displayName = "Robbery";
            bounty = 100000;
        };
        class Section9 {
            displayName = "Burglary";
            bounty = 70000;
        };
        class Section10 {
            displayName = "Aggravated Burglary";
            bounty = 125000;
        };
        class Section12 {
            displayName = "Taking Vehicle Without Consent";
            bounty = 75000;
        };
        class Section12A {
            displayName = "Aggravated Vehicle Taking";
            bounty = 100000;
        };
        class Section25 {
            displayName = "Going Equipped";
            bounty = 15000;
        };
    };

    class Firearms {
        displayName = "Firearms Act 1968";

        class Section1 {
            displayName = "Purchasing or Possessing Firearms or Ammunition without Certificate";
            bounty = 45000;
        };
        class Section5 {
            displayName = "Possession of a Weapon Subject to General Prohibition";
            bounty = 65000;
        };
        class Section16 {
            displayName = "Possession of Firearm with Intent to Injure";
            bounty = 95000;
        };
        class Section16A {
            displayName = "Possession of Firearm with Intent to Cause Fear of Violence";
            bounty = 65000;
        };
        class Section18 {
            displayName = "Carrying a Firearm with Criminal Intent";
            bounty = 55000;
        };
        class Section19 {
            displayName = "Carrying a Firearm in a Public Place";
            bounty = 20000;
        };
        class Section21 {
            displayName = "Unauthorised Supply of Firearms or Ammunition";
            bounty = 45000;
        };
    };

    class Terrorism {
        displayName = "Terrorism Act 2000";

        class MembershipOfAProscribedOrganisation : Escape { displayName = "Membership of a Proscribed Organisation"; };
        class SupportOfAProscribedOrganisation {
            displayName = "Support of a Proscribed Organisation";
            bounty = 80000;
        };
    };

    class MisuseOfDrugs {
        displayName = "Misuse of Drugs Act 1971";

        class Section4 {
            displayName = "Production and Supply of Controlled Drugs";
            bounty = 150000;
        };
        class Section5 {
            displayName = "Possession of Controlled Drugs";
            bounty = 50000;
        };
    };

    class CivilAviation {
        displayName = "Civil Aviation Act 1982";

        class DangerousFlying {
            displayName = "Dangerous Flying";
            bounty = 20000;
        };
        class ViolationOfNoiseControl {
            displayName = "Violation of Noise Control";
            bounty = 15000;
        };
        class ViolationOfRestrictedSites {
            displayName = "Violation of Restricted Sites";
            bounty = 15000;
        };
    };

    class RoadTraffic {
        displayName = "Road Traffic Act 1988";

        class Section1 : Escape { displayName = "Causing Death by Dangerous Driving"; };
        class Section1A : Escape { displayName = "Causing Serious Injury by Dangerous Driving"; };
        class Section2 {
            displayName = "Dangerous Driving";
            bounty = 80000;
        };
        class Section3 {
            displayName = "Careless, and inconsiderate, driving";
            bounty = 45000;
        };
        class Section3A : Escape { displayName = "Causing Death by Careless Driving when Under Influence"; };
        class Section4 {
            displayName = "Driving, or being in charge, when under Influence of Drink or Drugs";
            bounty = 35000;
        };
        class Section34 {
            displayName = "Driving mechanically propelled vehicles elsewhere than on roads.";
            bounty = 15000;
        };
        class Section35 {
            displayName = "Drivers to comply with traffic directions";
            bounty = 15000;
        };
        class Section87 {
            displayName = "Driving Otherwise than in Accordance with a Licence";
            bounty = 20000;
        };
        class Section168 {
            displayName = "Failing to Give/Or Giving False, Name or Address";
            bounty = 5000;
        };
        class Section170 {
            displayName = "Failing to Stop at an Accident";
            bounty = 65000;
        };
        class Speeding {
            displayName = "Speeding";
            bounty = 15000;
        };
        class DrivingPossessingAVehicleSubjectToGeneralProhibition {
            displayName = "Driving/Possessing a Vehicle Subject to General Prohibition";
            bounty = 50000;
        };
    };
};