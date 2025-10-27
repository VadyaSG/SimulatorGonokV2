#include"pch.h"
#include"Boots.h"

Boots::Boots() :Ground("Ботинки-вездеходы", 6) {};
int Boots::getDriveToRes() const { return 60; }
double Boots::getDurationToRes(int resCount) const 
{
	if (resCount == 1)
	{
		return 10;
	}
	return 5;
}