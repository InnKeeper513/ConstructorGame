#ifndef _PATH_H_
#define _PATH_H_
//class Builder;
#include <vector>


class Path
{
public:
	Path();
	Path(int number);
	//Builder* GetBuilder();
	int GetNumber();
	void addPath(int);
private:
	std::vector<Path> paths;
	int number;
	int numNeighborPathes;
};

#endif
