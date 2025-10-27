#include"pch.h"
#include"Transport.h"

Transport::Transport(std::string name, int speed): name(std::move(name)),speed(speed) {}
Transport::~Transport() = default;
void Transport::displayInfo() const
{
	std::cout << "Транспорт: " << name;
}

const std::string Transport::getName() const
{
	return name;
}

int Transport::getSpeed() const
{
	return speed;
}

double Transport::calculateTime(double km) const
{
	return 1;
}
