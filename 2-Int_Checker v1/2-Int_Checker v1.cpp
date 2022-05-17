
#include <iostream>
#include <string>
#include <algorithm>

using namespace::std;

int int_checker(string question, int min) {
	cout << question;
	bool valid_answer = true;
	while (valid_answer == true) {
		string user_input;
		getline(cin, user_input);
		try
		{
			int user_input_rounded_up = stoi(user_input) + 1;
			for (int i = 0; i < user_input_rounded_up; i += 1) {
				float r = stof(user_input);
				if (r == i) {
					int k = stoi(user_input);
					if (k > min) {
						return stoi(user_input);
					}

				}

			}

			cout << "Please enter a whole number that is above " << min << "\n  :";
		}
		catch (const std::exception&)
		{
			cout << "Please enter a whole number \n  :";
		}
	}
}


int main()
{
	int age;
	age = int_checker("please enter your age\n  :", 12);
	cout << "valid age :" << age << endl;

}


