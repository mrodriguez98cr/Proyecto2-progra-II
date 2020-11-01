#pragma once
#include"lib/json.hpp"
#include "Paciente.h"
#include "Enfermedad.h"
using nlohmann::json;

void to_json(json& j, const Enfermedad& enfermedad);
void to_json(json& j, const Paciente& paciente);
void from_json(const json& j, Enfermedad& paciente);
void from_json(const json& j, Paciente& paciente);


