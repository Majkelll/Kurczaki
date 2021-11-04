#include "MoveBody.h"

MoveBody::MoveBody(sf::RenderWindow& window)
	:m_window(window)
{
	this->kabum = false;
}

sf::Vector2f MoveBody::get_position() const
{
	return this->position;
}

int MoveBody::get_speed() const
{
	return this->speed;
}

int MoveBody::get_damage() const
{
	return this->damage;
}

int MoveBody::get_size() const
{
	return this->size;
}

bool MoveBody::get_kabum() const
{
	return this->kabum;
}

void MoveBody::set_speed(int newSpeed)
{
	this->speed = newSpeed;
}

void MoveBody::set_damage(int newDamage)
{
	this->damage = newDamage;
}

void MoveBody::set_size(int newSize)
{
	this->size = newSize;
}

void MoveBody::set_texture(sf::Texture newTexture)
{
	this->texture = newTexture;
}

void MoveBody::initSprite(sf::IntRect texturePos)
{
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(texturePos);
}

void MoveBody::set_kabum()
{
	this->kabum = true;
}

void MoveBody::set_position(sf::Vector2f newPos)
{
	this->position = newPos;
}

void MoveBody::update()
{
	this->position.y -= this->speed;
	if (this->position.y > m_window.getSize().y
		|| this->position.y < 0) {
		this->set_kabum();
	}
}

void MoveBody::render()
{
	this->sprite.setPosition(this->position);
	m_window.draw(this->sprite);
}
