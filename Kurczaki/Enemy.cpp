#include "Enemy.h"

void Enemy::initVeriables()
{
	this->damage = 1;
	this->hp = 1;
	this->size = 100;
	this->texture.loadFromFile("./assets/chicken-1.png");
	this->texture.setSmooth(true);
}

void Enemy::initShape()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
}

Enemy::Enemy(sf::Vector2f pos, sf::RenderWindow& window)
	:m_window(window)
{
	this->initVeriables();
	this->initShape();
}

bool Enemy::del_obj()
{
	return false;
}

void Enemy::update()
{

}

void Enemy::render()
{
	this->sprite.setPosition(this->position);
	m_window.draw(this->sprite);
}
