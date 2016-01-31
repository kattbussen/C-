#include <iostream>
#include <vector>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

vector<Date> dates;

void readDate()
{
	Date newDate;
	cout << "Enter year for new date: " << endl;
	cin >> newDate.year;
	cout << "Enter month for new date: " << endl;
	cin >> newDate.month;
	cout << "Enter day for new date: " << endl;
	cin >> newDate.day;
	cout << "New date entered." << endl;

	dates.push_back(newDate);
}

void printDates()
{
	cout << "There are " << dates.size() << " dates stored." << endl;
	int count = 0;

	for(vector<Date>::iterator it = dates.begin(); it != dates.end(); it++)
	{
		cout << count << ". " << (*it).year << " " << (*it).month << " " << (*it).day << endl;
	}
}

int main()
{
	readDate();
	readDate();
	readDate();
	printDates();
}
