#include "DeathScreen.h"

void DeathScreen::initVariables()
{
	this->buttonSize = sf::Vector2f(500, 100);
	this->buttonPosition = sf::Vector2f(1280 / 2 - this->buttonSize.x / 2, 300);

	this->loseTexture.loadFromFile("./assets/lose.png");
	this->loseTexture.setSmooth(true);

	this->loseSprite.setTexture(this->loseTexture);
	this->loseSprite.setTextureRect(sf::IntRect(0, 0, 1280, 720));
	this->loseSprite.setPosition(0, 0);

	this->buttons.push_back(Button(sf::Vector2f(this->buttonPosition.x, this->buttonPosition.y + 240), 2, this->buttonSize, "Exit", this->m_window));
}

void DeathScreen::renderScore()
{
	this->textScore.setString("Score: " + std::to_string(this->m_windowHandler.get_score()));
	m_window.draw(this->textScore);
}

void DeathScreen::renderBackground()
{
	this->m_window.draw(this->loseSprite);
}

void DeathScreen::initText()
{
	this->font.loadFromFile("./assets/font.ttf");
	this->textScore.setFont(this->font);
	this->textScore.setString("Score: 0");
	this->textScore.setCharacterSize(80);
	this->textScore.setOrigin(-500, -300);
}

void DeathScreen::updateState()
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

bool DeathScreen::buttonHitBox(sf::Vector2f buttonPos, sf::Vector2i mousePos)
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

DeathScreen::DeathScreen(sf::RenderWindow& window, WindowHendler& newWindowHandler)
	:m_window(window), m_windowHandler(newWindowHandler)
{
	this->initVariables();
	this->initText();
}

void DeathScreen::update()
{
	this->mousePos = sf::Mouse::getPosition(this->m_window);
	this->updateState();
}

void DeathScreen::render()
{
	m_window.clear();

	this->renderBackground();
	this->renderScore();
	for (auto& b : this->buttons) {
		b.render();
	}

	m_window.display();
}
