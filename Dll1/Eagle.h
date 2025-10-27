#pragma once
#include<iostream>
#include<string>

#include"Flying.h"

#ifdef  DLLGONKY_EXPORTS
#define EAGLE_API __declspec(dllexport)
#else
#define EAGLE_API __declspec(dllimport)
#endif

class EAGLE_API Eagle :public Flying
{
public:
	Eagle();
	double getDDR(double) const override;

};