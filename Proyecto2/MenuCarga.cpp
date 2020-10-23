#include "MenuCarga.h"

char MenuCarga::mostrarOpciones()
{
	system("cls");
	cout << logo();
	char opcion;
	cout << "		Menu de Carga " << endl << "	    Seleccione una opcion:" << endl;
	cout << "      *********************************\n";
	cout << "	1.	Carga de Archivos de Pacientes.cvs" << endl;
	cout << "	2.	Carga de Archivos de Enfermedades.cvs" << endl;
	cout << "	3.	Generar Archivo Datos_Geneticos.json" << endl;
	cout << "	4.	Salir" << endl << endl;
	cout << "	Opcion: "; cin >> opcion;
	system("cls");
	return opcion;
}

string MenuCarga::logo()
{
	stringstream s;
	s << "      *********************************" << endl;
	s << "	   %   %    %    %   % % %" << endl;
	s << "	   %   %    % %  %   %   %" << endl;
	s << "	   %   %    %  % %   % % %" << endl;
	s << "	   %   %    %    %   %   %" << endl;
	s << "	   % % %    %    %   %   %" << endl;
	s << "	     UNIVERSIDAD NACIONAL" << endl;
	s << "      *********************************" << endl;
	s << " Escuela de Informatica & Escuela de Biologia" << endl;
	s << "      *********************************" << endl;
	return s.str();
}

MenuCarga::MenuCarga()
{
}

void MenuCarga::invocarMenu()
{
	const char opcionSalida = '4';
	char opcion;
	do {
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			//this->menuAdmin->invocarMenu();
			break;
		case '2':
			//this->menuCobro->invocarMenu();
			break;
		case '3':
			//this->menuCobro->invocarMenu();
			break;
		case opcionSalida:
			break;
		default:
			cout << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);
}

MenuCarga::~MenuCarga()
{
}
