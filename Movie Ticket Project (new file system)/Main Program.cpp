
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#include <fstream>

using namespace::std;

int const max_tickets = 3;



// ====== Snack Data ======
string snacks[] = { "popcorn","m & m's","pita chips","orange juice","water" };

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

float credit_card_surcharge = 5; //in percent 

int snack_info[max_tickets][sizeof(snacks) / sizeof(snacks[0])];

int total_snacks[sizeof(snacks) / sizeof(snacks[0])];

ofstream attendee_details("attendee_details.csv");

// This fucntion takes a question then asks it and returns a valid stirng
string string_checker(string question) {
	// declares local varables that will be used
	string user_input;
	int test_int;
	float test_float;

	cout << question << endl << "  :";

	bool infinate_loop = true;
	while (infinate_loop == true) {
		getline(cin, user_input);
		// this try statment tests if what the user inputed will convert to a intiger
		try
		{
			// this trys and converts the users input into a intiger 
			test_int = stoi(user_input);
		}
		catch (const std::exception&)
		{
			// this try statment tests if what the user inputed will convert to a float
			try
			{
				// this trys and converts the users input into a float
				test_float = stoi(user_input);
			}
			catch (const std::exception&)
			{
				return user_input;
			}
		}
		// the error message for if it does convert to a string or a float 
		cout << "plese enter a string" << endl << "  :";
	}
}


//This function takes a question and a minimum number and returns an int
int int_checker(string question, int min) {
	//This asks the question
	cout << question << endl << "  :";
	//Initilizes valid_answer as true which will only turn to false when a valid input is entered
	bool valid_answer = true;
	while (valid_answer == true) {
		string user_input;
		// takes the input from the question asked
		getline(cin, user_input);
		//sets up a try statment incase the program can not convert the input into an int
		try
		{
			//Converts the users input into an int. In doing this it rounds down so it also adds 1...
			//It does this because to check weather the number is an int we need to find the...
			//number of whole numbers/ints between it and 0
			int user_input_rounded_up = stoi(user_input) + 1;
			for (int i = 0; i < user_input_rounded_up; i += 1) {
				float r = stof(user_input);
				if (r == i) {
					//checks weather the users input is above the minimum
					int k = stoi(user_input);
					if (k > min) {
						return stoi(user_input);
					}

				}

			}
			//Error message outputted if the user_input is bellow the minimum
			cout << "Please enter a whole number that is above " << min << "\n  :";
		}
		catch (const std::exception&)
		{
			//The error message outputed if the users input is not an int
			cout << "Please enter a whole number \n  :";
		}
	}
}

void snack_extractor(int person_num) {
	regex range0_9("[0-9]");
	smatch regex_results;
	smatch regext_match_results;
	string str_num_of_snacks;
	string string_to_extract;
	int snack_type;
	int snack_quantity;

	cout << "What snacks would you like ? if you do not want any snacks or have finished your selecton enter 3 x's\n please enter a number before or after the snack's name to order multiple" << endl;
	cout << "your options are ";
	for (int r = 0; r < sizeof(snacks) / sizeof(snacks[0]); r += 1) {
		cout << snacks[r];
		if (r != sizeof(snacks) / sizeof(snacks[0]) - 1 && r != sizeof(snacks) / sizeof(snacks[0]) - 2) {
			cout << ", ";
		}
		else if (r == sizeof(snacks) / sizeof(snacks[0]) - 2) {
			cout << " and ";
		}
	}
	bool loop = true;
	while (loop == true) {
		while (true) {
		top:
			cout << "\n  :";
			getline(cin, string_to_extract);
			for_each(string_to_extract.begin(), string_to_extract.end(), [](char& c) {
				c = ::tolower(c);
				});

			if (regex_search(string_to_extract, regex_results, range0_9)) {
				str_num_of_snacks = regex_results[0];
				if (string_to_extract[regex_results.position() + 1] == '.' && isdigit(string_to_extract[regex_results.position() + 2])) {
					goto error;
				}
				string test1 = string_to_extract;
				test1[regex_results.position()] = 'a';
				if (regex_search(test1, regex_results, range0_9)) {
					goto error;
				}
				snack_quantity = stoi(str_num_of_snacks);
			}
			else
			{
				snack_quantity = 1;
			}

			for (int i = 0; i < sizeof(snacks) / sizeof(snacks[0]); i += 1) {
				if (string_to_extract.find(snacks[i]) != std::string::npos) {
					snack_type = i;
					snack_info[person_num][snack_type] = snack_quantity;
					goto top;
				}
			}
			if (string_to_extract.find("xxx") != std::string::npos) {
				loop = false;
				break;
			}
		error:
			cout << "please enter a snacks name and the number of snacks wanted";
		}

	}

}

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


void ticket_cost_calculator(int age, float& ticket_price, float& ticket_profit) {
	for (int f = 0; f < sizeof(ticket_prices) / sizeof(ticket_prices[0]); f += 1) {
		if (age >= ticket_cost_ranges[f][0] and age <= ticket_cost_ranges[f][1]) {
			ticket_price = ticket_prices[f];
			ticket_profit = ticket_profits[f];
		}
	}
}

// This function takes the users data then writes it to a csv file called results attendee_details.csv
void csv_file_writter(int ID, string name, int age, float ticket_price, float snack_cost, bool cash_or_card, float ticket_profit, bool last_ticket, float grand_total_profit) {
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

	if (last_ticket) {
		attendee_details << endl << " Totals" << endl << ID + 1 << "," << "," << ",";
		for (int c = 0;c < sizeof(snacks) / sizeof(snacks[0]); c += 1) {
			attendee_details << total_snacks[c] << ",";
			grand_total_profit += total_snacks[c] * snacks_profit[c];
		};

		attendee_details << grand_total_profit;
		attendee_details.close();
	}
}






int main()
{

	float grand_total_profit = 0;
	int i = 0;
	while (i < max_tickets) {
		string name = string_checker("What is your name ?");
		int age = int_checker("what is your age ?", 12);

		float ticket_price;
		float ticket_profit;
		ticket_cost_calculator(age, ticket_price, ticket_profit);
		grand_total_profit += ticket_profit;

		snack_extractor(i);

		float snack_cost = 0;
		float snack_profit = 0;

		for (int k = 0;k < sizeof(snacks) / sizeof(snacks[0]); k += 1) {
			snack_cost += snacks_price[k] * snack_info[i][k];
			snack_profit += snacks_profit[k] * snack_info[i][k];
			total_snacks[k] += snack_info[i][k];
		}

		bool card = yes_or_no("Which payment method would you like to use; cash or card ?", "cash", "card", "plese enter your payment method eyther cash or card");


		if (yes_or_no("would you like to sell another seat", "no", "yes", "Pleease enter yes or no") == false) {
			csv_file_writter(i, name, age, ticket_price, snack_cost, card, ticket_profit, true, grand_total_profit);
			exit;
		}
		else {
			csv_file_writter(i, name, age, ticket_price, snack_cost, card, ticket_profit, false, grand_total_profit);
		}
		i += 1;
	}
}