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

	this->buttons.push_back(Button(this->buttonPosition, 1, this->buttonSize, "Play", this->m_window));
	this->buttons.push_back(Button(sf::Vector2f(this->buttonPosition.x, this->buttonPosition.y + 120), 2, this->buttonSize, "Exit", this->m_window));
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

void Menu::updateState()
{
	for (auto& b : this->buttons) {
		if (this->buttonHitBox(b.get_position(), this->mousePos)
			&& sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (b.get_name() == "Play") {
				this->m_windowHandler.set_renderState(2);
			}
			if (b.get_name() == "Exit") {
				m_window.close();
			}
		}
		b.update();
	}
}

Menu::Menu(sf::RenderWindow& window, WindowHendler& newWindowHendler)
	:m_window(window), m_windowHandler(newWindowHendler)
{
	this->initVariables();
}

void Menu::update()
{
	this->mousePos = sf::Mouse::getPosition(this->m_window);
	this->updateState();
}

void Menu::render()
{
	m_window.clear();

	this->renderBackground();

	m_window.display();
}
