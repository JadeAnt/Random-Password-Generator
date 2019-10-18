#include <string>
using namespace std;

void exitProgram(); // Exit program message

void generatedPassword(string Final_password); // outputs the generated password

void FindSavedPassword();//searches for saved password in text file

void savePassword(string Final_password, ofstream& output);//saves password within text file

int Welcome();//weclome start page with all user choices
