#include "Recipient.h"
#include<iostream>
#include<vector>
using namespace std;
int flag = 0, flag2 = 0, flag3 = 0;
int Login_index = 0;		// current user(recipient) index
vector<string> recipients_name;
vector<string> recipients_email;
vector<string> recipients_password;
vector<string> recipients_gender;
vector<string> recipients_hospital;
vector<int> recipients_age;
vector<int> recipients_id;
vector<string> recipients_doctor_names;
vector<char> recipients_blood_type;
vector<string> donors_name_in_donationRequast;
vector<int> donors_amount_in_donationRequast;
vector<string> donors_date_in_donationRequast;
vector<char> donors_type_in_donationRequast;

Recipient::Recipient()
{
	// getting data from recipient file and push it to vectors
	string name_, email_, password_, gender_, hospital_, doctor_;
	char bloo_type_;
	int id_, age_;
	ifstream Recipient;
	Recipient.open("recipient.txt"); // opening recipient file
	if (!Recipient.fail()) {
		// searching in file and get all recipients data 
		while (!Recipient.eof()) {
			Recipient >> name_ >> id_ >> gender_ >> age_ >> email_ >> password_ >> bloo_type_ >> doctor_ >> hospital_;
			recipients_name.push_back(name_);
			recipients_id.push_back(id_);
			recipients_gender.push_back(gender_);
			recipients_age.push_back(age_);
			recipients_email.push_back(email_);
			recipients_password.push_back(password_);
			recipients_blood_type.push_back(bloo_type_);
			recipients_doctor_names.push_back(doctor_);
			recipients_hospital.push_back(hospital_);
		}		// end search
	}
	Recipient.close(); // close recipient file
	remove("recipient.txt");
	// getting data of donation requests from its file
	string nam, dat, sufferOther;
	char typ;
	int amoun;
	bool suffer;
	ifstream donationRequast;
	donationRequast.open("donationRequast.txt");
	if (!donationRequast.fail()) {
		while (!donationRequast.eof()) {
			donationRequast >> nam  >> typ >> amoun >> dat;
			donors_name_in_donationRequast.push_back(nam);
			donors_type_in_donationRequast.push_back(typ);
			donors_amount_in_donationRequast.push_back(amoun);
			donors_date_in_donationRequast.push_back(dat);
		}
	}
	donationRequast.close();
	remove("donationRequast.txt");
	cout << endl << endl;
	// welcome recipient in his page
	system("cls");
	cout << "                      ======================================================================\n";
	cout << "                      ||                          Hello in Recipient page                 ||\n";
	cout << "                      ======================================================================\n\n";
	cout << "                                             ---------------\n";
	cout << "                                             | 1- Login    |\n";
	cout << "                                             | 2- Register |\n";
	cout << "                                             | 3- Exit     |\n";
	cout << "                                             ---------------\n\n";
	cout << " Enter your choice: ";
	int ch; cin >> ch;
	if (ch == 1)
		Login();
	else if (ch == 2)
		Register();
	else if (ch == 3)
		Exit();
	else {
		cout << " ============================================================================\n";
		cout << " Incorrect choice, please press Enter and try again...\n";
		cout << " ============================================================================\n\n";
		cin.get();
		cin.get();
		Exit();
	}
}
// setters and getters for private local members
void Recipient::setHospital(string hos)
{
	Hospital = hos;
}
void Recipient::setDoctor(string doc)
{
	CaseDoctor = doc;
}
string Recipient::getHospital()
{
	return Hospital ;
}
string Recipient::getDoctor()
{
	return CaseDoctor ;
}
void  Recipient::Register()
{
	system("cls");
	// get recipient data and push it to vectors
	cout << " Enter your Data .. \n\n";
	cout << "-----------------------------------------------------\n";
	cout << " Your Name : "; // Enter his name
	string name; cin >> name;
	setName(name);
	recipients_name.push_back(getName());
	cout << "-----------------------------------------------------\n";
	cout << " Your ID: "; //Enter his ID
	int id;  cin >> id;
	setID(id);
	recipients_id.push_back(getID());
	cout << "-----------------------------------------------------\n";
	cout << " Your Email : "; //Enter his mail
	string mail; cin >> mail;
	setEmail(mail);
	recipients_email.push_back(getEmail());
	cout << "-----------------------------------------------------\n";
	cout << " Your password : ";  // Enter his password
	string pass; cin >> pass;
	setpassword(pass);
	recipients_password.push_back(getpassword());
	cout << "-----------------------------------------------------\n";
	cout << " Your Age : "; //Enter his Age
	int age; cin >> age;
	setAge(age);
	recipients_age.push_back(getAge());
	cout << "-----------------------------------------------------\n";
	cout << " Your Gender : ";  // Enter his Gender
	string gen; cin >> gen;
	setGender(gen);
	recipients_gender.push_back(getGender());
	cout << "-----------------------------------------------------\n";
	cout << " Your Blood Type : "; // Enter his blood Type
	char bType; cin >> bType;
	setbloodType(bType);
	recipients_blood_type.push_back(getbloodType());
	cout << "-----------------------------------------------------\n";
	cout << " Your Hospital : "; // Enter hospital name
	string hos; cin >> hos;
	setHospital(hos);
	recipients_hospital.push_back(getHospital());
	cout << "-----------------------------------------------------\n";
	cout << " Your Doctor Name : "; // Enter his doctor name
	string doctor; cin >> doctor;
	setDoctor(doctor);
	recipients_doctor_names.push_back(getDoctor());
	// finish registration and back to his menu to login or exit from system
	cout << " ============================================================================\n";
	cout << " Congratulations, Your process is Done ... press Enter to return main...\n";
	cout << " ============================================================================\n\n";
	cin.get();
	cin.get();
	Recipient::Recipient();
}
void Recipient::Login()
{
	system("cls");
	// Enter his E-mail and password
	cout << "-----------------------------------------------------\n";
	cout << " Your E-Mail: ";
	string mail; cin >> mail;
	cout << "-----------------------------------------------------\n";
	cout << " You Password: ";
	string pass; cin >> pass;
	// check in vectors if these data exist or not
	for (int i = 0; i < recipients_password.size(); i++) {
		if (mail == recipients_email[i] && pass == recipients_password[i]) {
			flag = 1;
			Login_index = i; // get current user index to use in other functions
			break;
		}
	}
	if (flag == 1) { // if it exist
		cout << " ============================================================================\n";
		cout << " Successful Login, Please press Enter to go in main menue...." << endl;
		cout << " ============================================================================\n";
		cin.get();
		cin.get();
		flag = 0;
		main_menue_recipient(); // calling main menu function of donor 
	}
	else { //if it dosn't exist ask him to try again
		cout << " ============================================================================\n";
		cout << " Incorrect E-Mail or Password, please try again...Press Enter to Login again.." << endl;
		cout << " ============================================================================\n";
		cin.get();
		cin.get();
		Login();
	}
}
void Recipient::main_menue_recipient() {		// Recipient main menu function
	system("cls");
	cout << "                      ====================================================================== \n";
	cout << "                      ||                   Wlcome in main menue                           || \n";
	cout << "                      ====================================================================== \n\n\n";
	cout << "                                  -------------------------------------------------\n";
	cout << "                                  |Are You want to:                               |\n";
	cout << "                                  -------------------------------------------------\n";
	cout << "                                  | 1- Search for the availlability of blood type |\n";
	cout << "                                  | 2- Display all blood data                     |\n";
	cout << "                                  | 3- Update your data                           |\n";
	cout << "                                  | 4- Delete Account                             |\n";
	cout << "                                  | 5- Requast blood type and quantity you want   |\n";
	cout << "                                  | 6- Exit                                       |\n";
	cout << "                                  -------------------------------------------------\n";
	cout << " Enter your choice: "; 
	int ch; cin >> ch;
	if (ch == 1) {
		search_for_blood();
	}
	else if (ch == 2)
		display_all_blood();
	else if (ch == 3)
		updatAccount();
	else if (ch == 4)
		deleteAccount();
	else if (ch == 5)
		requast_blood();
	else if (ch == 6)
		Exit();
	else {	// if he enters incorrect choice 
		cout << " ============================================================================\n";
		cout << " Incorrect choice, please press Enter and try again...\n";
		cout << " ============================================================================\n\n";
		cin.get();
		cin.get();
		main_menue_recipient();
	}
}
void Recipient::updatAccount() {
	// All recipient data is deleted from the list and all donor data is registered again
	recipients_name.erase(recipients_name.begin() + Login_index);
	recipients_id.erase(recipients_id.begin() + Login_index);
	recipients_gender.erase(recipients_gender.begin() + Login_index);
	recipients_age.erase(recipients_age.begin() + Login_index);
	recipients_email.erase(recipients_email.begin() + Login_index);
	recipients_password.erase(recipients_password.begin() + Login_index);
	recipients_blood_type.erase(recipients_blood_type.begin() + Login_index);
	recipients_doctor_names.erase(recipients_doctor_names.begin() + Login_index);
	recipients_hospital.erase(recipients_hospital.begin() + Login_index);
	Register();  // register again
}
void Recipient::deleteAccount() {
	system("cls");
	cout << "                                      -------------------------------------------\n";
	cout << "                                      |Are You sure from deleting your account: |\n";
	cout << "                                      -------------------------------------------\n";
	cout << "                                      | 1- Yes                                  |\n";
	cout << "                                      | 2- No                                   |\n";
	cout << "                                      -------------------------------------------\n";
	cout << " Enter your choice: ";
	int ch; cin >> ch;
	if (ch == 1) { // delete all his data from vectors
		recipients_name.erase(recipients_name.begin() + Login_index);
		recipients_id.erase(recipients_id.begin() + Login_index);
		recipients_gender.erase(recipients_gender.begin() + Login_index);
		recipients_age.erase(recipients_age.begin() + Login_index);
		recipients_email.erase(recipients_email.begin() + Login_index);
		recipients_password.erase(recipients_password.begin() + Login_index);
		recipients_blood_type.erase(recipients_blood_type.begin() + Login_index);
		recipients_doctor_names.erase(recipients_doctor_names.begin() + Login_index);
		recipients_hospital.erase(recipients_hospital.begin() + Login_index);
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
		else if (ch == 2) // if he dosen't want to delete his acc, will back to his main menu
			main_menue_recipient();
		else {  // if he enters incorrect choice
			cout << " ============================================================================\n";
			cout << " Incorrect choice, please press Enter and try again...\n";
			cout << " ============================================================================\n\n";;
			cin.get();
			cin.get();
			deleteAccount();
		}
	}
}
void Recipient::display_all_blood() {
	// display all informations about Bloods 
	system("cls");
	cout << " ============================================================================\n";
	cout << "                       The available blood type                              \n";
	cout << " ============================================================================\n\n";
	for (int i = 0; i < donors_name_in_donationRequast.size(); i++) {
		cout << " ------------------------------------------------------------------\n";
		cout << " Donor name: " << donors_name_in_donationRequast[i] << endl;
		cout << " ------------------------------------------------------------------\n";
		cout << " The blood type: " << donors_type_in_donationRequast[i] << endl;
		cout << " ------------------------------------------------------------------\n";
		cout << " The amount: " << donors_amount_in_donationRequast[i] << endl;
		cout << " ------------------------------------------------------------------\n";
		cout << " Received date: " << donors_date_in_donationRequast[i] << endl;
		cout << " ------------------------------------------------------------------\n";
		cout << " Expiry date: " << 42 << " Days from the received date" << endl;;
		cout << "=======================================================================\n\n";
	}
	cout << "                                  -------------------------------------------------\n";
	cout << "                                  | 1- Requast blood type and quantity you want   |\n";
	cout << "                                  | 2- Back to menue                              |\n";
	cout << "                                  | 3- Exit                                       |\n";
	cout << "                                  -------------------------------------------------\n";
	cout << " Enter your choice: ";
	int ch; cin >> ch;
	if (ch == 1)
		requast_blood();
	else if (ch == 2)
		main_menue_recipient();
	else if (ch == 3)
		Exit();
	else {   // if user enter incorrect choice..
		cout << " ============================================================================\n";
		cout << " Incorrect choice, please press Enter and try again...\n";
		cout << " ============================================================================\n\n";;
		cin.get();
		cin.get();
		display_all_blood();
	}
}
void Recipient::requast_blood() {
	system("cls");
	cout << "---------------------------------------------\n";
	cout << " Enter blood type you want: ";
	char type; cin >> type;
	cout << "---------------------------------------------\n";
	cout << " Enter the quantity you want in Liters: ";
	int quantity; cin >> quantity;
	cout << "---------------------------------------------\n";
	for (int i = 0; i < donors_name_in_donationRequast.size(); i++) { // searching in donation request vector
		if (type == donors_type_in_donationRequast[i]) {  // search about blood type
			if (donors_amount_in_donationRequast[i] >= quantity) { // check if there is enough amount of this blood type or not
				flag2 = 1;
				break;
			}
		}
	}
	if (flag2 == 1) {	// if required amount of blood is found
		system("cls");
		cout << " ============================================================================\n";
		cout << " Your request was successful, Please wait for the hospital's approval....\n";
		cout << " ============================================================================\n\n";
		flag2 = 0;
		cout << "                                  -------------------------------------------------\n";
		cout << "                                  | 1- Back to menue                              |\n";
		cout << "                                  | 2- Exit                                       |\n";
		cout << "                                  -------------------------------------------------\n";
		cout << " Enter your choice: ";
		int ch; cin >> ch;
		if (ch == 1)
			main_menue_recipient();
		else if (ch == 2)
			Exit();
		else {		// if he enters incorrect choice
			cout << " ============================================================================\n";
			cout << " Incorrect choice, please press Enter and try again...\n";
			cout << " ============================================================================\n\n";
			cin.get();
			cin.get();
			requast_blood();
		}
	}
	else {		// if required amount of blood isn't enough
		system("cls");
		cout << " ===============================================================================================\n";
		cout << " You have entered an excess amount than the existing one or a type of blood that is not present.\n";
		cout << " ==============================================================================================\n\n";;
		cout << "                                  -------------------------------------------------\n";
		cout << "                                  | 1- Display all blood data                     |\n";
		cout << "                                  | 2- Back to menue                              |\n";
		cout << "                                  | 3- Exit                                       |\n";
		cout << "                                  -------------------------------------------------\n";
		cout << " Enter your choice: ";
		int ch; cin >> ch;
		if (ch == 1)
			display_all_blood();
		else if (ch == 2)
			main_menue_recipient();
		else
			Exit();
	}
}
void Recipient::search_for_blood() {
	// searching for blood with his type 
	system("cls");
	cout << "---------------------------------------------\n";
	cout << " Enter blood type you want: ";
	char type; cin >> type;
	cout << "---------------------------------------------\n";
	// if his blood type exist 
	cout << " ===============================================================================================\n";
	cout << " The available blood type you search :\n";
	cout << " ==============================================================================================\n\n";
	for (int i = 0; i < donors_name_in_donationRequast.size(); i++) {
		if (donors_type_in_donationRequast[i] == type) {
			cout << "---------------------------------------------------\n";
			cout << "Donor name: " << donors_name_in_donationRequast[i] << endl;
			cout << "----------------------------------------------------\n";
			cout << "The blood type: " << donors_type_in_donationRequast[i] << endl;
			cout << "----------------------------------------------------\n";
			cout << "The amount: " << donors_amount_in_donationRequast[i] << endl;
			cout << "----------------------------------------------------\n";
			cout << " Received date: " << donors_date_in_donationRequast[i] << endl;
			cout << "=======================================================================\n\n";
			flag3 = 1; // to check if blood type exist or not
		}
	}
	if (flag3 != 1) { // if blood type not exist
		cout << "Unfortunately, there is no available blood type like the one you want, press enter to conyinue...\n\n";
		cin.get();
		cin.get();
	}
	cout << "                                  -------------------------------------------------\n";
	cout << "                                  | 1- Requast blood type and quantity you want   |\n";
	cout << "                                  | 2- Back to menue                              |\n";
	cout << "                                  | 3- Exit                                       |\n";
	cout << "                                  -------------------------------------------------\n";
	cout << " Enter your choice: ";
	int ch; cin >> ch;
	if (ch == 1)
		requast_blood();
	else if (ch == 2)
		main_menue_recipient();
	else if (ch == 3)
		Exit();
}
void Recipient::Exit() {	// exit function..
	fstream Recipient;
	Recipient.open("recipient.txt", ios::app);  // opening recipient file to put all data in it 
	for (int i = 0; i < recipients_email.size(); i++) {
		if (i == recipients_email.size() - 1) { // if this line will be last line in file
			Recipient << recipients_name[i] << ' ' << recipients_id[i] << ' ' << recipients_gender[i] << ' ' << recipients_age[i] << ' ' <<
				recipients_email[i] << ' ' << recipients_password[i] << ' ' << recipients_blood_type[i] << ' ' << recipients_hospital[i]
				<< ' ' << recipients_doctor_names[i];
		}
		else {
			Recipient << recipients_name[i] << ' ' << recipients_id[i] << ' ' << recipients_gender[i] << ' ' << recipients_age[i] << ' ' <<
				recipients_email[i] << ' ' << recipients_password[i] << ' ' << recipients_blood_type[i] << ' ' << recipients_hospital[i]
				<< ' ' << recipients_doctor_names[i] << endl;
		}
	}
	Recipient.close(); // close recipient file
	fstream donationRequast;
	donationRequast.open("donationRequast.txt", ios::app); // opening doantion requests file and put data of requests in it
	for (int i = 0; i < donors_name_in_donationRequast.size(); i++) {
		if (i == donors_name_in_donationRequast.size() - 1) {
			donationRequast << donors_name_in_donationRequast[i] << ' ' << donors_type_in_donationRequast[i] << ' '
				<< donors_amount_in_donationRequast[i] << ' ' << donors_date_in_donationRequast[i];
		}
		else {
			donationRequast << donors_name_in_donationRequast[i] << ' ' << donors_type_in_donationRequast[i] << ' '
				<< donors_amount_in_donationRequast[i] << ' ' << donors_date_in_donationRequast[i] << endl;
		}
	}
	donationRequast.close(); // close donation request file
	exit(1); // exit from program
}
Recipient::~Recipient()
{
}
