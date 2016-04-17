#ifndef CD_H
#define CD_H

#include "item.h"
#include <string>

class Cd : public Item {

	public:
		Cd(std::string inArtist, std::string inTitle, double inPlaytime, int itemIdNumber);
		~Cd();
		std::string getArtist();
		std::string getTitle();
		double getPlaytime();
		void printInfo();

	private:
		std::string artist;
		std::string title;
		double playtime;			
};

#endif
