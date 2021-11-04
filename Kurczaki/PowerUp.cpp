#include "PowerUp.h"

void PowerUp::initVeriables()
{
	this->set_speed(0);
	this->set_damage(1);
	this->set_size(100);
	this->set_position(sf::Vector2f(100, 100));

	sf::Texture tempTexture;
	tempTexture.loadFromFile("./assets/ship.png");
	tempTexture.setSmooth(true);
	this->set_texture(tempTexture);

	this->initSprite(sf::IntRect(0, 0, 100, 100));
}
