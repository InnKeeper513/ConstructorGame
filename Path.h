#ifndef _PATH_H_
#define _PATH_H_
//class Builder;

class Path
{
public:
	Path();
	Path(int number);
	//Builder* GetBuilder();
	int GetNumber();
	void AddNeighborPath(Path* path);
	void PushNeighborPath(Path* path);
private:
	int number;
	//Builder* owner;
	Path** neighborPathes;
	int numNeighborPathes;
	bool isInNeighborPathes(int number);
};

#endif
