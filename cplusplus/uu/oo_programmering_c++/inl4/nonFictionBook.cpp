#include "nonFictionBook.h"

NonFictionBook::NonFictionBook(std::string inTitle, std::string inAuthor) : Book(inTitle, inAuthor, "NonFiction") {
}

NonFictionBook::~NonFictionBook() {
}

void NonFictionBook::printInfo() {
	std::cout << "Type:       " << getType() << std::endl;
	std::cout << "Author:     " << getAuthor() << std::endl;
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}	
