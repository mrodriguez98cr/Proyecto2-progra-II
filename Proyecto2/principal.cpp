#include "Enfermedad.h"
#include "Paciente.h"

int main()
{
	Paciente* p = new Paciente("117110640", "Marco Rodriguez", "8914-5640", "davidcr98@gmail.com", "AGAGAG");
	Enfermedad* e = new Enfermedad("Cagadera", " caca");
	
	cout << p->toString() << endl;
	cout << e->toString() << endl;

	system("pause");

	delete p;
	delete e;

	return 0;

}