#pragma once
#include "MoveBody.h"
class Bullet_v2 : public MoveBody
{
private:

public:
	void initVeriables(sf::Vector2f newPosition);
	using MoveBody::MoveBody;
};

