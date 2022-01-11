#include "WindowHendler.h"

window_handler::window_handler(sf::RenderWindow& window)
	: m_window_(window), render_state_(1)
{
	window.setFramerateLimit(60);
}

void window_handler::event_basic_handler()
{
	sf::Event ev{};
	while (m_window_.pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			m_window_.close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
			{
				this->set_render_state(1);
			}
			break;
		default: ;
		}
	}
}

void window_handler::set_score(const int new_score)
{
	this->score_ = new_score;
}

void window_handler::set_render_state(const int new_render_state)
{
	this->render_state_ = new_render_state;
}

int window_handler::get_renderState() const
{
	return this->render_state_;
}

int window_handler::get_score() const
{
	return this->score_;
}
