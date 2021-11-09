#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "Egg.h"
#include "Bullet.h"

class Game
{
private:
	sf::RenderWindow& m_window;
	Player player;
	sf::Text textScore;

	std::vector<std::unique_ptr<Enemy>> enemies;

	std::list<PowerUp> powerUps;
	std::list<Egg> eggs;
	std::list<Bullet_v2> bullets_v2;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Font font;

	int currLvl;

	void initVeriables();
	void generateLvl(int level);
	void initTextScore();
	bool hitbox(sf::Vector2f pos1, sf::Vector2f pos2, int size1, int size2);
	void generatePowerUps(sf::Vector2f pos);

	void renderPowerUps();
	void renderEnemies();
	void renderBackground();
	void renderScore();
	void renderEggs();
	void renderBullets();

	void updateHitBoxBulletsEnemies();
	void updateShoot();
	void updateEnemies();
	void updateLvl();
	void updatePowerUps();
	void updateText();
	void updateEggs();
	void updateBullets();

public:
	Game(sf::RenderWindow& window);
	void update();
	void render();
};
