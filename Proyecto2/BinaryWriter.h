#pragma once
#include<fstream>
#include"TransformadorBinario.h"
#include"IWriter.h"

template<class T>
class BinaryWriter : public IWriter<T>
{
private:
	fstream salida;
	ITransformadorBinario<T>* transformadorBinario;

public:

	BinaryWriter(string rutaArchivo, ITransformadorBinario<T>* transformadorBinario)
	{
		this->transformadorBinario = transformadorBinario;
		this->salida.open(rutaArchivo, ios::out | ios::binary);
		if (!this->salida.good())
		{
			throw invalid_argument("Ruta del archivo no es valida o no hay permisos.");
		}
	}

	void escribir(T elemento) override 
	{
		this->transformadorBinario->serializar(elemento, this->salida);
	}

	void escribirTodos(vector<T>* elementos) override 
	{
		for (auto& actual : *elementos)
		{
			this->escribir(actual);
		}
	}

	void cerrar() override
	{
		this->salida.close();
	}

	~BinaryWriter()
	{
		this->cerrar();
		delete this->transformadorBinario;
	}
};