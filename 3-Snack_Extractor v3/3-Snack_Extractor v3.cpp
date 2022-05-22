#include <iostream>
#include <regex>
#include <string>
#include <regex>
using namespace::std;
int const max_tickets = 3;
string snacks[] = { "popcorn","m & m's","pita chips","orange juice","water" };
int snack_info[max_tickets][sizeof(snacks) / sizeof(snacks[0])];

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
		for (int f = 0; f < size(string_to_extract); f +=1) {
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


int main()
{

	for (int f = 0; f < max_tickets; f += 1) {
		snack_extractor(f);
		for (int i = 0; i < sizeof(snacks) / sizeof(snacks[0]); i += 1) {
			cout << snacks[i] << " x " << snack_info[f][i] << endl;
		}
		cout << endl << endl;
	}


}