#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <fstream>

using namespace std;

void FindPassword() {
	ifstream out;
	string find, looking, found;

	out.open("SavedPasswords.txt");

	cout << "What password are you looking for: "; cin >> looking;

	while (out >> find) {
		if (find == looking) {
			
			out >> found;
		}
	}

	cout << "Found password for " << looking << " : " << found << endl;
	out.close();
}

int main(){

	ofstream output;
	string Final_password, purpose;
	char c_maker, n, in;
	int upper_finder, lower_finder, special_finder, number_finder;

	output.open("SavedPasswords.txt");
	output << "Purpose   |   Password" << endl;

	cout << "=============================\n"
		<< "WELCOME TO PASSWORD GENERATOR\n"
		<< "ENTER BELOW TO GET STARTED\n"
		<< "=============================" << endl;

	cout << "Do you want a new password to be generated? (y - continue/n - exit)"; cin >> n;

	srand(time(NULL));

	while (n != 'n') {

		Final_password = "";

		//Password Generation
		for (int i = 0; i < 9; ++i) {

			int change = rand() % (4 + 1 - 1) + 1;

			switch (change) {
				case 1:
					//uppercase A - Z #'s 65 - 90
					upper_finder = rand() % (90 + 1 - 65) + 65;
					c_maker = upper_finder;
					Final_password += c_maker;

					number_finder = rand() % (57 + 1 - 48) + 48;
					c_maker = number_finder;
					Final_password += c_maker;
					break;

				case 2:
					//random number generator from 0 to 9
					number_finder = rand() % (57 + 1 - 48) + 48;
					c_maker = number_finder;
					Final_password += c_maker;
					break;

				case 3:
					//special characters #'s 33 - 46
					special_finder = rand() % (46 + 1 - 33) + 33;
					c_maker = special_finder;
					Final_password += special_finder;

					number_finder = rand() % (57 + 1 - 48) + 48;
					c_maker = number_finder;
					Final_password += c_maker;
					break;

				case 4:
					//lowercase a - z #'s 97 - 122
					lower_finder = rand() % (122 + 1 - 97) + 97;
					c_maker = lower_finder;
					Final_password += c_maker;
					break;
			}

		}

		cout << "Generated Password: " << Final_password << endl;

		cout << "Would you like to save this password for future use?: (y - save/n - no)"; cin >> in;
		if (in == 'y') {
			cout << "What is this password for?: "; cin >> purpose;
			output << purpose << "     " << Final_password << endl;
		}

		cout << "\n Do you want a new password to be generated? (y - continue/n - exit) "; cin >> n;

	}

	while (n != 'o') {

		cout << "\nWould you like to find a Saved Password you generated? (f - yes/ o - exit): "; cin >> n;
		if (n == 'f') {
			FindPassword();
		}
	}

	output.close();
	system("pause");
	return 0;
}
