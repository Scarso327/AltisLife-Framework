class CfgWarrants {
    NoteLength = 128;
    
    class CommonLaw {
        displayName = "Common Law";
        
        class EscapeEscort {
			displayName = "Escape from a Closed Establishment or Secure Escort";
            allowManual = true;
			bounty = 200000;
        };
        class PervertingJustice : EscapeEscort {
			displayName = "Perverting the Course of Justice";
			bounty = 50000;
        };
    };

    class AccessoriesAndAbettors {
        displayName = "Accessories and Abettors Act 1861";

        class AidingAndAbetting {
			displayName = "Aiding and Abetting";
            allowManual = true;
			bounty = 75000;
        };
    };

    class PublicOrder {
        displayName = "Public Order Act 1986";

        class Section1 {
            displayName = "Rioting";
            allowManual = true;
            bounty = 75000;
        };
        class Section2 : Section1 {
            displayName = "Violent Disorder";
            bounty = 80000;
        };
        class Section4 : Section1 {
            displayName = "Fear or Provocation of Violence";
            bounty = 55000;
        };
    };

    class Treason {
        displayName = "Treason Act 1351";

        class Treason { 
            displayName = "Treason";
            allowManual = true;
			bounty = 200000; 
        };
    };

    class ProtectionFromHarassment {
        displayName = "Protection from Harassment Act 1997";

        class Section2 {
            displayName = "Harassment";
            allowManual = true;
            bounty = 25000;
        };
        class Section2A : Section2 {
            displayName = "Stalking";
            bounty = 30000;
        };
    };

    class Fraud {
        displayName = "Fraud Act 2006";

        class Section2 {
            displayName = "False Representation";
            allowManual = true;
            bounty = 40000;
        };
        class Section3 : Section2 {
            displayName = "Failure to Disclose Information";
            bounty = 20000;
        };
        class Section4 : Section2 {
            displayName = "Abuse of Position";
            bounty = 75000;
        };
        class Section6 : Section2 {
            displayName = "Possession of Items used for Fraud";
            bounty = 5000;
        };
    };

    class OffencesAgainstThePerson {
        displayName = "Offences Against the Person Act 1861";

        class Section1 { 
            displayName = "Murder"; 
            allowManual = true;
            bounty = 200000;
        };
        class Section4 : Section1 {
            displayName = "Conspiracy or Soliciting to Commit Murder";
            bounty = 160000;
        };
        class Section5 : Section1 { displayName = "Manslaughter"; };
        class Section16 : Section1 { displayName = "Threats to Kill"; };
        class Section18 : Section1 { displayName = "Shooting or attempting to shoot, or wounding with intent to do harm"; };
        class Section20 : Section4 { displayName = "Inflicting bodily injury, with or without weapon"; };
    };

    class CriminalAttempts {
        displayName = "Criminal Attempts Act 1981";

        class Section1 {
            displayName = "Attempting to Commit an Offence";
            allowManual = true;
            bounty = 30000;
        };
    };

    class Prison {
        displayName = "Prison Act 1952";

        class AssistingEscape { 
            displayName = "Assisting Prisoner to Escape"; 
            allowManual = true;
            bounty = 200000;
        };
        class SmugglingIntoPrison : AssistingEscape {
            displayName = "Smuggling Contraband into/out(of) Prison";
            bounty = 30000;
        };
    };

    class TakingOfHostages {
        displayName = "Taking of Hostages Act 1982";

        class HostageTaking { 
            displayName = "Hostage-Taking"; 
            allowManual = true;
            bounty = 200000;
        };
    };

    class Theft {
        displayName = "Theft Act 1968";

        class Section7 {
            displayName = "Theft";
            allowManual = true;
            bounty = 20000;
        };
        class Section8 : Section7 {
            displayName = "Robbery";
            bounty = 100000;
        };
        class Section9 : Section7 {
            displayName = "Burglary";
            bounty = 70000;
        };
        class Section12 : Section7 {
            displayName = "Taking Vehicle Without Consent";
            bounty = 75000;
        };
        class Section25 : Section7 {
            displayName = "Going Equipped";
            bounty = 15000;
        };
    };

    class Firearms {
        displayName = "Firearms Act 1968";

        class Section1 {
            displayName = "Purchasing or Possessing Firearms or Ammunition without Certificate";
            allowManual = true;
            bounty = 45000;
        };
        class Section5 : Section1 {
            displayName = "Possession of a Weapon Subject to General Prohibition";
            bounty = 65000;
        };
        class Section18 : Section1 {
            displayName = "Carrying a Firearm with Criminal Intent";
            bounty = 55000;
        };
        class Section19 : Section1 {
            displayName = "Carrying a Firearm in a Public Place";
            bounty = 20000;
        };
        class Section21 : Section1 {
            displayName = "Unauthorised Supply of Firearms or Ammunition";
            bounty = 45000;
        };
    };

    class Terrorism {
        displayName = "Terrorism Act 2000";

        class MembershipProscribed { 
            displayName = "Membership of a Proscribed Organisation"; 
            allowManual = true;
            bounty = 200000;
        };
        class SupportProscribed : MembershipProscribed {
            displayName = "Support of a Proscribed Organisation";
            bounty = 80000;
        };
    };

    class MisuseOfDrugs {
        displayName = "Misuse of Drugs Act 1971";

        class Section4 {
            displayName = "Production and Supply of Controlled Drugs";
            allowManual = true;
            bounty = 150000;
        };
        class Section5 : Section4 {
            displayName = "Possession of Controlled Drugs";
            bounty = 50000;
        };
    };

    class CivilAviation {
        displayName = "Civil Aviation Act 1982";

        class DangerousFlying {
            displayName = "Dangerous Flying";
            allowManual = true;
            bounty = 20000;
        };
        class ViolationOfNoiseControl : DangerousFlying {
            displayName = "Violation of Noise Control";
            bounty = 15000;
        };
        class ViolationOfRestrictedSites : DangerousFlying {
            displayName = "Violation of Restricted Sites";
            bounty = 15000;
        };
    };

    class RoadTraffic {
        displayName = "Road Traffic Act 1988";

        class Section1 { 
            displayName = "Causing Death by Dangerous Driving";
            allowManual = true;
            bounty = 200000; 
        };
        class Section2 : Section1 {
            displayName = "Dangerous Driving";
            bounty = 80000;
        };
        class Section3 : Section1 {
            displayName = "Careless, and inconsiderate, driving";
            bounty = 45000;
        };
        class Section4 : Section1 {
            displayName = "Driving, or being in charge, when under Influence of Drink or Drugs";
            bounty = 35000;
        };
        class Section34 : Section1 {
            displayName = "Driving mechanically propelled vehicles elsewhere than on roads.";
            bounty = 15000;
        };
        class Section35 : Section1 {
            displayName = "Drivers to comply with traffic directions";
            bounty = 15000;
        };
        class Section87 : Section1 {
            displayName = "Driving Otherwise than in Accordance with a Licence";
            bounty = 20000;
        };
        class Section168 : Section1 {
            displayName = "Failing to Give/Or Giving False, Name or Address";
            bounty = 5000;
        };
        class Speeding : Section1 {
            displayName = "Speeding";
            bounty = 15000;
        };
        class VehicleProhibition : Section1 {
            displayName = "Driving/Possessing a Vehicle Subject to General Prohibition";
            bounty = 50000;
        };
    };

    class Other {
        displayName = "Other";

        class Note {
            displayName = "Added Note";
            allowManual = true;
            bounty = 0; 
        };
    };
};