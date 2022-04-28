#pragma once

#include "Personnage.h";
#include "Hero.h";
#include "raylib.h";

class Antagoniste : public Personnage {
private:
	int recompense; //reward
	Rectangle rec;
	bool active;
	Vector2 pos;
	int facingLeft;
public:
	Antagoniste(string nom, int vie, int recompense)
		:Personnage(nom, vie)
		, recompense{ recompense }{

	};
	//getteur et setteurs
	int getRecompense() const;
	void setRecompense(int r);

	Rectangle getRect() const;
	bool getActive() const;
	Vector2 getPos() const;
	int getSide() const;

	void setRect(Rectangle r);
	void setActive(bool a);
	void setPos(Vector2 v);
	void setSide(int s);


	void runleft() override {
		cout << "JE SUIS UN ME ET JE MARCHE VERS LA GAUCHE" << std::endl;
	}
	void runright() override {
		cout << "JE SUIS UN ME ET JE MARCHE VERS LA DROITE" << std::endl;
	};


	//methodes
	void oneShot(Hero hero);

};