#pragma once
#include "Antagoniste.h";
#include "Potion.h";

class Sorciere : public Antagoniste {
public:
	Sorciere(string nom, int vie, int recompense)
		:Antagoniste(nom, vie, recompense) {
		setImageRun(LoadImage("resources/B_witch_run.png"));
		setImageAttack(LoadImage("resources/B_witch_attack.png"));
	};

	void voler(Hero& h); //voler des pieces.

	void runleft() override {
		cout << "JE SUIS UNE SORCIERE ET JE MARCHE VERS LA GAUCHE " << std::endl;
	}
	void runright() override {
		cout << "JE SUIS UNE SORCIERE ET JE MARCHE VERS LA DROITE " << std::endl;
	};
	void attaque() override {
		cout << "JE SUIS UNe sorciere ET J'ATTAQUE" << std::endl;
	}
};