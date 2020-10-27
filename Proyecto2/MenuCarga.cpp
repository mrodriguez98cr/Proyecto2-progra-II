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

MenuCarga::MenuCarga(vector<Enfermedad*> *x, vector<Paciente*> *y)
{
	enfermedades = x;
	pacientes = y;
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
			cargarPacientes();
			break;
		case '2':
			cargarEnfermedades();
			break;
		case '3':
			generador();
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
	delete pacientes;
	delete enfermedades;
}

void MenuCarga::cargarPacientes()
{
	IReader<Paciente*> *readerp = new CsvReader<Paciente*>("pacientes.csv", new TransformadorCsvPaciente());
	pacientes = readerp->leerTodos();
	pacientes->erase(pacientes->begin());
	for (auto& persona : *pacientes)
	{
		cout << persona->toString() << endl;
	}
	system("pause");
}

void MenuCarga::cargarEnfermedades()
{
	IReader<Enfermedad*>* readerp = new CsvReader<Enfermedad*>("enfermedades.csv", new TransformadorCsvEnfermedad());
	enfermedades = readerp->leerTodos();
	enfermedades->erase(enfermedades->begin());
	for (auto& enfer : *enfermedades)
	{
		cout << enfer->toString() << endl;
	}
	system("pause");
}

void MenuCarga::generador()
{
	
	for (auto& enfer : *pacientes)
	{
		enfer->agregarLista(*enfermedades);
		cout << enfer->toString();
	}
	system("pause");

	//aqui se tiene que cargar la lista en json
}
