#include "fictionBook.h"

FictionBook::FictionBook(std::string inTitle, int itemNumber, int borrowedNumber, std::string inAuthor) : Book(inTitle, itemNumber, borrowedNumber, inAuthor, "Fiction") {
}

FictionBook::~FictionBook() {
}

std::string FictionBook::extractInfo() {
	std::string type = "Fiction";
	std::string id = std::to_string(getIdNumber());
	std::string borrowed = std::to_string(borrowedBy);

	return type+"\n"+getAuthor()+"\n"+getTitle()+"\n"+id+"\n"+borrowed;
}

void FictionBook::printInfo() {
	std::cout << "Type:       " << getType() << std::endl;
	std::cout << "Author:     " << getAuthor() << std::endl;
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}	
