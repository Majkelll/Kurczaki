#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Enemy
{
private:
	sf::RenderWindow& m_window;

	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	int damage;
	int hp;
	int size;

	void initVeriables();
	void initShape();

public:
	Enemy(sf::Vector2f pos, sf::RenderWindow& window);

	bool del_obj();
	void update();
	void render();
};
