#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Enemy.h"
#include "Egg.h"

class Game
{
private:
	sf::RenderWindow& m_window;
	Player player;
	sf::Text textScore;

	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<std::unique_ptr<Bullet>> bullets;
	std::vector<std::unique_ptr<Egg>> eggs;


	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Font font;

	int currLvl;

	void initVeriables();
	void generateLvl(int level);
	void bulletsUpdate();
	void enemiesUpdate();
	void bulletsEnemiesColider();
	void eggsPlayerColider();
	void initTextScore();
	void updateLvl();
	void eggsUpdate();
	bool hitbox(sf::Vector2f pos1, sf::Vector2f pos2, float size1, float size2);

public:
	Game(sf::RenderWindow& window);
	void update();
	void render();
};
