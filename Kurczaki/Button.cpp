#include "Button.h"

void Button::initVariables()
{
}

void Button::initShape()
{

	this->btnTexture.loadFromFile("./assets/buttonExit.png");
	this->sprite.setTexture(this->btnTexture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, this->size.x, this->size.y));
	this->sprite.setPosition(this->position);
}

Button::Button(sf::Vector2f newPosition, int newTexture, sf::Vector2f newSize, std::string newName, sf::RenderWindow& window)
	:m_window(window)
{
	this->position = newPosition;
	this->size = newSize;
	this->name = newName;
	this->texture = newTexture;
	this->initVariables();
	this->initShape();
}

sf::Vector2f Button::get_position()
{
	return this->position;
}

std::string Button::get_name()
{
	return this->name;
}

void Button::update()
{

}

void Button::render()
{
	this->m_window.draw(this->sprite);
}
