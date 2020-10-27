#pragma once

#pragma once
#include<fstream>
#include"lib/json.hpp"
#include"IReader.h"
#include"TransformadorJson.h"
using nlohmann::json;

template<class T>
class JsonReader : public IReader<T>
{
private:
	fstream entrada;

public:
	JsonReader(string rutaArchivo)
	{
		this->entrada.open(rutaArchivo, ios::in);
		if (!entrada.good())
		{
			throw invalid_argument("Ruta del archivo no es valida o no hay permisos.");
		}
	}

	vector<T>* leerTodos()
	{
		json modeloJson;
		this->entrada >> modeloJson;
		vector<T>* objetos = new vector<T>();
		*objetos = modeloJson.get<vector<T>>();
		return objetos;
	}

	void cerrar() override
	{
		this->entrada.close();
	}

	~JsonReader()
	{
		this->entrada.close();
	}
};
