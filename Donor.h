
#include "User.h"
class Donor : public User
{	
	// local Data members
	bool suffers;
	string suffer_other;
	string donationDate;
public:
	Donor();
	void Register();
	void Login();
	void setSuffers(bool suf);
	void setSuffersOther(string oth);
	string getSuffersOther();
	void setdonationDate(string date);
	bool getSuffers();
	string getdonationDate();
	void updatAccount();
	void deleteAccount();
	void donationRequast();
	void main_menue_donor();
	void Exit();
	~Donor();
};

