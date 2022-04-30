#include "Antagoniste.h";
#include "Hero.h"
class Hero;

int Antagoniste::getRecompense() const
{
	return recompense;
}

void Antagoniste::setRecompense(int r)
{
	recompense = r;
}

int Antagoniste::getDamage() const
{
	return damage;
}

void Antagoniste::setDamage(int r)
{
	damage = r;
}

void Antagoniste::giveRecompense(Hero h){
	cout << "HELLEOO" << std::endl;
	//h.setScore(h.getScore() + this->getRecompense());

}

bool Antagoniste::getActive() const {
	return active;
}


Rectangle Antagoniste::getDamageRect() const
{
	return damageRec;
}


void Antagoniste::setDamageRect(Rectangle r)
{
	damageRec = r;
}


void Antagoniste::setActive(bool r)
{
	active = r;
}

