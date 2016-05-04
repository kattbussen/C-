#include "lib.h"

int Item::globalIdNumber = 0;

int main()
{
	/*Cd cd = Cd("Faith", 1, 0, "The Cure", 43.13);
	cd.borrowedBy = 12515;
	
	Magazine mag = Magazine("Ciklidbladet", 2, 1, 0, 2016);
	FictionBook fb = FictionBook("Lord of the Rings", 3, 0, "J.R.R Tolkien");
	NonFictionBook nfb = NonFictionBook("Real Shizzle", 4, 0, "Deez Nutz");

	cd.printInfo();
	mag.printInfo();
	fb.printInfo();
	nfb.printInfo();

	std::cout << cd.getGlobalIdNumber() << std::endl;
	*/
	
	LibActions lib = LibActions("lib.txt");
	lib.printItems();
	return 0;
}
