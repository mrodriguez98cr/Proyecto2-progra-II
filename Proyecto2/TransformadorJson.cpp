#include "TransformadorJson.h"

void to_json(json& j, const Enfermedad& enfermedad)
{
	j = json{ {"nombre", enfermedad.getNombre()}, {"secuencia", enfermedad.getSecuencia()} };
}


void to_json(json& j, const Paciente& paciente)
{
	json EnfermedadesJson = json::array();

	for (auto enfermedad : *(paciente.getLista()))
	{
		json EnfermedadJson = *enfermedad;
		EnfermedadesJson.push_back(EnfermedadJson);
	}

	j = json{ {"id", paciente.getID()}, {"nombre", paciente.getNombre()},{"telefono", paciente.getTelefono()},{"email", paciente.getEmail()},{"secuencia", paciente.getSecuencia()}, {"enfermedades", EnfermedadesJson} };
}


void from_json(const json& j, Enfermedad& paciente)
{
	paciente.setNombre(j.at("nombre").get<string>());
	paciente.setSecuencia(j.at("secuencia").get<string>());

}

void from_json(const json& j, Paciente& paciente)
{
	paciente.setID(j.at("id").get<string>());
	paciente.setNombre(j.at("nombre").get<string>());
	paciente.setTelefono(j.at("telefono").get<string>());
	paciente.setEmail(j.at("email").get<string>());
	paciente.setSecuencia(j.at("secuencia").get<string>());
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