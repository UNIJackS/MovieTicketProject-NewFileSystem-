#include <iostream>
#include <string>
#include <algorithm>
using namespace::std;

bool cash_or_card(string question) {
    cout << question << "\n  :";
    string user_input;
    while (true) {
        getline(cin, user_input);
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
