#include "Egg.h"

int Egg::get_damage()
{
	return this->damage;
}

void Egg::initVeriables(sf::Vector2f newPos)
{
	this->set_speed(-5);
	this->set_damage(1);
	this->set_size(40);
	this->set_position(newPos);

	sf::Texture tempTexture;
	tempTexture.loadFromFile("./assets/egg.png");
	tempTexture.setSmooth(true);
	this->set_texture(tempTexture);
	this->initSprite(sf::IntRect(0, 0, 40, 40));
}