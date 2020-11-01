#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Paciente.h"


using namespace std;

class MenuAnalizar
{
private:
	char mostrarOpciones();
	string logo();
	vector<Paciente> *Pacientes;

public:
	MenuAnalizar();
	MenuAnalizar(vector<Paciente>*);
	void invocarMenu();
	~MenuAnalizar();
	void leer();
	void analisisUno();
	void analisisdos();
	void analisistres();
};
