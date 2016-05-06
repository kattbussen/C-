#include "libActions.h"

int Item::globalIdNumber = 0;
LibActions lib = LibActions("lib.txt");

void printHeader() {
	std::cout << "Choose one of X/C/F/N/J/H(Help)/S/B/R/Q/P" << std::endl;
}

void printHelp() {
	printHeader();
	std::cout << "C - insert new CD" << std::endl;
	std::cout << "F - insert new Fiction book" << std::endl;
	std::cout << "N - insert new Non-Fiction book" << std::endl;
	std::cout << "J - insert new Journal" << std::endl;
	std::cout << "X - remove an object from the library" << std::endl;
	std::cout << "H - show this text" << std::endl;
	std::cout << "S - Search for an item in the library" << std::endl;
	std::cout << "B - Borrow an item from the library" << std::endl;
	std::cout << "R - Return an item to the library" << std::endl;
	std::cout << "Q - Quit the program" << std::endl; 
	std::cout << "P - Print the content of the library" << std::endl;
}

void search() {
	std::string selection;
	std::cout << "Search by title (T) or author/artist (A)?" << std::endl;
	std::cin >> selection;

	if(selection == "T") {
		std::string title;
		
		std::cout << "Enter title search: ";
		std::cin.ignore();
		std::getline(std::cin, title);

		lib.searchByTitle(title);	
	}
	else if(selection == "A") {
		std::string searchString;
		
		std::cout << "Enter author/title search: ";
		std::cin.ignore();
		std::getline(std::cin, searchString);

		lib.searchByArtistOrAuthor(searchString);	
	}
	else {
		std::cout << "Unknown option, returning to main menu." << std::endl;
	}
}

void borrow() {
	int idNumber;
	int borrower;
	std::cout << "Enter number of item you want to borrow:" << std::endl;
	std::cin >> idNumber;
	std::cout << "Enter your borrower-number:" << std::endl;
	std::cin >> borrower;
	lib.borrowItem(idNumber, borrower);
}

void deleteItem() {
	int idNumber;
	std::cout << "Enter number of item to remove:" << std::endl;
	std::cin >> idNumber;
	lib.removeItem(idNumber);
}

void returnItem() {
	int idNumber;
	std::cout << "Enter number of item to return:" << std::endl;
	std::cin >> idNumber;
	lib.returnItem(idNumber);
}

void addCd() {
	std::string artist;
	std::string title;
	std::string playtime;
	
	std::cout << "Artist: ";
	std::cin.ignore();
	std::getline(std::cin, artist);
	std::cout << "Title: ";
	std::getline(std::cin, title);
	std::cout << "Playtime (HH:MM): ";
	std::cin >> playtime;

	lib.addCd(artist, title, playtime);
}

void addJournal() {
	std::string title;
	int issue;
	int year;

	std::cout << "Title: ";
	std::cin.ignore();
	std::getline(std::cin, title);
	std::cout << "Issue: ";
	std::cin >> issue;
	std::cout << "Year: ";
	std::cin >> year;

	lib.addJournal(title, issue, year);
}

void exitLib() {
	lib.updateLib("saved_lib.txt");
	std::cout << "Exiting." << std::endl;
}

void addNonFictionBook() {
	std::string title;
	std::string author;
	
	std::cout << "Title: ";
	std::cin.ignore();
	std::getline(std::cin, title);
	std::cout << "Author: ";
	std::getline(std::cin, author);
	
	lib.addNonFictionBook(title, author);
}

void addFictionBook() {
	std::string title;
	std::string author;
	
	std::cout << "Title: ";
	std::cin.ignore();
	std::getline(std::cin, title);
	std::cout << "Author: ";
	std::getline(std::cin, author);
	
	lib.addFictionBook(title, author);
}

void mainMenu() {
	std::string selection;
	
	while(selection != "Q") {
		printHeader();
		std::cin >> selection;
	
		if(selection == "C") { addCd(); }	
		else if(selection == "F") { addFictionBook(); }
		else if(selection == "N") { addNonFictionBook(); }
		else if(selection == "J") { addJournal(); }
		else if(selection == "X") { deleteItem(); }
		else if(selection == "H") { printHelp(); }
		else if(selection == "S") { search();	}
		else if(selection == "B") { borrow();	}
		else if(selection == "R") { returnItem(); }
		else if(selection == "Q") { exitLib(); }
		else if(selection == "P") { lib.printItems(); }
		else { std::cout << "Unknown option." << std::endl; }
	}
}

int main() {
	mainMenu();
}
