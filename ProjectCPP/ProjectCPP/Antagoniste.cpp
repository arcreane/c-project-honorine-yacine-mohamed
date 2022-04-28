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

//void Antagoniste::oneShot(Hero h)
//{
//	// ecrire la fonction oneshot
//}

bool Antagoniste::getActive() const {
	return active;
}

Rectangle Antagoniste::getRect() const
{
	return rec;
}

Vector2 Antagoniste::getPos() const
{
	return pos;
}

int Antagoniste::getSide() const
{
	return facingLeft;
}

void Antagoniste::setRect(Rectangle r)
{
	rec = r;
}

void Antagoniste::setPos(Vector2 p)
{
	pos = p;
}

void Antagoniste::setActive(bool r)
{
	active = r;
}

void Antagoniste::setSide(int r)
{
	facingLeft = r;
}

void Antagoniste::oneShot(Hero hero)
{
}
