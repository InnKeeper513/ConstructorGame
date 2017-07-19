#include "Tile.h"

Tile::Tile()
{
	this->row = 0;
	this->col = 0;
	this->numAddress = 0;
	this->number = 0;
	this->numpath = 0;
	this->value = 0;
	this->pathes = new Path*[0];
	this->addresses = new Address*[0];
	this->resource = "";
	this->geese = "";

}

Tile::Tile(int number, string resource, int value):Tile()
{
	this->number = number;
	this->value = value;
	this->resource = resource;

}

Tile::~Tile()
{
	//delete this->pathes;
	//this->pathes = NULL;
	//delete this->addresses;
	//this->addresses = NULL;
}


void Tile::SetGeese()
{
	if (this->geese == "")
	{
		this->geese = "GEESE";
	}
	else
	{
		this->geese = "";
	}
}
string Tile::GetGeese()
{
	return this->geese;

}


int Tile::GetNumber()
{
	return this->number;
}
string Tile::GetResource()
{
	return this->resource;
}

int Tile::GetValue()
{
	return this->value;
}

void Tile::SetPos(int row, int col)
{
	this->row = row;
	this->col = col;
}

void Tile::AddPath(Path *path)
{
	Path** newArr = new Path*[this->numAddress + 1];
	copy(this->pathes, this->pathes + this->numpath, newArr);
	delete[] this->pathes;
	this->pathes = newArr;

	this->pathes[this->numpath] = path;
	this->numpath++;

}

void Tile::AddAddress(Address *address)
{
	Address** newArr = new Address*[this->numAddress + 1];
	copy(this->addresses, this->addresses + this->numAddress, newArr);
	delete[] this->addresses;
	this->addresses = newArr;

	this->addresses[this->numAddress] = address;
	this->numAddress++;

}
