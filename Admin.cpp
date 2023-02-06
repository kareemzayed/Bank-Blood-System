#include "Admin.h"
#include<fstream>
#include <vector>
vector<string> donor_name_in_donationRequast;
vector<int> donor_amount_in_donationRequast;
vector<string> donor_date_in_donationRequast;
vector<char> donor_type_in_donationRequast;

Admin::Admin() {
	string nam, dat, sufferOther;
	char typ;
	int amoun;
	bool suffer;
	ifstream accept;
	accept.open("accept.txt");
	if (!accept.fail()) {
		while (!accept.eof()) {
			accept >> nam >> typ >> amoun >> dat;
			donor_name_in_donationRequast.push_back(nam);
			donor_type_in_donationRequast.push_back(typ);
			donor_amount_in_donationRequast.push_back(amoun);
			donor_date_in_donationRequast.push_back(dat);
		}
	}
	accept.close();
	remove("accept.txt");
	cout << endl << endl;
	cout << "                      ======================================================================\n";
	cout << "                      ||                          Hello in Admin page                     ||\n";
	cout << "                      ======================================================================\n\n";
	cout << "                                        -------------------------------------\n";
	cout << "                                        | 1-Validate the donor’s request     |\n";
	cout << "                                        | 2-                                 |\n";
	cout << "                                        | 3-Exit                             |\n";
	cout << "                                        --------------------------------------\n\n";
	cout << " Enter your choice: ";
	int ch; cin >> ch;
	if (ch == 1)
		validate_donors_requast();
	else if(ch == 3)
		Exit();
	///////////
	///////////
}
void Admin::validate_donors_requast() {
	string nam, dat, sufferOther, donationDate;
	char typ;
	int amoun, age;
	bool suffer;
	ifstream donationRequast;
	donationRequast.open("donationRequast.txt");
	if (!donationRequast.fail()) {
		while (!donationRequast.eof()) {
			donationRequast >> nam >> typ >> suffer >> sufferOther >> age >> donationDate >> amoun >> dat;
			if (!suffer && sufferOther == "null" && age >= 17 && age <= 60) {
				donor_name_in_donationRequast.push_back(nam);
				donor_type_in_donationRequast.push_back(typ);
				donor_amount_in_donationRequast.push_back(amoun);
				donor_date_in_donationRequast.push_back(dat);
			}
		}
		donationRequast.close();
		cout << " =========================================================================================\n";
		cout << " The validation of the donors’ requests was successful, press enter to back menue.." << endl;
		cout << " =========================================================================================\n";
		cin.get();
		cin.get();
		Admin::Admin();
	}
	else {
		cout << " No donation requasts available, please press enter to continue..\n";
		cin.get();
		cin.get();
		Admin::Admin();
	}
}
void Admin::Exit() {
	fstream accept;
	accept.open("accept.txt", ios::app);
	for (int i = 0; i < donor_name_in_donationRequast.size(); i++) {
		if (i == donor_name_in_donationRequast.size() - 1) {
			accept << donor_name_in_donationRequast[i] << ' ' << donor_type_in_donationRequast[i] << ' ' << donor_amount_in_donationRequast[i] <<
				' ' << donor_date_in_donationRequast[i];
		}
		else {
			accept << donor_name_in_donationRequast[i] << ' ' << donor_type_in_donationRequast[i] << ' ' << donor_amount_in_donationRequast[i] <<
				' ' << donor_date_in_donationRequast[i] << endl;
		}
	}
	accept.close();
}
Admin::~Admin() {

}