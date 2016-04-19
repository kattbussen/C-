#include "lib.h"

int main()
{
	Cd cd = Cd(1, "Faith", "The Cure", 43.13);
	cd.borrowedBy = 12515;
	cd.printInfo();
	
	Magazine mag = Magazine(2, "Ciklidbladet", 1, 2016);
	mag.printInfo();

	FictionBook fb = FictionBook(3, "Lord of the Rings", "J.R.R Tolkien");
	fb.printInfo();

	NonFictionBook nfb = NonFictionBook(4, "Real Shizzle", "Deez Nutz");
	nfb.printInfo();

	return 0;
}
