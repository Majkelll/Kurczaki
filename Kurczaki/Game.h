#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Enemy.h"

class Game
{
private:
	sf::RenderWindow& m_window;
	Player player;

	std::vector<std::unique_ptr<Enemy>> enemies;

public:
	Game(sf::RenderWindow& window);

	void generateLvl();

	void update();
	void render();
};
