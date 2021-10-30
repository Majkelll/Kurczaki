#include "Enemy.h"

void Enemy::initVeriables()
{
	this->coins = 5;
	this->damage = 1;
	this->hp = 5;
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
	this->position = pos;
	this->initVeriables();
	this->initShape();
}

sf::Vector2f Enemy::get_position()
{
	return this->position;
}

int Enemy::get_size()
{
	return this->size;
}

int Enemy::get_hp()
{
	return this->hp;
}

int Enemy::get_coins()
{
	return this->coins;
}

void Enemy::set_hp(int newHp)
{
	this->hp = newHp;
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
