#include "libActions.h"
#include "cd.h"
#include "journal.h"
#include "fictionBook.h"
#include "nonfictionBook.h"
#include "libActions.h"

LibActions::LibActions(std::string file) {
	contentChanged = false;	
	vec.clear();
	readFile(file);
}

LibActions::~LibActions() {
	std::vector<Item*>::iterator i;
	for(i = vec.begin(); i != vec.end(); ++i) {
		delete *i;
	}
}

void LibActions::readFile(std::string file) {
	std::ifstream ifs(file);	

	std::string type;
	std::getline(ifs, type);

	while(!(ifs.eof())) {

		std::string itemNumber;
		std::string borrowedBy;

		if( type == "Fiction" || type == "NonFiction") {
			std::string author;
			std::string title;

			std::getline(ifs, author);
			std::getline(ifs, title);
			std::getline(ifs, itemNumber);
			std::getline(ifs, borrowedBy);

			if(type == "Fiction") {
				vec.push_back(new FictionBook(title, std::stoi(itemNumber), std::stoi(borrowedBy), author));
			}
			else {
				vec.push_back(new NonFictionBook(title, std::stoi(itemNumber), std::stoi(borrowedBy), author));
			}
		}
		else if( type == "CD") {
			std::string artist;
			std::string title;
			std::string time;
	
			std::getline(ifs, artist);
			std::getline(ifs, title);
			std::getline(ifs, time);
			std::getline(ifs, itemNumber);
			std::getline(ifs, borrowedBy);
				
			vec.push_back(new Cd(title, std::stoi(itemNumber), std::stoi(borrowedBy), artist, time));
		}
		else if( type == "Journal") {
			std::string title;
			std::string issueYear;

			std::getline(ifs, title);
			std::getline(ifs, issueYear);
			std::getline(ifs, itemNumber);
			std::getline(ifs, borrowedBy);
	
			size_t pos = 0;
			pos = issueYear.find("/");

			int issue = std::stoi(issueYear.substr(0,pos));
			issueYear.erase(0, pos+1);
			int year = std::stoi(issueYear);
	
			vec.push_back(new Journal(title, std::stoi(itemNumber), std::stoi(borrowedBy), issue, year));
		}
		else {
			std::cout << "Read unknown type of item. Aborting." << std::endl;
			exit(0);
		}
		
		std::getline(ifs, type);
	}	
}

void LibActions::removeItem(int itemNumber) {
	std::vector<Item*>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it) {
		if((*it)->getIdNumber() == itemNumber){
			vec.erase(it);
			contentChanged = true;
			std::cout << "Successfully removed item with number: " << itemNumber << std::endl;
			return;
		}
	}
	std::cout << "Unable to find element with number: " << itemNumber << std::endl;
}

void LibActions::borrowItem(int itemNumber, int borrower) {
	std::vector<Item*>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it) {
		if((*it)->getIdNumber() == itemNumber){
			bool success = (*it)->checkout(borrower);
			if(success) {
				contentChanged = true;
				std::cout << "Item " << itemNumber << " borrowed by " << borrower << std::endl;
			}
			else {
				std::cout << "Item " << itemNumber << " is already borrowed, by " << (*it)->borrowedBy << std::endl;
			}
			return;
		}
	}
	std::cout << "Unable to find element with number: " << itemNumber << std::endl;
} 

void LibActions::returnItem(int itemNumber) {
	std::vector<Item*>::iterator it;
	for(it = vec.begin(); it != vec.end(); ++it) {
		if( (*it)->getIdNumber() == itemNumber) {
			(*it)->borrowedBy = 0;
			contentChanged = true;
			std::cout << "Returned item " << itemNumber << std::endl;
			return;
		}
	}
	std::cout << "Unable to find element with number: " << itemNumber << std::endl;
}

void LibActions::addCd(std::string artist, std::string title, std::string playtime) {
	int idNumber = vec.front()->getGlobalIdNumber();
	idNumber++;
	vec.push_back(new Cd(title, idNumber, 0, artist, playtime));
	contentChanged = true;
	std::cout << "Added new CD" << std::endl;
}

void LibActions::printItems() {
	std::vector<Item*>::iterator i;
	for(i = vec.begin(); i != vec.end(); ++i) {
		(*i)->printInfo();
	}
}

void LibActions::addJournal(std::string title, int issue, int year) {
	int idNumber = vec.front()->getGlobalIdNumber();
	idNumber++;
	vec.push_back(new Journal(title, idNumber, 0, issue, year));
	contentChanged = true;
	std::cout << "Added new Journal" << std::endl;
}

void LibActions::updateLib(std::string fileName) {
	if(contentChanged) {
		std::ofstream file;
		file.open(fileName);
		
		std::vector<Item*>::iterator it;
		for(it = vec.begin(); it != vec.end(); ++it) {
			file << (*it)->extractInfo() << std::endl;
		}
		std::cout << "Wrote to " << fileName << std::endl;
	}
	else {
		std::cout << "No changes made." << std::endl;
	}
}
