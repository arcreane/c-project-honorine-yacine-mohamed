#pragma once
#include "Antagoniste.h";
#include "Potion.h";

class Sorciere : public Antagoniste {
public: 
	void givePotion(Potion p);
};