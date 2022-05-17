
#include <iostream>
#include <string>
#include <algorithm>

using namespace::std;

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


int main()
{
	int age;
	age = int_checker("please enter your age", 12);
	cout << "valid age :" << age << endl;

}


