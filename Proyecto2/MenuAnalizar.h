#pragma once
#include <iostream>
#include <sstream>
#include <vector>


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
	void leer();
	void analisisUno();
	void analisisdos();
	void analisistres();
};
