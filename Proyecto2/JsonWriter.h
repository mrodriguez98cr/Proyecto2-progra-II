#pragma once
#include<fstream>
#include"lib/json.hpp"
#include"IWriter.h"
#include"TransformadorJson.h"
using nlohmann::json;

template<class T>
class JsonWriter : public IWriter<T>
{
private:
	string rutaArchivo;
	json modeloJson;

public:

	JsonWriter(string rutaArchivo) : modeloJson(json::array())
	{
		this->rutaArchivo = rutaArchivo;
	}

	void escribir(T elemento) override // T&
	{
		json elementoJson = elemento;
		this->modeloJson.push_back(elementoJson);
	}

	void escribirTodos(vector<T> *elementos) override
	{
		for (auto& actual : *elementos)
		{
			this->escribir(actual);
		}
	}

	void cerrar() 
	{
		ofstream salida;
		salida.open(rutaArchivo, ios::out);
		if (!salida.good())
		{
			throw invalid_argument("Ruta del archivo no es valida o no hay permisos.");
		}
		salida << modeloJson;
	}

	~JsonWriter()
	{
		this->cerrar();
	}
};