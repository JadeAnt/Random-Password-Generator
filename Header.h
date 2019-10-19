#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char Welcome() {
	char n;

	cout << "\n=============================\n"
		<< "WELCOME TO PASSWORD GENERATOR\n"
		<< "ENTER BELOW TO GET STARTED\n"
		<< "=============================" << endl;

	cout << "Do you want a new password to be generated? (y - continue/n - exit)"; cin >> n;

	return n;
}


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