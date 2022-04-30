#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <raylib.h>
using namespace std;


class Item
{
private:
	string nom;
	Rectangle rect;
	int position_x;  //position
	int position_y;
	Texture2D model;
	Vector2 pos;
	bool active;
	Image i;


public:
	//Constructeurs
	Item();
	Item(string nom);

	Item(string nom, Rectangle r);

	//Destructeurs
	//~Item();

	//getteur et setteurs
	string getNom() const;
	void setNom(string n);

	Rectangle getRectangle() const;
	void setRectangle(Rectangle r);

	int getPosX() const;
	int getPosY() const;
	void setPosX(int x);
	void setPosY(int y);

	void setPos(Vector2 v);
	Vector2 getPos() const;


	Texture2D getModel();
	void setModel(Texture2D m);

	void setImage(Image ic);
	Image getImage();

	void setActive(bool s);
	bool getActive();



	template<typename Base, typename T>
	inline bool instanceof(const T*) {
		return std::is_base_of<Base, T>::value;
	}

};

#endif