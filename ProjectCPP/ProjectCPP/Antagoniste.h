#pragma once

#include "Personnage.h";
#include "Hero.h";
#include "raylib.h";

class Antagoniste : public Personnage {
private:
	int recompense; //reward
	bool active;
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

	Rectangle getDamageRect() const;
	int getDamage() const;

	void setActive(bool a);

	void setDamageRect(Rectangle r);
	void setDamage(int s);

	void runleft() override {
		cout << "JE SUIS UN ME ET JE MARCHE VERS LA GAUCHE" << std::endl;
	}
	void runright() override {
		cout << "JE SUIS UN ME ET JE MARCHE VERS LA DROITE" << std::endl;
	};

	void attaque() override {
		cout << "JE SUIS UN ME ET J'ATTAQUE" << std::endl;
	}

	void attaque(Personnage h) override {  //quand un antagoniste attaque un hero on lui enl�ve de la vie.
		h.setVie(h.getVie() - this->getDamage());
	}

};