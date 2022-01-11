#include "Egg.h"

int egg::get_damage() const
{
	return this->damage_;
}

void egg::init_variables(const sf::Vector2f new_pos)
{
	this->set_speed(-5);
	this->set_damage(1);
	this->set_size(40);
	this->set_position(new_pos);

	sf::Texture temp_texture;
	temp_texture.loadFromFile("./assets/egg.png");
	temp_texture.setSmooth(true);
	this->set_texture(temp_texture);
	this->init_sprite(sf::IntRect(0, 0, 40, 40));
}
