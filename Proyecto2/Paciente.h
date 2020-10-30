#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Enfermedad.h"
using namespace std;
class Paciente
{
public:
	string id;
	string nombre;
	string telefono;
	string email;
	string secuencia;
	vector<Enfermedad*> *listaEnfermedades;

public:

	Paciente(string, string, string, string, string);//agregar lista
	Paciente();
	string getID()const;
	string getNombre()const;
	string getTelefono()const;
	string getEmail()const;
	string getSecuencia()const;
	vector<Enfermedad*>* getLista()const;
	~Paciente();

	void setID(string);
	void setNombre(string);
	void setTelefono(string);
	void setEmail(string);
	void setSecuencia(string);
	void setLista(vector<Enfermedad*>*);
	
	string toString();


	void agregarLista(vector<Enfermedad*> enfe);
	

	bool buscador(string x);

};

