// 4_Cash_or_Card.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;

//A function that takes a question and returns a bool of weather they selcted true or false 
bool yes_or_no(string question, string value1, string value2, string error_message) {
    cout << question << "\n  :";
    string user_input;
    // loops the function till a valid input of either value 1 or 2
    while (true) {
        getline(cin, user_input);
        //makes the users input into all lower case 
        for_each(user_input.begin(), user_input.end(), [](char& c) {
            c = ::tolower(c);
            });
        if (user_input == value1) {
            return false;
        }
        else if (user_input == value2) {
            return true;
        }
        else {
            // The error message printed if the user's input is not value 1 or 2
            cout << error_message;
        }
    }
}


int main()
{
    while (true) {
        bool card = yes_or_no("Which payment method would you like to use; cash or card ?");
        cout << "card = " << card << endl << endl;
    }

}
