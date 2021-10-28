#include "Player.h"

void Player::initVeriables()
{
	this->position.x = 500;
	this->position.y = 500;
	this->hp = 10;
	this->points = 0;
	this->speed = 10.f;
	this->size = 50.f;
	this->shootSpeed = 1.f;
	this->weaponLvl = 1;
	this->speedLvl = 1;
	this->shootLvl = 1;
}

void Player::initShape()
{
	this->playerShape.setPosition(this->position);
	this->playerShape.setFillColor(sf::Color(1, 1, 255));
	this->playerShape.setSize(sf::Vector2f(size, size));
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

void Player::shoot()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		bullets.push_back(Bullet(sf::Vector2f(this->position.x + this->size / 2, this->position.y), m_window));
	}
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

	//bullets update
	for (int i = 0; i < this->bullets.size();i++) {
		bullets[i].update();
		if (bullets[i].kabum()) {
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Player::render()
{
	//player render
	playerShape.setPosition(this->position);
	m_window.draw(this->playerShape);

	//bullets render
	for (int i = 0; i < this->bullets.size(); i++) {
		bullets[i].render();
	}
}
