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
	int coins;

	void initVeriables();
	void initShape();

public:
	Enemy(sf::Vector2f pos, sf::RenderWindow& window);
	sf::Vector2f get_position();
	int get_size();
	int get_hp();
	int get_coins();
	void set_hp(int newHp);

	bool del_obj();
	void update();
	void render();
};
