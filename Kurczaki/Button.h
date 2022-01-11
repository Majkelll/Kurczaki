#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class button
{
private:
	sf::Vector2f position_;
	sf::Vector2f size_;

	sf::RenderWindow& m_window_;
	std::string name_;

	sf::Sprite sprite_;
	sf::Texture btn_texture_;
	int texture_;

	static void init_variables();
	void init_shape();

public:
	button(sf::Vector2f new_position, int new_texture, sf::Vector2f new_size, std::string new_name,
	       sf::RenderWindow& window);

	sf::Vector2f get_position() const;
	std::string get_name();
	static void update();
	void render() const;
};
