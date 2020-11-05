#include "Paciente.h"

Paciente::Paciente(string id, string name, string tel, string email, string secuencia)
{
	this->id = id;
	this->nombre = name;
	this->telefono = tel;
	this->email = email;
	this->secuencia = secuencia;
	this->listaEnfermedades=new vector<Enfermedad*>();
}

Paciente::Paciente()
{
	this->id = " ";
	this->nombre = " ";
	this->telefono = " ";
	this->email = " ";
	this->secuencia = " ";
	this->listaEnfermedades = new vector<Enfermedad*>();
}

string Paciente::getID()const
{
	return id;
}

string Paciente::getNombre()const
{
	return nombre;
}

string Paciente::getTelefono()const
{
	return telefono;
}

string Paciente::getEmail()const
{
	return email;
}

string Paciente::getSecuencia()const
{
	return secuencia;
}

vector<Enfermedad*>* Paciente::getLista()const
{
	return listaEnfermedades;
}

Paciente::~Paciente()
{
	
}

void Paciente::setID(string x)
{
	this->id = x;
}

void Paciente::setNombre(string x)
{
	this->nombre = x;
}

void Paciente::setTelefono(string x)
{
	this->telefono = x;
}

void Paciente::setEmail(string x)
{
	this->email = x;
}

void Paciente::setSecuencia(string x)
{
	this->secuencia = x;
}

void Paciente::setLista(vector<Enfermedad*>* h)
{
	listaEnfermedades = h;
}

string Paciente::toString()
{
	stringstream s;
	s << endl<<"-------------------------------------------------------------------------" << endl;
	s << "   ID: " << id << "     NOMBRE: " << nombre
		<<endl <<"   TELEFONO: " << telefono << "     EMAIL: " << email<<endl;
	s << "-------------------------------------------------------------------------" << endl;
		s<< "          LISTA DE ENFERMEDADES: " << endl
		<< "-------------------------------------------------------------------------"<< endl;
	for (auto& enfer : *listaEnfermedades)
	{
		s << enfer->toString() << endl;
	}
	s <<endl;

	

	return s.str();
}

string Paciente::miniString()
{
	stringstream s;

	s << "   ID: " << id << "     Nombre: " << nombre << endl;


	return s.str();
}

void Paciente::calculador()
{
	float A=cuenta("A");
	float C = cuenta("C");
	float G = cuenta("G");
	float T = cuenta("T");

	float total = A + C + G + T;

	cout << "	La concentración de cada base nitrogenada de: " << nombre << ":\n"
		<< "	A: " << (A / total) * 100 << "%" << endl
		<< "	C: " << (C / total) * 100 << "%" << endl
		<< "	G: " << (G / total) * 100 << "%" << endl
		<< "	T: " << (T / total) * 100 << "%" << endl;
}

float Paciente::cuenta(string x)
{
	
	float resultado = 0;
		for (auto posicion = secuencia.find(x);
			posicion != std::string::npos;
			posicion = secuencia.find(x, posicion + 1))
		{
			++resultado;
		}

		return resultado;
	
}

void Paciente::agregarLista(vector<Enfermedad*> enfe)
{
	for (int i = 0; i < enfe.size(); i++)
	{
		if (buscador(enfe[i]->getSecuencia()))
			listaEnfermedades->push_back(enfe[i]);
	}

}

void Paciente::probabilizador()
{
	
	cout << miniString()<<endl;
	
	if (listaEnfermedades->size() <= 1)
	{
		cout << "	La probalididad de enfermarse de: " << endl;
		for (auto& m : *listaEnfermedades)
			cout << m->toString();
		cout <<"	Es de 0% " << endl<<endl;
		cout << "	***************************** " << endl << endl;
	}
	else
		if (listaEnfermedades->size() == 2)
		{
			cout << "	La probalididad de enfermarse de: " << endl;
			for (auto& m : *listaEnfermedades)
				cout << m->toString();
			cout << "	Es de 35% " << endl << endl;
			cout << "	***************************** " << endl << endl;
		}
		else
			if (listaEnfermedades->size() >= 3)
			{
				cout << "	La probalididad de enfermarse de: " << endl;
				for (auto& m : *listaEnfermedades)
					cout << m->toString();
				cout << "	Es de 65% " << endl << endl;
				cout << "	***************************** " << endl << endl;
			}



}

bool Paciente::buscador(string x)
{
	auto it = secuencia.find(x);

	if (it != string::npos)
		return true;
	else
		return false;
}
