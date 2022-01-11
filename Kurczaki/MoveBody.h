#pragma once

#include <SFML/Graphics.hpp>

class move_body
{
	sf::RenderWindow& m_window_;

	sf::Vector2f position_;
	sf::Texture texture_;
	sf::Sprite sprite_;

	int speed_;
	int damage_;
	int size_;
	bool to_destruction_;

public:
	explicit move_body(sf::RenderWindow& window);
	sf::Vector2f get_position() const;
	int get_speed() const;
	int get_damage() const;
	int get_size() const;
	bool get_to_destruction() const;

	void set_speed(int new_speed);
	void set_damage(int new_damage);
	void set_size(int new_size);
	void set_texture(sf::Texture new_texture);
	void set_to_destruction();
	void set_position(sf::Vector2f new_pos);

	void init_sprite(sf::IntRect texture_pos);
	virtual void update();
	virtual void render();
};
