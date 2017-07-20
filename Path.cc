#include "Path.h"
#include "Address.h"
#include <algorithm>

using namespace std;

Path::Path()
{
	this->number = 0;
	this->numNeighborPathes = 0;
	this->neighborPathes = new Path*[0];
}

Path::Path(int number):Path()
{
	this->number = number;
}


int Path::GetNumber()
{
	return this->number;
}

void Path::AddNeighborPath(Path* path)
{
	this->PushNeighborPath(path);
	path->PushNeighborPath(this);
}

void Path::PushNeighborPath(Path* path)
{
	if (!this->isInNeighborPathes(path->GetNumber()))
	{
		Path** newArr = new Path*[this->numNeighborPathes + 1];
		copy(this->neighborPathes, this->neighborPathes + this->numNeighborPathes, newArr);
		delete[] this->neighborPathes;
		this->neighborPathes = newArr;

		this->neighborPathes[this->numNeighborPathes] = path;
		this->numNeighborPathes++;
	}
}

bool Path::isInNeighborPathes(int number)
{
	for (int i = 0;i<this->numNeighborPathes;i++)
	{
		if (this->neighborPathes[i]->GetNumber() == number)
			return true;
	}
	return false;
}
