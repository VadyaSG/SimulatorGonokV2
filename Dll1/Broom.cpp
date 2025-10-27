#include"pch.h"
#include"Broom.h"

Broom::Broom() :Flying("Метла", 20) {}

double Broom::getDDR(double km) const
{
	int roadKm = static_cast<int>(floor(km / 1000));
	double redDistan = static_cast<double>(roadKm) * 0.01;
	if (redDistan > 1.0)
	{
		return 1.0;
	}
	return redDistan;
}