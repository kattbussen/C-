#include "book.h"

#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

class FictionBook : public Book {
	
	public:
		FictionBook(int itemIdNumber, std::string inTitle, std::string inAuthor);
		~FictionBook();
		void printInfo();

	private:
		std::string type;
};	

#endif
