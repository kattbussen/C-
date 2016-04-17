#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "item.h"
#include <string>

class Magazine : public Item {

	public:
		Magazine(std::string inTitle, int inIssue, int inYear, int itemIdNumber);
		~Magazine();
		std::string getTitle();
		double getPlaytime();
		void printInfo();

	private:
		std::string title;
		int issue;
		int year;
};

#endif
