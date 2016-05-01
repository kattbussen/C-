#include "libActions.h"

LibActions::LibActions(std::string file) 
{
	readFile(file);
}

void LibActions::readFile(std::string file)
{
	std::ifstream ifs(file);	

	std::string type;
	ifs >> type;

	//if(ifs.eof())
	//	return false;

	
}
