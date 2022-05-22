#include <string>
#include <fstream>
#include <iostream>

using namespace::std;

ofstream attendee_details("attendee_details.csv");

float credit_card_surcharge = 5; //in percent 

int const max_tickets = 3;

// ====== Snack Data ======
string snacks[] = { "popcorn","m & m's","pita chips","orange juice","water"};

float snacks_price[] = { 2.5,3.0,4.5,3.25,2.0 };

float snacks_profit[] = { 0.5,0.6,0.9,0.65,0.4 };

// ====== Ticket Data ======
//To add or subtract ranges you must increse the first number in the arry decleraton...
//... and then add the new range to the "ticket_cost_ranges" array Eg to add a new ...
//... range from 55-64 it would look like this ...
//... int ticket_cost_ranges[4][2] = { {0,16},{17,54},{55,64},{65,200} };
int ticket_cost_ranges[3][2] = { {0,16},{17,64},{65,200} };
//To add a new price for the new range you must add a new price to the ticket_cost_prices...
//... array and it must be in the same order as the ticket_cost_ranges...
//... Eg to add a $20 price to the previous example it would look like this...
//...float ticket_cost_prices[] = { 7.5,10.5,20.0,6.5 };
float ticket_prices[] = { 7.5,10.5,6.5 };
//To add a new profit for the new range you must add a new number to the ticket_cost_profits...
//... array and it must be in the same order as the ticket_cost_ranges...
//... Eg to add a $15 profit to the previous example it would look like this...
//...float ticket_cost_profits[] = { 2.5,5.5,15.0,1.5 };
float ticket_profits[] = { 2.5,5.5,1.5 };



int snack_info[max_tickets][sizeof(snacks) / sizeof(snacks[0])];



// This function takes the users data then writes it to a csv file called results attendee_details.csv
void csv_file_writter(int ID, string name, int age, float ticket_price, float snack_cost, bool cash_or_card, float ticket_profit, bool last_ticket, float grand_total_profit) {
	// This if statement ouputs the titles for the collums if this is the first seat sold (ID = 0)
	if (ID == 0) {
		attendee_details << "Seat Num , Name , Age,Ticket price,";
		// This loop outputs the names of the snacks for the number of snacks in the list.
		for (int p = 0;p < sizeof(snacks) / sizeof(snacks[0]); p += 1) {
			attendee_details << snacks[p] << ",";
		}
		attendee_details << "Snack Cost,Payment Method,Surcharge,Total Cost,Seat Profit,Snack Profit,Total Profit " << endl;
	}
	// Out puts the most basic info to the file
	attendee_details << ID + 1 << "," << name << "," << age << "," << ticket_price << ",";
	for (int t = 0;t < sizeof(snacks) / sizeof(snacks[0]); t += 1) {
		attendee_details << snack_info[ID][t] << ",";
	}
	// calulates the total price to be charged by adding the ticket price and the snack cost
	float total_price = ticket_price + snack_cost;
	// adds the credit card surcharge if they selected card as their payment method
	if (cash_or_card == true) {
		total_price += (total_price / 100) * credit_card_surcharge;
	}
	attendee_details << snack_cost << ",";
	// out puts cash or card to the file depending on what they selected
	if (cash_or_card) {
		attendee_details << "cash ,";
	}
	else {
		attendee_details << "card ,";
	}
	float snack_profit = 0;
	// This loop adds up the cost of all the snacks they have ordered
	for (int c = 0;c < sizeof(snacks) / sizeof(snacks[0]); c += 1) {
		snack_profit += snack_info[ID][c] * snacks_profit[c];
	};
	float total_profit = ticket_profit + snack_profit;
	attendee_details << (total_price / 100) * credit_card_surcharge << "," << total_price << "," << ticket_price << ",," << ticket_profit << "," << snack_profit << ",";
	attendee_details << total_profit << endl;

	// This if statment outputs the summary statsitcs ot the file if this is the last ticket to be sold
	if (last_ticket) {
		attendee_details << endl << " Totals" << endl << ID + 1 << ",,,";
		// This for loop prints the total number of snacks that every one has ordered
		for (int c = 0;c < sizeof(snacks) / sizeof(snacks[0]); c += 1) {
			attendee_details << total_snacks[c] << ",";
			grand_total_profit += total_snacks[c] * snacks_profit[c];
		};
		// THis for loop prints "," for the number of snacks. It does this so that the program can scale with added or subtracted snacks.
		for (int v = 0;v < sizeof(snacks) / sizeof(snacks[0]); v += 1) {
			attendee_details << ",";
		}
		attendee_details << ",,Total profit:," << total_profit << endl << ",,Total seats :," << ID + 1;
		// Closese the file
		attendee_details.close();
	}
}

// Because of how much stuff is required for this to be tested i simply coppy pasted it into the main program and tested it there rather than make a main loop 
