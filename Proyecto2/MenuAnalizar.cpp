#include "MenuAnalizar.h"
#include "IReader.h"
#include "IWriter.h"
#include "JsonReader.h"
#include "BinaryReader.h"
#include "BinaryWriter.h"
#include "Paciente.h"
#include <Windows.h>
#include "MiExepcion.h"
#include <exception>
#include <map>

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
	this->Pacientes = nullptr;
}

MenuAnalizar::MenuAnalizar(vector<Paciente*>* Pacientes)
{
	this->Pacientes = Pacientes;
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
			this->leer();
			break;
		case '2':
			this->analisisUno();
			break;
		case '3':
			this->analisisdos();
			break;
		case '4':
			this->analisistres();
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

void MenuAnalizar::leer()
{
	cout << logo();
	cout << "           LEYENDO Datos_Geneticos.json " << endl;
	cout << "      *********************************" << endl << endl;
	cout << "      [%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%]" << endl << endl;
	cout << "      *********************************" << endl;
	Sleep(1000);
	IReader<Paciente>* reader = new JsonReader<Paciente>("Datos_Geneticos.json");
	vector<Paciente>* pacientesJson = new vector<Paciente>();
	pacientesJson = reader->leerTodos();
	delete reader;
	cout << endl << "          Datos_Geneticos.json generado al 100% " << endl;
	cout << "          Total de pacientes: " << pacientesJson->size() << endl << endl;
	cout << "      *********************************" << endl << endl;

	system("pause");
	system("cls");

	cout << logo();
	cout << "           Generando base_datos.dat " << endl;
	cout << "      *********************************" << endl << endl;
	cout << "      [%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%]" << endl << endl;
	cout << "      *********************************" << endl;
	Sleep(1000);

	IWriter<Paciente*>* writer = new BinaryWriter<Paciente*>("base_datos.dat", new TransformadorBinarioPaciente());
	
	for (auto& paciente : *pacientesJson)
	{
		writer->escribir(&paciente);
		
	}

	delete writer;

	cout << endl << "         base_datos.dat generado al 100% " << endl;
	cout << "          Total de pacientes: " << pacientesJson->size() << endl << endl;
	cout << "      *********************************" << endl << endl;

	system("pause");
	system("cls");

	cout << logo();
	cout << "           LEYENDO base_datos.dat " << endl;
	cout << "      *********************************" << endl << endl;
	cout << "      [%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%"; Sleep(500); cout << "%%%%]" << endl << endl;
	cout << "      *********************************" << endl;
	Sleep(1000);

	IReader<Paciente*>* readerbin = new BinaryReader<Paciente*>("base_datos.dat", new TransformadorBinarioPaciente());
	Pacientes=readerbin->leerTodos(); //asignar a una lista 
	
	

	delete readerbin;

	cout << endl << "         base_datos.dat leido al 100% " << endl;
	cout << "          Total de pacientes: " << Pacientes->size() << endl << endl;
	cout << "      *********************************" << endl << endl;
	
	pr = TRUE;
	//writer->escribirTodos(Pacientes);

	system("pause");
}

void MenuAnalizar::analisisUno()
{
	try
	{
		if (pr == false)
			throw exception("	Archivo no cargado");
		else
		{
			cout << logo();
			cout << "           Analisis # 2 " << endl;
			cout << "      *********************************" << endl << endl;
			cout << "      [%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%]" << endl << endl;
			cout << "      *********************************" << endl;
			Sleep(500);
			map<string, int> mapaEnfermedades;
			for (auto& pas : *Pacientes)
				for (auto& enfe : *pas->getLista())
					mapaEnfermedades[enfe->getNombre()]++;
			cout << endl;
			system("pause");

			for (auto& pareja : mapaEnfermedades)
			{
				cout << "Nombre de la enfermedad: " << pareja.first << endl;
				cout << "Ocurrencias: " << pareja.second << endl;
			}
			system("pause");


		}
	}
	catch (exception& e)
	{
		cerr << "	**************************" << endl;
		cerr << e.what() << endl;
		cerr << "	**************************" << endl;
		system("pause");
	}
}

void MenuAnalizar::analisisdos()
{
	try {
		if (pr == false)
		{
			throw exception("Archivo no Cargado");
		}
		else
		cout << logo();
		cout << "           Analisis # 2 " << endl;
		cout << "      *********************************" << endl << endl;
		cout << "      [%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%]" << endl << endl;
		cout << "      *********************************" << endl;
		Sleep(500);
		int contador = 1;
		for (auto& pas : *Pacientes)
		{
			cout << "	[ " << contador << " ] " << pas->miniString() << endl;
			Sleep(50);
			contador++;
		}
		string x;
		cout << "	Ingrese el numero de ID del Paciente: "; cin >> x;

		bool n = TRUE;
		try {
			for (auto& pas : *Pacientes)
			{
				if (pas->getID() == x)
				{
					cout << pas->toString() << endl;
					pas->calculador();
					n = FALSE;

				

				}

			}
			if (n == TRUE)
				throw exception("	Paciente Invalido");

		}
		catch (exception& e)
		{
			cerr << "	*******************" << endl;
			cerr << "	" << e.what() << endl;
			cerr << "	*******************" << endl;
		}
	}
	catch (exception& e)
	{
		cerr << "	**************************" << endl;
		cerr <<"	"<< e.what() << endl;
		cerr << "	**************************" << endl;
		system("pause");
	}

	

	system("pause");

	
}

void MenuAnalizar::analisistres()
{
	try {
		if (pr == false)
		{
			throw exception("Archivo no Cargado");
		}
		else
			cout << logo();
		cout << "           Analisis # 2 " << endl;
		cout << "      *********************************" << endl << endl;
		cout << "      [%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%"; Sleep(250); cout << "%%%%]" << endl << endl;
		cout << "      *********************************" << endl;
		Sleep(500);
		for (auto& pas : *Pacientes)
		{
			pas->probabilizador();
		}
		system("pause");
	}
	catch(exception& e)
		{
		cerr << "	*******************" << endl;
		cerr << "	" << e.what() << endl;
		cerr << "	*******************" << endl;
		system("pause");
		}
}
