#pragma once
#include<iostream>
#include<string>

#include"Ground.h"

#ifdef  DLLGONKY_EXPORTS
#define FASTCAMEL_API __declspec(dllexport)
#else
#define FASTCAMEL_API __declspec(dllimport)
#endif

class FASTCAMEL_API FastCamel:public Ground
{
public:
	FastCamel();
	int getDriveToRes()const override;
	double getDurationToRes(int)const override;
};
