#include "Game.h"
#include "Window.h"


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Test");
	Window windowHandler(window);
	Game game(window);
	while (window.isOpen())
	{
		windowHandler.eventBasicHandler();
		game.update();
		game.render();
	}
	return 0;
}
