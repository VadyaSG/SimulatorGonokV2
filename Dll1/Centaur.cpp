#include"pch.h"
#include"Centaur.h"

Centaur::Centaur() :Ground("�������", 15) {};
int Centaur::getDriveToRes() const
{
	return 8;
}
double Centaur::getDurationToRes(int resCount)const { return 2; }