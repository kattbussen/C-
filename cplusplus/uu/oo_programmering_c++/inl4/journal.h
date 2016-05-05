#ifndef JOURNAL_H
#define JOURNAL_H

#include "item.h"
#include <string>

class Journal : public Item {

	public:
		Journal(std::string inTitle, int itemNumber, int borrowedNumber, int inIssue, int inYear);
		~Journal();
		int getIssue();
		int getYear();
		void printInfo();
		std::string extractInfo();

	private:
		std::string title;
		int issue;
		int year;
};

#endif
