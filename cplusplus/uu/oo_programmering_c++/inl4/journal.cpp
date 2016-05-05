#include "journal.h"

Journal::Journal(std::string inTitle, int itemNumber, int borrowedNumber, int inIssue, int inYear) : Item(inTitle, itemNumber, borrowedNumber){
	issue = inIssue;
	year = inYear;
}
		
Journal::~Journal(){

}

int Journal::getIssue(){
	return issue;
}

int Journal::getYear(){
	return year;
}

void Journal::printInfo(){
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "Issue/year: " << issue << "/" << year << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}
