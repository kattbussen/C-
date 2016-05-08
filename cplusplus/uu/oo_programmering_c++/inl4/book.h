#ifndef BOOK_H
#define BOOK_H

#include "item.h"

class Book : public Item {

	public:
		Book(std::string inTitle, int itemNumber, int borrowedNumber, std::string inAuthor, std::string inType) : Item(inTitle, itemNumber, borrowedNumber) {
			author = inAuthor;
			type = inType;
		}

		std::string getAuthor() {
			return author;
		}

		std::string getType() {
			return type;
		}

	private:
		std::string author;
		std::string type;
};

#endif
