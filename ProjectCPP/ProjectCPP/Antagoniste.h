#pragma once

#include "Personnage.h";
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

	//methodes
	void oneShot(Personnage hero);

};