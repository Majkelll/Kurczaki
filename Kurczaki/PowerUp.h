#pragma once
#include "MoveBody.h"
class PowerUp : public MoveBody
{
private:
	int buff;
	int buffValue;
public:
	int get_buff();
	int get_buffValue();
	void initVeriables(sf::Vector2f newPos);
	using MoveBody::MoveBody;
};
