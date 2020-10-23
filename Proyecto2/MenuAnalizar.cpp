#include "MenuAnalizar.h"

char MenuAnalizar::mostrarOpciones()
{
	system("cls");
	cout << logo();
	char opcion;
	cout << "		Menu Analizador de Archivos " << endl << "	    Seleccione una opcion:" << endl;
	cout << "      *********************************\n";
	cout << "	1.	Carga archivo: Datos_Geneticos.json" << endl;
	cout << "	2.	Analisis 1" << endl;
	cout << "	3.	Analisis 2" << endl;
	cout << "	4.	Analisis 3" << endl;
	cout << "	5.	Salir" << endl << endl;
	cout << "	Opcion: "; cin >> opcion;
	system("cls");
	return opcion;
}

string MenuAnalizar::logo()
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

MenuAnalizar::MenuAnalizar()
{
}

void MenuAnalizar::invocarMenu()
{
	const char opcionSalida = '5';
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
		case '4':
			//this->menuCobro->invocarMenu();
			break;
		case opcionSalida:
			break;
		default:
			cout << "Opcion invalida, digite otra vez" << endl;
		}
	} while (opcion != opcionSalida);
}

MenuAnalizar::~MenuAnalizar()
{
}
