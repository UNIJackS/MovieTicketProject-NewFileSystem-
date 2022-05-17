#include <iostream>
#include <regex>
#include <string>
#include <regex>
using namespace::std;

string snacks[] = { "popcorn","M & M's","Pita Chips","Orange Juice","Water" };

void snack_extractor(string string_to_extract, int& snack_quantity, int& snack_type) {
	regex range0_9("[0-9]");
	smatch regex_results;
	string str_num_of_snacks;
	if (regex_search(string_to_extract, regex_results, range0_9)) {
		str_num_of_snacks = regex_results[0];
		snack_quantity = stoi(str_num_of_snacks);
	}
	else
	{
		snack_quantity = 1;
	}

	for (int i = 0; i < sizeof(snacks) / sizeof(snacks[0]); i += 1) {
		if (string_to_extract.find(snacks[i]) != std::string::npos) {
			std::cout << "found!" << '\n';
			snack_type = i;
		}
	}

}




int main() {
	string user_input;
	cout << "input\n  :";
	getline(cin, user_input);
	cout << "user_input  :" << user_input << endl;
	vector<vector<int>> snacks_selected(2, vector<int>());
	int snack_quantity;
	int snack_type;
	snack_extractor(user_input, snack_quantity, snack_type);
	cout << "snack_quantity  :" << snack_quantity << endl << "snack_type  :" << snack_type << endl;
}