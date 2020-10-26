#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Enfermedad.h"
using namespace std;
class Paciente
{
private:
	string id;
	string nombre;
	string telefono;
	string email;
	string secuencia;
	vector<Enfermedad*> listaEnfermedades;

public:

	Paciente(string, string, string, string, string);//agregar lista

	string getID();
	string getNombre();
	string getTelefono();
	string getEmail();
	string getSecuencia();
	vector<Enfermedad*> getLista();
	~Paciente();

	void setID(string);
	void setNombre(string);
	void setTelefono(string);
	void setEmail(string);
	void setSecuencia(string);
	
	string toString();


	void agregarLista(vector<Enfermedad*> enfe);
	

	bool buscador(string x);

};

