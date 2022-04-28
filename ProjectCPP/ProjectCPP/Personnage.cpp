#include "Personnage.h"

Personnage::Personnage() :Personnage("sans nom", 10)
{

}

Personnage::Personnage(string nom, int vie)
	: nom{ nom }
	, vie{ vie }
	, attack{ false }
	, run{ false }
	, idle{ true }
	, position_x {0}  //position
	, position_y {0}
{
}

Personnage::~Personnage()
{
}

string Personnage::getNom()const
{
	return (nom);
}

int Personnage::getVie()const
{
	return (vie);
}

int Personnage::getPosX() const
{
	return position_x;
}

int Personnage::getPosY() const
{
	return position_y;
}

void Personnage::setNom(string n)
{
	nom = n;
}

void Personnage::setVie(int v)
{
	vie = v;
}


void Personnage::setPosX(int x)
{
	position_x = x;
}

void Personnage::setPosY(int y)
{
	position_y = y;
}

int Personnage::getFacingLeft() const
{
	return facingLeft;
}

void Personnage::setFacingLeft(int fc)
{
	facingLeft = fc;
}

bool Personnage::getrun() const
{
	return run;
}

bool Personnage::getattack() const
{
	return attack;
}

bool Personnage::getidle() const
{
	return idle;
}

void Personnage::setrun(bool b)
{
	run = b;
}

void Personnage::setattack(bool b)
{
	attack = b;
}

void Personnage::setidle(bool b)
{
	idle = b;
}

std::ostream& operator<<(std::ostream& out, const Personnage& p)
{
	out << "Mon nom est  : " << p.nom << "Ma vie est de : " << p.vie << std::endl;

	return out;
}
