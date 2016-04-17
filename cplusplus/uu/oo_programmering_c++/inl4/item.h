#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
	public:
		int borrowedBy;

		Item(int itemIdNumber) {
			idNumber = itemIdNumber;
			borrowedBy = 0;
		}	

		virtual void printInfo(){
			std::cout << "This item has idNumber " << idNumber << " and is borrowed by " << borrowedBy << std::endl;
		}

		int getIdNumber(){
			return idNumber;
		}
		
	private:
		int idNumber;

};
#endif
