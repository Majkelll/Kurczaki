#include "Egg.h"

void Egg::update()
{
	this->position.y += this->speed;
	this->destruct();
}

void Egg::render()
{
	this->sprite.setPosition(this->position);
	m_window.draw(this->sprite);
}

void Egg::initVeriables()
{
	this->speed = 5;
	this->damage = 1;
	this->size = 40;
	this->texture.loadFromFile("./assets/egg.png");
	this->texture.setSmooth(true);
	this->kabum = false;
}

void Egg::initShape()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}

Egg::Egg(sf::Vector2f pos, sf::RenderWindow& window)
	:m_window(window)
{
	this->initVeriables();
	this->position = pos;
	this->initShape();
}

sf::Vector2f Egg::get_position()
{
	return this->position;
}

int Egg::get_size()
{
	return this->size;
}

int Egg::get_damage()
{
	return this->damage;
}

int Egg::get_speed()
{
	return this->speed;
}

bool Egg::destruct()
{
	if (this->position.y > 1500 - this->size ||
		this->kabum) {
		return true;
	}
	return false;
}

void Egg::set_speed(int newSpeed)
{
	this->speed = newSpeed;
}

void Egg::set_kabum()
{
	this->kabum = true;
}
