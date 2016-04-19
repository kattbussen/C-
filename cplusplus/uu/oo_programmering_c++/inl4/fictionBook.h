#include "book.h"

#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

class FictionBook : public Book {
	
	public:
		FictionBook(std::string inTitle, std::string inAuthor);
		~FictionBook();
		void printInfo();

	private:
};	

#endif
