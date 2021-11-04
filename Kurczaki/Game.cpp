#include "Game.h"

void Game::initVeriables()
{
	this->backgroundTexture.loadFromFile("./assets/background.jpg");
	this->backgroundTexture.setSmooth(true);

	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1280, 720));

	this->currLvl = 1;

	initTextScore();
}

void Game::initTextScore()
{
	this->font.loadFromFile("./assets/font.ttf");
	this->textScore.setFont(this->font);
	this->textScore.setString("Score: 0");
	this->textScore.setCharacterSize(40);
	this->textScore.setOrigin(-20, -10);
}

void Game::updateLvl()
{
	if (this->enemies.size() <= 0) {
		this->currLvl++;
		this->generateLvl(this->currLvl);
		this->bullets.clear();
	}
}

void Game::eggsUpdate()
{
	for (int i = 0; i < this->eggs.size(); i++) {
		eggs[i]->update();
		if (eggs[i]->destruct()) {
			eggs.erase(eggs.begin() + i);
		}
	}
}

Game::Game(sf::RenderWindow& window)
	:m_window(window), player(window)
{
	this->initVeriables();
	this->generateLvl(this->currLvl);
}
void Game::generateLvl(int level)
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 4; j++) {
			enemies.emplace_back(std::make_unique<Enemy>(sf::Vector2f(40 + 100.f * i, 60 + 100.f * j), m_window));
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
		if (rand() % (1000 / this->currLvl) == 500) {
			eggs.emplace_back(std::make_unique<Egg>(sf::Vector2f(this->enemies[i]->get_position().x + 25, this->enemies[i]->get_position().y + 90), m_window));
		}
		if (rand() % 1000 == 100) {
			this->generatePowerUps(this->enemies[i]->get_position());
		}
		if (std::rand())
			if (this->enemies[i]->get_hp() <= 0) {
				this->enemies.erase(this->enemies.begin() + i);
				this->player.set_points(this->player.get_points() + 5 * this->currLvl);
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
void Game::eggsPlayerColider()
{
	for (int i = 0; i < this->eggs.size(); i++) {
		if (this->hitbox(eggs[i]->get_position(),
			this->player.get_position(),
			this->eggs[i]->get_size(),
			this->player.get_size())
			&& !this->player.get_godMode()) {
			this->player.set_hp(this->player.get_hp() - 1);
			this->eggs.erase(this->eggs.begin() + i);
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

	this->eggsUpdate();

	this->bulletsEnemiesColider();

	this->updateLvl();

	this->eggsPlayerColider();

	this->updatePowerUps();

}

void Game::render()
{
	m_window.clear();
	m_window.draw(this->backgroundSprite);

	//eggs render
	for (int i = 0; i < this->eggs.size(); i++) {
		eggs[i]->render();
	}

	//enemies render
	for (int i = 0; i < this->enemies.size(); i++) {
		enemies[i]->render();
	}

	//bullets render
	for (int i = 0; i < this->bullets.size(); i++) {
		bullets[i]->render();
	}


	//player render
	player.render();
	//text score render
	m_window.draw(this->textScore);
	//buffs render
	this->renderPowerUps();
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

void Game::generatePowerUps(sf::Vector2f pos)
{
	this->powerUps.push_back(PowerUp(m_window));
	powerUps.back().initVeriables(pos);
}

void Game::renderPowerUps()
{
	for (auto& p : this->powerUps) {
		p.render();
	}
}

void Game::updatePowerUps()
{
	std::list<PowerUp>::iterator it;
	for (it = powerUps.begin(); it != powerUps.end(); ++it) {
		it->update();
		std::cout << this->player.get_godMode() << std::endl;
		if (it->get_kabum()) {
			this->powerUps.erase(it);
		}
		if (this->hitbox(this->player.get_position(), it->get_position(), this->player.get_size(), it->get_size())) {
			switch (it->get_buff()) {
			case 0:
				this->player.set_hp(this->player.get_hp() + 1);
			case 1:
				this->player.on_godMode();
			}
			this->powerUps.erase(it);
		}
	}
}
