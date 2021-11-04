#include "Bullet.h"

void Bullet::initVeriables()
{
	this->speed = 5;
	this->damage = 1;
	this->size = 5;
	this->texture.loadFromFile("./assets/bullet.png");
	this->texture.setSmooth(true);
	this->kabum = false;
}

void Bullet::initShape()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 5, 5));
}

Bullet::Bullet(sf::Vector2f pos, sf::RenderWindow& window)
	:m_window(window)
{
	this->initVeriables();
	this->position = pos;
	this->initShape();
}

sf::Vector2f Bullet::get_position()
{
	return this->position;
}

int Bullet::get_size()
{
	return this->size;
}

int Bullet::get_damage()
{
	return this->damage;
}

void Bullet::set_kabum()
{
	this->kabum = true;
}

void Bullet::update()
{
	this->position.y -= this->speed;
	this->destruct();
}

void Bullet::render()
{
	this->sprite.setPosition(this->position);
	m_window.draw(this->sprite);
}

bool Bullet::destruct()
{
	if (this->position.y < 0 - this->size ||
		this->kabum) {
		return true;
	}
	return false;
}
