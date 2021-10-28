#pragma once

#include <iostream>
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

	void initVeriables();
	void initShape();
	void moveColider();
	void move();

	//TO DO

public:
	sf::RectangleShape playerShape;
	Player(sf::RenderWindow& window);
	void update();
	void render();

};
