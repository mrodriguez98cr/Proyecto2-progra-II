#include "Enfermedad.h"
#include "Paciente.h"
#include "Menu.h"
#include "MenuAnalizar.h"
#include "MenuCarga.h"
#include"CsvWriter.h"
#include"CsvReader.h"
using namespace std;

int main()
{
	/*MenuAnalizar* ma = new MenuAnalizar();
	MenuCarga* mc = new MenuCarga();
	Menu* men = new Menu(mc, ma);

	men->invocarMenu();


	Paciente* p = new Paciente("117110640", "Marco Rodriguez", "8914-5640", "davidcr98@gmail.com", "AGAGAG");
	Enfermedad* e = new Enfermedad("Cagadera", " caca");
	
	cout << p->toString() << endl;
	cout << e->toString() << endl;*/

	/*IWriter<Paciente*>* writer = new CsvWriter<Paciente*>("personas.csv", new TransformadorCsvPaciente);
	Paciente* p1 = new Paciente("117110640", "Marco Rodriguez", "8914-5640", "davidcr98@gmail.com", "AGAGAG");
	Paciente* p2 = new Paciente("117145640", "Gabriel Alvarado", "8969-5623", "gabo98@gmail.com", "ATAAG");
	Paciente* p3 = new Paciente("116980640", "Giancarlo Chaves", "8984-5640", "gian98@gmail.com", "AGTAAG");
	
	writer->escribir(p1);
	writer->escribir(p2);
	writer->escribir(p3);
	
	system("pause");

	delete p1;
	delete p2;
	delete p3;
	*/
	
	//delete e;

	/*IReader<Paciente*>* readerp = new CsvReader<Paciente*>("pacientes.csv", new TransformadorCsvPaciente());
	vector<Paciente*>* personas = readerp->leerTodos();

	for (auto& persona : *personas)
	{
		cout << persona->toString() << endl;
	}

	delete personas;
	delete readerp;*/


	IReader<Enfermedad*>* readerE = new CsvReader<Enfermedad*>("enfermedades.csv", new TransformadorCsvEnfermedad());
	vector<Enfermedad*>* personas = readerE->leerTodos();

	for (auto& persona : *personas)
	{
		cout << persona->toString() << endl;
	}

	delete personas;
	delete readerE;

	return 0;

}