#include "User.h"


User::User()
{
}
// setters and getters for private data members
void User :: setName(string s)
{
	UserName = s;
}
void User::setID(int n)
{
	ID = n;
}
void User::setEmail(string E)
{
	Email = E;
}
void User::setpassword(string s)
{
	password = s;
}
void User::setAge(int g)
{
	Age = g;
}
void User::setGender(string gen)
{
	gender = gen;
}
void User::setbloodType(char b)
{
	bloodType= b;
}
string User::getName()
{
	return UserName;
}
string User::getEmail()
{
	return Email;
}
string User::getpassword()
{
	return password;
}
string User::getGender()
{
	return gender;
}
int User::getAge()
{
	return Age;
}
int User::getID()
{
	return ID;
}
char User::getbloodType()
{
	return bloodType;
}

User::~User()
{
}
