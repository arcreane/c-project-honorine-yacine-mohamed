#pragma once
#include "Personnage.h";
#include "Item.h";
#include<iostream>
#include "Piece.h";
#include <vector>
#include "raylib.h";

class Hero : public Personnage {
private:
	int speed;
	int score;
	int strength;
	std::vector<Piece> coinsList;

public:
	Hero(string nom, int vie, int speed, int score, int strength)
		:Personnage(nom, vie)
		, speed{ speed }
		, score{ score }
		, strength{ strength }
		, coinsList{ NULL }
	{
		setImageRun(LoadImage("resources/hero_run.png"));
		setImageAttack(LoadImage("resources/hero_attack.png"));
		setImageIdle(LoadImage("resources/hero_idle.png"));
	};
	//getteur et setteurs
	int getSpeed() const;
	int getScore() const;
	int getStrength() const;

	void setSpeed(int s);
	void setScore(int s);
	void setStrength(int s);

	const std::vector<Piece> getCoinsList() const;
	void setCoinsList(const std::vector<Piece>& coinsList);
	void initCoinsList();

	int getnbCoins() const;

	//methodes
	void getItem(Item i);


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

	//void run();
	//void jump();
};