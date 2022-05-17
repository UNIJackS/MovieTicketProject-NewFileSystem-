#include <string>
#include <iostream>
#include <algorithm>

using namespace::std;


int ticket_cost_ranges[3][2] = { {0,16},{17,64},{65,200} };
float ticket_prices[3] = { 7.5,10.5,6.5 };


float ticket_cost_calculator(int age) {
    for (int f = 0; f < sizeof(ticket_prices) / sizeof(ticket_prices[0]); f += 1) {
        if (age >= ticket_cost_ranges[f][0] and age <= ticket_cost_ranges[f][1]) {
            return ticket_prices[f];
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

