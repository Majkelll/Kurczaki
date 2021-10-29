#include "Game.h"

Game::Game(sf::RenderWindow& window)
	:m_window(window), player(window)
{
	this->generateLvl();
}
void Game::generateLvl()
{
	enemies.emplace_back(std::make_unique<Enemy>(sf::Vector2f(100.f, 100.f), m_window));
}
void Game::update()
{
	player.update();
	//enemies update
	for (int i = 0; i < this->enemies.size(); i++) {
		enemies[i]->update();
	}
}

void Game::render()
{
	m_window.clear();
	//player render
	player.render();
	//enemies render
	for (int i = 0; i < this->enemies.size(); i++) {
		enemies[i]->render();
	}
	m_window.display();
}
