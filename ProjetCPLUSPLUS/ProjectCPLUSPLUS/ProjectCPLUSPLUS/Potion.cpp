#include "Potion.h";

int Potion::getNombre() const
{
	return nombre;
}

void Potion::setNombre(int n)
{
	nombre = n;
}

string Potion::getType() const
{
	return type;
}

void Potion::setType(string type)
{
	type = type;
}
