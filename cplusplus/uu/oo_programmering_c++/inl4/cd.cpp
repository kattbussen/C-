#include "cd.h"

Cd::Cd(int itemIdNumber, std::string inTitle, std::string inArtist, double inPlaytime) : Item(itemIdNumber, inTitle){
	artist = inArtist;
	playtime = inPlaytime;
}
		
Cd::~Cd(){

}

std::string Cd::getArtist(){
	return artist;
}

double Cd::getPlaytime(){
	return playtime;
}

void Cd::printInfo(){
	std::cout << "Artist:     " << artist << std::endl;
	std::cout << "Title:      " << getTitle() << std::endl;
	std::cout << "Length:     " << playtime << " min." << std::endl;
	std::cout << "id:         " << getIdNumber() << std::endl;
	std::cout << "borr. by:   " << borrowedBy << std::endl;
}
