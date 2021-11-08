#include "PowerUp.h"

int PowerUp::get_buff()
{
	return this->buff;
}

int PowerUp::get_buffValue()
{
	return this->buffValue;
}

void PowerUp::initVeriables(sf::Vector2f newPos)
{
	this->buff = rand() % 5;
	this->buff = 3;
	this->set_speed(-5);
	this->set_damage(1);
	this->set_size(40);
	this->set_position(newPos);

	sf::Texture tempTexture;
	switch (this->buff) {
	case 0:
		tempTexture.loadFromFile("./assets/heart2.png");
		break;
	case 1:
		tempTexture.loadFromFile("./assets/buff_shield.png");
		break;
	case 2:
		tempTexture.loadFromFile("./assets/update_shoot_speed.png");
		break;
	case 3:
		tempTexture.loadFromFile("./assets/buff_egg.png");
		break;
	case 4:
		tempTexture.loadFromFile("./assets/speed.png");
		break;
	default:
		tempTexture.loadFromFile(".png");
	}
	tempTexture.setSmooth(true);
	this->set_texture(tempTexture);

	this->initSprite(sf::IntRect(0, 0, 40, 40));
}
