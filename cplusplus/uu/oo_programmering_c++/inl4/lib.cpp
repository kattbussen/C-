#include "lib.h"

int main()
{
	Cd cd = Cd("Faith", "The Cure", 43.13);
	cd.borrowedBy = 12515;
	
	Magazine mag = Magazine("Ciklidbladet", 1, 2016);
	FictionBook fb = FictionBook("Lord of the Rings", "J.R.R Tolkien");
	NonFictionBook nfb = NonFictionBook("Real Shizzle", "Deez Nutz");

	cd.printInfo();
	mag.printInfo();
	fb.printInfo();
	nfb.printInfo();
	
	return 0;
}
