#pragma once
#include<iostream>
#include"Enfermedad.h"
#include"Paciente.h"

template<class T>
class ITransformadorBinario
{
public:
	virtual void serializar(T elemento, ostream& out) = 0;
	virtual T deserializar(istream& in) = 0;
	virtual ~ITransformadorBinario() = default;
};

class TransformadorBinarioEnfermedad : public ITransformadorBinario<Enfermedad*>
{
public:
	void serializar(Enfermedad* elemento, ostream& out) override
	{
		out.write(reinterpret_cast<char*>(elemento), sizeof(Enfermedad));
	}

	Enfermedad* deserializar(istream& in) override
	{
		Enfermedad* nuevaEnfermedad = new Enfermedad();
		in.read(reinterpret_cast<char*>(nuevaEnfermedad), sizeof(Enfermedad));
		return nuevaEnfermedad;
	}
};

class TransformadorBinarioString : public ITransformadorBinario<string>
{
public:
	void serializar(string elemento, ostream& out) override
	{
		size_t largoString = elemento.length() + 1;
		out.write(reinterpret_cast<char*>(&largoString), sizeof(size_t));
		out.write(elemento.c_str(), (std::streamsize)largoString);
		if (!out.good())
			throw ios_base::failure("Error serializando string...");
	}

	string deserializar(istream& in) override
	{
		string nuevoString;
		size_t largoString = 0;

		in.read(reinterpret_cast<char*>(&largoString), sizeof(size_t));

		char* caracteres = new char[largoString];
		in.read(caracteres, (std::streamsize)largoString);
		nuevoString = string(caracteres);
		delete[] caracteres;

		if (!in.good())
			throw ios_base::failure("Error deserializando string...");

		return nuevoString;
	}
};

template<class T>
class TransformadorBinarioVector : public ITransformadorBinario<vector<T>*>
{
private:
	ITransformadorBinario<T>* transformadorT;

public:
	TransformadorBinarioVector(ITransformadorBinario<T>* transformadorT)
	{
		this->transformadorT = transformadorT;
	}

	void serializar(vector<T>* coleccion, ostream& out) override
	{
		int cantidadElementos = coleccion->size();
		out.write(reinterpret_cast<char*>(&cantidadElementos), sizeof(int));
		for (auto& item : *coleccion)
		{
			this->transformadorT->serializar(item, out);
		}
	}

	vector<T>* deserializar(istream& in) override
	{
		vector<T>* nuevoVector = new vector<T>();
		int cantidadElementos = 0;
		in.read(reinterpret_cast<char*>(&cantidadElementos), sizeof(int));
		for (int i = 0; i < cantidadElementos; i++)
		{
			nuevoVector->push_back(this->transformadorT->deserializar(in));
		}

		return nuevoVector;
	}

	~TransformadorBinarioVector()
	{
		delete transformadorT;
	}
};


class TransformadorBinarioPaciente : public ITransformadorBinario<Paciente*>
{
private:
	TransformadorBinarioVector<Enfermedad*> transformadorEnfermedades;
	TransformadorBinarioString transformadorString;

public:
	TransformadorBinarioPaciente() : transformadorEnfermedades(new TransformadorBinarioEnfermedad()){

	}

	void serializar(Paciente* elemento, ostream& out) override
	{
		this->transformadorString.serializar(elemento->id, out);
		this->transformadorString.serializar(elemento->nombre, out);
		this->transformadorString.serializar(elemento->telefono, out);
		this->transformadorString.serializar(elemento->email, out);
		this->transformadorString.serializar(elemento->secuencia, out);
	    this->transformadorEnfermedades.serializar(elemento->listaEnfermedades, out);
	}

	Paciente* deserializar(istream& in) override
	{
		string id = this->transformadorString.deserializar(in);
		string nombre = this->transformadorString.deserializar(in);
		string telefono = this->transformadorString.deserializar(in);
		string email = this->transformadorString.deserializar(in);
		string secuencia = this->transformadorString.deserializar(in);
		vector<Enfermedad*>* enfermedades = this->transformadorEnfermedades.deserializar(in);
		Paciente* paciente = new Paciente(id, nombre, telefono, email, secuencia);
		paciente->setLista(enfermedades);
		return paciente;
	}
};