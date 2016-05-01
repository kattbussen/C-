#include "book.h"

#ifndef NONFICTIONBOOK_H
#define FICTIONBOOK_H

class NonFictionBook : public Book {
	
	public:
		NonFictionBook(std::string inTitle, int itemNumber, std::string inAuthor);
		~NonFictionBook();
		void printInfo();

	private:
};	

#endif
