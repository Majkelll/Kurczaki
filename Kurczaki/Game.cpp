#include "Game.h"

Game::Game(sf::RenderWindow& window)
	:m_window(window), player(window)
{
}
void Game::update()
{
	player.update();
}

void Game::render()
{
	m_window.clear();
	player.render();
	m_window.display();
}
