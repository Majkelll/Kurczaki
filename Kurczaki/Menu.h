#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "WindowHendler.h"

class Menu
{
private:
	sf::RenderWindow& m_window;
	WindowHendler m_windowHenlder;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	void initVariables();

	void renderBackground();

public:
	Menu(sf::RenderWindow& window, WindowHendler& windowHandler);
	void update();
	void render();
};

