#include "Item.h"

Item::Item() :Item("sans nom") {
}

Item::Item(string nom)
	: nom{ nom }
{
}

Item::Item(string nom, Rectangle r)
{
	nom = nom;
	rect = r;
}

string Item::getNom()const
{
	return (nom);
}


void Item::setNom(string n)
{
	nom = n;
}

Rectangle Item::getRectangle() const
{
	return rect;
}

void Item::setRectangle(Rectangle r)
{
	rect = r;
}
