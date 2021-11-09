#include "Bullet.h"

void Bullet_v2::initVeriables(sf::Vector2f newPosition)
{
	this->set_speed(5);
	this->set_damage(1);
	this->set_size(5);
	this->set_position(newPosition);
	sf::Texture tempTexture;
	tempTexture.loadFromFile("./assets/bullet.png");
	tempTexture.setSmooth(true);
	this->set_texture(tempTexture);
	this->initSprite(sf::IntRect(0, 0, 5, 5));
}
