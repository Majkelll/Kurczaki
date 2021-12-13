#include "WindowHendler.h"

WindowHendler::WindowHendler(sf::RenderWindow& window)
	:m_window(window)
{
	window.setFramerateLimit(60);
	this->renderState = 1;
}

void WindowHendler::eventBasicHandler()
{
	sf::Event ev;
	while (m_window.pollEvent(ev))
	{
		switch (ev.type) {
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape) {
				this->set_renderState(1);
			}
			break;
		}
	}
}

void WindowHendler::set_score(int newScore)
{
	this->score = newScore;
}

void WindowHendler::set_renderState(int newRenderState)
{
	this->renderState = newRenderState;
}

int WindowHendler::get_renderState()
{
	return this->renderState;
}

int WindowHendler::get_score()
{
	return this->score;
}
