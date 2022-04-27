#pragma once
// Personnage.h

#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <string>
using namespace std;


class Personnage
{
private:
	string nom; //name
	int vie;    //life


public:
	//Constructeurs
	Personnage();
	Personnage(string nom, int vie); 

	//Destructeurs
	~Personnage();

	//Guetter et Setteurs 
	string getNom() const;
	int getVie() const;
	void setNom(string n);
	void setVie(int v);

	//Autres methodes
	void attaque(Personnage antagoniste);

	//fonctions friends 
	// An overloaded operator<<, allowing us to print a pair via cout<<

	friend std::ostream& operator<<(std::ostream& out, const Personnage & p);
};


#endif
