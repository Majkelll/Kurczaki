#include "Enemy.h"

void enemy::init_variables()
{
	this->coins_ = 5;
	this->damage_ = 1;
	this->hp_ = 5;
	this->size_ = 100;
	this->texture_.loadFromFile("./assets/chicken-1.png");
	this->texture_.setSmooth(true);
}

void enemy::init_shape()
{
	this->sprite_.setTexture(this->texture_);
	this->sprite_.setTextureRect(sf::IntRect(0, 0, 100, 100));
}

enemy::enemy(const sf::Vector2f pos, sf::RenderWindow& window)
	: m_window_(window), position_(pos)
{
	this->init_variables();
	this->init_shape();
}

sf::Vector2f enemy::get_position() const
{
	return this->position_;
}

int enemy::get_size() const
{
	return this->size_;
}

int enemy::get_hp() const
{
	return this->hp_;
}

int enemy::get_coins() const
{
	return this->coins_;
}

void enemy::set_hp(int new_hp)
{
	this->hp_ = new_hp;
}

bool enemy::del_obj()
{
	return false;
}

void enemy::update()
{
}

void enemy::render()
{
	this->sprite_.setPosition(this->position_);
	m_window_.draw(this->sprite_);
}
