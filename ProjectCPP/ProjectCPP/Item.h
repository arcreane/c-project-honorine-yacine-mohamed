#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;


class Item
{
private:
	string nom;
public:
	//Constructeurs
	Item();
	Item(string nom);

	//Destructeurs
	//~Item();

	//getteur et setteurs
	string getNom() const;
	void setNom(string n);

};

#endif