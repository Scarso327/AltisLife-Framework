class CfgWarrants {
    NoteLength = 128;
    
    class CommonLaw {
        displayName = "Common Law";

        class PervertingJustice {
			displayName = "Perverting the Course of Justice";
			bounty = 50000;
            allowManual = true;
        };
        class EscapeCustody : PervertingJustice { // Escaping Prison
			displayName = "Escape from Custody";
			bounty = 200000;
        };
        class FalseImprisonment : PervertingJustice {
			displayName = "False Imprisonment";
			bounty = 200000;
        };
    };

    class TreasonAct {
        displayName = "Treason Act";

        class Treason { 
            displayName = "Treason";
            allowManual = true;
			bounty = 200000; 
        };
    };

    class TreasonAct {
        displayName = "Terrorism Act";

        class Membership { 
            displayName = "Member of Proscribed Group"; 
            allowManual = true;
            bounty = 200000;
        };
        class Support : Membership {
            displayName = "Supporting Proscribed Group";
            bounty = 80000;
        };
    };

    class PrisonAct {
        displayName = "Prison Act";

        class Assisting { 
            displayName = "Assisting Prisoner to Escape"; 
            allowManual = true;
            bounty = 200000;
        };
        class Smuggling : Assisting {
            displayName = "Smuggling Contraband";
            bounty = 30000;
        };
    };

    class OffencesAct {
        displayName = "Offences Against the Person Act";

        class S1 { // Execute Player
            displayName = "Murder"; 
            allowManual = true;
            bounty = 200000;
        };
        class S5 : S1 { displayName = "Manslaughter"; };
        class S16 : S1 { 
            displayName = "Threats to Kill"; 
            bounty = 50000;
        };
        class S18 : S1 { // Incap Player
            displayName = "Grievous Bodily Harm"; 
            bounty = 180000;
        };
        class S38 : S1 { // Knocking Non-Civilian Out
            displayName = "Assault on Emergency Worker"; 
            bounty = 150000;
        };
        class S47 : S1 { // Knocking Civilian Out
            displayName = "Actual Bodily Harm"; 
            bounty = 100000;
        };
        class S66 : S1 { 
            displayName = "Loitering with Intent to Harm"; 
            bounty = 30000;
        };
    };

    class FirearmsAct {
        displayName = "Firearms Act";

        class S1 {
            displayName = "Possession without Certificate";
            allowManual = true;
            bounty = 45000;
        };
        class S5 : S1 {
            displayName = "Possession of Prohibited Firearm";
            bounty = 65000;
        };
        class S18 : S1 {
            displayName = "Possession with Criminal Intent";
            bounty = 55000;
        };
        class S19 : S1 {
            displayName = "Carrying a Firearm in a Public Place";
            bounty = 20000;
        };
    };

    class PublicOrderAct {
        displayName = "Public Order Act";

        class S1 {
            displayName = "Riot";
            allowManual = true;
            bounty = 75000;
        };
        class S2 : S1 {
            displayName = "Violent Disorder";
            bounty = 80000;
        };
        class S3 : S1 {
            displayName = "Affray";
            bounty = 30000;
        };
        class S4 : S1 {
            displayName = "Fear/Provocation of Violence";
            bounty = 55000;
        };
        class S5 : S1 {
            displayName = "Harassment, Alarm or Distress";
            bounty = 15000;
        };
    };

    class DrugsAct {
        displayName = "Misuse of Drugs Act";

        class S3 {
            displayName = "Intent to Supply";
            allowManual = true;
            bounty = 150000;
        };
        class S5 : S3 {
            displayName = "Possession";
            bounty = 50000;
        };
    };

    class TheftAct {
        displayName = "Theft Act";

        class S7 {
            displayName = "Theft";
            allowManual = true;
            bounty = 20000;
        };
        class S8 : S7 { // Robbing Player or Store
            displayName = "Robbery";
            bounty = 100000;
        };
        class S9 : S7 {
            displayName = "Burglary";
            bounty = 70000;
        };
        class S12 : S7 { // Successfully Lockpicking
            displayName = "Taking Vehicle Without Consent";
            bounty = 75000;
        };
        class S21 : S7 {
            displayName = "Blackmail";
            bounty = 20000;
        };
        class S22 : S7 {
            displayName = "Handling Stolen Goods";
            bounty = 30000;
        };
        class S25 : S7 {
            displayName = "Going Equipped for Stealing";
            bounty = 15000;
        };
    };

    class FraudAct {
        displayName = "Fraud Act";

        class S2 {
            displayName = "False Representation";
            allowManual = true;
            bounty = 40000;
        };
        class S3 : S2 {
            displayName = "Failure to Disclose";
            bounty = 20000;
        };
        class S4 : S2 {
            displayName = "Abuse of Position";
            bounty = 75000;
        };
        class S6 : S2 {
            displayName = "Possession of Articles";
            bounty = 5000;
        };
    };

    class RoadsAct {
        displayName = "Road Traffic Act";

        class S1 {
            displayName = "Injury Dangerous Driving";
            allowManual = true;
            bounty = 200000; 
        };
        class S2 : S1 { 
            displayName = "Dangerous Driving";
            bounty = 80000; 
        };
        class S3 : S1 {
            displayName = "Careless/Inconsiderate Driving";
            bounty = 45000;
        };
        class S4 : S1 {
            displayName = "Driving under the Influence";
            bounty = 35000;
        };
        class S6 : S1 {
            displayName = "Failing to Provide a Breath Test";
            bounty = 55000;
        };
        class S14 : S1 {
            displayName = "Failing to Wear a Seat Belt";
            bounty = 5000;
        };
        class S25 : S1 { // Attempting to Lockpick
            displayName = "Vehicle Interferance";
            bounty = 16000;
        };
        class S40 : S1 {
            displayName = "Vehicle in Dangerous Condition";
            bounty = 10000;
        };
        class S87 : S1 {
            displayName = "Driving without a License";
            bounty = 20000;
        };
        class S163 : S1 {
            displayName = "Failing to Stop for Police";
            bounty = 65000;
        };
        class S170 : S1 {
            displayName = "Failing to Stop at RTC";
            bounty = 5000;
        };
        class Speed : S1 {
            displayName = "Speeding";
            bounty = 15000;
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