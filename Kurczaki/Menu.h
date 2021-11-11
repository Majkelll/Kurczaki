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

class Menu
{
private:
	sf::RenderWindow& m_window;
	WindowHendler& m_windowHandler;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Vector2f buttonSize;
	sf::Vector2f buttonPosition;
	sf::Vector2i mousePos;

	std::list<Button> buttons;

	bool renderMe;

	void initVariables();
	bool buttonHitBox(sf::Vector2f buttonPos, sf::Vector2i mousePos);
	void renderBackground();
	void updateState();

public:
	Menu(sf::RenderWindow& window, WindowHendler& newWindowHendler);
	bool get_renderMe();
	void update();
	void render();
};

