#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Paciente
{
private:
	string id;
	string nombre;
	string telefono;
	string email;
	string secuencia;
	//lista de enfermedades

public:

	Paciente(string, string, string, string, string);//agregar lista

	string getID();
	string getNombre();
	string getTelefono();
	string getEmail();
	string getSecuencia();

	void setID(string);
	void setNombre(string);
	void setTelefono(string);
	void setEmail(string);
	void setSecuencia(string);
	
	string toString();
};

