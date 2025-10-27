#pragma once
#ifdef  DLLGONKY_EXPORTS
#define Dll1_API_API __declspec(dllexport)
#else
#define Dll1_API_API __declspec(dllimport)
#endif
#include "pch.h"
#include"Transport.h"
#include"Ground.h"
#include "Flying.h"
#include "Camel.h"
#include "FastCamel.h"
#include"Centaur.h"
#include"Boots.h"
#include"Carpet.h"
#include"Eagle.h"
#include"Broom.h"
#include"HelpsElem.h"



