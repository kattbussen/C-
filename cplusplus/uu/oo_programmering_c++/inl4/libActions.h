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


		//bool borrowItem(int itemIdNum);
		//bool returnItem(int itemIdNum);
		//bool search(std::string searchString);
		//void addItem(Item it);
		//void removeItem(Item it);
		void printItems();


	private:
		bool registerChanged;
		std::vector<Item*> vec;
		void readFile(std::string file);
};

#endif
