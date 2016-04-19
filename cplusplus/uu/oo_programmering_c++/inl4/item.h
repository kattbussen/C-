#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
	public:
		int borrowedBy;

		Item(int itemIdNumber, std::string inTitle) {
			idNumber = itemIdNumber;
			title = inTitle;
			borrowedBy = 0;
		}	

		virtual void printInfo(){
			std::cout << "This item has idNumber " << idNumber << " and is borrowed by " << borrowedBy << std::endl;
		}

		int getIdNumber(){
			return idNumber;
		}
	
		std::string getTitle(){
			return title;
		}

	private:
		int idNumber;
		std::string title;

};
#endif
