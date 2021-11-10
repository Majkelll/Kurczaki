#include "Button.h"

void Button::initVariables()
{
	this->color = sf::Color(150, 150, 67);
}

void Button::initShape()
{
	this->shape.setSize(this->size);
	this->shape.setPosition(this->position);
	this->shape.setFillColor(this->color);
}

Button::Button(sf::Vector2f newPosition, sf::Vector2f newSize, std::string newName, sf::RenderWindow& window)
	:m_window(window)
{
	this->position = newPosition;
	this->size = newSize;
	this->name = newName;
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
	this->m_window.draw(this->shape);
}
