#include "cd.h"

Cd::Cd(std::string inTitle, int itemNumber, int borrowedNumber, std::string inArtist, std::string inPlaytime) : Item(inTitle, itemNumber, borrowedNumber) {
	artist = inArtist;
	playtime = inPlaytime;
}
		
Cd::~Cd() {
}

std::string Cd::getArtist() {
	return artist;
}

std::string Cd::getPlaytime() {
	return playtime;
}

void Cd::printInfo() {
	std::cout << "Artist:     " << artist << std::endl;
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "Length:     " << playtime << " hours" << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}
