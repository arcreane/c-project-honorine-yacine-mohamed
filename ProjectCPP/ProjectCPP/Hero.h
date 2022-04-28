#pragma once
#include "Personnage.h";
#include "Item.h";

class Hero : public Personnage {
private:
	int speed;
	int score;
	int money;
	int strength;
	int position_x;  //position
	int position_y;


public:
	Hero(string nom, int vie, int speed, int score, int money, int strength)
		:Personnage(nom, vie)
		, speed{ speed }
		, score{ score }
		, money{ money }
		, strength{ strength }{

	};
	//getteur et setteurs
	int getSpeed() const;
	int getScore() const;
	int getMoney() const;
	int getStrength() const;
	int getPosX() const;
	int getPosY() const;

	void setSpeed(int s);
	void setScore(int s);
	void setMoney(int m);
	void setStrength(int s);
	void setPosX(int x);
	void setPosY(int y);

	//methodes
	void getItem(Item i);
	void move(); //avec x et y ?

};