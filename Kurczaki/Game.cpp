#include "Game.h"

void Game::initVeriables()
{
	this->backgroundTexture.loadFromFile("./assets/background.jpg");
	this->backgroundTexture.setSmooth(true);

	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1280, 720));

	initTextScore();
}

void Game::initTextScore()
{
	this->font.loadFromFile("./assets/font.ttf");
	this->textScore.setFont(this->font);
	this->textScore.setString("Score: 0");
	this->textScore.setCharacterSize(40);
	this->textScore.setOrigin(0, 0);
}

Game::Game(sf::RenderWindow& window)
	:m_window(window), player(window)
{
	this->initVeriables();
	this->generateLvl(1);
}
void Game::generateLvl(int level)
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 4; j++) {
			enemies.emplace_back(std::make_unique<Enemy>(sf::Vector2f(40 + 100.f * i, 40 + 100.f * j), m_window));
		}
	}
	for (auto& e : enemies) {
		e->set_hp(e->get_hp() * level);
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
	this->textScore.setString("Score: " + std::to_string(this->player.get_points()));

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
	m_window.draw(this->backgroundSprite);

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

	m_window.draw(this->textScore);
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
