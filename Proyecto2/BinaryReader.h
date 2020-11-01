#pragma once
#include<fstream>
#include"IReader.h"
#include"TransformadorBinario.h"

template<class T>
class BinaryReader : public IReader<T>
{
private:
	fstream entrada;
	ITransformadorBinario<T>* transformadorBinario;

public:
	BinaryReader(string rutaArchivo, ITransformadorBinario<T>* transformadorBinario)
	{
		this->transformadorBinario = transformadorBinario;
		this->entrada.open(rutaArchivo, ios::in | ios::binary);
		if (!entrada.good())
		{
			throw invalid_argument("Ruta del archivo no es valida o no hay permisos.");
		}
	}

	vector<T>* leerTodos()
	{
		vector<T>* objetos = new vector<T>();
		while (this->entrada.peek() != EOF)
		{
			objetos->push_back(this->transformadorBinario->deserializar(this->entrada));
		}
		return objetos;
	}

	void cerrar() override
	{
		this->entrada.close();
	}

	~BinaryReader()
	{
		this->entrada.close();
		delete this->transformadorBinario;
	}
};