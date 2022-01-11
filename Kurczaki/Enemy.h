#pragma once

#include <SFML/Graphics.hpp>

class enemy
{
private:
	sf::RenderWindow& m_window_;

	sf::Vector2f position_;
	sf::Texture texture_;
	sf::Sprite sprite_;

	int damage_{};
	int hp_{};
	int size_{};
	int coins_{};

	void init_variables();
	void init_shape();

public:
	enemy(sf::Vector2f pos, sf::RenderWindow& window);
	sf::Vector2f get_position() const;
	int get_size() const;
	int get_hp() const;
	int get_coins() const;
	void set_hp(int new_hp);

	static bool del_obj();
	static void update();
	void render();
};
