#include "Paciente.h"

Paciente::Paciente(string id, string name, string tel, string email, string secuencia)
{
	this->id = id;
	this->nombre = name;
	this->telefono = tel;
	this->email = email;
	this->secuencia = secuencia;
	this->listaEnfermedades;
}

string Paciente::getID()
{
	return id;
}

string Paciente::getNombre()
{
	return nombre;
}

string Paciente::getTelefono()
{
	return telefono;
}

string Paciente::getEmail()
{
	return email;
}

string Paciente::getSecuencia()
{
	return secuencia;
}

vector<Enfermedad> Paciente::getLista()
{
	return listaEnfermedades;
}

void Paciente::setID(string x)
{
	this->id = x;
}

void Paciente::setNombre(string x)
{
	this->nombre = x;
}

void Paciente::setTelefono(string x)
{
	this->telefono = x;
}

void Paciente::setEmail(string x)
{
	this->email = x;
}

void Paciente::setSecuencia(string x)
{
	this->secuencia = x;
}

string Paciente::toString()
{
	stringstream s;

	s << "	ID: " << id << endl
		<< "	Nombre: " << nombre << endl
		<< "	telefono: " << telefono << endl
		<< "	Email: " << email << endl;
		//<< "	Secuencia: " <<secuencia<< endl;
	s << "----------------------------------------" << endl
		<< "	Lista de enfermedades: " << endl
		<< "----------------------------------------";
		//vector. to string

	

	return s.str();
}
