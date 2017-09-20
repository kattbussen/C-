#include <list>
#include <iostream>

using namespace std;

template <typename T> class UnaryPredicate {
	public:
  	virtual bool operator()( T value ) = 0;
};

template <typename T> class GreaterThan : public UnaryPredicate<T> {
	private:
		T limit;
	public:
		GreaterThan(T lim) : limit(lim) {
	}

	bool operator()(T val) {
		return val > limit;
	}
};

template <typename T> class List {
	private:
		std::list<T> list;
	
	public:
		List() {
		}

		~List() {
		}

		void add(T val) {
			list.push_back(val);
		}

		void add_if(T val, UnaryPredicate<T>& pred) {
			if(pred(val))
				list.push_back(val);
		}

		List<T> remove_if(UnaryPredicate<T>& pred) {
			List<T> alist;
			
			typename std::list<T>::iterator it;
			for(it = list.begin(); it != list.end(); ++it) {
				if(!pred(*it)) {
					alist.add(*it);
				}
			}
			return alist;
		}

		void printList() {
			typename std::list<T>::iterator it;
			for(it = list.begin(); it != list.end(); ++it) {
				cout << *it << endl;
			}	
		}
};


int main() {
  List<int> listan;
  listan.add( 5 );
  listan.add( 2 );
  listan.add( 7 );  
	GreaterThan<int> gt4(4);
  listan.add_if( 2, gt4 ); 
  listan.add_if( 8, gt4 ); 
	
	List<int> annanlista = listan.remove_if( gt4 );
	
}
