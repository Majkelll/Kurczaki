#include "Menu.h"

void Menu::initVariables()
{
	this->buttonSize = sf::Vector2f(500, 100);
	this->buttonPosition = sf::Vector2f(1280 / 2 - this->buttonSize.x / 2, 300);

	this->backgroundTexture.loadFromFile("./assets/menu.png");
	this->backgroundTexture.setSmooth(true);

	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1280, 720));
	this->backgroundSprite.setPosition(0, 0);

	this->buttons.push_back(Button(this->buttonPosition, this->buttonSize, "Play", this->m_window));
	this->buttons.push_back(Button(sf::Vector2f(this->buttonPosition.x, this->buttonPosition.y + 120), this->buttonSize, "Exit", this->m_window));
}

bool Menu::buttonHitBox(sf::Vector2f buttonPos, sf::Vector2i mousePos)
{
	int size2 = 1;
	if (buttonPos.x < mousePos.x + 1 &&
		buttonPos.x + this->buttonSize.x > mousePos.x &&
		buttonPos.y < mousePos.y + 1 &&
		this->buttonSize.y + buttonPos.y > mousePos.y) {
		return true;
	}
	return false;

}

void Menu::renderBackground()
{
	this->m_window.draw(this->backgroundSprite);
}

Menu::Menu(sf::RenderWindow& window)
	:m_window(window)
{
	this->renderMe = true;
	this->initVariables();
}

bool Menu::get_renderMe()
{
	return this->renderMe;
}

void Menu::update()
{
	this->mousePos = sf::Mouse::getPosition(this->m_window);
	this->m_windowHendler.set_renderState(5);
	for (auto& b : this->buttons) {
		if (this->buttonHitBox(b.get_position(), this->mousePos)
			&& b.get_name() == "Play"
			&& sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->renderMe = false;
		}
		b.update();
	}
}

void Menu::render()
{
	m_window.clear();

	this->renderBackground();

	for (auto& b : this->buttons) {
		b.render();
	}

	m_window.display();
}
