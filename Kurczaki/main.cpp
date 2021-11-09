#include "Game.h"
#include "Window.h"


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Kurczaki v.0");
	window.setFramerateLimit(60);
	Window windowHandler(window);
	Game game(window,windowHandler);
	while (window.isOpen())
	{
		windowHandler.eventBasicHandler();
		if (windowHandler.get_renderState() == 1) {
			game.update();
			game.render();
		}
	}
	return 0;
}
