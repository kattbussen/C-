#include "journal.h"

Journal::Journal(std::string inTitle, int itemNumber, int borrowedNumber, int inIssue, int inYear) : Item(inTitle, itemNumber, borrowedNumber) {
	issue = inIssue;
	year = inYear;
}
		
Journal::~Journal() {

}

int Journal::getIssue() {
	return issue;
}

int Journal::getYear() {
	return year;
}

std::string Journal::extractInfo() {
	std::string type = "Journal";
	std::string sIssue = std::to_string(issue);
	std::string sYear = std::to_string(year);
	std::string id = std::to_string(getIdNumber());
	std::string borrowed = std::to_string(borrowedBy);

	return type+"\n"+getTitle()+"\n"+sIssue+"/"+sYear+"\n"+id+"\n"+borrowed; 
}

void Journal::printInfo() {
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "Issue/year: " << issue << "/" << year << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}
