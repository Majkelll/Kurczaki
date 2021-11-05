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
	sf::Texture shieldTexture;
	sf::Sprite shieldSprite;
	sf::RenderWindow& m_window;

	int hp;
	int points;
	float speed;
	float shootSpeed;
	int size;
	int weaponLvl;
	int speedLvl;
	int shootLvl;
	int shootTimer;

	int godModeTimer;
	bool godMode;

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
	int get_size();
	int get_points();
	int get_hp();
	bool get_godMode();
	float get_shootSpeed();
	float get_speed();

	void on_godMode();
	void set_points(int newPoints);
	void set_hp(int newHp);
	void set_shootSpeed(float newSpeed);
	void set_speed(float newSpeed);

	bool shoot();
	void update();
	void render();
};
