#include "MenuAnalizar.h"
#include "IReader.h"
#include "IWriter.h"
#include "JsonReader.h"
#include "BinaryReader.h"
#include "BinaryWriter.h"
#include "Paciente.h"
#include <Windows.h>

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

MenuAnalizar::MenuAnalizar(vector<Paciente>* Pacientes)
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
	//vector<Paciente*> *pas = NULL;
	Pacientes = reader->leerTodos();
	
	
	for (auto& enfes : *Pacientes)
	{
		Sleep(50);
		cout << enfes.toString();
		
	}

	

	cout << endl << "          Datos_Geneticos.json generado al 100% " << endl;
	cout << "          Total de pacientes: " << Pacientes->size() << endl << endl;
	cout << "      *********************************" << endl << endl;

	/*IWriter<Paciente>* writer = new BinaryWriter<Paciente>("base_datos.dat", new TransformadorBinarioPaciente());
	
	writer->escribirTodos(Pacientes);

	system("pause");*/
}

void MenuAnalizar::analisisUno()
{
}

void MenuAnalizar::analisisdos()
{
}

void MenuAnalizar::analisistres()
{
}
