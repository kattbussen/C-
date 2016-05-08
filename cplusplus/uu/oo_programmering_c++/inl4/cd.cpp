#include "cd.h"

Cd::Cd(std::string inTitle, int itemNumber, int borrowedNumber, std::string inArtist, std::string inPlaytime) : Item(inTitle, itemNumber, borrowedNumber) {
	artist = inArtist;
	playtime = inPlaytime;
}
		
std::string Cd::getArtist() {
	return artist;
}

std::string Cd::getPlaytime() {
	return playtime;
}

std::string Cd::extractInfo() {
	std::string type = "CD";
	std::string idNumber = std::to_string(getIdNumber());
	std::string borrowed = std::to_string(borrowedBy);
	return type+"\n"+artist+"\n"+getTitle()+"\n"+playtime+"\n"+idNumber+"\n"+borrowed;
}

void Cd::printInfo() {
	std::cout << "Artist:     " << artist << std::endl;
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "Length:     " << playtime << " hours" << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}
