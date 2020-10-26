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

vector<Enfermedad*> Paciente::getLista()
{
	return listaEnfermedades;
}

Paciente::~Paciente()
{
	
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
		<< "----------------------------------------"<< endl;
	for (int i = 0; i < listaEnfermedades.size(); i++)
	{
		s << listaEnfermedades[i]->toString();
	}
	s << endl<<endl;

	

	return s.str();
}

void Paciente::agregarLista(vector<Enfermedad*> enfe)
{
	for (int i = 0; i < enfe.size(); i++)
		if (buscador(enfe[i]->getSecuencia()))
			listaEnfermedades.push_back(enfe[i]);

}

bool Paciente::buscador(string x)
{
	auto it = secuencia.find(x);

	if (it != std::string::npos)
		return true;
	else
		return false;
}
