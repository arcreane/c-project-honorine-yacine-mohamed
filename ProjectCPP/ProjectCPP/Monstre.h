#pragma once
#include "Antagoniste.h";

class Monstre : public Antagoniste {
public:
	//methodes
	Monstre(string nom, int vie, int recompense)
		:Antagoniste(nom, vie, recompense) {
		setImageRun(LoadImage("resources/Monster_walk.png"));
		setImageAttack(LoadImage("resources/Monster_attack.png"));
	};

	void jump();
	void oneshot(Hero& h);

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