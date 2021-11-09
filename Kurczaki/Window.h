#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
class Window
{
private:
	sf::RenderWindow& m_window;
	int renderState;
public:
	Window(sf::RenderWindow& window);
	void eventBasicHandler();

	void set_renderState(int newRenderState);

	int get_renderState();
};