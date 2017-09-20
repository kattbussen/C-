#include <iostream>
#include <algorithm>
using namespace std;

class A {
public:
  A(int a ) : a(a) {}
  int get() const { return a; }
private:
  int a;
};

bool sortA(const A first, const A second) {
	if(first.get() < second.get())
		return true;
	else
		return false;
}

int main()
{
  A a[10] = {A(10), A(1), A(2), A(3), A(4), A(5), A(6), A(7), A(8), A(9)};
  //A* a = new A[10];
  
  cout << "(";
  for (int i=0; i < 10; i++)
    cout << a[i].get() << " ";

  cout << ")" << endl;
  
  sort( a, a+10, sortA);

  cout << "(";
  for (int i=0; i < 10; i++)
    cout << a[i].get() << " ";

  cout << ")" << endl;
}
