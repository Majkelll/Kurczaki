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
	void initVeriables();
	void initShape();
public:
};
