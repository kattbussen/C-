#include "book.h"

#ifndef NONFICTIONBOOK_H
#define FICTIONBOOK_H

class NonFictionBook : public Book {
	
	public:
		NonFictionBook(std::string inTitle, int itemNumber, int borrowedNumber, std::string inAuthor);
		~NonFictionBook();
		void printInfo();
		std::string extractInfo();

	private:
};	

#endif
