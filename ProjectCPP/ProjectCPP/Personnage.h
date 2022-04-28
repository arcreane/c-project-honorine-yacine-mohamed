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
	int position_x;  //position
	int position_y;


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

	int getPosX() const;
	int getPosY() const;
	void setPosX(int x);
	void setPosY(int y);

	//Autres methodes
	void attaque(Personnage antagoniste);
	void attaque();

	//fonctions friends 
	// An overloaded operator<<, allowing us to print a pair via cout<<

	friend std::ostream& operator<<(std::ostream& out, const Personnage& p);
};


#endif
