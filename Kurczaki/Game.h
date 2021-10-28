#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"

class Game
{
private:
	sf::RenderWindow& m_window;
	Player player;
public:
	Game(sf::RenderWindow& window);
	void update();
	void render();
};
