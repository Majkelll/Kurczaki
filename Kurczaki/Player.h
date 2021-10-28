#pragma once
#include "Bullet.h"

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Player
{
private:
	sf::Vector2f position;
	int hp;
	int points;
	float speed;
	float size;
	float shootSpeed;
	int weaponLvl;
	int speedLvl;
	int shootLvl;
	sf::RenderWindow& m_window;

	std::vector<std::unique_ptr<Bullet>> bullets;

	void initVeriables();
	void initShape();
	void moveColider();
	void move();
	void shoot();

	sf::Texture texture;
	sf::Sprite sprite;
public:
	Player(sf::RenderWindow& window);
	void update();
	void render();

};
