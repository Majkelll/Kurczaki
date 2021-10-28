#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Bullet
{
private:
	sf::Vector2f position;
	int speed;
	int damage;
	int size;
	sf::RectangleShape bulletShape;
	sf::RenderWindow& m_window;
	void initVeriables();
	void initShape();
public:
	Bullet(sf::Vector2f pos, sf::RenderWindow& window);
	void update();
	void render();
	bool kabum();
	sf::RectangleShape getShape();
};
