#include <fstream>
#include <iostream>
using namespace::std;

int const max_tickets = 3;

ofstream attendee_details("attendee_details.csv");

string snacks[] = { "popcorn","M & M's","Pita Chips","Orange Juice","Water" };

int snack_info[max_tickets][sizeof(snacks) / sizeof(snacks[0])];

void csv_file_writter(int ID, string name, int age, int ticket_price, int snack_cost) {
	attendee_details << "Person #:" << ID << endl;
	attendee_details << "Name :" << name << endl;
	attendee_details << "Age :" << age << endl;
	for (int t = 0;t < sizeof(snacks) / sizeof(snacks[0]); t += 1) {
		attendee_details << snacks[t] << " x " << snack_info[ID][t] << endl;
	}
	float total_price = ticket_price + snack_cost;
	attendee_details << "Total price :" << total_price << endl << endl << endl;
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

