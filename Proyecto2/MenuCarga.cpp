#include "MenuCarga.h"
#include "JsonWriter.h"
#include "IWriter.h"
#include <windows.h>

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
	int contador = 1;
	
	cout<<logo();
	cout << "           Cargando Pacientes.cvs " << endl;
	cout << "      *********************************" << endl << endl;
	cout << "      [%%%%"; Sleep(500); cout << "%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%]"<<endl<<endl; 
	cout << "      *********************************" << endl;
	Sleep(1000);
	
	IReader<Paciente*>* readerp = new CsvReader<Paciente*>("pacientes.csv", new TransformadorCsvPaciente());
	pacientes = readerp->leerTodos();
	pacientes->erase(pacientes->begin());//ES PARA BORRAR LA PRIMERA LINEA

	for (auto& pas : *pacientes)
	{
		cout << "	[ " << contador << " ] " << pas->miniString() << endl;
		Sleep(50);
		contador++;
	}

	cout << endl<<"          Pacientes.cvs cargado 100% " << endl;
	cout << "          Total de Pacientes: " << pacientes->size() << endl<<endl;
	cout << "      *********************************" << endl<<endl;
	system("pause");
	readerp->cerrar();
	delete readerp;
}

void MenuCarga::cargarEnfermedades()
{
	cout << logo();
	cout << "           Cargando Enfermedades.cvs " << endl;
	cout << "      *********************************" << endl << endl;
	cout << "      [%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%]" << endl << endl;
	cout << "      *********************************" << endl;
	Sleep(1000);
	IReader<Enfermedad*>* readerp = new CsvReader<Enfermedad*>("enfermedades.csv", new TransformadorCsvEnfermedad());
	enfermedades = readerp->leerTodos();
	enfermedades->erase(enfermedades->begin());
	int contador = 1;
	for (auto& enfer : *enfermedades)
	{
		cout << "	[ " <<contador<<" ] "<<enfer->toString() << endl;
		Sleep(50);
		contador++;
	}
	Sleep(1000);

	cout << endl << "          Pacientes.cvs cargado 100% " << endl;
	cout << "          Total de enfermedades: " << enfermedades->size() << endl<<endl;
	cout << "      *********************************" << endl << endl;

	system("pause");
	readerp->cerrar();
	delete readerp;
}

void MenuCarga::generador()
{
	cout << logo();
	cout << "           Generando Datos_Geneticos.json " << endl;
	cout << "      *********************************" << endl << endl;
	cout << "      [%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%]" << endl << endl;
	cout << "      *********************************" << endl;
	Sleep(1000);
	
	for (auto& enfer : *pacientes)
	{
		enfer->agregarLista(*enfermedades);
		Sleep(50);
		cout << enfer->toString();
	}
	
	cout << endl << "          Datos_Geneticos.json generado al 100% " << endl;
	cout << "          Total de pacientes: " << pacientes->size() << endl << endl;
	cout << "      *********************************" << endl << endl;


	//aqui se tiene que cargar la lista en json
	IWriter<Paciente>* writer = new JsonWriter<Paciente>("Datos_Geneticos.json");
	for (auto& enfer : *pacientes)
	{
		writer->escribir(*enfer);
	}

	writer->cerrar();

	delete writer;

	system("pause");
}
