#include "cd.h"

Cd::Cd(std::string inTitle, std::string inArtist, double inPlaytime) : Item(inTitle){
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

/*int main()
{
	return 0;
}*/
