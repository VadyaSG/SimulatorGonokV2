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
	double DriveToRes = getDriveToRes();

	double relaxCount = TimeWishoutRes / DriveToRes;
	double relaxTime{};
	
	
	int relax{0};
	double fractpart,intpart;     

	fractpart = modf(relaxCount, &intpart); // отделить дробную часть от целой


	if (fractpart == 0) //если дробная часть == 0, то отдых приходится на финиш
	{
		while (relax < trunc(relaxCount)-1)
		{
			relax++;

			relaxTime += getDurationToRes(relax);


		}
		return TimeWishoutRes + relaxTime;
	}
	else
	{
		while (relax < trunc(relaxCount))
		{
			relax++;

			relaxTime += getDurationToRes(relax);


		}
		return TimeWishoutRes + relaxTime;
	}


	


