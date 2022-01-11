#pragma once

#include <SFML/Graphics.hpp>
#include "WindowHendler.h"
#include "Button.h"
#include <list>

class death_screen
{
private:
	sf::RenderWindow& m_window_;
	window_handler& m_window_handler_;

	sf::Texture lose_texture_;
	sf::Sprite lose_sprite_;

	sf::Font font_;
	sf::Text text_score_;

	sf::Vector2f button_size_;
	sf::Vector2f button_position_;
	sf::Vector2i mouse_pos_;

	std::list<button> buttons_;

	void init_variables();
	void init_text();
	void update_state();
	bool button_hit_box(sf::Vector2f button_pos, sf::Vector2i mouse_pos) const;

	void render_score();
	void render_background() const;
public:
	death_screen(sf::RenderWindow& window, window_handler& new_window_handler);
	void update();
	void render();
};
