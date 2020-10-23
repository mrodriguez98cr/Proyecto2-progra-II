#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class MenuAnalizar
{
private:
	char mostrarOpciones();
	string logo();

public:
	MenuAnalizar();
	void invocarMenu();
	~MenuAnalizar();
};
