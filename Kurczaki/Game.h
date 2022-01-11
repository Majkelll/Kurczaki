#pragma once

#include <list>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"
#include "PowerUp.h"
#include "Egg.h"
#include "WindowHendler.h"
#include "Bullet.h"

class game
{
private:
	sf::RenderWindow& m_window_;
	window_handler& m_window_handler_;
	player player_;
	sf::Text text_score_;

	std::vector<std::unique_ptr<enemy>> enemies_;
	std::vector<std::unique_ptr<bullet>> bullets_;

	std::list<power_up> power_ups_;
	std::list<egg> eggs_;

	sf::Texture background_texture_;
	sf::Sprite background_sprite_;

	sf::Font font_;

	int current_lvl_;

	void init_variables();
	void generate_lvl(int level);
	void init_text_score();
	static bool collider(sf::Vector2f pos1, sf::Vector2f pos2, int size1, int size2);
	void generate_power_ups(sf::Vector2f pos);
	void state_handler();

	void render_power_ups();
	void render_enemies() const;
	void render_background() const;
	void render_score() const;
	void render_eggs();
	void render_bullets() const;

	void update_hit_box_bullets_enemies();
	void update_shoot();
	void update_enemies();
	void update_lvl();
	void update_power_ups();
	void update_text();
	void update_eggs();
	void update_bullets();

public:
	game(sf::RenderWindow& window, window_handler& new_window_handler);
	void update();
	void render();
};
