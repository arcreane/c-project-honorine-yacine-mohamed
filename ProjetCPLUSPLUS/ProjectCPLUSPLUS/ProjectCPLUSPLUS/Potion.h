#pragma once
#include "Item.h";

class Potion : public Item {
private:
	int nombre;
	string type;  //heal or speed it can be bool
public:
	Potion(string nom, int nb, string type)
		:Item(nom)
		, nombre{ nb }
		, type(type){
	};
	//getteur et setteurs
	int getNombre() const;
	void setNombre(int n);
	string getType() const;
	void setType(string type);
};