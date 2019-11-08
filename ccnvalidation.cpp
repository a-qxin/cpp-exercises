/**
 * Credit Card Number Validation
 *
 * @file ccnvalidation.cpp
 * @author Brenda Yau
 */

#include <vector>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

bool isvalidcc(const string&);

int main()
{
   // main tests isvalidcc, checking whether each card number below is valid/invalid.
   vector<string> cardnumbers =
   {
      "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
      "4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
      "5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
      "4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
      "5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
      "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
      "4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
      "5556551555555557", "6011316011016011"
   };

   int i; // outputs card number order
   vector<string>::iterator itr; // vector iterator

   for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
      cout << setw(2)  << i << " "
          << setw(17) << *itr
          << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
   }

   return 0;
}

/**
 * Returns whether credit card number is valid by the given rules:
 *
 * Double every second digit from right to left.
 * If doubling results in a 2 digit number, add the two digits to get one digit.
 * Add all single digits from above.
 * Add all the odd places' digits from right to left.
 * Add the above two steps.
 * If this sum is divisible by ten, the card number is valid, invalid otherwise.
 *
 * @param str string of the card number.
 * @return true if number is valid, false otherwise.
 */
bool isvalidcc(const string& str)
{
   int result = 0, evenDigitSum = 0, oddDigitSum = 0;

   //get every second digit from right to left
   for (int evenIndex = (int) str.size() - 2; evenIndex >= 0; evenIndex-=2)
   {
      int evenDoubles = 2 * stoi(str.substr(evenIndex, 1));

      // if result is 2 digits add them to get one digit
      if (evenDoubles >= 10)
      {
         int evenDoublesOnes = evenDoubles % 10;
         int evenDoublesTens = evenDoubles / 10;
         evenDoubles = evenDoublesOnes + evenDoublesTens;
      }
      // add all the single digits
      evenDigitSum += evenDoubles;
   }

   // add all odd places' digits from right to left
   for (int oddIndex = (int) str.size() - 1; oddIndex >= 0; oddIndex-=2)
   {
      oddDigitSum += stoi(str.substr(oddIndex, 1));
   }

   result = evenDigitSum + oddDigitSum;

   // card is valid if result is divisible by ten
   if (result % 10 == 0)
      return true;
   return false;
}
