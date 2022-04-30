#pragma once
#include "Antagoniste.h";

class Monstre : public Antagoniste {
public:
	//methodes
	void jump();
	void oneshot(Hero h);

	void runleft() override {
		cout << "JE SUIS UN Monstre ET JE MARCHE VERS LA GAUCHE " << std::endl;
	}
	void runright() override {
		cout << "JE SUIS UN Monstre ET JE MARCHE VERS LA DROITE " << std::endl;
	};
	void attaque() override {
		cout << "JE SUIS UN Monstre ET J'ATTAQUE" << std::endl;
	}
};