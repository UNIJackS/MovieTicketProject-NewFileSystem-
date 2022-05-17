// 4_Cash_or_Card.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;

//A function that takes a question and returns a bool of weather they selcted true or false 
bool cash_or_card(string question) {
    cout << question << "\n  :";
    string user_input;
    // loops the function till a valid input of eyther card or cash is inputed 
    while (true) {
        getline(cin, user_input);
        //makes the users input into all lower case 
        for_each(user_input.begin(), user_input.end(), [](char& c) {
            c = ::tolower(c);
            });
        if (user_input == "cash") {
            return false;
        }
        else if (user_input == "card") {
            return true;
        }
        else {
            // The error message printed if the user's input is not cash or card
            cout << "plese enter your payment method eyther cash or card\n  :";
        }
    }
}


int main()
{
    while (true) {
        bool card = cash_or_card("Which payment method would you like to use; cash or card ?");
        cout << "card = " << card << endl << endl;
    }

}
