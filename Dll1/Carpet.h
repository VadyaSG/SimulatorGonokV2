#pragma once
#include<iostream>
#include<string>

#include"Flying.h"

#ifdef  DLLGONKY_EXPORTS
#define CARPET_API __declspec(dllexport)
#else
#define CARPET_API __declspec(dllimport)
#endif

class CARPET_API Carpet :public Flying
{
public:
	Carpet();
	double getDDR(double) const override;

};
