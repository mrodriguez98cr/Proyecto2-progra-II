#include "Menu.h"

char Menu::mostrarOpciones()
{
	system("cls");
	cout << logo();
	char opcion;
	cout << "		Menu Principal " << endl << "	    Seleccione una opcion:" << endl;
	cout << "      *********************************\n";
	cout << "	1.	Carga de Archivos" << endl;
	cout << "	2.	Analizar Archivos" << endl;
	cout << "	3.	Salir" << endl << endl;
	cout << "	Opcion: "; cin >> opcion;
	system("cls");
	return opcion;
}

string Menu::logo()
{
	stringstream s;
	s << "      *********************************" << endl;
	s << "	   %   %    %    %   % % %" << endl;
	s << "	   %   %    % %  %   %   %" << endl;
	s << "	   %   %    %  % %   % % %" << endl;
	s << "	   %   %    %    %   %   %" << endl;
	s << "	   % % %    %    %   %   %" << endl;
	s << "	     UNIVERSIDAD NACIONAL" << endl ;
	s << "      *********************************" << endl;
	s << " Escuela de Informatica & Escuela de Biologia" << endl;
	s << "      *********************************" << endl;
	return s.str();
}

Menu::Menu(MenuCarga* mc, MenuAnalizar* ma)
{
	this->mc = mc;
	this->ma = ma;
}

void Menu::invocarMenu()
{
	const char opcionSalida = '3';
	char opcion;
	do {
		opcion = mostrarOpciones();
		switch (opcion)
		{
		case '1':
			mc->invocarMenu();
			break;
		case '2':
			ma->invocarMenu();
			break;
		case opcionSalida:
			break;
		default:
			cout << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);
}

Menu::~Menu()
{
}
