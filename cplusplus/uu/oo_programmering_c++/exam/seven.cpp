#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

class Class {
	public:
  	Class(int ii, double dd ) : ival(ii)  { 
			dval = new double; 
			*dval = dd;
		}
	
  	~Class() { 
			delete dval;
		}

		Class(const Class &cl) {
			if(this != &cl) {
				ival = cl.ival;
				dval = new double(*(cl.dval));
			}
		}

		int getInt() {
			return ival;
		}

		double getDouble() {
			return *dval;
		}	

		friend std::ostream& operator<<(std::ostream &output, Class cl) {
			output << "(" << cl.getInt() << " " << cl.getDouble() << ")";
			return output;
		}

	private:
  	int ival;
  	double *dval;
};

int main()
{
  vector<Class> vec;
  list<Class> list;
  vec.push_back( Class(1, 2.2) );
  vec.push_back( Class(2, 4.3) );
  vec.push_back( Class(3, 5.7) );
  ostream_iterator<const Class> classout(cout,"\n");
  copy( vec.begin(), vec.end(), classout );
}

