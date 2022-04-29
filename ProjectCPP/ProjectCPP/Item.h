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


};

#endif