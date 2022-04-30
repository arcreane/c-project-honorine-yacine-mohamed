#pragma once
#include "Item.h";

class Piece : public Item {

public:
	Piece()
		:Item()
	{
		setImage(LoadImage("resources/coin1.png"));
		setActive(false);
	};
};