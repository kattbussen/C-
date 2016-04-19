#include "fictionBook.h"

FictionBook::FictionBook(std::string inTitle, std::string inAuthor) : Book(inTitle, inAuthor, "Fiction") {
}

FictionBook::~FictionBook() {
}

void FictionBook::printInfo() {
	std::cout << "Type:       " << getType() << std::endl;
	std::cout << "Author:     " << getAuthor() << std::endl;
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}	
