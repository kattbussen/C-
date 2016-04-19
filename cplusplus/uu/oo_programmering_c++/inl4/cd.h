#ifndef CD_H
#define CD_H

#include "item.h"
#include <string>

class Cd : public Item {

	public:
		Cd(std::string inTitle, std::string inArtist, double inPlaytime);
		~Cd();
		std::string getArtist();
		double getPlaytime();
		void printInfo();

	private:
		std::string artist;
		std::string title;
		double playtime;			
};

#endif
