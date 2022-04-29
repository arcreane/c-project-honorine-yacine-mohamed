#include "Antagoniste.h";
#include "Hero.h"

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

//void Antagoniste::oneShot(Hero h)
//{
//	// ecrire la fonction oneshot
//}

bool Antagoniste::getActive() const {
	return active;
}


Rectangle Antagoniste::getDamageRect() const
{
	return damageRec;
}

Vector2 Antagoniste::getPos() const
{
	return pos;
}

void Antagoniste::setDamageRect(Rectangle r)
{
	damageRec = r;
}

void Antagoniste::setPos(Vector2 p)
{
	pos = p;
}

void Antagoniste::setActive(bool r)
{
	active = r;
}

void Antagoniste::oneShot(Hero hero)
{
}
