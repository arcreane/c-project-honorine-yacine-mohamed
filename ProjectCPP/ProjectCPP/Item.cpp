#include "Item.h"

Item::Item() :Item("sans nom") {
}

Item::Item(string nom)
	: nom{ nom }
{
}

Item::Item(string nom, Rectangle r)
{
	nom = nom;
	rect = r;
}

string Item::getNom()const
{
	return (nom);
}


void Item::setNom(string n)
{
	nom = n;
}

Rectangle Item::getRectangle() const
{
	return rect;
}

void Item::setRectangle(Rectangle r)
{
	rect = r;
}

int Item::getPosX() const
{
	return position_x;
}

int Item::getPosY() const
{
	return position_y;
}

void Item::setPosX(int x)
{
	position_x = x;
}

void Item::setPosY(int y)
{
	position_y = y;
}

void Item::setPos(Vector2 v)
{
	pos = v;
}

Vector2 Item::getPos() const
{
	return pos;
}

Texture2D Item::getModel()
{
	return LoadTextureFromImage(this->getImage());
}

void Item::setModel(Texture2D m)
{
	model = m;
}
void Item::setImage(Image ic)
{
	i = ic;
}

Image Item::getImage()
{
	return i;
}

bool Item::getActive()
{
	return active;
}

void Item::setActive(bool s)
{
	active = s;
}