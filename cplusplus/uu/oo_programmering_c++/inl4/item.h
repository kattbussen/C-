#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
	public:
		int borrowedBy;

		Item(std::string inTitle, int itemNumber) {
			static int globalIdNumber = 0;
			if (itemNumber > globalIdNumber)
				globalIdNumber = itemNumber;

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

	  int getGlobalIdNumber(){
	  //void getGlobalIdNumber(){
			return globalIdNumber;
			//std::cout << globalIdNumber << std::endl;
			//std::cout << "hej" << std::endl;
		}

	private:
		static int globalIdNumber;
		int idNumber;
		std::string title;
};
#endif
