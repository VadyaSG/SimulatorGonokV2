#pragma once
#include<string>
#include<iostream>

#ifdef  DLLGONKY_EXPORTS
#define TRANSPORT_API __declspec(dllexport)
#else
#define TRANSPORT_API __declspec(dllimport)
#endif

class TRANSPORT_API Transport
{
private:

	std::string name;
	int speed;

public:
	Transport(std::string, int);
	virtual ~Transport() ;
	virtual void displayInfo() const;
	const std::string getName() const;
	int getSpeed()const ;
	virtual double calculateTime(double) const;
};
