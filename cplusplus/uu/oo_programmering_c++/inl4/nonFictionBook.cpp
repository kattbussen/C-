#include "nonFictionBook.h"

NonFictionBook::NonFictionBook(std::string inTitle, int itemNumber, int borrowedNumber, std::string inAuthor) : Book(inTitle, itemNumber, borrowedNumber, inAuthor, "NonFiction") {
}

NonFictionBook::~NonFictionBook() {
}

std::string NonFictionBook::extractInfo() {
	std::string type = "NonFiction";
	std::string id = std::to_string(getIdNumber());
	std::string borrowed = std::to_string(borrowedBy);

	return type+"\n"+getAuthor()+"\n"+getTitle()+"\n"+id+"\n"+borrowed;
}

void NonFictionBook::printInfo() {
	std::cout << "Type:       " << getType() << std::endl;
	std::cout << "Author:     " << getAuthor() << std::endl;
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}	
