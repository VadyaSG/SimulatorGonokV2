#include"pch.h"
#include"Camel.h"

Camel::Camel() :Ground("Верблюд", 10) {}

int Camel::getDriveToRes() const
{
	return 30;
}

double Camel::getDurationToRes(int resCount) const 
{
	
	if (resCount == 1)
	{
		return 5;
	}
	
		return 8;
	
}

