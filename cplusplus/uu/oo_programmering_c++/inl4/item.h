#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
	public:
		int borrowedBy;

		Item(std::string inTitle, int itemNumber, int borrowedNumber) {
			if (itemNumber > globalIdNumber)
				globalIdNumber = itemNumber;

			idNumber = globalIdNumber;
			title = inTitle;
			borrowedBy = borrowedNumber;
		}	

		virtual void printInfo() {
			std::cout << "This item has idNumber " << idNumber << " and is borrowed by " << borrowedBy << std::endl;
		}
	
		virtual std::string extractInfo() {
			std::string id = std::to_string(idNumber);
			std::string borrowed = std::to_string(borrowedBy);
			return id+"\n"+borrowed;
		}

		int getIdNumber() {
			return idNumber;
		}
	
		std::string getTitle() {
			return title;
		}

	  int getGlobalIdNumber() {
			return globalIdNumber;
		}

		bool checkout(int number) {
			if (borrowedBy == 0) {
				borrowedBy = number;
				return true;
			}
			return false;
		}

	private:
		static int globalIdNumber;
		int idNumber;
		std::string title;
};
#endif
