#include "Game.h"
#include "WindowHendler.h"
#include "Menu.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Kurczaki v.0");
	window.setFramerateLimit(60);
	WindowHendler windowHandler(window);
	Menu menu(window, windowHandler);
	Game game(window);
	while (window.isOpen())
	{
		windowHandler.eventBasicHandler();
		if (windowHandler.get_renderState() == 1) {
			menu.update();
			menu.render();

		}
		else {
			game.update();
			game.render();
		}
	}
	return 0;
}
