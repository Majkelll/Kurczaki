#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class window_handler
{
private:
	sf::RenderWindow& m_window_;
	int render_state_;
	int score_;
public:
	explicit window_handler(sf::RenderWindow& window);
	void event_basic_handler();

	void set_score(int new_score);
	void set_render_state(int new_render_state);

	int get_renderState() const;
	int get_score() const;
};
