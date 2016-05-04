#ifndef CD_H
#define CD_H

#include "item.h"
#include <string>

class Cd : public Item {

	public:
		Cd(std::string inTitle, int itemNumber, int borrowedNumber, std::string inArtist, std::string inPlaytime);
		~Cd();
		std::string getArtist();
		std::string getPlaytime();
		void printInfo();

	private:
		std::string artist;
		std::string title;
		std::string playtime;			
};

#endif
