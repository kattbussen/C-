#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
	public:
		int borrowedBy;

		Item(std::string inTitle) {
			static int globalIdNumber = 0;
			globalIdNumber++;
			idNumber = globalIdNumber;
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
		static int globalIdNumber;
		int idNumber;
		std::string title;
};
#endif
