#include "Donor.h"
#include <fstream>
#include <vector>
using namespace std;

int check;
vector<string> donors_name;
vector<string> donors_email;
vector<string> donors_password;
vector<string> donors_gender;
vector<string> donors_donation_date;
vector<int> donors_age;
vector<int> donors_id;
vector<bool> donors_suffers;
vector<string> donors_suffers_other;
vector<char> donors_blood_type;
vector<bool> can_donate;
int Login_indix;

//	All previous variables have been placed in the global due to their frequent use in different functions..

Donor::Donor()
{
	/*
	This constractor is used to take all the data recorded in the file "donor" and
	it is recorded in the vectors and it deletes the file to work on vectors
	*/
	string name_, email_, password_, gender_, date_, sufferOther_;
	char bloo_type_;
	bool suffer_, can_donaet_;
	int id_, age_;
	ifstream donor;
	donor.open("donor.txt");
	if (!donor.fail()) {
		while (!donor.eof()) {
			donor >> name_ >> id_ >> gender_ >> age_ >> email_ >> password_ >> bloo_type_ >> suffer_ >> can_donaet_ >> sufferOther_ >>  date_;
			donors_name.push_back(name_);
			donors_id.push_back(id_);
			donors_gender.push_back(gender_);
			donors_age.push_back(age_);
			donors_email.push_back(email_);
			donors_password.push_back(password_);
			donors_blood_type.push_back(bloo_type_);
			donors_suffers.push_back(suffer_);
			can_donate.push_back(can_donaet_);
			donors_suffers_other.push_back(sufferOther_);
			donors_donation_date.push_back(date_);
			/*
				The file is opened, then all the data is received, each line individually,
				and then it is taken into the appropriate vector, such as:
				The name is taken in donors_name, etc...
			*/
		}
	}
	donor.close(); // close file
	remove("donor.txt");    // delete file
	//	This constractor also shows the selection list in front of the donor either to log in or sign in...
	system("cls");
	cout << endl << endl;
	cout << "                      ======================================================================\n";
	cout << "                      ||                          Hello in Donor page                     ||\n";
	cout << "                      ======================================================================\n\n";
	cout << "                                             ---------------\n";
	cout << "                                             | 1- Login    |\n";
	cout << "                                             | 2- Register |\n";
	cout << "                                             | 3- Exit     |\n";
	cout << "                                             ---------------\n\n";
	cout << " Enter your choice: ";
	int ch; cin >> ch;
	if (ch == 1)
		Login(); // login function
	else if (ch == 2) 
		Register(); // rigester function
	else if (ch == 3) 
		Exit(); // exit from program
}
void Donor::setSuffers(bool suf)
{
	suffers = suf;
}
void Donor::setdonationDate(string date)
{
	donationDate= date;
}
bool Donor::getSuffers()
{
	return suffers;
}
void Donor::setSuffersOther(string oth) {
	suffer_other = oth;
}
string Donor::getSuffersOther() {
	return suffer_other;
}
string Donor:: getdonationDate()
{
	return donationDate;
}
void  Donor:: Register()
{
		/*
			This function records the donor's data to create a new account in the program.
			When recording the data, it is taken from the donor, and then it is placed in its own vector to work on later.
		*/
		system("cls");
		cout << "\n Enter your Data .. \n\n";
		cout << "-----------------------------------------------------\n";
		cout << " Your Name : ";
		string name;
		cin >> name;
		setName(name);
		donors_name.push_back(getName());   // put name in name's vector...
		cout << "-----------------------------------------------------\n";
		cout << " Your ID: ";
		int id;  cin >> id;
		setID(id);
		donors_id.push_back(getID());       // put name in ID's vector....
		cout << "-----------------------------------------------------\n";
		cout << " Your Gender : ";
		string gen; cin >> gen;
		setGender(gen);
		donors_gender.push_back(getGender());	// put name in gender's vector....
		cout << "-----------------------------------------------------\n";
		cout << " Your Age : ";
		int age; cin >> age;
		setAge(age);
		donors_age.push_back(getAge());		// put name in age's vector....
		cout << "-----------------------------------------------------\n";
		cout << " Your E-Mail : ";
		string mail; cin >> mail;
		setEmail(mail);
		donors_email.push_back(getEmail());		// put name in email's vector....
		cout << "-----------------------------------------------------\n";
		cout << " Your password : ";
		string pass; cin >> pass;
		setpassword(pass);
		donors_password.push_back(getpassword());		// put name in password's vector....
		cout << "-----------------------------------------------------\n";
		cout << " Your Blood Type : ";
		char bType; cin >> bType;
		setbloodType(bType);
		donors_blood_type.push_back(getbloodType());  // put name in blood type's vector....
		cout << "-----------------------------------------------------\n";
		cout << " Do you suffer from any diseases from these (blood pressure disorders, thyroid disease," << endl
			<< " diabetes, cancer, heart disorders, hepatitis)? (y,n)";
		char ch; cin >> ch;
		if (ch == 'Y' || ch == 'y') {
			setSuffers(true);
			donors_suffers.push_back(getSuffers());   // put name in boolean vector....
		}
		else {
			setSuffers(false);
			donors_suffers.push_back(getSuffers());		// put name in boolean vector....
		}
		cout << "-----------------------------------------------------\n";
		cout << " Do you suffer from any other diseases or taken any medicine? (y,n)";
		char ch2; cin >> ch2;
		if (ch2 == 'Y' || ch2 == 'y') {
			cout << "       Enter the name of your diseases or medicine: ";
			string diseases; cin >> diseases;
			setSuffersOther(diseases);
			donors_suffers_other.push_back(getSuffersOther());  // put name in suufers' vector....
		}
		else {
			setSuffersOther("null");
			donors_suffers_other.push_back(getSuffersOther());		// put name in suufers' vector....
		}
		cout << "-----------------------------------------------------\n";
		cout << " The Last donation of you must be at least 3 months, are you that? (y,n)";
		char c; cin >> c;
		if (c == 'Y' || c == 'y') {
			can_donate.push_back(true);		// put name in boolean vector....
			cout << "-----------------------------------------------------\n";
			cout << " Enter your Last Donation Date: (dd/mm/yyyy) ";
			string date; cin >> date;
			setdonationDate(date);
			donors_donation_date.push_back(getdonationDate());		// put name in date's vector....
		}
		else {
			cout << " ==========================================================================================\n";
			cout << " You can not make any donation requast before at least 3 months, press enter to continue...\n";
			cout << " ==========================================================================================\n\n";
			can_donate.push_back(false);		// put name in boolean vector....
			cin.get();
			cin.get();
			cout << "-----------------------------------------------------\n";
			cout << " Enter your Last Donation Date: (dd/mm/yyyy) ";
			string date; cin >> date;
			setdonationDate(date);
			donors_donation_date.push_back(getdonationDate());		// put name in date's vector....
		}
		cout << " ============================================================================\n";
		cout << " Congratulations, Your process is Done ... press Enter to return main...\n";
		cout << " ============================================================================\n\n";
		cin.get();
		cin.get();
		Donor::Donor();
}
void Donor::Login()
{
	/*
		This function logs the donor in.
		This search for his account in all the accounts that are registered in vector.
		This are looking for whether the account and password that was entered already exist in vectors or not.
	*/
	system("cls");
	cout << "-----------------------------------------------------\n";
	cout << " Your E-Mail: ";
	string mail; cin >> mail;
	cout << "-----------------------------------------------------\n";
	cout << " You Password: ";
	string pass; cin >> pass;
	for (int i = 0; i < donors_password.size(); i++) {
		if (mail == donors_email[i] && pass == donors_password[i]) {
			check = 1;   // Verify that the account and password exist or not
			Login_indix = i;    // save the donor's vector index to facilitate in the future, such as updating or deleting the account
			break;
		}
	}
	if (check == 1) {
		// If the account exists 
		cout << " ============================================================================\n";
		cout << " Successful Login, Please press Enter to go in main menue...." << endl;
		cout << " ============================================================================\n";
		check = 0;
		cin.get();
		cin.get();
		main_menue_donor();
	}
	else {
		// If the account doesn't exist 
		cout << " ==============================================================================\n";
		cout << " Incorrect E-Mail or Password, please try again...Press Enter to Login again...\n";
		cout << " ==============================================================================\n";
		cin.get();
		cin.get();
		Login();     // to try again...
	}
}
void Donor::donationRequast() {
	system("cls");
	// check if this user can donate or not
	if (can_donate[Login_indix]) {  // if he can
		cout << "-----------------------------------------------------------\n";
		cout << " Enter the amount of blood you want to donate in liters: ";
		int amount; cin >> amount;
		cout << "-----------------------------------------------------\n";
		cout << " Enter today's date:(dd/mm/yy) ";
		string date; cin >> date;
		cout << "-----------------------------------------------------\n";
		if (amount > 2) {     // he can donate 2 liters maximum and if he enters more than it it's not allowed
			cout << " ========================================================================================\n";
			cout << " The quantity you entered is more than the allowed limit (2), press enter to try again...\n";
			cout << " ========================================================================================\n";
			cin.get();
			cin.get();
			donationRequast();
		}
		else if (amount < 1) {	// if he enters uncorrect data
			cout << " ====================================================================================\n";
			cout << " The quantity you entered is not correct, please press enter to try again..." << endl;
			cout << " ====================================================================================\n";
			cin.get();
			cin.get();
			donationRequast();
		}
		else {		// if he enters correct data 
			cout << " =======================================================================================================\n";
			cout << " Thank you, the donation was successful. Wait for approval from the admine, press enter to back menue.." << endl;
			cout << " =======================================================================================================\n";
			fstream donationRequast;		// opening doantion request file
			donationRequast.open("donationRequast.txt", ios::app);	//put data on it
			donationRequast << endl << donors_name[Login_indix] << ' ' << donors_blood_type[Login_indix]
				<< ' ' << amount << ' ' << date;
			donationRequast.close(); // close file
			cin.get();
			cin.get();
			main_menue_donor(); // back to donor main menu
		}
	}
	else {
		cout << " ==========================================================================================\n";
		cout << " You can not make any donation requast before at least 3 months, press enter to continue...\n";
		cout << " ==========================================================================================\n\n";
		cin.get();
		cin.get();
		main_menue_donor();
	}
}
void Donor::updatAccount() {
	// All donor data is deleted from the list and all donor data is registered again
	donors_name.erase(donors_name.begin() + Login_indix);
	donors_id.erase(donors_id.begin() + Login_indix);
	donors_gender.erase(donors_gender.begin() + Login_indix);
	donors_age.erase(donors_age.begin() + Login_indix);
	donors_email.erase(donors_email.begin() + Login_indix);
	donors_password.erase(donors_password.begin() + Login_indix);
	donors_blood_type.erase(donors_blood_type.begin() + Login_indix);
	donors_suffers.erase(donors_suffers.begin() + Login_indix);
	donors_donation_date.erase(donors_donation_date.begin() + Login_indix);
	Register();  // register again..
}
void Donor::deleteAccount() {
	system("cls");
	// first ask him if he sure to delete his acc or not 
	cout << "                                      -------------------------------------------\n";
	cout << "                                      |Are You sure from deleting your account: |\n";
	cout << "                                      -------------------------------------------\n";
	cout << "                                      | 1- Yes                                  |\n";
	cout << "                                      | 2- No                                   |\n";
	cout << "                                      -------------------------------------------\n";
	cout << " Enter your choice: ";
	int ch; cin >> ch;
	if (ch == 1) { // delete all his data from vectors
		donors_name.erase(donors_name.begin() + Login_indix);
		donors_id.erase(donors_id.begin() + Login_indix);
		donors_gender.erase(donors_gender.begin() + Login_indix);
		donors_age.erase(donors_age.begin() + Login_indix);
		donors_email.erase(donors_email.begin() + Login_indix);
		donors_password.erase(donors_password.begin() + Login_indix);
		donors_blood_type.erase(donors_blood_type.begin() + Login_indix);
		donors_suffers.erase(donors_suffers.begin() + Login_indix);
		donors_donation_date.erase(donors_donation_date.begin() + Login_indix);
		cout << " =============================================================================\n";
		cout << " Your account has been deleted successfully, please press Enter to continue...\n";
		cout << " =============================================================================\n";
		cin.get();
		cin.get();
		// after deleting his account he should register or exit from system
		system("cls");
		cout << "                      ======================================================================\n";
		cout << "                      ||                          Hello in Donor page                     ||\n";
		cout << "                      ======================================================================\n\n";
		cout << "                                              ---------------\n";
		cout << "                                              | 1- Register |\n";
		cout << "                                              | 2- Exit     |\n";
		cout << "                                              ---------------\n\n";
		cout << " Enter your choice: ";
		int ch; cin >> ch;
		if (ch == 1)
			Register();
		else if (ch == 2)
			Exit();
	}
	else if (ch == 2) { // if he dosen't want to delete his acc, will back to main menu
		main_menue_donor();
	}
	else { // if he enters incorrect choice
		cout << " ============================================================================\n";
		cout << " Incorrect choice, please press Enter and try again...\n";
		cout << " ============================================================================\n\n";;
		cin.get();
		cin.get();
		deleteAccount();
	}
}
void Donor::main_menue_donor() {	// Donor main menu function
	system("cls");
	cout << "                      ====================================================================== \n";
	cout << "                      ||                   Wlcome in main menue                           || \n";
	cout << "                      ====================================================================== \n\n\n";
	cout << "                                          -----------------------\n";
	cout << "                                          |Are You want to:     |\n";
	cout << "                                          -----------------------\n";
	cout << "                                          | 1- Donation Requast |\n";
	cout << "                                          | 2- Update your data |\n";
	cout << "                                          | 3- Delete Account   |\n";
	cout << "                                          | 4- Exit             |\n";
	cout << "                                          -----------------------\n";
	cout << " Enter your choice: ";
	int ch; cin >> ch;
	if (ch == 1)
		donationRequast();
	else if (ch == 2)
		updatAccount();
	else if (ch == 3)
		deleteAccount();
	else if (ch == 4)
		Exit();
	else {		// if he enters incorrect choice
		cout << " ============================================================================\n";
		cout << " Incorrect choice, please press Enter and try again...\n";
		cout << " ============================================================================\n\n";
		cin.get();
		cin.get();
		main_menue_donor();
	}
}
void Donor::Exit() {	// exit function
	fstream donor;	// opening donor file to put all data in it 
	donor.open("donor.txt", ios::app);
	for (int i = 0; i < donors_email.size(); i++) {
		if (i == donors_email.size() - 1) {		// if this line will be last line in file 
			donor << donors_name[i] << ' ' << donors_id[i] << ' ' << donors_gender[i] << ' ' << donors_age[i] << ' ' <<
				donors_email[i] << ' ' << donors_password[i] << ' ' << donors_blood_type[i] << ' ' << donors_suffers[i] << ' '
				<< can_donate[i] << ' ' << donors_suffers_other[i] << ' ' << donors_donation_date[i];
		}
		else {
			donor << donors_name[i] << ' ' << donors_id[i] << ' ' << donors_gender[i] << ' ' << donors_age[i] << ' ' <<
				donors_email[i] << ' ' << donors_password[i] << ' ' << donors_blood_type[i] << ' ' << donors_suffers[i] << ' '
				<< can_donate[i] << ' ' << donors_suffers_other[i] << ' ' << donors_donation_date[i] << endl;
		}
	}
	donor.close();	// close donor file
	exit(1);	// exit from program
}
Donor::~Donor() {
	
}
