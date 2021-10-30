#include "Player.h"

void Player::initVeriables()
{
	this->position.x = 500;
	this->position.y = 500;
	this->hp = 10;
	this->points = 0;
	this->speed = 10.f;
	this->size = 100.f;
	this->shootSpeed = 1.f;
	this->weaponLvl = 1;
	this->speedLvl = 1;
	this->shootLvl = 1;

	this->texture.loadFromFile("./assets/ship.png");
	this->texture.setSmooth(true);
}

void Player::initShape()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
}

void Player::moveColider()
{
	if (this->position.x + this->size > m_window.getSize().x) {
		this->position.x = m_window.getSize().x - this->size;
		this->position.y = this->position.y;
	}
	if (this->position.x < 0) {
		this->position.x = 0;
		this->position.y = this->position.y;
	}
	if (this->position.y < 0) {
		this->position.x = this->position.x;
		this->position.y = 0;
	}
	if (this->position.y > 720 - this->size) {
		this->position.x = this->position.x;
		this->position.y = m_window.getSize().y - this->size;
	}
}

void Player::move()
{
	sf::Vector2f velocity(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.x -= this->speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x += this->speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocity.y += this->speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		velocity.y -= this->speed;
	}
	this->position.x += velocity.x;
	this->position.y += velocity.y;

	this->moveColider();
}

sf::Vector2f Player::get_position()
{
	return this->position;
}

float Player::get_size()
{
	return this->size;
}

int Player::get_points()
{
	return this->points;
}

void Player::set_points(int newPoints)
{
	this->points = newPoints;
}

bool Player::shoot()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		return true;
	}
	return false;
}

Player::Player(sf::RenderWindow& window)
	:m_window(window)
{
	this->initVeriables();
	this->initShape();
}

void Player::update()
{
	//player update
	this->move();
	this->shoot();
}

void Player::render()
{
	//player render
	this->sprite.setPosition(this->position);
	m_window.draw(this->sprite);
}
