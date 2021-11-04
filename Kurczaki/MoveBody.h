#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class MoveBody
{
	sf::RenderWindow& m_window;

	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

	int speed;
	int damage;
	int size;
	bool kabum;

public:
	explicit MoveBody(sf::RenderWindow& window);
	sf::Vector2f get_position() const;
	int get_speed() const;
	int get_damage() const;
	int get_size() const;
	bool get_kabum() const;

	void set_speed(int newSpeed);
	void set_damage(int newDamage);
	void set_size(int newSize);
	void set_texture(sf::Texture newTexture);
	void set_kabum();
	void set_position(sf::Vector2f newPos);

	void initSprite(sf::IntRect texturePos);
	virtual void update();
	virtual void render();
};
