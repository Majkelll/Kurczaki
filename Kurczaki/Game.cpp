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
	}
}

Game::Game(sf::RenderWindow& window, WindowHendler& newWindowHandler)
	:m_window(window), player(window), m_windowHandler(newWindowHandler)
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
void Game::updateEggs()
{
	std::list<Egg>::iterator egg;
	for (egg = eggs.begin(); egg != eggs.end(); ++egg) {
		egg->update();
		if (egg->get_kabum()) {
			this->eggs.erase(egg);
		}
		if ((this->hitbox(this->player.get_position(), egg->get_position(), this->player.get_size(), egg->get_size()))
			&& !this->player.get_godMode())
		{
			this->player.set_hp(this->player.get_hp() - 1);
			this->eggs.erase(egg);
		}
	}
}
void Game::updateBullets()
{
	for (int i = 0; i < this->bullets.size(); i++) {
		bullets[i]->update();
		if (bullets[i]->get_kabum()) {
			this->bullets.erase(this->bullets.begin() + i);
		}
	}
}
void Game::updateHitBoxBulletsEnemies()
{
	for (int j = 0; j < this->bullets.size(); j++) {
		for (int i = 0; i < this->enemies.size(); i++) {
			if (this->hitbox(bullets[j]->get_position(), this->enemies[i]->get_position(), bullets[j]->get_size(), this->enemies[i]->get_size())) {
				this->enemies[i]->set_hp(this->enemies[i]->get_hp() - bullets[j]->get_damage());
				this->bullets.erase(this->bullets.begin() + j);
			}
		}
	}
}
void Game::updateShoot()
{
	if (player.shoot()) {
		bullets.emplace_back(std::make_unique<Bullet_v2>(m_window));
		bullets[bullets.size() - 1]->initVeriables(sf::Vector2f(
			this->player.get_position().x + this->player.get_size() / 2,
			this->player.get_position().y));
	}
}
void Game::updateEnemies()
{
	for (int i = 0; i < this->enemies.size(); i++) {
		enemies[i]->update();
		if (rand() % (3000 / this->currLvl) == 500) {
			this->eggs.push_back(Egg(m_window));
			eggs.back().initVeriables(this->enemies[i]->get_position());
		}
		if (rand() % 5000 == 100) {
			this->generatePowerUps(this->enemies[i]->get_position());
		}
		if (this->enemies[i]->get_hp() <= 0) {
			this->enemies.erase(this->enemies.begin() + i);
			this->player.set_points(this->player.get_points() + 5 * this->currLvl);
		}
	}
}
void Game::update()
{
	this->m_windowHandler.set_score(this->player.get_points());
	this->stateHandler();
	this->updateShoot();
	this->player.update();
	this->updateText();
	this->updateEnemies();
	this->updateLvl();
	this->updatePowerUps();
	this->updateEggs();
	this->updateBullets();
	this->updateHitBoxBulletsEnemies();
}

void Game::render()
{
	m_window.clear();

	this->renderBackground();
	this->renderEnemies();
	this->player.render();
	this->renderScore();
	this->renderPowerUps();
	this->renderEggs();
	this->renderBullets();

	m_window.display();
}

bool Game::hitbox(sf::Vector2f pos1, sf::Vector2f pos2, int size1, int size2)
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

void Game::stateHandler()
{
	if (player.get_hp() <= 0) {
		this->m_windowHandler.set_renderState(3);
	}
}

void Game::renderPowerUps()
{
	for (auto& p : this->powerUps) {
		p.render();
	}
}

void Game::renderEnemies()
{
	for (int i = 0; i < this->enemies.size(); i++) {
		enemies[i]->render();
	}
}

void Game::renderBackground()
{
	m_window.draw(this->backgroundSprite);
}

void Game::renderScore()
{
	m_window.draw(this->textScore);
}

void Game::renderEggs()
{
	for (auto& e : this->eggs) {
		e.render();
	}
}

void Game::renderBullets()
{
	for (int i = 0; i < this->bullets.size(); i++) {
		bullets[i]->render();
	}
}

void Game::updatePowerUps()
{
	std::list<PowerUp>::iterator buff;
	for (buff = powerUps.begin(); buff != powerUps.end(); ++buff) {
		buff->update();
		if (buff->get_kabum()) {
			this->powerUps.erase(buff);
		}
		if (this->hitbox(this->player.get_position(), buff->get_position(), this->player.get_size(), buff->get_size())) {
			switch (buff->get_buff()) {
			case 0:
				this->player.set_hp(this->player.get_hp() + 1);
				break;
			case 1:
				this->player.on_godMode();
				break;
			case 2:
				this->player.set_shootSpeed(this->player.get_shootSpeed() - 10);
				break;
			case 3:
				for (auto& a : this->eggs) {
					a.set_speed(a.get_speed() + 4);
				}
				break;
			case 4:
				this->player.set_speed(this->player.get_speed() + 1);
				break;
			}
			this->powerUps.erase(buff);
		}
	}
}

void Game::updateText()
{
	this->textScore.setString("Score: " + std::to_string(this->player.get_points()));
}
