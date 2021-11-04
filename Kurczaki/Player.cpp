#include "Player.h"

void Player::initVeriables()
{
	this->position.x = 1280 / 2 - 50;
	this->position.y = 720 - 150;
	this->hp = 3;
	this->points = 0;
	this->speed = 5.f;
	this->size = 100.f;
	this->shootSpeed = 5;
	this->weaponLvl = 1;
	this->speedLvl = 1;
	this->shootLvl = 1;

	this->texture.loadFromFile("./assets/ship.png");
	this->texture.setSmooth(true);

	this->hpTexture.loadFromFile("./assets/heart.png");
	this->hpTexture.setSmooth(true);
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

void Player::hpRender()
{
	for (int i = 0; i < this->hpSprites.size(); i++) {
		m_window.draw(this->hpSprites[i]);
	}
}

void Player::hpUpdate()
{
	if (this->hp != this->hpSprites.size()) {
		hpSprites.clear();
		for (int i = 0; i < this->hp; i++) {
			sf::Sprite temp;
			temp.setTexture(this->hpTexture);
			temp.setTextureRect(sf::IntRect(0, 0, 40, 40));
			temp.setPosition(sf::Vector2f(m_window.getSize().x - 60 - (i * 40), 20.f));
			hpSprites.push_back(temp);
		}
	}
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

void Player::on_godMode()
{
	this->godMode = true;
	this->godModeTimer = 300;
}

void Player::set_points(int newPoints)
{
	this->points = newPoints;
}

void Player::set_hp(int newHp)
{
	this->hp = newHp;
}

int Player::get_hp()
{
	return this->hp;
}

bool Player::get_godMode()
{
	return this->godMode;
}

bool Player::shoot()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->shootTimer < 0) {
		this->shootTimer = this->shootSpeed;
		return true;
	}
	this->shootTimer -= 1;
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
	//TO DO
	if (this->godModeTimer > 0 && this->godMode == true) {
		this->godModeTimer--;
	}
	else {
		this->godMode = false;
	}
	this->move();
	this->shoot();
	this->hpUpdate();
	this->sprite.setPosition(this->position);
}

void Player::render()
{
	m_window.draw(this->sprite);
	this->hpRender();
}
