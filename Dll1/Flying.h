#pragma once
#include<iostream>
#include<string>

#include"Transport.h"

#ifdef  DLLGONKY_EXPORTS
#define FLYING_API __declspec(dllexport)
#else
#define FLYING_API __declspec(dllimport)
#endif


class FLYING_API Flying :public Transport
{
public:
	Flying(std::string, int );
	virtual double getDDR(double) const;
	void displayInfo()const override;
	double calculateTime(double) const override;

};

