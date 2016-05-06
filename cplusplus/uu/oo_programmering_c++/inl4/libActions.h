#ifndef LIBACTIONS_H
#define LIBACTIONS_H

#include <string>
#include <fstream>
#include <vector>
#include "item.h"
#include "cd.h"
#include "journal.h"
#include "fictionBook.h"
#include "nonfictionBook.h"
#include "libActions.h"

class LibActions {

	public:	
		LibActions(std::string file);
		~LibActions();


		void borrowItem(int itemNumber, int borrower);
		void returnItem(int itemNumber);
		void searchByTitle(std::string title);
		void searchByArtistOrAuthor(std::string searchString);
		void addCd(std::string artist, std::string title, std::string playtime);
		void addJournal(std::string title, int issue, int year);
		void addNonFictionBook(std::string title, std::string author);
		void addFictionBook(std::string title, std::string author);
		void removeItem(int itemNumber);
		void printItems();
		void updateLib(std::string fileName);

	private:
		bool contentChanged;
		std::vector<Item*> vec;
		void readFile(std::string file);
};
#endif
