#pragma once
#include<iostream>
#include <memory>


#include"Transport.h";
#include"Camel.h"
#include"FastCamel.h"
#include"Centaur.h"
#include"Boots.h"
#include"Carpet.h"
#include"Eagle.h"
#include"Broom.h"

#ifdef  DLLGONKY_EXPORTS
#define HELPSELEM_API __declspec(dllexport)
#else
#define HELPSELEM_API __declspec(dllimport)
#endif

HELPSELEM_API int  getChoise(const std::string, int, int);
HELPSELEM_API std::unique_ptr<Transport> createPlayer(int );

