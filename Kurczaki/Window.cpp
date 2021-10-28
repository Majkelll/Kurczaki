#include "Window.h"

Window::Window(sf::RenderWindow& window)
	:m_window(window)
{
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
				m_window.close();
			}
			break;
		}
	}
}
