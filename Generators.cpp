#pragma once
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include "Generators.h"
using namespace std;


char upperGenerator() {

	int upper_finder = rand() % (90 + 1 - 65) + 65;
	char upper_maker = upper_finder;

	return upper_maker;
}

char lowerGenerator() {
	int lower_finder = rand() % (122 + 1 - 97) + 97;
	char lower_maker = lower_finder;

	return lower_maker;
}

int numberGenerator() {
	int number_finder = rand() % (57 + 1 - 48) + 48;
	char number_maker = number_finder;

	return number_maker;
}

char specialGenerator() {
	int special_finder = rand() % (46 + 1 - 33) + 33;
	char special_maker = special_finder;

	return special_maker;
}

string Password_Generator() {
	string Final_password;
	srand(time(NULL));

	Final_password = "";

	int length = rand() % (7 + 1 - 9) + 9;

	//Password Generation
	for (int i = 0; i < length; ++i) {

		int change = rand() % (4 + 1 - 1) + 1;

		switch (change) {
			case 1:
				//uppercase A - Z #'s 65 - 90
				Final_password += upperGenerator();

				Final_password += numberGenerator();
				break;

			case 2:
				//random number generator from 0 to 9
				Final_password += numberGenerator();
				break;

			case 3:
				//special characters #'s 33 - 46

				Final_password += specialGenerator();

				Final_password += numberGenerator();

				break;

			case 4:
				//lowercase a - z #'s 97 - 122
				Final_password += lowerGenerator();
				break;
		}

	}

	return Final_password;
}

string Generator_Preferences() {
	string Final_password;

	/*User needs to be able to:
		1)Exclude certain variables(numbers, upper/lower letters, special characters)
		2)Choose number of variables to include in password
		*/
	char bo_upper, bo_lower, bo_special, bo_number;
	int nr_length;

	//Prompt user to input values for characters
	cout << "y = yes, n = no" << endl;
	cout << "Do you want upper characters: "; cin >> bo_upper;
	cout << "Do you want lower characters: "; cin >> bo_lower;
	cout << "Do you want special characters: "; cin >> bo_special;
	cout << "Do you want numbers: "; cin >>bo_number;
	cout << "How long do you want the password to be?: "; cin >> nr_length;

	srand(time(NULL));

	Final_password = "";

	for (int i = 0; i < nr_length; i++) {

		int change = rand() % (4 + 1 - 1) + 1;

		switch (change) {
		case 1:
			//uppercase A - Z #'s 65 - 90
			if (bo_upper == 'y') {
				Final_password += upperGenerator();
			}
			else {
				i--;
			}
			break;

		case 2:
			//random number generator from 0 to 9
			if(bo_number == 'y') {
				Final_password += numberGenerator();
			}
			else {
				i--;
			}
			break;

		case 3:
			//special characters #'s 33 - 46
			if(bo_special == 'y') {
				Final_password += specialGenerator();
			}
			else {
				i--;
			}
			break;

		case 4:
			//lowercase a - z #'s 97 - 122
			if(bo_lower == 'y') {
				Final_password += lowerGenerator();
			}
			else {
				i--;
			}
			break;
		}


	}

	return Final_password;
}
