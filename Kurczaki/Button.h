#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Button
{
private:
	sf::Vector2f position;
	sf::Vector2f size;

	sf::Color color;
	sf::RectangleShape shape;
	sf::RenderWindow& m_window;
	std::string name;


	void initVariables();
	void initShape();

public:
	Button(sf::Vector2f newPosition, sf::Vector2f newSize, std::string newName, sf::RenderWindow& window);

	sf::Vector2f get_position();
	std::string get_name();
	void update();
	void render();
};

