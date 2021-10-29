#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Bullet
{
private:
	sf::RenderWindow& m_window;

	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	int speed;
	int damage;
	int size;
	bool kabum;

	void initVeriables();
	void initShape();

public:
	Bullet(sf::Vector2f pos, sf::RenderWindow& window);

	bool destruct();

	void set_kabum();
	void update();
	void render();

};
