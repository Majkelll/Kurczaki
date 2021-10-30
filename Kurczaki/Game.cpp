#include "Game.h"

Game::Game(sf::RenderWindow& window)
	:m_window(window), player(window)
{
	this->generateLvl();
}
void Game::generateLvl()
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 4; j++) {
			enemies.emplace_back(std::make_unique<Enemy>(sf::Vector2f(40 + 100.f * i, 40 + 100.f * j), m_window));
		}
	}
}
void Game::bulletsUpdate()
{
	for (int i = 0; i < this->bullets.size(); i++) {
		bullets[i]->update();
		if (bullets[i]->destruct()) {
			bullets.erase(bullets.begin() + i);
		}
	}
}
void Game::enemiesUpdate()
{
	for (int i = 0; i < this->enemies.size(); i++) {
		enemies[i]->update();
		if (this->enemies[i]->get_hp() <= 0) {
			this->enemies.erase(this->enemies.begin() + i);
			this->player.set_points(this->player.get_points() + this->enemies[i]->get_coins());
			std::cout << this->player.get_points() << std::endl;
		}
	}
}
void Game::bulletsEnemiesColider()
{
	for (int i = 0; i < this->enemies.size(); i++) {
		for (int j = 0; j < this->bullets.size(); j++) {
			if (this->hitbox(enemies[i]->get_position(),
				this->bullets[j]->get_position(),
				this->enemies[i]->get_size(),
				this->bullets[j]->get_size()))
			{
				this->enemies[i]->set_hp(this->enemies[i]->get_hp() - this->bullets[j]->get_damage());
				this->bullets.erase(this->bullets.begin() + j);
			}
		}
	}
}
void Game::update()
{
	//player update
	player.update();

	if (player.shoot()) {
		bullets.emplace_back(std::make_unique<Bullet>(sf::Vector2f(this->player.get_position().x + this->player.get_size() / 2, this->player.get_position().y + this->player.get_size() / 3), m_window));
	}

	this->enemiesUpdate();

	this->bulletsUpdate();

	this->bulletsEnemiesColider();
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

	//bullets render
	for (int i = 0; i < this->bullets.size(); i++) {
		bullets[i]->render();
	}

	m_window.display();
}

bool Game::hitbox(sf::Vector2f pos1, sf::Vector2f pos2, float size1, float size2)
{
	if (pos1.x < pos2.x + size2 &&
		pos1.x + size1 > pos2.x &&
		pos1.y < pos2.y + size2 &&
		size1 + pos1.y > pos2.y
		) {
		return true;
	}
	return false;
}
