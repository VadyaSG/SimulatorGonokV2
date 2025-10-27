#include"pch.h"
#include "Ground.h"

Ground::Ground(std::string name, int speed):Transport(std::move(name), speed) {}

int Ground::getDriveToRes() const
{
	return 0;
}

double Ground::getDurationToRes(int restCount) const
{
	return 0.0;
}

void Ground::displayInfo() const
{
	Transport::displayInfo();
}

double Ground::calculateTime(double km) const
{
	double TimeWishoutRes = km / getSpeed();
	double TotalResTime{ 0.0 };
	double DriveToRes = getDriveToRes();
	if (DriveToRes <= 0)
	{
		return TimeWishoutRes;
	}
	double mileage{ 0.0 };
	int relax{ 0 };
	
	while (mileage + DriveToRes < km)
	{
		relax++;
		TotalResTime=TimeWishoutRes / getDriveToRes()*getDurationToRes(relax);
		TotalResTime += getDurationToRes(relax) / 60;
		mileage += DriveToRes;
		
	}
	return TimeWishoutRes + TotalResTime;
}

