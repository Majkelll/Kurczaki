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
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RenderWindow& m_window;

	int hp;
	int points;
	float speed;
	float size;
	float shootSpeed;
	int weaponLvl;
	int speedLvl;
	int shootLvl;

	sf::Texture hpTexture;

	std::vector <sf::Sprite> hpSprites;

	void initVeriables();
	void initShape();
	void moveColider();
	void move();
	void hpRender();
	void hpUpdate();

public:
	Player(sf::RenderWindow& window);

	sf::Vector2f get_position();
	float get_size();
	int get_points();
	void set_points(int newPoints);
	bool shoot();

	void update();
	void render();
};
