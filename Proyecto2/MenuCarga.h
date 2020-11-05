#pragma once
#include <iostream>
#include <sstream>
#include "Enfermedad.h"
#include "Paciente.h"
#include"CsvWriter.h"
#include"CsvReader.h"
#include <vector>
#include "IReader.h"
#include "MiExepcion.h"
using namespace std;

class MenuCarga
{
private:
	char mostrarOpciones();
	string logo();
	vector<Enfermedad*> *enfermedades;
	vector<Paciente*> *pacientes;


public:
	MenuCarga(vector<Enfermedad*> *, vector<Paciente*> *);
	void invocarMenu();
	~MenuCarga();
	void cargarPacientes();
	void cargarEnfermedades();
	void generador();
	
};

