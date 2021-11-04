#pragma once
#include "Bullet.h"
class Egg
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
	Egg(sf::Vector2f pos, sf::RenderWindow& window);
	sf::Vector2f get_position();
	int get_size();
	int get_damage();
	int get_speed();

	void set_speed(int newSpeed);
	void set_kabum();
	bool destruct();
	void update();
	void render();
};
