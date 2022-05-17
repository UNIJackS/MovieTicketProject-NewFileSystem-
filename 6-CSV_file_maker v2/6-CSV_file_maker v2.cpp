#include <fstream>
#include <iostream>
using namespace::std;

int const max_tickets = 3;

float credit_card_surcharge = 5;

ofstream attendee_details("attendee_details.csv");

string snacks[] = { "popcorn","M & M's","Pita Chips","Orange Juice","Water" };

int snack_info[max_tickets][sizeof(snacks) / sizeof(snacks[0])];

void csv_file_writter(int ID, string name, int age, float ticket_price, float snack_cost, bool cash_or_card) {
	if (ID == 0) {
		attendee_details << "Seat Num , Name , Age,";
		for (int p = 0;p < sizeof(snacks) / sizeof(snacks[0]); p += 1) {
			attendee_details << snacks[p] << ",";
		}
		attendee_details << "Total price" << endl;
	}

	attendee_details << ID + 1 << "," << name << "," << age << ",";
	for (int t = 0;t < sizeof(snacks) / sizeof(snacks[0]); t += 1) {
		attendee_details << snack_info[ID][t] << ",";
	}
	float total_price = ticket_price + snack_cost;
	if (cash_or_card == true) {
		total_price += (total_price / 100) * credit_card_surcharge;
	}
	attendee_details << total_price << endl;
}




int main()
{
	for (int i = 0; i < max_tickets; i += 1) {
		cout << "name :";
		string name;
		cin >> name;
		cout << "age :";
		int age;
		cin >> age;
		cout << "ticket_price :";
		int ticket_price;
		cin >> ticket_price;
		cout << "snack_cost :";
		int snack_cost;
		cin >> snack_cost;
		csv_file_writter(i, name, age, ticket_price, snack_cost);
	}

}