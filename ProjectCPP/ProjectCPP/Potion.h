#pragma once
#include "Item.h";

class Potion : public Item {
private:
	int nombre;
public:
	Potion(string nom, int nb)
		:Item(nom)
		, nombre{ nb }{
		setImage(LoadImage("resources/potion1.png"));
	};
	int getNombre() const;
	void setNombre(int n);
};