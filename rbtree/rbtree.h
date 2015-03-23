#include "node.h"

template<class T> class Rbtree
{
	public:
		Rbtree(T val) : Rbtree<T>::rootP(new Node<T>(val)), (Rbtree<T>::root=*rootP) {}
//			rootP(new Node<T>(val)); 
//			root = *rootP;
//		}
	
		void push(Node<T> node);
		void print(std::shared_ptr<Node<T>> node);
		int getElementCount();
		Node<T> getRoot();

	private:	
		Node<T> root;
		std::shared_ptr<Node<T>> rootP;
		int elementCount;
};
