#include "magazine.h"

Magazine::Magazine(int itemIdNumber, std::string inTitle, int inIssue, int inYear) : Item(itemIdNumber, inTitle){
	issue = inIssue;
	year = inYear;
}
		
Magazine::~Magazine(){

}

int Magazine::getIssue(){
	return issue;
}

int Magazine::getYear(){
	return year;
}

void Magazine::printInfo(){
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "Issue/year: " << issue << "/" << year << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}
