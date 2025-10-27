#pragma once
#include<iostream>
#include<string>
#include<cmath>

#include"Flying.h"

#ifdef  DLLGONKY_EXPORTS
#define BROOM_API __declspec(dllexport)
#else
#define BROOM_API __declspec(dllimport)
#endif

class BROOM_API Broom : public Flying
{
public:

	Broom();
	double getDDR(double) const override;
};
