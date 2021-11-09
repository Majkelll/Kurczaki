#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "WindowHendler.h"


class MenuButton
{
private:
	sf::RenderWindow& m_window;
	WindowHendler& m_windowHandler;

	sf::Texture texture;
	sf::Sprite sprite;

	int width;
	int height;
	std::string text;

	void clickHitBox();

public:
	MenuButton(sf::RenderWindow& window, WindowHendler& windowHandler);

	int get_width();
	int get_height();

	void update();
	void render();
};

