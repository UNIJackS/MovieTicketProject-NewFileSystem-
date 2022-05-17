#include <iostream>
#include <regex>
#include <string>
#include <regex>
using namespace::std;
int const max_tickets = 3;
string snacks[] = { "popcorn","M & M's","Pita Chips","Orange Juice","Water" };
int snack_info[max_tickets][sizeof(snacks) / sizeof(snacks[0])];


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
		if (r != sizeof(snacks) / sizeof(snacks[0])) {
			cout << ", ";
		}
	}
	bool loop = true;
	while (loop == true) {
		while (true) {
		top:
			cout << "\n  :";
			getline(cin, string_to_extract);
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