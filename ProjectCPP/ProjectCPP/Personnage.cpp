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
	, position_x{ 0 }  //position
	, position_y{ 0 }
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

bool Personnage::getdie() const
{
	return die;
}

void Personnage::setdie(bool b)
{
	die = b;
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

Texture2D Personnage::getModel() const
{
	return model;
}

void Personnage::setModel(Texture2D m)
{
	model = m;
}

Texture2D Personnage::getAttackModel() const
{
	return attackModel;
}

void Personnage::setAttackModel(Texture2D m)
{
	attackModel = m;
}

void Personnage::setRect(Rectangle r)
{
	rec = r;
}
Rectangle Personnage::getRect() const
{
	return rec;
}

int Personnage::getSide() const
{
	return facingLeft;
}

void Personnage::setImageAttack(Image ia)
{
	imageAttack = ia;
}

void Personnage::setImageRun(Image ir)
{
	imageRun = ir;
}

void Personnage::setImageIdle(Image ii)
{
	imageIdle = ii;
}

Image Personnage::getImageAttack()
{
	return imageAttack;
}

Image Personnage::getImageRun()
{
	return imageRun;
}

Image Personnage::getImageIdle()
{
	return imageIdle;
}


Texture2D Personnage::getTexture2DAttack()
{
	return LoadTextureFromImage(this->getImageAttack());
}

Texture2D Personnage::getTexture2DRun()
{
	return LoadTextureFromImage(this->getImageRun());
}

Texture2D Personnage::getTexture2DIdle()
{
	return LoadTextureFromImage(this->getImageIdle());
}

void Personnage::setSide(int r)
{
	facingLeft = r;
}

Vector2 Personnage::getPos() const
{
	return pos;
}

void Personnage::setPos(Vector2 p)
{
	pos = p;
}
void Personnage::setImageDie(Image ii)
{
	imageDie = ii;
}

Image Personnage::getImageDie()
{
	return imageDie;
}

Texture2D Personnage::getTexture2DDie()
{
	return LoadTextureFromImage(this->getImageDie());
}

std::ostream& operator<<(std::ostream& out, const Personnage& p)
{
	out << "Mon nom est  : " << p.nom << "Ma vie est de : " << p.vie << std::endl;

	return out;
}
