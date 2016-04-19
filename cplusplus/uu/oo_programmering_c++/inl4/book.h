#include "item.h"

#ifndef BOOK_H
#define BOOK_H

class Book : public Item {

	public:
		Book(int itemIdNumber, std::string inTitle, std::string inAuthor, std::string inType) : Item(itemIdNumber, inTitle){
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
