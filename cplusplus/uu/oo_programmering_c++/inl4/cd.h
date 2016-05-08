#ifndef CD_H
#define CD_H

#include "item.h"
#include <string>

class Cd : public Item {

	public:
		Cd(std::string inTitle, int itemNumber, int borrowedNumber, std::string inArtist, std::string inPlaytime);
		std::string getArtist();
		std::string getPlaytime();
		void printInfo();
		std::string extractInfo();

	private:
		std::string artist;
		std::string playtime;			
};

#endif
