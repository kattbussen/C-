#ifndef NONFICTIONBOOK_H
#define NONFICTIONBOOK_H

#include "book.h"

class NonFictionBook : public Book {
	
	public:
		NonFictionBook(std::string inTitle, int itemNumber, int borrowedNumber, std::string inAuthor);
		void printInfo();
		std::string extractInfo();

	private:
};	
#endif
