#include "cd.h"

Cd::Cd(std::string inTitle, int itemNumber, std::string inArtist, double inPlaytime) : Item(inTitle, itemNumber){
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

void Cd::printBla(){
	//std::cout << globalIdNumber << std::endl;
	//Cd::getGlobalIdNumber();
	std::cout << Cd::getGlobalIdNumber() << std::endl;
}

int main()
{
	Cd cd = Cd("Faith", 1, "The Cure", 43.13);
	cd.printBla();
	return 0;
}
