#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "item.h"
#include <string>

class Magazine : public Item {

	public:
		Magazine(int itemIdNumber, std::string inTitle, int inIssue, int inYear);
		~Magazine();
		int getIssue();
		int getYear();
		void printInfo();

	private:
		std::string title;
		int issue;
		int year;
};

#endif
