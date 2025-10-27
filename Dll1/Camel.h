#pragma once

#include<iostream>
#include<string>
#include"Ground.h"

#ifdef  DLLGONKY_EXPORTS
#define CAMEL_API __declspec(dllexport)
#else
#define CAMEL_API __declspec(dllimport)
#endif

class CAMEL_API Camel : public Ground 
{
public:
	Camel();
	int getDriveToRes()const override;
	double getDurationToRes(int)const override;
};