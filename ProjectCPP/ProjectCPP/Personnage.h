#pragma once
// Personnage.h

#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <string>
#include <raylib.h>
using namespace std;


class Personnage
{
private:
	string nom; //name
	int vie;    //life
	int position_x;  //position
	int position_y;
	Texture2D model;
	Rectangle rec;
	int facingLeft;
	Image imageAttack;
	Image imageRun;
	Image imageIdle;
	Vector2 pos;



	string image; //image de personnage debout

protected:
	bool attack;
	bool run;
	bool idle; // etre immobile

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

	bool getrun() const;
	bool getattack() const;
	bool getidle() const;

	void setrun(bool b);
	void setattack(bool b);
	void setidle(bool b);

	Texture2D getModel() const;
	void setModel(Texture2D m);

	Rectangle getRect() const;
	void setRect(Rectangle r);

	void setSide(int s);
	int getSide() const;

	void setImageAttack(Image ia);
	void setImageRun(Image ir);
	void setImageIdle(Image ii);

	Image getImageAttack();
	Image getImageRun();
	Image getImageIdle();

	Texture2D getTexture2DAttack();
	Texture2D getTexture2DRun();
	Texture2D getTexture2DIdle();

	void setPos(Vector2 v);
	Vector2 getPos() const;


	//Autres methodes
	virtual void attaque() { cout << "J'ATTAQUE"; };
	virtual void attaque(Personnage p) { cout << "J'attaque" << p; };


	//fonction virtuelle pure
	virtual void runleft() { cout << "JE MARCHE VERS LA GAUCHE"; }
	virtual void runright() { cout << "JE MARCHE VERS LA DROITE"; }
	virtual void notmove() { cout << "JE SUIS IMMOBILE"; }

	//fonctions friends 
	// An overloaded operator<<, allowing us to print a pair via cout<<

	friend std::ostream& operator<<(std::ostream& out, const Personnage& p);

	template<typename Base, typename T>
	inline bool instanceof(const T*) {
		return std::is_base_of<Base, T>::value;
	}
};


#endif
