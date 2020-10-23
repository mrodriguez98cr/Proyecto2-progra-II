#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class MenuCarga
{
private:
	char mostrarOpciones();
	string logo();

public:
	MenuCarga();
	void invocarMenu();
	~MenuCarga();
};

