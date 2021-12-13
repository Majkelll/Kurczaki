#include "Game.h"
#include "WindowHendler.h"
#include "Menu.h"
#include "DeathScreen.h"

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
	Game game(window, windowHandler);
	DeathScreen deathScreen(window, windowHandler);

	while (window.isOpen())
	{
		windowHandler.eventBasicHandler();
		if (windowHandler.get_renderState() == 1) {
			menu.update();
			menu.render();

		}
		else if (windowHandler.get_renderState() == 2) {
			game.update();
			game.render();
		}
		else if (windowHandler.get_renderState() == 3) {
			deathScreen.update();
			deathScreen.render();
		}
		else if (windowHandler.get_renderState() == 4) {
			break;
		}
		else {
			std::cout << "Can't handle render state";
		}
	}

	return 0;
}
