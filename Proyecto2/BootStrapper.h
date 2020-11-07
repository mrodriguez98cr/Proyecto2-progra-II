#pragma once

#include "Enfermedad.h"
#include "Paciente.h"
#include "Menu.h"
#include "MenuAnalizar.h"
#include "MenuCarga.h"
#include"CsvWriter.h"
#include"CsvReader.h"
using namespace std;

class BootStrapper
{
public:

	static void correrApp()
	{
		vector<Paciente*>* personas = NULL;
		vector<Enfermedad*>* enfer = NULL;
		vector<Paciente*>* pacientes= new vector<Paciente*>();
		MenuAnalizar* ma = new MenuAnalizar(pacientes);
		MenuCarga* mc = new MenuCarga(enfer, personas);
		Menu* men = new Menu(mc, ma);

		men->invocarMenu();

		delete personas;
		delete enfer;
		delete pacientes;

		delete ma;
		delete mc;
		delete men;

	}
};