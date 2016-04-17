#include "cd.h"

Cd::Cd(std::string inArtist, std::string inTitle, double inPlaytime, int itemIdNumber) : Item(itemIdNumber){
	artist = inArtist;
	title = inTitle;
	playtime = inPlaytime;
}
		
Cd::~Cd(){

}

std::string Cd::getArtist(){
	return artist;
}

std::string Cd::getTitle(){
	return title;
}

double Cd::getPlaytime(){
	return playtime;
}

void Cd::printInfo(){
	std::cout << "Artist:   " << artist << std::endl;
	std::cout << "Title:    " << title << std::endl;
	std::cout << "Length:   " << playtime << " min." << std::endl;
	std::cout << "id:       " << getIdNumber() << std::endl;
	std::cout << "borr. by: " << borrowedBy << std::endl;
}
