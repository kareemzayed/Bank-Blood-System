#include <iostream>
#include "Donor.h"
#include "User.h"
#include "Recipient.h"
using namespace std;

int main()
{
	system("COLOR A");
	system("cls");
	cout << "                      ====================================================================== \n";
	cout << "                      ||                   Welcome in Bank Blood page                     || \n";
	cout << "                      ====================================================================== \n\n\n";
	cout << "                                             ---------------\n";
	cout << "                                             |Are You:     |\n";
	cout << "                                             ---------------\n";
	cout << "                                             | 1- Donor    |\n";
	cout << "                                             | 2- Recepient|\n";
	cout << "                                             | 3- Exit     |\n";
	cout << "                                             ---------------\n\n";
	cout << " Enter your choice: ";
	int ch; cin >> ch;
	if (ch == 1)
		Donor don; // create object from donor class
	else if (ch == 2)
		Recipient rep; // create object from recepient class
	else if (ch == 3)
		exit(1); // exit from program
	else {		// enters incorrect choice
		cout << " ============================================================================\n";
		cout << " Incorrect choice, please press Enter and try again...\n";
		cout << " ============================================================================\n\n";;
		cin.get();
		cin.get();
		main();
	}
}