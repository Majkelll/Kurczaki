#pragma once

#include <SFML/Graphics.hpp>
#include "WindowHendler.h"
#include "Button.h"
#include <list>

class menu
{
private:
	sf::RenderWindow& m_window_;
	window_handler& m_window_handler_;

	sf::Texture background_texture_;
	sf::Sprite background_sprite_;

	sf::Vector2f button_size_;
	sf::Vector2f button_position_;
	sf::Vector2i mouse_pos_;

	std::list<button> buttons_;

	void init_variables();
	bool button_hit_box(sf::Vector2f button_pos, sf::Vector2i mouse_pos) const;
	void render_background() const;
	void update_state();

public:
	menu(sf::RenderWindow& window, window_handler& new_window_handler);
	void update();
	void render() const;
};
