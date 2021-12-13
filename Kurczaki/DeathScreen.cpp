#include "DeathScreen.h"

void DeathScreen::initVariables()
{
	this->loseTexture.loadFromFile("./assets/lose.png");
	this->loseTexture.setSmooth(true);

	this->loseSprite.setTexture(this->loseTexture);
	this->loseSprite.setTextureRect(sf::IntRect(0, 0, 1280, 720));
	this->loseSprite.setPosition(0, 0);
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

DeathScreen::DeathScreen(sf::RenderWindow& window, WindowHendler& newWindowHandler)
	:m_window(window), m_windowHandler(newWindowHandler)
{
	this->initVariables();
	this->initText();
}

void DeathScreen::update()
{
}

void DeathScreen::render()
{
	m_window.clear();

	this->renderBackground();
	this->renderScore();

	m_window.display();
}
