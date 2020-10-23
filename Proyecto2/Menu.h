#pragma once
#include <iostream>
#include <sstream>
#include "MenuAnalizar.h"
#include "MenuCarga.h"
using namespace std;

class Menu
{
private:
	

	MenuCarga* mc;
	MenuAnalizar* ma;
	char mostrarOpciones();
	string logo();

public:

	Menu(MenuCarga*, MenuAnalizar*);
	void invocarMenu();
	~Menu();
};

