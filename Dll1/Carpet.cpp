#include"pch.h"
#include"Carpet.h"

Carpet::Carpet() :Flying("Ковер-самолет", 10) {};
double Carpet::getDDR(double km) const
{
    if (km < 1000.0) {
        return 0.0;
    }
    else if (km < 5000.0) {
        return 0.03; 
    }
    else if (km < 10000.0) {
        return 0.10; 
    }
    else {
        return 0.05;
    }
}
