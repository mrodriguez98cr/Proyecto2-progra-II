#include "Enfermedad.h"

Enfermedad::Enfermedad()
{
	this->nombre = " ";
	this->secuencia = " ";
}

Enfermedad::Enfermedad(string enfermedad, string secuencia)
{
	this->nombre = enfermedad;
	this->secuencia = secuencia;
}

string Enfermedad::getNombre()
{
	return nombre;
}

string Enfermedad::getSecuencia()
{
	return secuencia;
}

void Enfermedad::setNombre(string n)
{
	this->nombre = n;
}

void Enfermedad::setSecuencia(string s)
{
	this->secuencia = s;
}

string Enfermedad::toString()
{
	stringstream s;

	s << "	Enfermedad: " << nombre << "	Secuencia: " << secuencia << endl
		<< "----------------------------------------" << endl;
	
	return s.str();
}
