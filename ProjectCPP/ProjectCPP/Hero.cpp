#include "Hero.h";

int Hero::getSpeed() const
{
	return speed;
}

int Hero::getScore() const
{
	return score;
}


int Hero::getStrength() const
{
	return strength;
}


void Hero::setSpeed(int s)
{
	speed = s;
}

void Hero::setScore(int s)
{
	score = s;
}

void Hero::setStrength(int s)
{
	strength = s;
}

const std::vector<Piece> Hero::getCoinsList() const
{
	return coinsList;
}

void Hero::setCoinsList(const std::vector<Piece>& coinsList)
{
	Hero::coinsList = coinsList;
}

void Hero::initCoinsList()
{
	std::vector<Piece> coinList;

	Piece c = Piece();  //mettre son image

	for (int i = 0; i < 10; i++) {  //on va lui donner 10 pièces au tout début.
		coinList.push_back(c);
	}

	Hero::setCoinsList(coinList);

}

int Hero::getnbCoins() const
{
	return size(coinsList);
}



void Hero::getItem(Item i)
{

	// if c'est un Piece je l'ajoute à ma liste
	// 
	// if Position ...
	//a coder
}





