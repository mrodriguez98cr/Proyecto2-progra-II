

#pragma once
#include<iostream>
#include<sstream>
#include<vector>
#include"Enfermedad.h"
using namespace std;

struct Pacientej
{
	string id;
	string nombre;
	string telefono;
	string email;
	string secuencia;
	vector<Enfermedad*> *listaEnfermedades;

	string toString()
	{
		stringstream s;

		s << "	ID: " << id << endl
			<< "	Nombre: " << nombre << endl
			<< "	telefono: " << telefono << endl
			<< "	Email: " << email << endl;
		//<< "	Secuencia: " <<secuencia<< endl;
		s << "----------------------------------------" << endl
			<< "	Lista de enfermedades: " << endl
			<< "----------------------------------------" << endl;
		for (auto& enfer : *listaEnfermedades)
		{
			s<< enfer->toString() << endl;
		}
		s << endl << endl;



		return s.str();
	}
};