#pragma once
#include "Antagoniste.h";
#include "Potion.h";

class Sorciere : public Antagoniste {
public:
	void voler();

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