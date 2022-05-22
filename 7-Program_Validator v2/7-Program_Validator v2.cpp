
#include <string>
#include <iostream>

using namespace::std;

// ====== Snack Data ======
string snacks[] = { "popcorn","m & m's","pita chips","orange juice","water","coffeyy" };

float snacks_price[] = { 2.5,3.0,4.5,3.25,2.0 };

float snacks_profit[] = { 0.5,0.6,0.9,0.65,0.4 };

// ====== Ticket Data ======
//To add or subtract ranges you must increse the first number in the arry decleraton...
//... and then add the new range to the "ticket_cost_ranges" array Eg to add a new ...
//... range from 55-64 it would look like this ...
//... int ticket_cost_ranges[4][2] = { {0,16},{17,54},{55,64},{65,200} };
int ticket_cost_ranges[][2] = { {0,16},{17,64},{65,100},{101,120} };
//To add a new price for the new range you must add a new price to the ticket_cost_prices...
//... array and it must be in the same order as the ticket_cost_ranges...
//... Eg to add a $20 price to the previous example it would look like this...
//...float ticket_cost_prices[] = { 7.5,10.5,20.0,6.5 };
float ticket_prices[] = { 7.5,10.5,6.5,7.8 };
//To add a new profit for the new range you must add a new number to the ticket_cost_profits...
//... array and it must be in the same order as the ticket_cost_ranges...
//... Eg to add a $15 profit to the previous example it would look like this...
//...float ticket_cost_profits[] = { 2.5,5.5,15.0,1.5 };
float ticket_profits[] = { 2.5,5.5,1.5,9.0,20.0 };

float credit_card_surcharge = 5.5; //in percent 


//This function validates the data that can be changed by someone with little to no c++ knoledge ...
//...It does this by comparing the size of the arrays relating to snacks and ticket prices and by ...
//...making sure the credit card surcharge is greater than or equal to 0
void Program_Validator() {
    bool valid = true;
    // Compares the size of the arrays to do with ticket's and their price,profit and age ranges
    if (sizeof(ticket_cost_ranges) / sizeof(ticket_cost_ranges[0]) != sizeof(ticket_prices) / sizeof(ticket_prices[0]) || sizeof(ticket_prices) / sizeof(ticket_prices[0]) != sizeof(ticket_profits) / sizeof(ticket_profits[0])) {
        cout << "The size of ticket_cost_ranges,ticket_prices and ticket_profits lists must be the same" << endl;
        valid = false;
    }
    // Compares the size of the arrays to do with snack's and their price, profit and selection
    if (sizeof(snacks) / sizeof(snacks[0]) != sizeof(snacks_price) / sizeof(snacks_price[0]) || sizeof(snacks) / sizeof(snacks[0]) != sizeof(snacks_profit) / sizeof(snacks_profit[0])) {
        cout << "The size of snacks,snacks_price and snacks_profit lists must be the same" << endl;
        valid = false;
    }
    // Checks if the credit card surcharge is above or equal to 0
    if (credit_card_surcharge <= 0) {
        cout << "The credit_card_surcharge varable must be greater than or equal to 0 " << endl;
        valid = false;
    }
    // Exits the program if any of the previous if statements where true
    if (valid == false) {
        exit;
    }
}



int main()
{
    Program_Validator();
}


