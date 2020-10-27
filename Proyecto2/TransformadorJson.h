#pragma once
#include"lib/json.hpp"
#include "Paciente.h"
using nlohmann::json;


void to_json(json& j,  Paciente& paciente)
{
	json enfermedadesJson = json::array();

	for (auto& enfermedad : *paciente.getLista())  //ni idea
	{
		json EnfermedadJson = *enfermedad;
		enfermedadesJson.push_back(EnfermedadJson);
	}

	j = json{ {"id", paciente.getID()}, {"nombre", paciente.getNombre()},{"telefono", paciente.getTelefono()},{"email", paciente.getEmail()},{"secuencia", paciente.getSecuencia()}, {"enfermedades", enfermedadesJson} };
}


void from_json(const json& j, Paciente& paciente)
{
	paciente.setID(j.at("id").get<string>());
	paciente.setNombre(j.at("nombre").get<string>());
	paciente.setTelefono(j.at("telefono").get<string>());
	paciente.setEmail(j.at("email").get<string>());
	json arregloEnfermedadesJson = j.at("enfermedades");

	vector<Enfermedad*>* listaEnfermedades = new vector<Enfermedad*>();
	for (auto& objetoenfermedadJson : arregloEnfermedadesJson)
	{
		Enfermedad* enfermedad = new Enfermedad();
		*enfermedad = objetoenfermedadJson;
		listaEnfermedades->push_back(enfermedad);
	}
	paciente.setLista(listaEnfermedades);

}



/*paciente.id = j.at("id").get<string>();
paciente.nombre = j.at("nombre").get<string>();
paciente.telefono = j.at("telefono").get<string>();
paciente.email = j.at("email").get<string>();
paciente.secuencia = j.at("secuencia").get<string>();*/