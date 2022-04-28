#include "Personnage.h"

Personnage::Personnage() :Personnage("sans nom", 10)
{

}

Personnage::Personnage(string nom, int vie)
	: nom{ nom }
	, vie{ vie }
{
}

Personnage::~Personnage()
{
}

string Personnage::getNom()const
{
	return (nom);
}

int Personnage::getVie()const
{
	return (vie);
}


void Personnage::setNom(string n)
{
	nom = n;
}

void Personnage::setVie(int v)
{
	vie = v;
}

void Personnage::attaque(Personnage antagoniste)
{
	// ecrire le code d'attaque
}

void Personnage::attaque()
{
	//ecrire le code pour attaquer.
}

std::ostream& operator<<(std::ostream& out, const Personnage& p)
{
	out << "Mon nom est  : " << p.nom << "Ma vie est de : " << p.vie << std::endl;

	return out;
}
