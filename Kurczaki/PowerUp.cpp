#include "PowerUp.h"

int power_up::get_buff() const
{
	return this->buff_;
}

int power_up::get_buff_value() const
{
	return this->buff_value_;
}

void power_up::init_variables(const sf::Vector2f new_pos)
{
	this->buff_ = rand() % 5;
	this->set_speed(-5);
	this->set_damage(1);
	this->set_size(40);
	this->set_position(new_pos);

	sf::Texture temp_texture;
	switch (this->buff_)
	{
	case 0:
		temp_texture.loadFromFile("./assets/heart2.png");
		break;
	case 1:
		temp_texture.loadFromFile("./assets/buff_shield.png");
		break;
	case 2:
		temp_texture.loadFromFile("./assets/update_shoot_speed.png");
		break;
	case 3:
		temp_texture.loadFromFile("./assets/buff_egg.png");
		break;
	case 4:
		temp_texture.loadFromFile("./assets/speed.png");
		break;
	default:
		temp_texture.loadFromFile(".png");
	}
	temp_texture.setSmooth(true);
	this->set_texture(temp_texture);

	this->init_sprite(sf::IntRect(0, 0, 40, 40));
}
