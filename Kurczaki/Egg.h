#pragma once
#include "MoveBody.h"
class Egg : public MoveBody
{
private:
	int damage;
public:
	int get_damage();
	void initVeriables(sf::Vector2f newPos);
	using MoveBody::MoveBody;
};