#include <iostream>
#include <string>
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
//... int ticket_cost_ranges[4][2] = { {0,16},{17,54},{55,64},{65,100} };
int ticket_cost_ranges[3][2] = { {0,16},{17,64},{65,100} };
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

int min_age = 12;

int max_age = 100;


int snack_info[max_tickets][sizeof(snacks) / sizeof(snacks[0])];

int total_snacks[sizeof(snacks) / sizeof(snacks[0])];

ofstream attendee_details("attendee_details.csv");

// This fucntion takes a question then asks it and returns a valid stirng
string string_checker(string question, string error_message) {
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
				if (user_input != "") {
					return user_input;
				}
			}
		}
		// the error message for if it does convert to a string or a float 
		cout << error_message << endl << "  :";
	}
}

//This function takes a question and a minimum number and returns an int
int int_checker(string question, int min, int max) {
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
					if (k > min && k < max) {
						return stoi(user_input);
					}

				}

			}
			//Error message outputted if the user_input is bellow the minimum
			cout << "Please enter a whole number that is above " << min << " and bellow " << max << "\n  :";
		}
		catch (const std::exception&)
		{
			//The error message outputed if the users input is not an int
			cout << "Please enter a whole number \n  :";
		}
	}
}

// This function takes a persons num and assigns what snacks they want and how many to the snaack_info array
void snack_extractor(int person_num) {
	//  This is the range of numbers it will check for in the 
	regex range0_9("[0-9]");
	smatch regex_results;
	smatch regext_match_results;
	string str_num_of_snacks;
	string string_to_extract;
	int snack_type;
	int snack_quantity;

	cout << "Which snacks would you like to pre order ?" << endl;
	cout << "your options are ";
	// This for loop prints the snack options offered 
	for (int r = 0; r < sizeof(snacks) / sizeof(snacks[0]); r += 1) {
		cout << snacks[r];
		// This if statement prints a comma between each snack unless it is the last or second to last snack option in the snacks array
		if (r != sizeof(snacks) / sizeof(snacks[0]) - 1 && r != sizeof(snacks) / sizeof(snacks[0]) - 2) {
			cout << ", ";
		}
		// This if statment prints an and between the second to last snack and the last snack in the snacks array
		else if (r == sizeof(snacks) / sizeof(snacks[0]) - 2) {
			cout << " and ";
		}
	}
	cout << endl << "Please enter the name of the snack then the quntity of said snack desired. With a maximum of 9" << endl;
	cout << "once you have finished your selection of snacks please enter 3 x's" << endl;

	while (true) {
	top:
		cout << "  :";
		getline(cin, string_to_extract);
		// makes the users input all lower case
		for (int f = 0; f < size(string_to_extract); f += 1) {
			string_to_extract[f] = tolower(string_to_extract[f]);
		}
		// searches the users input for the presense and position of the first number
		if (regex_search(string_to_extract, regex_results, range0_9)) {
			// Checks if the char 1 to the right of the first number in the users input is a "." and weather the next char is a number
			if (string_to_extract[regex_results.position() + 1] == '.' && isdigit(string_to_extract[regex_results.position() + 2])) {
				goto error;
			}
			string str_with_no_num = string_to_extract;
			// converts the number detected with the first regex to an "a"
			str_with_no_num[regex_results.position()] = 'a';
			// searches this new str with out the first number to see if it still contains a number 
			if (regex_search(str_with_no_num, range0_9)) {
				// if there is a second number then it errors out
				goto error;
			}
			// makes the snack quanity to the found number 
			snack_quantity = stoi(regex_results[0]);
		}
		// if no number is found in the users input 
		else
		{
			// then set the quntity to 1
			snack_quantity = 1;
		}
		// for the number of items/snacks in the snacks list 
		for (int i = 0; i < sizeof(snacks) / sizeof(snacks[0]); i += 1) {
			// .find returns the pos of a sub string if it is in a string and returns npos (maximum size of a string) if it is not in the main string
			// so if the sub string is detected then it will not be npos
			if (string_to_extract.find(snacks[i]) != std::string::npos) {
				// sets snack type to i which will be the snacks pos in the snacks list 
				snack_type = i;
				// sets the snack quanityty onto the snack_info list
				snack_info[person_num][snack_type] = snack_quantity;
				goto top;
			}
		}
		// if "xxx" is found it exits the while loop c
		if (string_to_extract.find("xxx") != std::string::npos) {
			break;
		}
	error:
		cout << "please enter a snacks name and the number of snacks wanted\n\n";
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

// This function takes the users data then writes it to a csv file called results attendee_details.csv
void csv_file_writter(int ID, string name, int age, float ticket_price, float snack_cost, bool cash_or_card, float ticket_profit, bool last_ticket, float grand_total_profit) {
	// This if statement ouputs the titles for the collums if this is the first seat sold (ID = 0)
	if (ID == 0) {
		attendee_details << "Seat Num , Name , Age,Ticket price,";
		// This loop outputs the names of the snacks for the number of snacks in the list.
		for (int p = 0;p < sizeof(snacks) / sizeof(snacks[0]); p += 1) {
			attendee_details << snacks[p] << ",";
		}
		attendee_details << "Snack Cost,Payment Method,Surcharge,Total Cost,,Seat Profit,Snack Profit,Total Profit " << endl;
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
	attendee_details << (total_price / 100) * credit_card_surcharge << "," << total_price << "," << ",," << ticket_profit << "," << snack_profit << ",";
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
	float grand_total_profit = 0;
	int i = 0;
	while (i < max_tickets) {
		string name = string_checker("What is your name ?","Please enter your name. This can not be blank or a lone number");
		int age = int_checker("what is your age ?", min_age, max_age);

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

		bool card = yes_or_no("Which payment method would you like to use cash or card ?", "cash", "card", "plese enter your payment method eyther cash or card");

		


		if (yes_or_no("would you like to sell another seat", "yes", "no", "Pleease enter yes or no") == true) {
			csv_file_writter(i, name, age, ticket_price, snack_cost, card, ticket_profit, true, grand_total_profit);
			goto stop;
		}
		else {
			csv_file_writter(i, name, age, ticket_price, snack_cost, card, ticket_profit, false, grand_total_profit);
		}
		i += 1;
	}
stop:;
}