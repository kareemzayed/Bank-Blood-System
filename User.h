#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class User
{
		int ID;
		string UserName;
		string Email;
		string password;
		string gender;
		int Age;
		char bloodType;
	

public:
	User();
	void setName(string s);
	void setID(int n);
	void setEmail(string E);
	void setpassword(string p);
	void setGender(string gen);
	void setAge(int g);
	void setbloodType(char b);
	string getName();
	int getID();
	string getEmail();
	string getpassword();
	string getGender();
	int getAge();
	char getbloodType();
    void Register();
	~User();
};


