#include <string>
#include <fstream>
#include <vector>
#include "item.h"

#ifndef LIBACTIONS_H
#define LIBACTIONS_H

class LibActions{

	public:	
		LibActions(std::string file);
		~LibActions();


		void borrowItem(int itemNumber, int borrower);
		void returnItem(int itemNumber);
		//bool search(std::string searchString);
		void addCd(std::string artist, std::string title, std::string playtime);
		void addJournal(std::string title, int issue, int year);
		void removeItem(int itemNumber);
		void printItems();
		void updateLib(std::string fileName);

	private:
		bool contentChanged;
		std::vector<Item*> vec;
		void readFile(std::string file);
};

#endif
