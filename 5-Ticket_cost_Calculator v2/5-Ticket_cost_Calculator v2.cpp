#include <string>
#include <iostream>
#include <algorithm>

using namespace::std;


int ticket_cost_ranges[3][2] = { {0,16},{17,64},{65,200} };
float ticket_prices[3] = { 7.5,10.5,6.5 };
float ticket_profits[3] = { 2.5,5.5,1.5 };

//This function takes the age of the customet and then checks what pricing range they fit into. It then returns the profit and price of their ticket
void ticket_cost_calculator(int age, float& ticket_price, float& ticket_profit) {
    //this loop runs for the number of items in the ticket_prices list
    for (int f = 0; f < sizeof(ticket_prices) / sizeof(ticket_prices[0]); f += 1) {
        if (age >= ticket_cost_ranges[f][0] and age <= ticket_cost_ranges[f][1]) {
            //sets the ticked_price pointer as ticked_prices and ticket_profit pointer as ticket_profit
            ticket_price = ticket_prices[f];
            ticket_profit = ticket_profits[f];
        }
    }
}


int main()
{
    while (true) {
        int age;
        cout << "enter your age\n  :";
        cin >> age;
        float ticket_price = ticket_cost_calculator(age);
        cout << "ticket_price : " << ticket_price << endl;
    }

}

