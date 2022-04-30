#include "Hero.h";
#include "Item.h";
#include "Potion.h";

int Hero::getScore() const
{
	return score;
}

void Hero::setScore(int s)
{
	score = s;
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


template<typename Base, typename T>
inline bool instanceof(const T*) {
	return std::is_base_of<Base, T>::value;
}


void Hero::getItem(Item i)  // trouver une solution
{
	Item* pi = &i;

	cout << "J'ai touché" << i.getNom() << std::endl;

	if (instanceof<Potion>(pi)) {  //si une piece ajoute à notre list de piece cette piece
		cout << "une piece" << std::endl;
		Item& piece = i;
		std::vector<Piece> vec = this->getCoinsList();
		vec.insert(vec.end() + 1, static_cast<Piece&>(i));
	}

	if (instanceof<Potion>(pi)) {  //si une potion ajoute autant de vie que la potion nous en donne.
		cout << "une potion" << std::endl;
		Item& potion = i;
		Potion p = static_cast<Potion&>(i);
		this->setVie(this->getVie() + p.getNombre());
	}
}

void Hero::getCoin(Piece p)
{
	std::vector<Piece> vec = this->getCoinsList();
	vec.insert(vec.end(), p);
	this->setCoinsList(vec);
	cout << this->getnbCoins() << std::endl;
}

void Hero::getPotion(Potion p)
{
	this->setVie(this->getVie() + p.getNombre());
}






