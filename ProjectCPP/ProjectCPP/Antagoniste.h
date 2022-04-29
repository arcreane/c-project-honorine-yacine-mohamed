#pragma once

#include "Personnage.h";
#include "Hero.h";
#include "raylib.h";

class Antagoniste : public Personnage {
private:
	int recompense; //reward
	bool active;
	Vector2 pos;
	Rectangle damageRec;
	int damage;

public:
	Antagoniste(string nom, int vie, int recompense)
		:Personnage(nom, vie)
		, recompense{ recompense }{

	};
	//getteur et setteurs
	int getRecompense() const;
	void setRecompense(int r);

	bool getActive() const;
	Vector2 getPos() const;

	Rectangle getDamageRect() const;
	int getDamage() const;

	void setActive(bool a);
	void setPos(Vector2 v);
	void setDamageRect(Rectangle r);
	void setDamage(int s);

	void runleft() override {
		cout << "JE SUIS UN ME ET JE MARCHE VERS LA GAUCHE" << std::endl;
	}
	void runright() override {
		cout << "JE SUIS UN ME ET JE MARCHE VERS LA DROITE" << std::endl;
	};


	//methodes
	void oneShot(Hero hero);

};