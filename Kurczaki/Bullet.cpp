#include "Bullet.h"

void Bullet::initVeriables()
{
	this->speed = 5;
	this->damage = 1;
	this->size = 5;
}

void Bullet::initShape()
{
	this->bulletShape.setPosition(this->position);
	this->bulletShape.setFillColor(sf::Color(255, 1, 1));
	this->bulletShape.setSize(sf::Vector2f(this->size, this->size));
}

Bullet::Bullet(sf::Vector2f pos, sf::RenderWindow& window)
	:m_window(window)
{
	this->initVeriables();
	this->position = pos;
	this->initShape();
}

void Bullet::update()
{
	this->bulletShape.setPosition(this->position);
	this->position.y -= this->speed;
}

void Bullet::render()
{
	m_window.draw(this->bulletShape);
}

bool Bullet::kabum()
{
	if (this->position.y < 100) {
		return true;
	}
	return false;
}

sf::RectangleShape Bullet::getShape()
{
	return this->bulletShape;
}
