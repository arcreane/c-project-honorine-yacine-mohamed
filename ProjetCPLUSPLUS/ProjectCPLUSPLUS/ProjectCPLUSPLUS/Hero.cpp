#include "Hero.h";

int Hero::getSpeed() const
{
	return speed;
}

int Hero::getScore() const
{
	return score;
}

int Hero::getMoney() const
{
	return money;
}

int Hero::getStrength() const
{
	return strength;
}

int Hero::getPosX() const
{
	return position_x;
}

int Hero::getPosY() const
{
	return position_y;
}

void Hero::setSpeed(int s)
{
	speed = s;
}

void Hero::setScore(int s)
{
	score = s;
}

void Hero::setMoney(int m)
{
	money = m;
}

void Hero::setStrength(int s)
{
	strength = s;
}

void Hero::setPosX(int x)
{
	position_x = x;
}

void Hero::setPosY(int y)
{
	position_y = y;
}


void Hero::getItem(Item i)
{
	//a coder
}

void Hero::move()
{
	//a coder
}

