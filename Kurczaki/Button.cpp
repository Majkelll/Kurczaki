#include "Button.h"

void button::init_variables()
{
}

void button::init_shape()
{
	this->btn_texture_.loadFromFile("./assets/buttonExit.png");
	this->sprite_.setTextureRect(sf::IntRect(0, 0, 500, 100));
	this->sprite_.setTexture(this->btn_texture_);
	this->sprite_.setPosition(this->position_);
}

button::button(const sf::Vector2f new_position, const int new_texture, const sf::Vector2f new_size,
               const std::string new_name,
               sf::RenderWindow& window)
	: position_(new_position), size_(new_size), m_window_(window), name_(new_name), texture_(new_texture)
{
	this->init_variables();
	this->init_shape();
}

sf::Vector2f button::get_position() const
{
	return this->position_;
}

std::string button::get_name()
{
	return this->name_;
}

void button::update()
{
}


void button::render() const
{
	this->m_window_.draw(this->sprite_);
}
