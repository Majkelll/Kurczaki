#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "WindowHendler.h"
#include "Button.h"
#include <list>
#include "WindowHendler.h"
#include "Button.h"

class DeathScreen
{
private:
	sf::RenderWindow& m_window;
	WindowHendler& m_windowHandler;

	sf::Texture loseTexture;
	sf::Sprite loseSprite;

	sf::Font font;
	sf::Text textScore;

	sf::Vector2f buttonSize;
	sf::Vector2f buttonPosition;
	sf::Vector2i mousePos;

	std::list<Button> buttons;

	void initVariables();
	void initText();
	void updateState();
	bool buttonHitBox(sf::Vector2f buttonPos, sf::Vector2i mousePos);

	void renderScore();
	void renderBackground();
public:
	DeathScreen(sf::RenderWindow& window, WindowHendler& newWindowHandler);
	void update();
	void render();
};

