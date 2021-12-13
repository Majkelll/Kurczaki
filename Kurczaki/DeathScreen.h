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

class DeathScreen
{
private:
	sf::RenderWindow& m_window;
	WindowHendler& m_windowHandler;

	sf::Texture loseTexture;
	sf::Sprite loseSprite;

	sf::Font font;
	sf::Text textScore;

	void initVariables();
	void initText();

	void renderScore();
	void renderBackground();
public:
	DeathScreen(sf::RenderWindow& window, WindowHendler& newWindowHandler);
	void update();
	void render();
};

