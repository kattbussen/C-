#include "lib.h"

int main()
{
	Cd cd = Cd("Faith", 1, "The Cure", 43.13);
	cd.borrowedBy = 12515;
	
	Magazine mag = Magazine("Ciklidbladet", 2, 1, 2016);
	FictionBook fb = FictionBook("Lord of the Rings", 3, "J.R.R Tolkien");
	NonFictionBook nfb = NonFictionBook("Real Shizzle", 4, "Deez Nutz");

	cd.printInfo();
	mag.printInfo();
	fb.printInfo();
	nfb.printInfo();

	cd.printBla();
	//std::cout << cd.getGlobalIdNumber() << std::endl;
	
	return 0;
}
