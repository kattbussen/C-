#include "book.h"

#ifndef NONFICTIONBOOK_H
#define FICTIONBOOK_H

class NonFictionBook : public Book {
	
	public:
		NonFictionBook(int itemIdNumber, std::string inTitle, std::string inAuthor);
		~NonFictionBook();
		void printInfo();

	private:
};	

#endif
