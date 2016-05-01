#ifndef CD_H
#define CD_H

#include "item.h"
#include <string>

class Cd : public Item {

	public:
		Cd(std::string inTitle, int itemNumber, std::string inArtist, double inPlaytime);
		~Cd();
		std::string getArtist();
		double getPlaytime();
		void printInfo();
		void printBla();

	private:
		std::string artist;
		std::string title;
		double playtime;			
};

#endif
