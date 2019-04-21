/*
	@File: fn_payChecks.sqf
  
	@Author: Lewis Mackinnon
  
	@Description: Sets custom paychecks depending on whitelisting and/or licences.
*/

#include "..\..\script_macros.hpp"

switch (playerSide) do
{
	case west: {
		switch(FETCH_CONST(life_coplevel)) do {
			case 0: { life_paycheck = life_paycheck + 0;};
			case 1: { life_paycheck = life_paycheck + 5000; };   // Police Cadet
			case 2: { life_paycheck = life_paycheck + 6000; };   // Police Constable
			case 3: { life_paycheck = life_paycheck + 7000; };   // Senior Police Constable
			case 4: { life_paycheck = life_paycheck + 8000; };   // Sergeant
			case 5: { life_paycheck = life_paycheck + 9000; };   // Inspector
			case 6: { life_paycheck = life_paycheck + 10000; };  // Chief Inspector
			case 7: { life_paycheck = life_paycheck + 11000; };  // Superintendent
			case 8: { life_paycheck = life_paycheck + 12000; };  // Chief Superintendent
			case 9: { life_paycheck = life_paycheck + 13000; };  // Deputy Commissioner
			case 10: { life_paycheck = life_paycheck + 14000; }; // Commissioner
			case 11: { life_paycheck = life_paycheck + 15000; }; // Commander
		};

		if(license_cop_sfo1) then
		{
			life_paycheck = life_paycheck + 1000;
		};
		if(license_cop_sfo2) then
		{
			life_paycheck = life_paycheck + 2000;
		};
		if(license_cop_sfo3) then
		{
			life_paycheck = life_paycheck + 3000;
		};

		if(license_cop_aso1) then
		{
			life_paycheck = life_paycheck + 1000;
		};
		if(license_cop_aso2) then
		{
			life_paycheck = life_paycheck + 2000;
		};
		if(license_cop_aso3) then
		{
			life_paycheck = life_paycheck + 3000;
		};
	};

	case independent: {
		switch(FETCH_CONST(life_mediclevel)) do {
			case 0: { life_paycheck = life_paycheck + 0;};
			case 1: { life_paycheck = life_paycheck - 2000; };  // Medical Student
			case 2: { life_paycheck = life_paycheck + 7500; };  // Nurse
			case 3: { life_paycheck = life_paycheck + 10000; }; // Junior Doctor
			case 4: { life_paycheck = life_paycheck + 12500; }; // Emergency Doctor
			case 5: { life_paycheck = life_paycheck + 15000; }; // Consultant
			case 6: { life_paycheck = life_paycheck + 17500; }; // Regional Director
		};

		if(license_med_taa1) then
		{
			life_paycheck = life_paycheck + 2000;
		};
		if(license_med_taa2) then
		{
			life_paycheck = life_paycheck + 4000;
		};
		if(license_med_taa3) then
		{
			life_paycheck = life_paycheck + 6000;
		};
	};
};