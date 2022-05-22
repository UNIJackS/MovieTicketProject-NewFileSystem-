#include <string>
#include <fstream>
#include <iostream>

using namespace::std;

ofstream attendee_details("attendee_details.csv");

string snacks[] = { "popcorn","m & m's","pita chips","orange juice","water" };

float credit_card_surcharge = 5; //in percent 

int snack_info[max_tickets][sizeof(snacks) / sizeof(snacks[0])];

int max_seats = 3;

void csv_file_writter(int ID, string name, int age, float ticket_price, float snack_cost, bool cash_or_card, float ticket_profit) {
	if (ID == 0) {
		attendee_details << "Seat Num , Name , Age,Ticket price,";
		for (int p = 0;p < sizeof(snacks) / sizeof(snacks[0]); p += 1) {
			attendee_details << snacks[p] << ",";
		}
		attendee_details << "Snack Cost,Payment Method,Surcharge,Total Cost,Seat Profit,Snack Profit,Total Profit " << endl;
	}

	attendee_details << ID + 1 << "," << name << "," << age << "," << ticket_price << ",";
	for (int t = 0;t < sizeof(snacks) / sizeof(snacks[0]); t += 1) {
		attendee_details << snack_info[ID][t] << ",";
	}
	float total_price = ticket_price + snack_cost;
	if (cash_or_card == true) {
		total_price += (total_price / 100) * credit_card_surcharge;
	}
	attendee_details << snack_cost << ",";
	if (cash_or_card) {
		attendee_details << "cash ,";
	}
	float snack_profit = 0;
	for (int c = 0;c < sizeof(snacks) / sizeof(snacks[0]); c += 1) {
		snack_profit += snack_info[ID][c] * snacks_profit[c];
	};
	float total_profit = ticket_profit + snack_profit;
	attendee_details << (total_price / 100) * credit_card_surcharge << "," << total_price << "," << ticket_price << ",," << ticket_profit << "," << snack_profit << ",";
	attendee_details << total_profit << endl;


}


// Because of how much stuff is required for this to be tested i simply coppy pasted it into the main program and tested it there rather than make a main loop 
