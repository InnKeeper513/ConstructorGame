#pragma once
#include "Builder.h"
using namespace std;
class Path
{
public:
	Path();
	Path(int number);
	~Path();
	Builder* GetBuilder();
	int GetNumber();
	void AddNeighborPath(Path* path);
	void PushNeighborPath(Path* path);
private:
	int number;
	Builder* owner;
	Path** neighborPathes;
	int numNeighborPathes;
	bool isInNeighborPathes(int number);
};

