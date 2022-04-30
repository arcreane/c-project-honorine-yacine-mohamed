#pragma once
#include "Item.h";

class Potion : public Item {
private:
	int nombre;
public:
	Potion(string nom, int nb, string type)
		:Item(nom)
		, nombre{ nb }{
	};
	//getteur et setteurs
	int getNombre() const;
	void setNombre(int n);
};