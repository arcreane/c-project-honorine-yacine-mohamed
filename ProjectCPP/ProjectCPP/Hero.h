#pragma once
#include "Personnage.h";
#include "Item.h";
#include<iostream>
#include "Piece.h";
#include <vector>
#include "raylib.h";
#include "Potion.h";
#include "Antagoniste.h";


class Hero : public Personnage {
private:
	int score;
	std::vector<Piece> coinsList;

public:
	Hero(string nom, int vie, int score)
		:Personnage(nom, vie)
		, score{ score }
		, coinsList{ NULL }
	{
		setImageRun(LoadImage("resources/hero_run.png"));
		setImageAttack(LoadImage("resources/hero_attack.png"));
		setImageIdle(LoadImage("resources/hero_idle.png"));
	};
	//getteur et setteurs
	int getScore() const;
	void setScore(int s);

	const std::vector<Piece> getCoinsList() const;
	void setCoinsList(const std::vector<Piece>& coinsList);
	void initCoinsList();

	int getnbCoins() const;

	//methodes
	void getItem(Item i);
	void getCoin(Piece p);
	void getPotion(Potion p);

	void runleft() override {
		cout << "JE SUIS UN HERO ET JE MARCHE VERS LA GAUCHE " << std::endl;
		this->setrun(true);
		this->setidle(false);
		this->setattack(false);
		this->setSide(-1);
	}
	void runright() override {
		cout << "JE SUIS UN HERO ET JE MARCHE VERS LA DROITE " << std::endl;
		this->setrun(true);
		this->setidle(false);
		this->setattack(false);
		this->setSide(1);
	};

	void notmove() override {
		cout << "JE SUIS IMMOBILE " << std::endl;
		run = false;
		attack = false;
		idle = true;
	};

	void attaque() override {           
		cout << "JE SUIS UN HERO ET J'ATTAQUE" << std::endl;
		this->setrun(false);
		this->setidle(false);
		this->setattack(true);
	}

	void attaque(Personnage h) override {   //quand un héro attaque un monstre il meurt sur le coup => sa vie passe à 0
		cout << "JE SUIS UN HERO ET J'ATTAQUE LE MONSTRE :" << h.getNom() << std::endl;
		h.setVie(0);
	}

};