#include "Bullet.h"

void bullet::init_variables(const sf::Vector2f new_position)
{
	this->set_speed(5);
	this->set_damage(1);
	this->set_size(5);
	this->set_position(new_position);
	sf::Texture temp_texture;
	temp_texture.loadFromFile("./assets/bullet.png");
	temp_texture.setSmooth(true);
	this->set_texture(temp_texture);
	this->init_sprite(sf::IntRect(0, 0, 5, 5));
}
