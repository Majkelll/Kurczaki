#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "Enemy.h"
#include "Egg.h"
#include "PowerUp.h"

class Game
{
private:
	sf::RenderWindow& m_window;
	Player player;
	sf::Text textScore;

	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<std::unique_ptr<Bullet>> bullets;
	std::vector<std::unique_ptr<Egg>> eggs;
	std::list<PowerUp> powerUps;


	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Font font;

	int currLvl;

	void initVeriables();
	void generateLvl(int level);
	void bulletsEnemiesColider();
	void eggsPlayerColider();
	void initTextScore();
	bool hitbox(sf::Vector2f pos1, sf::Vector2f pos2, float size1, float size2);
	void generatePowerUps(sf::Vector2f pos);

	void renderPowerUps();
	void renderEggs();
	void renderEnemies();
	void renderBullets();
	void renderBackground();
	void renderScore();

	void updateShoot();
	void updateEnemies();
	void updateLvl();
	void updateEggs();
	void updatePowerUps();
	void updateText();
	void updateBullets();

public:
	Game(sf::RenderWindow& window);
	void update();
	void render();
};
