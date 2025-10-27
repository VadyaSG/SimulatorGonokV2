#include"pch.h"
#include "Flying.h"

Flying::Flying(std::string name, int speed):Transport(std::move(name), speed) {}

double Flying::getDDR(double km) const
{
	return 0;
}

void Flying::displayInfo() const
{
	Transport::displayInfo();
}

double Flying::calculateTime(double km) const
{
	double effectivDistance = km * (1.0 - getDDR(km));
	return effectivDistance/getSpeed();
}
