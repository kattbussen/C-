#include "mydef.h"
#include <string>
#include <complex>

struct User {
	std::string name;
	int age;
};

double sqrt(double a)
{
	return a;
}

int main()
{
}

char ch;
std::string s;
int count = 1;
const double pi = 3.14;
extern int error_number;
	
const char* name = "Njal";
const char* season[] = { "spring", "summer", "autumn", "winter" };
	
struct Date { int d, m, y; };
int day(Date* p) {return p->d;}
double sqrt(double);
template<class T> T abs(T a) {return a<0 ? -a : a; }

typedef std::complex<short> Point;
struct User;
enum Beer { Carlsberg, Tuborg, Thor };
namespace NS { int a; }
Point punkt;
