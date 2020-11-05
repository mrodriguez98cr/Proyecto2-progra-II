#pragma once
#pragma once
#include <iostream>
#include <sstream>
#include <exception>
using namespace std;


class MiExcepcion : public exception
{
private:
	string EXP;

public:

	MiExcepcion(const char* mensaje, string x)
	{
		this->EXP = x;
	}

	string getEXP()const { return EXP; }
};