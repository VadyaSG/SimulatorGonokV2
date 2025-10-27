#pragma once
#include<iostream>
#include<string>

#include"Ground.h"

#ifdef  DLLGONKY_EXPORTS
#define CENTAUR_API __declspec(dllexport)
#else
#define CENTAUR_API __declspec(dllimport)
#endif

class CENTAUR_API Centaur:public Ground
{
public:
	Centaur();
	int getDriveToRes()const override;
	double getDurationToRes(int)const override;
};