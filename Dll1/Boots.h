#pragma once
#include<iostream>
#include<string>


#include"Ground.h"

#ifdef DLLGONKY_EXPORTS
#define BOOTS_API __declspec(dllexport)
#else
#define BOOTS_API __declspec(dllimport)
#endif

class BOOTS_API Boots :public Ground
{
public:
	Boots();
	int getDriveToRes()const override;
	double getDurationToRes(int)const override;
};