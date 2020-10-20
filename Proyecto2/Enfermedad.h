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

	Enfermedad(string, string);

	string getNombre();
	string getSecuencia();

	void setNombre(string);
	void setSecuencia(string);

	string toString();

};

