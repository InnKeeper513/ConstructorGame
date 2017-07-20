#include "Path.h"
#include "Address.h"
#include <algorithm>

using namespace std;

Path::Path(){}

Path::Path(int number):Path()
{
	this->number = number;
}


int Path::GetNumber()
{
	return this->number;
}

void Path::addPath(int set)
{
	paths.emplace_back(set);
}


