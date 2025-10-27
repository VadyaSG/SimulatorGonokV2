#pragma once
#include<iostream>
#include<string>

#include"Transport.h"

#ifdef  DLLGONKY_EXPORTS
#define GROUND_API __declspec(dllexport)
#else
#define GROUND_API __declspec(dllimport)
#endif
class GROUND_API Ground : public Transport 
{
public:
    Ground(std::string, int);
    virtual int getDriveToRes()  const;
    virtual double getDurationToRes(int)const;
    void displayInfo() const override;
    double calculateTime(double) const override;

};
