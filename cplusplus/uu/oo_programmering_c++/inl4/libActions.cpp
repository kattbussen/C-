#include "libActions.h"
#include "cd.h"
#include "magazine.h"
#include "fictionBook.h"
#include "nonfictionBook.h"
#include "libActions.h"

LibActions::LibActions(std::string file) 
{
	vec.clear();
	readFile(file);
}

LibActions::~LibActions()
{

}

void LibActions::readFile(std::string file)
{
	std::ifstream ifs(file);	

	std::string type;
	std::getline(ifs, type);

	while(!(ifs.eof()))
	{
		std::cout << "trying to read: " << type << std::endl;
		if( type == "Fiction" || type == "NonFiction")
		{
			std::string author;
			std::string title;
			std::string itemNumber;
			std::string borrowedBy;

			std::getline(ifs, author);
			std::getline(ifs, title);
			std::getline(ifs, itemNumber);
			std::getline(ifs, borrowedBy);

			if(type == "Fiction"){
				vec.push_back(new FictionBook(title, std::stoi(itemNumber), std::stoi(borrowedBy), author));
			}
			else
			{
				vec.push_back(new NonFictionBook(title, std::stoi(itemNumber), std::stoi(borrowedBy), author));
			}
		}
		else if( type == "CD")
		{
			std::string artist;
			std::string title;
			std::string time;
			std::string itemNumber;
			std::string borrowedBy;
	
			std::getline(ifs, artist);
			std::getline(ifs, title);
			std::getline(ifs, time);
			std::getline(ifs, itemNumber);
			std::getline(ifs, borrowedBy);
				
			vec.push_back(new Cd(title, std::stoi(itemNumber), std::stoi(borrowedBy), artist, time));
		}
		else if( type == "Journal")
		{
			std::cout << "reading magazine" << std::endl;
		}
		else
		{
			std::cout << "Read unknown type of item. Aborting." << std::endl;
			exit(0);
		}
		std::cout << type << std::endl;
		std::getline(ifs, type);
	}	
}

void LibActions::printItems()
{
	std::vector<Item*>::iterator i;
	for(i = vec.begin(); i != vec.end(); ++i)
	{
		(*i)->printInfo();
	}
}
