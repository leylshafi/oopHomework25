#pragma once
struct DateTime
{
	short day = 0;
	string month = "";
	short year = 0;
	DateTime() = default;
	DateTime(string month, short day, short year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
};

class Debtor
{
	string fullname = "";
	DateTime birthDay;
	string phone = "";
	string email = "";
	string address = "";
	int debt = 0;
public:
	Debtor() = default;
	Debtor(string fullname, DateTime birthDay, string phone, string email, string address, int debt)
	{
		this->fullname = fullname;
		this->birthDay = birthDay;
		this->phone = phone;
		this->email = email;
		this->address = address;
		this->debt = debt;
	};

	string getFullName()const { return fullname; }
	DateTime getBirthday()const { return birthDay; }
	string getPhone()const { return phone; }
	string getEmail()const { return email; }
	string getAddress()const { return address; }
	int getDebt()const { return debt; }

	friend ostream& operator<<(ostream& out, const Debtor& d);
};
ostream& operator<<(ostream& out, const Debtor& d)
{
	cout << "Full name: " << d.fullname << endl
		<< "Birthday: " << d.birthDay.day << "." << d.birthDay.month << "." << d.birthDay.year << endl
		<< "Phone: " << d.phone << endl
		<< "Email: " << d.email << endl
		<< "Address: " << d.address << endl
		<< "Debt: " << d.debt << endl;
	return out;
}