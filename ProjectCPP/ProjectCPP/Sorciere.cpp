#include "Sorciere.h";
#include <vector>

void Sorciere::voler(Hero &h)  //voler des PIECES au joueur
{
	cout << "J'AI VOLER 1 PIECE AU JOUEUR : " << h.getNom() << std::endl;
	std::vector<Piece> vec = h.getCoinsList();
	if (size(vec) > 0) {
		vec.erase(vec.begin());  //supprime le premier élement de la liste
	}
	h.setCoinsList(vec);  //set la liste
}

