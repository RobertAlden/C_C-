//**********************************************************
// Programmer: Robert Alden
// Course:	   CS-1313
// Program:         3
// Date:	    2/22/16
// Purpose:	    This program generates a monthly bill for electricity.
// Input:	     usage (kilowatt hours)
// Calculate:	     billing fees, subtotal, taxes, total amount due
// Output:	     monthly bill statement
//********************************************************** 
// YOUR CODE: insert the necessary include statements 
#include <iostream> 
#include <iomanip> 
using namespace std;
int main()
{
   const double  FEES = 16.16;			// minimum monthly fees
   int usage;					// monthly electricity usage in kwh
   double billing, subtotal, taxes, total;	// calculated variables
   cout << "How many kwh did you use? ";
   cin  >> usage;
   // YOUR CODE: calculate the amount of billing from usage
	if (usage < 475)
	{billing = usage * 0.0638;}

	else if (usage <= 1250)
	{billing = 475 * 0.0638 + (usage-475) * 0.0538;}

	else if (usage > 1250)
	{billing = 475 * 0.0638 + 775 * 0.0538 + (usage - 1250) * 0.0454;}

   // YOUR CODE: calculate other fees
   subtotal = billing + FEES;
   taxes = subtotal * 0.064;
   total = subtotal + taxes;
   // YOUR CODE: output a report (see the sample sessions on the next page).
   cout << "Usage in kwh: " << setw(15) << usage << endl;
   cout << "Billing Fees: " << setw(15) << billing << endl;
   cout << "Minumum Fees: " << setw(15) << FEES << endl;
   cout << "Subtotal: " << setw(15) << subtotal << endl;
   cout << "City & State taxes: " << setw(15) << setprecision(4) << taxes << endl;
   cout << "Total amount due: " << setw(15) << setprecision(5) << total << endl;
   return 0;
}

