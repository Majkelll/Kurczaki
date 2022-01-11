#include "Game.h"
#include "WindowHendler.h"
#include "Menu.h"
#include "DeathScreen.h"

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Kurczaki v.5.2");
	window.setFramerateLimit(60);
	window_handler window_handler(window);
	menu menu(window, window_handler);
	game game(window, window_handler);
	death_screen death_screen(window, window_handler);

	while (window.isOpen())
	{
		window_handler.event_basic_handler();
		if (window_handler.get_renderState() == 1)
		{
			menu.update();
			menu.render();
		}
		else if (window_handler.get_renderState() == 2)
		{
			game.update();
			game.render();
		}
		else if (window_handler.get_renderState() == 3)
		{
			death_screen.update();
			death_screen.render();
		}
		else if (window_handler.get_renderState() == 4)
		{
			break;
		}
		else
		{
			std::cout << "Can't handle render state";
		}
	}

	return 0;
}
