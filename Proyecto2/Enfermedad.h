#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Enfermedad
{
private:
	string nombre;
	string secuencia;

public:
	Enfermedad();
	Enfermedad(string, string);

	string getNombre()const;
	string getSecuencia()const;

	void setNombre(string);
	void setSecuencia(string);

	string toString();

};

