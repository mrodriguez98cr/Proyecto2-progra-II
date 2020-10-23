#pragma once
#include<vector>
#include<string>
#include"Paciente.h"
#include <iostream>
#include "Enfermedad.h"

using namespace std;

template<class T>
class ITransformadorCsv
{
public:
	virtual vector<string>* toStringVector(T elemento) = 0;
	virtual T fromStringVector(vector<string>* vector) = 0;
	virtual ~ITransformadorCsv() = default;
};

class TransformadorCsvPaciente : public ITransformadorCsv<Paciente*>
{
public:
	vector<string>* toStringVector(Paciente* elemento) override
	{
		vector<string>* campos = new vector<string>();
		campos->push_back(elemento->getID());
		campos->push_back(elemento->getNombre());
		campos->push_back(elemento->getTelefono());
		campos->push_back(elemento->getEmail());
		campos->push_back(elemento->getSecuencia());
		return campos;
	}

	Paciente* fromStringVector(vector<string>* vector) override
	{
		return new Paciente(vector->at(0), vector->at(1), vector->at(2), vector->at(3), vector->at(4));
	}
};


class TransformadorCsvEnfermedad : public ITransformadorCsv<Enfermedad*>
{
public:
	vector<string>* toStringVector(Enfermedad* elemento) override
	{
		vector<string>* campos = new vector<string>();
		campos->push_back(elemento->getNombre());
		campos->push_back(elemento->getSecuencia());
	
		return campos;
	}

	Enfermedad* fromStringVector(vector<string>* vector) override
	{
		return new Enfermedad(vector->at(0), vector->at(1));
	}
};
