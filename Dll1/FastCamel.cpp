#include"pch.h"
#include"FastCamel.h"

FastCamel::FastCamel() :Ground("Верблюд-быстроход", 40) {};

int FastCamel::getDriveToRes() const
{
	return 10;
}

double FastCamel::getDurationToRes(int resCount) const 
{
	if (resCount == 1) { return 5; }
	if (resCount == 2) { return 6.5; }
	return 8;
}