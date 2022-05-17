
#include <iostream>
#include <string>
#include <algorithm>

using namespace::std;
string string_checker(string question) {
	string user_input;
	int test_int;
	float test_float;
	cout << question << endl << "  :";
	cin >> user_input;
	try
	{
		test_int = stoi(user_input);
	}
	catch (const std::exception&)
	{
		try
		{
			test_float = stoi(user_input);
		}
		catch (const std::exception&)
		{
			return user_input;
		}
	}
	cout << "plese enter a string" << endl << "  :";
}




int main()
{
	string name = string_checker("enter name");
	cout << endl << "name entered :" << name << endl;

}