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

	string image; //image de personnage debout

protected:
	bool attack;
	bool run;
	bool idle; // etre immobile
	int facingLeft = 1;


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

	int getFacingLeft() const;
	void setFacingLeft(int fc);

	bool getrun() const;
	bool getattack() const;
	bool getidle() const;

	void setrun(bool b);
	void setattack(bool b);
	void setidle(bool b);

	//Autres methodes
	virtual void attaque() { cout << "J'ATTAQUE"; };


	//fonction virtuelle pure
	virtual void runleft() { cout << "JE MARCHE VERS LA GAUCHE"; }
	virtual void runright() { cout << "JE MARCHE VERS LA DROITE"; }
	virtual void notmove() { cout << "JE SUIS IMMOBILE"; }

	//fonctions friends 
	// An overloaded operator<<, allowing us to print a pair via cout<<

	friend std::ostream& operator<<(std::ostream& out, const Personnage& p);
};


#endif
