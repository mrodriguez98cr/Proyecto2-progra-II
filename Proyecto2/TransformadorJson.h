#pragma once
#include"lib/json.hpp"
#include "Modelo.h"
#include "Enfermedad.h"
using nlohmann::json;

void to_json(json& j, const Pacientej& paciente)
{
	json enfermedadesJson = json::array();

	for (auto& enfe : *paciente.listaEnfermedades)
	{
		json enfeJson = *enfe;
		enfermedadesJson.push_back(enfeJson);
	}

	//j = json{ {"id", paciente.id}, {"nombre", paciente.nombre}, {"direcciones", direccionesJson} };
}

void from_json(const json& j, Pacientej& paciente)
{
	paciente.id = j.at("id").get<string>();
	paciente.nombre = j.at("nombre").get<string>();
	paciente.telefono = j.at("telefono").get<string>();
	paciente.email = j.at("email").get<string>();
	paciente.secuencia = j.at("secuencia").get<string>();

	json arregloDireccionesJson = j.at("direcciones");

	vector<Enfermedad*>* le = new vector<Enfermedad*>();
	for (auto& objetoenferJson : arregloDireccionesJson)
	{
		Enfermedad* enfermedad = new Enfermedad();
		*enfermedad = objetoenferJson;
		le->push_back(enfermedad);
	}
	paciente.listaEnfermedades = le;

}




/*paciente.id = j.at("id").get<string>();
paciente.nombre = j.at("nombre").get<string>();
paciente.telefono = j.at("telefono").get<string>();
paciente.email = j.at("email").get<string>();
paciente.secuencia = j.at("secuencia").get<string>();*/