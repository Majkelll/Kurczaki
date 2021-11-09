#include "Menu.h"

void Menu::initVariables()
{
	this->backgroundTexture.loadFromFile("./assets/background.jpg");
	this->backgroundTexture.setSmooth(true);

	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1280, 720));
}

void Menu::renderBackground()
{
	this->m_window.draw(this->backgroundSprite);
}

Menu::Menu(sf::RenderWindow& window, WindowHendler& windowHandler)
	:m_window(window),m_windowHenlder(windowHandler)
{
}

void Menu::update()
{
}

void Menu::render()
{
	this->renderBackground();
}
