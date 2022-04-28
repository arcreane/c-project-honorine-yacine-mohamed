#pragma once

#include "Personnage.h";

class Antagoniste : public Personnage {
private:
	int recompense; //reward
public:
	Antagoniste(string nom, int vie, int recompense)
		:Personnage(nom, vie)
		, recompense{ recompense }{

	};
	//getteur et setteurs
	int getRecompense() const;
	void setRecompense(int r);

	//methodes
	void oneShot(Personnage hero);

};