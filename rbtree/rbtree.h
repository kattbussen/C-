#include "node.h"

class Rbtree
{
	public:
		//template <class T> Rbtree(T val) : {}
//			rootP(new Node<T>(val)); 
//			root = *rootP;
//		}
	
		template <class T> void push(Node<T> node);
		template <class T> void print(std::shared_ptr<Node<T>> node);
		int getElementCount();
		//template <class T> Node<T> getRoot();

	private:	
		//template <class T> Node<T> root;
		//template <class T> std::shared_ptr<Node<T>> rootP;
		int elementCount;
};
