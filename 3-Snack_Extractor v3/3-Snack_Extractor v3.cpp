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
	bool loop = true;
	while (loop == true) {
		while (true) {
		top:
			cout << "  :";
			getline(cin, string_to_extract);
			for (int f = 0; f < size(string_to_extract); f +=1) {
				string_to_extract[f] = tolower(string_to_extract[f]);
			}
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