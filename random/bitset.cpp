#include <iostream>
#include <bitset>
#include <string>

class BinaryOp
{
	int number = 0;
	int filter = 0;

	public:
	
	void readNumber()
	{
		std::cout << "Enter number to operate on: " << std::endl;
		std::cin >> number;
	}

	void readFilter()
	{
		std::cout << "Enter filter to operate on: " << std::endl;
		std::cin >> filter;
	}
	
	void setNumber(int num){
		number = num;
	}

	void setFilter(int fil){
		filter = fil;
	}

	std::bitset<16> binXor(){
		return (std::bitset<16> (number^filter));
	}	

	std::bitset<16> binAnd(){
		return (std::bitset<16> (number&filter));
	}

	std::bitset<16> binOr(){
		return (std::bitset<16> (number|filter));
	}
};


int main()
{
	std::bitset<4> firstSet (std::string( "0010"));
	std::bitset<4> filter (std::string( "0010"));

	int i = 3;
	int j = 2;

	std::bitset<4> tmp (i^j);
	std::cout << tmp << std::endl;

	std::cout << (i^j) << std::endl;

	std::cout << (firstSet|filter) << std::endl;
	std::cout << (firstSet&filter) << std::endl;
	std::cout << (firstSet^filter) << std::endl;

	std::cout << sizeof(firstSet) << " " << sizeof(short int) << std::endl;

	BinaryOp binop;
	binop.readNumber();
	binop.readFilter();
	
	std::cout << binop.binXor() << " " <<	binop.binAnd() << " " << binop.binOr() << std::endl;

	
}
