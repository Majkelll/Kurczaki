#include "Window.h"

Window::Window(sf::RenderWindow& window)
	:m_window(window)
{
	window.setFramerateLimit(60);
	this->renderState = 1;
}

void Window::eventBasicHandler()
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
				this->set_renderState(0);
			}
			break;
		}
	}
}

void Window::set_renderState(int newRenderState)
{
	this->renderState = newRenderState;
}

int Window::get_renderState()
{
	return this->renderState;
}
