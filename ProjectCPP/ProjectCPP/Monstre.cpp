#include "Monstre.h";

void Monstre::jump()  
{
	//a coder
}

void Monstre::oneshot(Hero &h)  //quand un monstre oneshot le hero meurt instantanément.
{
	cout << "JE VIENS DE ONE SHOT LE HERO" << std::endl;
	h.setVie(0);
}

