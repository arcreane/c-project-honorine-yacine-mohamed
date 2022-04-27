#include "Item.h"

Item::Item() :Item("sans nom"){
}

Item::Item(string nom)
	:nom{ nom }
{
}

string Item::getNom()const
{
	return (nom);
}


void Item::setNom(string n)
{
	nom = n;
}
