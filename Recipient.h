#pragma once
#include "User.h"
class Recipient : public User
{
	// local Data members
	string Hospital;
	string CaseDoctor;
public:
	Recipient();
	void Register();
	void Login();
	void setHospital(string hos);
	void setDoctor(string doc);
	string getHospital();
	string getDoctor();
	void updatAccount();
	void deleteAccount();
	void display_all_blood();;
	void requast_blood();
	void search_for_blood();
	void Exit();
	void main_menue_recipient();
	~Recipient();
};


	

