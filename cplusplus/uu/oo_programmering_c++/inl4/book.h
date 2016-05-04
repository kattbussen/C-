#include "item.h"

#ifndef BOOK_H
#define BOOK_H

class Book : public Item {

	public:
		Book(std::string inTitle, int itemNumber, int borrowedNumber, std::string inAuthor, std::string inType) : Item(inTitle, itemNumber, borrowedNumber){
			author = inAuthor;
			type = inType;
		}

		~Book(){
		}

		std::string getAuthor(){
			return author;
		}

		std::string getType(){
			return type;
		}

	private:
		std::string author;
		std::string type;
};

#endif
