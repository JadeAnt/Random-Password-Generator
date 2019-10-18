#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"
using namespace std;

void exitProgram() {
	cout << "Thank you for using PASSWORD GENERATOR!" << endl;
	exit(1);
}

void generatedPassword(string Final_password) {

	cout << "GENERATED PASSWORD: " << Final_password << endl;

}

void FindSavedPassword() {
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

void savePassword(string Final_password, ofstream& output) {
	string purpose;

	cout << "What is this password for?: "; cin >> purpose;
	output << purpose << "     " << Final_password << endl;

}

int Welcome() {

	int choice;
	cout << "=============================\n"
		<< "WELCOME TO PASSWORD GENERATOR\n"
		<< "ENTER BELOW TO GET STARTED\n"
		<< "=============================" << endl;

	cout << "1)Generate a new password\n"
		<< "2)Generate a new password with user input preferences\n"
		<< "3)Save newly generated Password\n"
		<< "4)Find a Previously Saved Password\n"
		<< "5)Clear Console\n"
		<< "6)Exit Program" << endl;

	cout << "\nWhat would you like to do?: "; cin >> choice;

	return choice;
}